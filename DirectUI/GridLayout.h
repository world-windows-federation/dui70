#pragma once

namespace DirectUI
{
	class UILIB_API GridLayout : public Layout
	{
	public:
		static HRESULT WINAPI Create(int dNumParams, int* pParams, Value** ppValue);
		static HRESULT WINAPI Create(int iRows, int iCols, Layout** ppLayout);

		void DoLayout(Element* pec, int cx, int cy) override;
		SIZE UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) override;
		Element* GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) override;

		GridLayout();
		GridLayout(const GridLayout& other) = delete;

		void Initialize(int iRows, int iCols);

		~GridLayout() override;

	protected:
		UINT _uRows;
		UINT _uCols;
		UINT _fBits;
		int* _arColMargins;
		int* _arRowMargins;

		UINT GetCurrentRows(Element* pec);
		UINT GetCurrentRows(int c);
		UINT GetCurrentCols(Element* pec);
		UINT GetCurrentCols(int c);
	};
}
