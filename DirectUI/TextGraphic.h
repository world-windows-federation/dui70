#pragma once

namespace DirectUI
{
	class UILIB_API TextGraphic : public Element
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		HRESULT Initialize(Element* pParent, DWORD* pdwDeferCookie);

		static const PropertyInfo* WINAPI SideGraphicProp();

		bool OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		LPCWSTR GetContentStringAsDisplayed(Value** ppv) override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

	protected:
		Element* _peText;
		Element* _peGraphic;
	};
}
