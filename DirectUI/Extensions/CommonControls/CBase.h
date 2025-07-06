#pragma once

namespace DirectUI
{
	typedef int (WINAPI *NOTIFYHANDLER)(UINT, UINT, int, int*, void*); // @TODO: Check the types

	class UILIB_API CCBase : public HWNDHost
	{
	public:
		CCBase(DWORD dwStyle = WM_NULL, const WCHAR* psz = nullptr);
		CCBase(const CCBase& other) = default;

		~CCBase() override;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		// ReSharper disable once CppHidingFunction
		HRESULT Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie);

		void OnInput(InputEvent* pie) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		bool OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) override;

		// Callbacks
		virtual bool OnCustomDraw(NMCUSTOMDRAW* pnmcd, LRESULT* plRet);
		virtual bool OnLostDialogFocus(IDialogElement* pDE);
		virtual bool OnReceivedDialogFocus(IDialogElement* pDE);

		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;
		HWND CreateHWND(HWND hwndParent) override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();

		int AddString(const WCHAR* pszString);

		UID WinStyleChange();

		static const PropertyInfo* WINAPI WinStyleProp();
		int GetWinStyle();
		HRESULT SetWinStyle(int v);

		void SetNotifyHandler(NOTIFYHANDLER pfnnh, HCONTEXT pContext);
		HRESULT DefaultAction() override;

	protected:
		DWORD _dwStyle;
		const WCHAR* _pszWindowClass;
		NOTIFYHANDLER _pfnnh;
		HCONTEXT _pContext;

		virtual void PostCreate(HWND hwnd);
	};
}
