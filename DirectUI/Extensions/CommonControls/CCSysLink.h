#pragma once

namespace DirectUI
{
	class UILIB_API CCSysLink : public CCBase
	{
	public:
		CCSysLink();
		CCSysLink(const CCSysLink& other) = default;
		CCSysLink(CCSysLink&& other) noexcept = default;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();

		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;
		void OnInput(InputEvent* pInputEvent) override;
		bool OnLostDialogFocus(IDialogElement* pDE) override;
		bool OnReceivedDialogFocus(IDialogElement* pDE) override;
	};
}
