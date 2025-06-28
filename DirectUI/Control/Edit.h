#pragma once

namespace DirectUI
{
	class UILIB_API Edit : public HWNDHost
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnInput(InputEvent*) override;

		bool OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) override;

		UINT MessageCallback(GMSG* pGMsg) override;

		bool IsContentProtected() override;

		const WCHAR* GetContentStringAsDisplayed(Value** ppv) override;
		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;

		static UID WINAPI Enter();

		static const PropertyInfo* WINAPI MultilineProp();
		static const PropertyInfo* WINAPI PasswordCharacterProp();
		static const PropertyInfo* WINAPI DirtyProp();
		static const PropertyInfo* WINAPI MaxLengthProp();
		static const PropertyInfo* WINAPI ThemedBorderProp();
		static const PropertyInfo* WINAPI WantTabsProp();

		int GetPasswordCharacter();
		bool GetMultiline();
		bool GetDirty();
		bool GetThemedBorder();
		int GetMaxLength();
		bool GetWantTabs();

		HRESULT SetPasswordCharacter(int v);
		HRESULT SetMultiline(bool v);
		HRESULT SetDirty(bool v);
		HRESULT SetThemedBorder(bool v);
		HRESULT SetMaxLength(int v);
		HRESULT SetWantTabs(bool v);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		Edit();
		Edit(const Edit& other) = default;
		~Edit() override;

		HRESULT Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie);

	protected:
		HWND CreateHWND(HWND hwndParent) override;
		virtual HWND CreateHWND(HWND hwndParent, bool bPassword);

	private:
		void PropertyChangedCore(const PropertyInfo* ppi, int iIndex, Value* pvNew, HWND hwnd);
		UINT GetTextHeight();
	};
}
