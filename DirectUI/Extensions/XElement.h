#pragma once

namespace DirectUI
{
	interface IXProvider;

	class UILIB_API XElement
		: public HWNDHost
		, IXElementCP
	{
	public:
		//~ Begin DirectUI::IXElementCP Interface
		HWND GetNotificationSinkHWND() override;
		UINT GetCreationFlags() override;
		//~ End DirectUI::IXElementCP Interface

		static const UINT s_uNavigateOutMsg;
		static const UINT s_uButtonFocusChangeMsg;
		static const UINT s_uUnhandledSyscharMsg;

		static UID WINAPI UnhandledSyschar();

		XElement();
		XElement(const XElement& other) = default;
		~XElement() override;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		void OnInput(InputEvent* pie) override;
		bool OnMessage(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) override;
		bool OnSysChar(WCHAR chKeyCode) override;
		bool OnSinkThemeChanged(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) override;
		void OnEvent(Event* pEvent) override;

		// ReSharper disable once CppHidingFunction
		HRESULT Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie);

		HWND CreateHWND(HWND hwndParent) override;
		void SetKeyFocus() override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		IXProvider* GetProvider();
		HRESULT SetProvider(IUnknown* punk);
		void FreeProvider();

		// ReSharper disable once CppHidingFunction
		bool IsDescendent(Element* pe);
		HWND GetInnerHWND();

	private:
		IXProvider* _pixp;
		HWND _hwndInner;
	};
}
