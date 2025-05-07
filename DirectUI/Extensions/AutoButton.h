#pragma once

namespace DirectUI
{
	class UILIB_API AutoButton : public AccessibleButton
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Initialize(Element* pParent, DWORD* pdwDeferCookie);

		void OnEvent(Event* pEvent) override;

		static UID WINAPI Toggle();

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();
	};
}
