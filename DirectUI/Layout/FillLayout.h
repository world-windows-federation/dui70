#pragma once

namespace DirectUI
{
	enum FillLayoutPos
	{
		FLP_Left   = 0,
		FLP_Top    = 1,
		FLP_Right  = 2,
		FLP_Bottom = 3,
	};
	
	class UILIB_API FillLayout : public Layout
	{
	public:
		static HRESULT WINAPI Create(int dNumParams, int* pParams, Value** ppValue);
		static HRESULT WINAPI Create(Layout** ppLayout);

		void DoLayout(Element* pec, int cx, int cy) override;
		SIZE UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) override;
		Element* GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) override;

		FillLayout();
		FillLayout(const FillLayout& other) = delete;

		void Initialize();

		~FillLayout() override;

	private:
		RECT rcMargin;
	};
}
