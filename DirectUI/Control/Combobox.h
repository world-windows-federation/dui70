#pragma once

namespace DirectUI
{
	class UILIB_API Combobox : public HWNDHost
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		void OnInput(InputEvent* pInput) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnHosted(Element* peNewHost) override;
		bool OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) override;
		int OnAdjustWindowSize(int x, int y, UINT uFlags) override;
		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT Register();

		int AddString(const WCHAR* lpszString); // @TODO: Really an int?
		static UID WINAPI SelectionChange();
		static const PropertyInfo* WINAPI SelectionProp();
		int GetSelection();
		HRESULT SetSelection(int v);

		Combobox();
		Combobox(const Combobox& other) = default;
		~Combobox() override;

		HRESULT Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie);
		HWND CreateHWND(HWND hwndParent) override;
	};
}
