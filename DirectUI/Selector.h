#pragma once

namespace DirectUI
{
	class UILIB_API Selector : public Element
	{
	public:
		HRESULT Create(Element*, unsigned long*, Element**);

		void OnEvent(Event* pEvent) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnInput(InputEvent* pInput) override;
		void OnKeyFocusMoved(Element* peFrom, Element* peTo) override;

		Element* GetAdjacent(Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) override;

		static UID WINAPI SelectionChange();
		static const PropertyInfo* WINAPI SelectionProp();

		Element* GetSelection();
		virtual HRESULT SetSelection(Element* peSelection);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT Register();

		Selector();
		Selector(const Selector& other) = default;

		static HRESULT WINAPI Initialize(Element* pParent, DWORD* pdwDeferCookie);
	};
}
