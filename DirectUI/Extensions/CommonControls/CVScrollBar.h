#pragma once

namespace DirectUI
{
	class CCVScrollBar : public CCBaseScrollBar
	{
	public:
		CCVScrollBar();
		CCVScrollBar(const CCVScrollBar& other) = default;
		CCVScrollBar(CCVScrollBar&& other) noexcept = default;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();
	};
}
