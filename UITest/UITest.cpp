#include <Windows.h>

#include <Vsstyle.h>
#include <vssym32.h>

#include <wil/common.h>
#include <wil/result.h>

#include <fstream>
#include <sstream>
#include <format>
#include <functional>
#include <filesystem>

#include "../DirectUI/DirectUI.h"

#pragma comment(lib,"dui70.lib")
#pragma comment(lib, "comctl32.lib")
#include "resource.h"

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


struct EventListener : IElementListener
{
	using handler_t = std::function<void(Element*, Event*)>;

	handler_t f;

	EventListener(const handler_t& f) : f(f)
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

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	wil::SetResultLoggingCallback(WilLogCallback);

	CoInitializeEx(nullptr, 0);

	THROW_IF_FAILED(InitProcessPriv(14, nullptr, true, true, true));
	THROW_IF_FAILED(InitThread(0x2));

	// uncomment to update class definitions
	// HookClassFactoryRegister();
	THROW_IF_FAILED(RegisterAllControls());

	NativeHWNDHost* pHost;
	THROW_IF_FAILED(NativeHWNDHost::Create(
		L"Microsoft DirectUI Test", nullptr, nullptr,
		//CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		600, 400, 800, 600,
		WS_EX_WINDOWEDGE, WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, &pHost));

	DUIXmlParser* pParser;
	THROW_IF_FAILED(DUIXmlParser::Create(&pParser, nullptr, nullptr, nullptr, nullptr));

	pParser->SetParseErrorCallback([](const WCHAR* pszError, const WCHAR* pszToken, int dLine, void* pContext)
	{
		MessageBox(nullptr, std::format(L"err: {}; {}; {}\n", pszError, pszToken, dLine).c_str(), L"Error while parsing DirectUI", 0);
		DebugBreak();
	}, nullptr);

	THROW_IF_FAILED(pParser->SetXMLFromResource(IDR_UIFILE1, hInstance, hInstance));

	DWORD dwDeferCookie;
	HWNDElement* peHwndElement;
	THROW_IF_FAILED(HWNDElement::Create(pHost->GetHWND(), true, 0, nullptr, &dwDeferCookie, (Element**)&peHwndElement));

	Element* peWizardMain;
	THROW_IF_FAILED(pParser->CreateElement(L"WizardMain", peHwndElement, nullptr, nullptr, &peWizardMain));

	THROW_IF_FAILED(peWizardMain->SetVisible(true));
	peWizardMain->EndDefer(dwDeferCookie);
	pHost->Host(peWizardMain);

	pHost->ShowWindow(SW_SHOW);

	//DumpDuiTree(pWizardMain, 0);

	StartMessagePump();

	UnInitProcessPriv(nullptr);
	return 0;
}
