#pragma once

namespace DirectUI
{
	struct CellInfo
	{
		UINT uXAlign;
		UINT uYAlign;
		UINT iWidth;
	};

	class UILIB_API TableLayout : public Layout
	{
	public:
		static HRESULT WINAPI Create(int dNumParams, int* pParams, Value** ppValue);

		void DoLayout(Element* pec, int cx, int cy) override;
		SIZE UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) override;
		Element* GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) override;

		static HRESULT WINAPI InternalCreate(int flags, int cxMinWidth, int dNumParams, int* pParams, Layout** ppLayout);
		void Initialize(int flags, int cxMinWidth, int dNumParams, int* pParams);

		~TableLayout() override;

		CellInfo* GetCellInfo(int nColumn);

	protected:
		int _cxMinWidth;
		int _cxFixedWidth;
		CellInfo* _pCellInfo;
		int _cCellInfo;
		int _nFlags;
	};
}
