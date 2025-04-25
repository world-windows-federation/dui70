#pragma once

namespace DirectUI
{
	class UILIB_API CCListBox : public CCBase
	{
	public:
		CCListBox();
		CCListBox(const CCListBox& other) = default;
		CCListBox(CCListBox&& other) noexcept = default;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();

		int AddString(const WCHAR* pszString);
		int DeleteString(int iDelete);

		int GetCount();
		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;
	};
}
