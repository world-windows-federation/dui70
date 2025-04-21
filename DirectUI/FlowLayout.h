#pragma once

namespace DirectUI
{
	class UILIB_API FlowLayout : public Layout
	{
	public:
		static HRESULT WINAPI Create(int dNumParams, int* pParams, Value** ppValue);
		static HRESULT WINAPI Create(bool fWrap, UINT uYAlign, UINT uXLineAlign, UINT uYLineAlign, Layout** ppLayout);

		void DoLayout(Element* pec, int cx, int cy) override;
		SIZE UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) override;
		Element* GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) override;

		int GetLine(Element* pec, Element* pe);

		FlowLayout();
		FlowLayout(const FlowLayout& other) = delete;

		void Initialize(bool fWrap, UINT uYAlign, UINT uXLineAlign, UINT uYLineAlign);

		~FlowLayout() override;

	protected:
		SIZE BuildCacheInfo(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf, bool fRealSize);

		bool _fWrap;
		UINT _uXLineAlign;
		UINT _uYLineAlign;
		UINT _uYAlign;
		SIZE _sizeDesired;
		SIZE _sizeLastConstraint;
		UINT _cLines;

		struct LINE
		{
			UINT cx;
			UINT cy;
			UINT y;
			UINT cElements;
			UINT* arxElement;
			UINT iStart;
		};

		LINE* _arLines;

		SIZE SizeZero();
	};
}
