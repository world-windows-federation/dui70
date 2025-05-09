#pragma once

namespace DirectUI
{
	class UILIB_API Expando : public Expandable
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		void OnEvent(Event* pEvent) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		HRESULT Add(Element** ppe, UINT cCount) override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		HRESULT Initialize(Element* pParent, DWORD* pdwDeferCookie);

	protected:
		static ATOM Arrow();
		static ATOM Clipper();
		void UpdateChildren(Value* pvNew);

	private:
		bool _fExpanding;
		static ATOM _atmArrow;
		static ATOM _atmClipper;
	};
}
