#pragma once

namespace DirectUI
{
	class UILIB_API CCCheckBox : public CCBaseCheckRadioButton
	{
	public:
		CCCheckBox(DWORD dwStyle);
		CCCheckBox(const CCCheckBox& other) = default;
		CCCheckBox(CCCheckBox&& other) noexcept = default;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();

		void OnInput(InputEvent* pInputEvent) override;
		bool OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) override;
	};
}
