#pragma once

namespace DirectUI
{
	class UILIB_API CCTreeView : public CCBase
	{
	public:
		CCTreeView(DWORD dwStyle = WM_NULL);
		CCTreeView(const CCTreeView& other) = default;
		CCTreeView(CCTreeView&& other) noexcept = default;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		bool OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) override;
		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;

		DWORD GetStyle();
		DWORD SetStyle(DWORD dwStyle);

		UINT GetItemState(const HTREEITEM hItem);
		void SetItemState(HTREEITEM hItem, UINT uState);

		HTREEITEM InsertItem(const TVINSERTSTRUCT* pInsertStruct);
		HTREEITEM InsertItem(WCHAR* pszItem, UINT uState, const HTREEITEM htiParent, const HTREEITEM htiInsertAfter);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo*);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();

	protected:
		virtual HRESULT _OnGetInfoTip(const NMTVGETINFOTIP*);
		virtual HRESULT _OnItemChanged(const NMTVITEMCHANGE*);
	};
}
