#pragma once

namespace DirectUI
{
	class UILIB_API Browser : public Element
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Initialize(Element* pParent, DWORD* pdwDeferCookie);

		static UID WINAPI StartNavigate();
		static UID WINAPI Entered();
		static UID WINAPI Leaving();

		void OnEvent(Event* pEvent) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		Element* GetCurrentPage();
		ATOM GetCurrentPageID();
		class Pages* GetPages();

	private:
		int FireNavigate(ATOM aNewPage);

		Element* _peCurrentPage;
	};
}
