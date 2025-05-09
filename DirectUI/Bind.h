#pragma once

namespace DirectUI
{
	class UILIB_API Bind : public Element
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Initialize(Element* pParent, DWORD* pdwDeferCookie);

		static const PropertyInfo* WINAPI ConnectProp();
		static const PropertyInfo* WINAPI PropertyProp();
		const WCHAR* GetConnect(Value** ppv);
		HRESULT SetConnect(const WCHAR* v);
		const WCHAR* GetProperty(Value** ppv);
		HRESULT SetProperty(const WCHAR* v);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();
	};
}
