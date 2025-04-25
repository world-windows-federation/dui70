#pragma once

namespace DirectUI
{
	class UILIB_API CCHScrollBar : public CCBaseScrollBar
	{
	public:
		CCHScrollBar();
		CCHScrollBar(const CCHScrollBar& other) = default;
		CCHScrollBar(CCHScrollBar&& other) noexcept = default;

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
