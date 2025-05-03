#pragma once

typedef HIMAGELIST (WINAPI *PFNIMAGELISTCREATE)(int cx, int cy, UINT flags, int cInitial, int cGrow);
typedef int (WINAPI *PFNIMAGELISTADDMASKED)(HIMAGELIST himl, HBITMAP hbmImage, COLORREF crMask);
typedef BOOL (WINAPI *PFNIMAGELISTDESTROY)(HIMAGELIST himl);
typedef BOOL (WINAPI *PFNIMAGELISTDRAWEX)(HIMAGELIST himl, int i, HDC hdcDst, int x, int y, int dx, int dy, COLORREF rgbBk, COLORREF rgbFg, UINT fStyle);

namespace DirectUI
{
	class UILIB_API AnimationStrip : public Element
	{
		PFNIMAGELISTCREATE m_pfnImageListCreate;
		PFNIMAGELISTADDMASKED m_pfnImageListAddMasked;
		PFNIMAGELISTDESTROY m_pfnImageListDestroy;
		PFNIMAGELISTDRAWEX m_pfnImageListDrawEx;
		HMODULE m_hmodComCtl32;

		HRESULT LoadCommonControlExports();
		void UnloadCommonControlExports();
		HRESULT Start();
		void Stop();

	public:
		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();
		static HRESULT Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		HRESULT Initialize(UINT); // Not sure
		// ReSharper disable once CppHidingFunction
		HRESULT Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie);

		AnimationStrip();
		AnimationStrip(const AnimationStrip& other) = default;
		~AnimationStrip() override;

		static const PropertyInfo* WINAPI FrameWidthProp();
		static const PropertyInfo* WINAPI FrameDurationProp();
		static const PropertyInfo* WINAPI FrameIndexProp();
		static const PropertyInfo* WINAPI PlayProp();

		int GetFrameWidth();
		int GetFrameDuration();
		int GetFrameIndex();
		bool GetPlay();

		HRESULT SetFrameWidth(int v);
		HRESULT SetFrameDuration(int v);
		HRESULT SetFrameIndex(int v);
		HRESULT SetPlay(bool v);

	protected:
		void Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) override;
		void OnDestroy() override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;

		HRESULT LoadImagesIntoAnimationStrip();
		void AdvanceFrame();
		void OnAction(GMA_ACTIONINFO* pActionInfo);

		static void WINAPI RawActionProc(GMA_ACTIONINFO* pActionInfo);

		int m_nFrameCount;
		HACTION m_hAction;
		HIMAGELIST m_himlAnimationStrip;
	};
}
