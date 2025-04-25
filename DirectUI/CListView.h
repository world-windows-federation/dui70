#pragma once

namespace DirectUI
{
	class UILIB_API CCListView : public CCBase
	{
	public:
		CCListView();
		CCListView(const CCListView& other) = default;
		CCListView(CCListView&& other) noexcept = default;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;

		// ReSharper disable once CppHidingFunction
		HRESULT Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();
	};
}
