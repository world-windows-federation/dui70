#pragma once

namespace DirectUI
{
	class UILIB_API CCBaseScrollBar
		: public CCBase
		, public BaseScrollBar
	{
	public:
		CCBaseScrollBar(DWORD dwStyle = WM_NULL);
		CCBaseScrollBar(const CCBaseScrollBar& other) = default;
		CCBaseScrollBar(CCBaseScrollBar&& other) noexcept = default;

		// ReSharper disable once CppHidingFunction
		HRESULT Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie);

		HWND CreateHWND(HWND hwndParent) override;

		void SyncScrollBar();

		bool OnMessage(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) override;
		bool OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;

		static const PropertyInfo* WINAPI PositionProp();
		static const PropertyInfo* WINAPI MinimumProp();
		static const PropertyInfo* WINAPI MaximumProp();
		static const PropertyInfo* WINAPI PageProp();
		static const PropertyInfo* WINAPI LineProp();
		static const PropertyInfo* WINAPI TrackingProp();

		Element* GetElement() override;

		int GetPosition() override;
		int GetMaximum() override;
		int GetMinimum() override;
		int GetPage() override;
		int GetLine() override;

		HRESULT SetPosition(int v) override;
		HRESULT SetMaximum(int v) override;
		HRESULT SetMinimum(int v) override;
		HRESULT SetPage(int v) override;
		HRESULT SetLine(int v) override;

		bool GetProportional() override;

		bool GetTracking();
		HRESULT SetTracking(bool v);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();
	};
}
