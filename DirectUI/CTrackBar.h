#pragma once

namespace DirectUI
{
	class UILIB_API CCTrackBar : public CCBase
	{
	public:
		CCTrackBar();
		CCTrackBar(const CCTrackBar& other) = default;
		CCTrackBar(CCTrackBar&& other) noexcept = default;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);


		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();

		static const PropertyInfo* WINAPI RangeMinProp();
		static const PropertyInfo* WINAPI RangeMaxProp();
		static const PropertyInfo* WINAPI LineSizeProp();
		static const PropertyInfo* WINAPI ThumbPositionProp();

		int GetRangeMin();
		int GetRangeMax();
		int GetLineSize();
		int GetThumbPosition();

		HRESULT SetRangeMin(int v);
		HRESULT SetRangeMax(int v);
		HRESULT SetLineSize(int v);
		HRESULT SetThumbPosition(int v);

		bool OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		bool OnMessage(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) override;

	protected:
		void PostCreate(HWND hwnd) override;
	};
}
