#pragma once

namespace DirectUI
{
	class UILIB_API CCPushButton : public CCBase
	{
	public:
		CCPushButton(DWORD dwStyle = WM_NULL);
		CCPushButton(const CCPushButton& other) = default;
		CCPushButton(CCPushButton&& other) noexcept = default;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();

		static const PropertyInfo* WINAPI OverrideButtonBackgroundProp();
		static const PropertyInfo* WINAPI HasShieldProp();

		bool GetOverrideButtonBackground();
		bool GetHasShield();

		HRESULT SetOverrideButtonBackground(bool v);

		bool OnMessage(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) override;
		bool GetButtonColor(HDC hdc, HBRUSH* phbrush);
		void OnInput(InputEvent* pInputEvent) override;
		bool OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;

		virtual void OnSelectedPropertyChanged();

		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;
		virtual SIZE EstimateContentSize(int dConstW, int dConstH, Surface* psrf);

		bool OnLostDialogFocus(IDialogElement* pDE) override;
		bool OnReceivedDialogFocus(IDialogElement* pDE) override;

		HRESULT DefaultAction() override;

	protected:
		void SetDefaultState(DWORD dwTypeNormal, DWORD dwTypeDefault);
	};
}
