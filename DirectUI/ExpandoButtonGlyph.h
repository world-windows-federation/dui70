#pragma once

namespace DirectUI
{
	class UILIB_API ExpandoButtonGlyph : public Button
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		HRESULT Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		bool OnLostDialogFocus(IDialogElement* pDE) override;
		bool OnReceivedDialogFocus(IDialogElement* pDE) override;
	};
}
