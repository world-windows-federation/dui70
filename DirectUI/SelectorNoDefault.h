#pragma once

namespace DirectUI
{
	class UILIB_API SelectorNoDefault : public Selector
	{
	public:
		static HRESULT WINAPI Create(Element*, unsigned long*, Element**);

		void OnEvent(Event* pEvent) override;
		void OnKeyFocusMoved(Element* peFrom, Element* peTo) override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT Register();

		HRESULT SetSelection(Element* peSelection) override;

		SelectorNoDefault();
		SelectorNoDefault(const SelectorNoDefault& other) = default;
		SelectorNoDefault(SelectorNoDefault&& other) noexcept = default;

		static HRESULT WINAPI Initialize(Element* pParent, DWORD* pdwDeferCookie);
	};
}
