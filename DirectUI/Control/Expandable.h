#pragma once

namespace DirectUI
{
	class UILIB_API Expandable : public Element
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		static const PropertyInfo* WINAPI ExpandedProp();
		bool GetExpanded();
		HRESULT SetExpanded(bool v);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();
	};
}
