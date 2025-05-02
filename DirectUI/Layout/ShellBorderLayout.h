#pragma once

namespace DirectUI
{
	class UILIB_API ShellBorderLayout : public BorderLayout
	{
	public:
		static HRESULT WINAPI Create(int dNumParams, int* pParams, Value** ppValue);
		static HRESULT WINAPI Create(Layout** ppLayout);

		void OnAdd(Element* pec, Element** ppeAdd, UINT cCount) override;
		void OnRemove(Element* pec, Element** ppeRemove, UINT cCount) override;
		void OnLayoutPosChanged(Element* pec, Element* peChanged, int dOldLP, int dNewLP) override;
		Element* GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) override;

		ShellBorderLayout();
		ShellBorderLayout(const ShellBorderLayout& other) = delete;

		~ShellBorderLayout() override;

	private:
		void _Reset();
		HRESULT _CalcTabOrder(Element* pec);

		DynamicArray<Element*>* _pdaTabOrder;
	};
}
