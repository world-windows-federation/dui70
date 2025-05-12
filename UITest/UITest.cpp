#include "UITest.h"

using namespace DirectUI;

struct LogListener : IElementListener
{
	void OnListenerAttach(Element* peFrom) override
	{
		OutputDebugString(std::format(L"attach: {:p}\n", (void*)peFrom).c_str());
	}

	void OnListenerDetach(Element* peFrom) override
	{
		OutputDebugString(std::format(L"detach: {:p}\n", (void*)peFrom).c_str());
	}

	bool OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override
	{
		OutputDebugString(std::format(L"prop change: {:p} {} {} {:p}<{}> {:p}<{}>\n",
			(void*)peFrom, (PCWSTR)ppi->pszName, iIndex, (void*)pvOld, pvOld->GetType(), (void*)pvNew, pvNew->GetType()).c_str());
		return true;
	}

	void OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* prop, int iIndex, Value* pvOld, Value* pvNew) override
	{
		OutputDebugString(std::format(L"listened prop change: {:p} {} {} {:p}<{}> {:p}<{}>\n",
			(void*)peFrom, (PCWSTR)prop->pszName, iIndex, (void*)pvOld, pvOld->GetType(), (void*)pvNew, pvNew->GetType()).c_str());
	}

	void OnListenedEvent(Element* peFrom, Event* pEvent) override
	{
		OutputDebugString(std::format(L"listened event: {:p} {:p}\n", (void*)peFrom, (void*)pEvent).c_str());
	}

	void OnListenedInput(Element* peFrom, InputEvent* pInput) override
	{
		OutputDebugString(std::format(L"listened input: {:p} {:p}\n", (void*)peFrom, (void*)pInput).c_str());
	}
};


template <typename TFunctor>
struct EventListener : IElementListener
{
	TFunctor f;

	EventListener(const TFunctor& f) : f(f)
	{
	}

	void OnListenerAttach(Element* peFrom) override {}
	void OnListenerDetach(Element* peFrom) override {}
	bool OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override { return true; }
	void OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override {}
	void OnListenedEvent(Element* peFrom, Event* pEvent) override { f(peFrom, pEvent); }
	void OnListenedInput(Element* peFrom, InputEvent* pInput) override {}
};

std::wstring to_string(ValueType type)
{
	switch (type)
	{
		case ValueType::Unavailable: return L"Unavailable";
		case ValueType::Unset:       return L"Unset";
		case ValueType::Null:        return L"Null";
		case ValueType::Int:         return L"Int";
		case ValueType::Bool:        return L"Bool";
		case ValueType::Element:     return L"Element";
		case ValueType::Ellist:      return L"Ellist";
		case ValueType::String:      return L"String";
		case ValueType::Point:       return L"Point";
		case ValueType::Size:        return L"Size";
		case ValueType::Rect:        return L"Rect";
		case ValueType::Color:       return L"Color";
		case ValueType::Layout:      return L"Layout";
		case ValueType::Graphic:     return L"Graphic";
		case ValueType::Sheet:       return L"Sheet";
		case ValueType::Expr:        return L"Expr";
		case ValueType::Atom:        return L"Atom";
		case ValueType::Cursor:      return L"Cursor";
		case ValueType::Float:       return L"Float";
		case ValueType::DblList:     return L"DblList";
		default:
			throw std::logic_error{ "unreachable" };
	}
}

void DumpClassInfo(IClassInfo* info)
{
	constexpr const WCHAR* DOC_DIR = LR"(C:\Users\7mile\source\repos\DirectUI\docs)";

	std::wstring name = info->GetName();

	std::wofstream os{ std::filesystem::path{ DOC_DIR } / (name + L"Class.g.txt") };

	os << (std::format(L"ClassInfo: <{}>\n", name).c_str());

	IClassInfo* base = info->GetBaseClass();
	os << (std::format(L"  Base Class: <{}>\n", base ? base->GetName() : L"None").c_str());

	os << (L"  Properties:\n");
	for (unsigned int i = 0; i < info->GetPICount(); i++)
	{
		const PropertyInfo* prop = info->EnumPropertyInfo(i);
		os << (std::format(L"    [{}]: {}\n", (LPCWSTR)prop->pszName, to_string((ValueType)(prop->pValidValues[0] & 0x3F))).c_str());
		if (prop->pEnumMaps)
		{
			os << (L"      Enum values:\n");
			for (const EnumMap* ptr = prop->pEnumMaps; ptr->pszEnum; ptr++)
			{
				os << (std::format(L"        {} : 0x{:x} ({})\n", (PCWSTR)ptr->pszEnum, (UINT32)ptr->nEnum, ptr->nEnum).c_str());
			}
		}
	}
}

namespace DirectUI
{
	class CClassFactory;
}

long (*RealClassFactoryRegister)(CClassFactory*, IClassInfo*) = nullptr;

HRESULT HookedRegister(CClassFactory* self, IClassInfo* info)
{
	DumpClassInfo(info);
	return RealClassFactoryRegister(self, info);
}

inline void HookClassFactoryRegister()
{
	RealClassFactoryRegister = (decltype(RealClassFactoryRegister))((UINT64)GetModuleHandle(L"dui70.dll") + 0x37634);

	//DetourTransactionBegin();
	//DetourUpdateThread(GetCurrentThread());

	auto pfMine = &HookedRegister;
	//DetourAttach(&(PVOID&)RealClassFactoryRegister, *(PBYTE*)&pfMine);
	//DetourTransactionCommit();
}

static void CALLBACK WilLogCallback(wil::FailureInfo const &failure) noexcept
{
	wchar_t message[2048];
	HRESULT hr = GetFailureLogString(message, ARRAYSIZE(message), failure);
	if (SUCCEEDED(hr))
	{
		wprintf(L"%s", message); // message includes newline
	}
}

void CALLBACK DUI_ParserErrorCB(const WCHAR* pszError, const WCHAR* pszToken, int dLine, void* pContext)
{
	//WCHAR szParserError[1024];
	//StringCchPrintfW(szParserError, ARRAYSIZE(szParserError), L"%s '%s' (%d)", pszError, pszToken, (dLine != -1) ? dLine : 0);
	//MessageBox(nullptr, szParserError, L"Error while parsing DirectUI", MB_ICONERROR);
	if (pszError != nullptr)
	{
		MessageBox(nullptr, pszError, L"Error while parsing DirectUI", MB_ICONERROR);
		OutputDebugString(pszError);
		DebugBreak();
	}
}

HRESULT WINAPI DUI_InitializeDUI()
{
	HRESULT hr = S_OK;

	hr = DirectUI::InitProcess(DUI_VERSION);
	if (SUCCEEDED(hr))
	{
		hr = DirectUI::InitThread(TSM_IMMERSIVE);
		if (FAILED(hr))
		{
			DirectUI::UnInitProcess();
		}
	}
	return hr;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
	// uncomment for earlier than 1703
	//SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);

	wil::SetResultLoggingCallback(WilLogCallback);

	THROW_IF_FAILED(CoInitializeEx(nullptr, 0));

	THROW_IF_FAILED(DUI_InitializeDUI());

	// uncomment to update class definitions
	// HookClassFactoryRegister();
	THROW_IF_FAILED(RegisterPVLBehaviorFactory());

	HMONITOR hMonitor = MonitorFromWindow(nullptr, MONITOR_DEFAULTTOPRIMARY);
	MONITORINFO mi = { sizeof(mi) };
	THROW_IF_WIN32_BOOL_FALSE(GetMonitorInfo(hMonitor, &mi));

	UINT dpiX, dpiY;
	THROW_IF_FAILED(GetDpiForMonitor(hMonitor, MDT_EFFECTIVE_DPI, &dpiX, &dpiY));
	int initWidth = MulDiv(800, dpiX, 96);
	int initHeight = MulDiv(600, dpiY, 96);

	RECT rcWindow;
	rcWindow.left = mi.rcWork.left + (RECTWIDTH(mi.rcWork) - initWidth) / 2;
	rcWindow.top = mi.rcWork.top + (RECTHEIGHT(mi.rcWork) - initHeight) / 2;
	rcWindow.right = rcWindow.left + initWidth;
	rcWindow.bottom = rcWindow.top + initHeight;

	NativeHWNDHost* pHost;
	THROW_IF_FAILED(NativeHWNDHost::Create(
		L"Microsoft DirectUI Test", nullptr, nullptr,
		rcWindow.left, rcWindow.top, RECTWIDTH(rcWindow), RECTHEIGHT(rcWindow),
		WS_EX_WINDOWEDGE, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, &pHost));

	DUIXmlParser* pParser;
	THROW_IF_FAILED(DUIXmlParser::Create(&pParser, nullptr, nullptr, DUI_ParserErrorCB, nullptr));

	THROW_IF_FAILED(pParser->SetXMLFromResource(IDR_UIFILE1, hInstance, HINST_THISCOMPONENT));

	Value* pvRefDuiSheet;
	THROW_IF_FAILED(pParser->GetSheet(L"ImmersiveLight", &pvRefDuiSheet));

	DWORD dwDeferCookie;
	HWNDElement* peHwndElement;
	THROW_IF_FAILED(HWNDElement::Create(pHost->GetHWND(), true, 0, nullptr, &dwDeferCookie, (Element**)&peHwndElement));
	auto peHwndElementCleaner = wil::scope_exit([&] { peHwndElement->Destroy(false); });

	Element* peWizardMain;
	THROW_IF_FAILED(pParser->CreateElement(L"WizardMain", peHwndElement, nullptr, nullptr, &peWizardMain));
	peHwndElementCleaner.release();
	auto peWizardMainCleaner = wil::scope_exit([&] { peWizardMain->Destroy(false); });

	TouchButton* peTouchButton;
	EventListener elTouchButton([&](Element* peFrom, Event* pEvent) -> void
	{
		if (pEvent->uidType == TouchButton::Click)
		{
			MessageBoxW(pHost->GetHWND(), L"TouchButton clicked!", L"UITest", MB_OK);
		}
	});

	RichText* peSXWizardContentBox = (RichText*)peWizardMain->FindDescendent(StrToID(L"SXWizardContentBox"));
	if (peSXWizardContentBox && peSXWizardContentBox->GetClassInfoW()->IsSubclassOf(RichText::GetClassInfoPtr()))
	{
		CValuePtr spv;
		const WCHAR* pszCurrent = peSXWizardContentBox->GetContentString(&spv);
		if (pszCurrent)
		{
			peSXWizardContentBox->SetContentString((std::wstring{ pszCurrent } + L"\n\nThis text is appended via code.").c_str());
		}

		Element* peParent = peSXWizardContentBox->GetParent();
		if (peParent)
		{
			peParent = peParent->GetParent();
		}
		if (peParent)
		{
			{
				TouchEdit2* peTouchEdit2;
				THROW_IF_FAILED(TouchEdit2::Create(peParent, nullptr, (DirectUI::Element**)&peTouchEdit2));
				auto peTouchEdit2Cleaner = wil::scope_exit([&] { peTouchEdit2->Destroy(false); });

				THROW_IF_FAILED(peTouchEdit2->SetSheet(pvRefDuiSheet->GetStyleSheet()));
				THROW_IF_FAILED(peTouchEdit2->SetPromptText(L"Test TouchEdit2 here"));

				THROW_IF_FAILED(peParent->Add(peTouchEdit2));
				peTouchEdit2Cleaner.release();
			}

			{
				THROW_IF_FAILED(TouchButton::Create(peParent, nullptr, (DirectUI::Element**)&peTouchButton));
				auto peTouchButtonCleaner = wil::scope_exit([&] { peTouchButton->Destroy(false); });

				// THROW_IF_FAILED(peTouchButton->SetSheet(pvRefDuiSheet->GetStyleSheet())); // Crash on exit
				THROW_IF_FAILED(peTouchButton->SetContentString(L"I am TouchButton, click me!"));
				THROW_IF_FAILED(peTouchButton->AddListener(&elTouchButton));

				THROW_IF_FAILED(peParent->Add(peTouchButton));
				peTouchButtonCleaner.release();
			}
		}
	}

	THROW_IF_FAILED(peWizardMain->SetVisible(true));
	peWizardMain->EndDefer(dwDeferCookie);
	pHost->Host(peWizardMain);
	peWizardMainCleaner.release();

	pHost->ShowWindow(SW_SHOW);

	//DumpDuiTree(peWizardMain, TRUE);

	StartMessagePump();

	pvRefDuiSheet->Release();
	pHost->Destroy();

	UnInitProcess();
	return 0;
}
