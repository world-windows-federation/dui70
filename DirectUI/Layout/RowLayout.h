#pragma once

namespace DirectUI
{
	class RowLayout;

	class RowLayoutSharedInfo
	{
	public:
		static HRESULT Create(int idShare, RowLayoutSharedInfo** ppsi);

		HRESULT Initialize(int idShare);

		HRESULT AttachClient(RowLayout* prl);
		void DetachClient(RowLayout* prl);

		void AddRef();
		void Release();

		int SetNumCols(UINT cCols);
		UINT NumColumns();

		void UpdateDesiredSizes(int cxConstraint, Surface* psrf);
		int GetColumnRightEdge(UINT);
		int GetColumnRightMargin(UINT);
		int GetRowWidth();

		~RowLayoutSharedInfo();

		struct ColumnInfo
		{
			int _xCol;
			int _cxMargin;
		};

		int _id;
		BOOL _fRecalc;
		int _cxConstraint;
		UINT _cCols;
		BOOL _fEnteredUpdate;
		ColumnInfo* _arci;
		DynamicArray<RowLayout*>* _arprlClients;
		int _cRef;
	};

	class UILIB_API RowLayout : public Layout
	{
	public:
		static HRESULT WINAPI Create(int dNumParams, int* pParams, Value** ppValue);
		static HRESULT WINAPI Create(UINT uXAlign, UINT uYAlign, Layout** ppLayout);
		static HRESULT WINAPI Create(int idShare, UINT uXAlign, UINT uYAlign, Layout** ppLayout);

		void DoLayout(Element* pec, int cx, int cy) override;
		SIZE UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) override;
		Element* GetAdjacent(Element* pec, Element*, int iNavDir, const NavReference* pnr, DWORD dwFlags) override;

		RowLayout();
		RowLayout(const RowLayout& other) = delete;

		HRESULT Initialize(int idShare, UINT uXAlign, UINT uYAlign);

		~RowLayout() override;

	protected:
		RowLayoutSharedInfo* _psi;
		UINT _uXAlign;
		UINT _uYAlign;
		int _cyMax;
		int _cyConstraint;
		UINT _rls_cElements;
		DynamicArray<Element*>* _rls_pel;
		Value* _rls_pvValue;
		Element* _rls_peCur;
	};
}
