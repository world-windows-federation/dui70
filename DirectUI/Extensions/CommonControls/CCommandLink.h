#pragma once

namespace DirectUI
{
	class UILIB_API CCCommandLink : public CCPushButton
	{
	public:
		CCCommandLink(DWORD dwStyle = WM_GETTEXTLENGTH);
		CCCommandLink(const CCCommandLink& other) = default;
		CCCommandLink(CCCommandLink&& other) noexcept = default;


		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();

		static const PropertyInfo* WINAPI NoteProp();
		const WCHAR* GetNote(Value** ppv);
		HRESULT SetNote(const WCHAR* v);

		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnSelectedPropertyChanged() override;
		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;

	protected:
		void PostCreate(HWND hwnd) override;

		void SyncNoteAndGlyph(HWND hwnd);
	};
}
