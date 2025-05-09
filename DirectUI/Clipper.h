#pragma once

namespace DirectUI
{
	class UILIB_API Clipper : public Expandable
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		void _SelfLayoutDoLayout(int cx, int cy) override;
		SIZE _SelfLayoutUpdateDesiredSize(int cxConstraint, int cyConstraint, Surface* psrf) override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();
		HRESULT Initialize(Element* pParent, DWORD* pdwDeferCookie);
	};
}
