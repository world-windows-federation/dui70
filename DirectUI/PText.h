#pragma once

namespace DirectUI
{
	class UILIB_API PText : public TextGraphic
	{
	public:
		~PText() override;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		HRESULT Initialize(Element* pParent, DWORD* pdwDeferCookie);

		bool OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;

		static IClassInfo* GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		void SetDataEntry(IDataEntry*);

	private:
		IDataEntry* _pde;
		BSTR _bstrTemplate;
	};
}
