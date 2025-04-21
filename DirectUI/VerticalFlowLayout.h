#pragma once

namespace DirectUI
{
	class UILIB_API VerticalFlowLayout : public Layout
	{
	public:
		static HRESULT WINAPI Create(int dNumParams, int* pParams, Value** ppValue);
		static HRESULT WINAPI Create(bool fWrap, UINT uXAlign, UINT uXLineAlign, UINT uYLineAlign, Layout** ppLayout);

		void DoLayout(Element* pec, int cx, int cy) override;
		SIZE UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) override;
		Element* GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) override;

		int GetLine(Element* pec, Element* pe);

		VerticalFlowLayout();
		VerticalFlowLayout(const VerticalFlowLayout& other) = delete;

		void Initialize(bool fWrap, UINT uXAlign, UINT uXLineAlign, UINT uYLineAlign);

		~VerticalFlowLayout() override;

	protected:
		SIZE BuildCacheInfo(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf, bool fRealSize);

		bool _fWrap;
		UINT _uXLineAlign;
		UINT _uYLineAlign;
		UINT _uXAlign;
		SIZE _sizeDesired;
		SIZE _sizeLastConstraint;
		UINT _cLines;

		struct VLINE
		{
			UINT cy;
			UINT cx;
			UINT x;
			UINT cElements;
			UINT* aryElement;
			UINT iStart;
		};

		VLINE* _arLines;

		SIZE SizeZero();
	};
}
