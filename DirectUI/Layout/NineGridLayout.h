#pragma once

namespace DirectUI
{
	enum NineGridLayoutPos
	{
		NGLP_TopLeft     = 0,
		NGLP_Top         = 1,
		NGLP_TopRight    = 2,
		NGLP_Left        = 3,
		NGLP_Client      = 4,
		NGLP_Right       = 5,
		NGLP_BottomLeft  = 6,
		NGLP_Bottom      = 7,
		NGLP_BottomRight = 8,
	};

	class UILIB_API NineGridLayout : public Layout
	{
	public:
		static HRESULT WINAPI Create(int dNumParams, int* pParams, Value** ppValue);
		static HRESULT WINAPI Create(Layout** ppLayout);

		void DoLayout(Element* pec, int cx, int cy) override;
		SIZE UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) override;
		void OnAdd(Element* pec, Element** ppeAdd, UINT cCount) override;
		void OnRemove(Element* pec, Element** ppeRemove, UINT cCount) override;
		void OnLayoutPosChanged(Element* pec, Element* peChanged, int dOldLP, int dNewLP) override;
		Element* GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) override;

		NineGridLayout();
		NineGridLayout(const NineGridLayout& other) = delete;

		void Initialize();

		~NineGridLayout() override;

		// No clue what Microsoft was doing here, possibly a leftover?
		enum
		{
		};

		enum ESlot
		{
			Margin1 = 0,
			Left = 1,
			Top = 1,
			Margin2 = 2,
			Center = 3,
			Margin3 = 4,
			Right = 5,
			Bottom = 5,
			Margin4 = 6,
			NumSlots = 7
		};

		enum EDim
		{
			X = 0,
			Y = 1,
			NumDims = 2
		};

		enum EConst
		{
			NumCells = 9,
			CellsPerRow = 3
		};

	private:
		Element* _peTiles[9];
		SIZE _sizeDesired;
		int _length[2][7];
		bool _fClientFills;

		void _UpdateTileList(int iTile, Element* pe);
	};
}
