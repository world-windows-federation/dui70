#pragma once

namespace DirectUI
{
	class UILIB_API CCBaseCheckRadioButton : public CCPushButton
	{
	public:
		CCBaseCheckRadioButton(DWORD dwStyle);
		CCBaseCheckRadioButton(const CCBaseCheckRadioButton& other) = default;
		CCBaseCheckRadioButton(CCBaseCheckRadioButton&& other) noexcept = default;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();

		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;
		bool OnLostDialogFocus(IDialogElement* pDE) override;
		bool OnReceivedDialogFocus(IDialogElement* pDE) override;

	protected:
		void PostCreate(HWND hwnd) override;
	};
}
