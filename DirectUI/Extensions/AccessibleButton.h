#pragma once

namespace DirectUI
{
	class UILIB_API AccessibleButton : public Button
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		HRESULT Initialize(Element* pParent, DWORD* pdwDeferCookie);

		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;

		void Recalc();

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		AccessibleButton();
		AccessibleButton(const AccessibleButton& other) = default;
		AccessibleButton(AccessibleButton&& other) noexcept = default;

		struct ACCESSIBLEROLE
		{
			int accRole;
			int stateUnselected;
			int unselectedAction;
			int stateSelected;
			int selectedAction;
		};

	private:
		static const ACCESSIBLEROLE c_rgar[];

		const ACCESSIBLEROLE* WINAPI FindAccessibleRole(int role);
		void UpdateState(ACCESSIBLEROLE*);

		UINT _uLastAction;
	};
}
