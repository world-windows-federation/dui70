#pragma once

namespace DirectUI
{
	class UILIB_API HWNDHost : public ElementWithHWND
	{
	public:
		HWNDHost(const HWNDHost &);
		HWNDHost();
		HWNDHost& operator=(const HWNDHost &);
		
		virtual ~HWNDHost();

		long Initialize(unsigned int, unsigned int, Element*, unsigned long*);
		void Detach();
		unsigned short GetBackgroundOwnerID();
		HWND GetHWNDParent();
		bool GetOptimizeMove();
		bool GetTransparent();
		long GetClientAccessibleImpl(IAccessible**);
		long SetBackgroundOwnerID(const WCHAR*);
		long SetOptimizeMove(bool);
		long SetTransparent(bool);

		static long WINAPI Create(unsigned int, unsigned int, Element*, unsigned long*, Element**pOut);
		static long WINAPI Create(Element*, unsigned long*, Element**pOut);
		static const PropertyInfo* WINAPI BackgroundOwnerIDProp();
		static IClassInfo* WINAPI GetClassInfoPtr();
		static const PropertyInfo* WINAPI OptimizeMoveProp();
		static long WINAPI Register();
		static void WINAPI SetClassInfoPtr(IClassInfo*);
		static const PropertyInfo* WINAPI ThemeChangedProp();
		static const PropertyInfo* WINAPI TransparentProp();

		virtual IClassInfo* GetClassInfoW() override;
		virtual long GetAccessibleImpl(IAccessible** ppAccessible) override;
		virtual bool GetKeyFocused() override;
		virtual unsigned int MessageCallback(GMSG* pgMsg) override;
		virtual void OnDestroy() override;
		virtual void OnEvent(Event* pEvent) override;
		virtual void OnInput(InputEvent* pInput) override;
		virtual void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		virtual void OnHosted(Element* peNewHost) override;
		virtual void OnUnHosted(Element* peOldHost) override;

		virtual void Paint(HDC, LPCRECT, LPCRECT, LPRECT, LPRECT) override;
		virtual void SetKeyFocus() override;

		virtual bool OnNotify(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) = 0;
		virtual bool OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) = 0;
		virtual bool OnSysChar(WCHAR chKeyCode) = 0;
		virtual bool OnSinkThemeChanged(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet);
		virtual bool OnCtrlThemeChanged(UINT, WPARAM wParam, LPARAM lParam, LRESULT* plRet);
		virtual void OnWindowStyleChanged(WPARAM wParam, const STYLESTRUCT* pstylestruct);
		virtual int OnAdjustWindowSize(int x, int y, UINT uFlags);
		virtual void SetWindowDirection(HWND hwnd);
		virtual HWND CreateHWND(HWND hwndParent) = 0;
		virtual bool EraseBkgnd(HDC hdcCtl, int* lpRet);

	protected:
		static void WINAPI AttachCtrlSubclassProc(HWND);
		static LRESULT WINAPI CtrlSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		void PrintRTLControl(HDC, HDC, const RECT&);
		long SetThemeChanged(int);
		void SyncBackground();
		void SyncDirection();
		void SyncFont();
		void SyncForeground();
		void SyncParent();
		void SyncRect(unsigned int, bool);
		void SyncStyle();
		void SyncText();
		void SyncVisible();
		int VerifyParentage();
		HWND CreateAccNameLabel(HWND);
		Element* GetBackgroundOwner();
		HFONT GetFont();
		bool GetStaticColor(HDC, HBRUSH*);
		int GetThemeChanged();
		bool IsMoveDeferred();

	private:
		static unsigned int const (* __ptr32 g_rgMouseMap)[3];
		static IClassInfo* s_pClassInfo;
		static BOOL __stdcall _CtrlWndProc(void *, HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* plResult);
		static BOOL WINAPI _SinkWndProc(void *, HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* plResult);

		void ApplySinkRegion(RECT const *, bool);
		long GetAccessibleImpl(IAccessible**, bool);
		void GetSinkRect(RECT const *, LPRECT);
		bool HaveWin32Focus();
		void SyncColorsAndFonts();
		void UnvirtualizePosition();
		void _DeleteCtrlWnd();

		bool _fHwndCreate;
		bool _fSpecOptimizeMove;
		bool _fMoveDeferred;
		HWND _hwndCtrl;
		HWND _hwndSink;
		LRESULT (CALLBACK *_pfnCtrlOrgProc)(HWND, UINT, WPARAM, LPARAM);
		HWND _hwndAccName;
		BOOL _fCtrlAttached;
		RECT _rcBounds;
		HFONT _hFont;
		COLORREF _crBkColor;
		HBRUSH _hBkBrush;
		COLORREF _crForegroundColor;
		bool _fForegroundColorSet;
		UINT _nCreate;
		int _cAnimate;
		bool _fSentMouseWheel;
		bool _fHandledMouseWheel;
		DirectUI::DuiAccessible *_pClientAccessible;
	};
}