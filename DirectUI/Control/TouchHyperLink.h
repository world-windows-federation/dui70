#pragma once

namespace DirectUI
{
	class TouchHyperLink : public TouchButton
	{
	public:
		UILIB_API static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		UILIB_API static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		UILIB_API void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		UILIB_API void GetImmersiveFocusRectOffsets(RECT* lprc) override;

		UILIB_API static const PropertyInfo* WINAPI VisitedProp();
		UILIB_API bool GetVisited();
		UILIB_API HRESULT SetVisited(bool v);

		UILIB_API static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		UILIB_API IClassInfo* GetClassInfoW() override;
		UILIB_API static HRESULT WINAPI Register();

		UILIB_API TouchHyperLink();
		UILIB_API ~TouchHyperLink() override;

	private:
		void _UpdateAccState(bool fAccessible, bool fVisited);
	};
}
