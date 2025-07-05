#include <Windows.h>

#include "DUser.h"

#define STUB_ZERO { return {}; }
#define STUB_VOID {}

DUSER_API HGADGET WINAPI DUserCastHandle(DUser::Gadget* pg) STUB_ZERO;
DUSER_API HRESULT WINAPI DUserDeleteGadget(DUser::Gadget* pg) STUB_ZERO;
// DUSER_API Gdiplus::Brush* WINAPI GetStdColorBrushF(UINT c) STUB_ZERO;
// DUSER_API Gdiplus::Color WINAPI GetStdColorF(UINT c) STUB_ZERO;
// DUSER_API Gdiplus::Pen* WINAPI GetStdColorPenF(UINT c) STUB_ZERO;
DUSER_API BOOL WINAPI UtilDrawOutlineRect(HDC hdc, const RECT* prcPxl, HBRUSH hbrDraw, int nThickness) STUB_ZERO;
DUSER_API BOOL WINAPI AddGadgetMessageHandler(HGADGET hgadMsg, MSGID nMsg, HGADGET hgadHandler) STUB_ZERO;
DUSER_API BOOL WINAPI AddLayeredRef(HGADGET hgad) STUB_ZERO;
DUSER_API BOOL WINAPI AdjustClipInsideRef(HGADGET hgad, BOOL fAdd) STUB_ZERO;
DUSER_API BOOL WINAPI AttachWndProcA(HWND hwnd, ATTACHWNDPROC pfn, void* pvThis) STUB_ZERO;
DUSER_API BOOL WINAPI AttachWndProcW(HWND hwnd, ATTACHWNDPROC pfn, void* pvThis) STUB_ZERO;
// DUSER_API void WINAPI AutoTrace(int, ...) STUB_ZERO;
DUSER_API BOOL WINAPI BeginHideInputPaneAnimation() STUB_ZERO;
DUSER_API BOOL WINAPI BeginShowInputPaneAnimation() STUB_ZERO;
DUSER_API BOOL WINAPI BuildAnimation(UINT nAniID, int nVersion, GANI_DESC* pDesc, REFIID riid, void** ppvUnk) STUB_ZERO;
DUSER_API BOOL WINAPI BuildDropTarget(HGADGET hgadRoot, HWND hwnd) STUB_ZERO;
DUSER_API BOOL WINAPI BuildInterpolation(UINT nIPolID, int nVersion, REFIID riid, void** ppvUnk) STUB_ZERO;
DUSER_API BOOL WINAPI CacheDWriteRenderTarget(IUnknown* punkRenderTarget) STUB_ZERO;
DUSER_API BOOL WINAPI ChangeCurrentAnimationScenario(bool fStart, REFGUID guid) STUB_ZERO;
DUSER_API BOOL WINAPI ClearPushedOpacitiesFromGadgetTree(HGADGET hgadRoot) STUB_ZERO;
DUSER_API BOOL WINAPI ClearTopmostVisual(HGADGET hgad) STUB_ZERO;
DUSER_API HACTION WINAPI CreateAction(const GMA_ACTION* pma) STUB_ZERO;
DUSER_API HGADGET WINAPI CreateGadget(HWND hParent, UINT nFlags, GADGETPROC pfnProc, void* pvGadgetData) STUB_ZERO;
DUSER_API BOOL WINAPI CustomGadgetHitTestQuery(UINT version, HGADGET hgad, GMSG_QUERYHITTEST* pQht) STUB_ZERO;
// DUSER_API DUser::Gadget* WINAPI DUserBuildGadget(HCLASS hcl, DUser::Gadget::ConstructInfo* pciData) STUB_ZERO;
DUSER_API DUser::Gadget* WINAPI DUserCastClass(DUser::Gadget* pg, HCLASS hclTest) STUB_ZERO;
DUSER_API DUser::Gadget* WINAPI DUserCastDirect(HGADGET hgad) STUB_ZERO;
DUSER_API HCLASS WINAPI DUserFindClass(const WCHAR* pszName, DWORD nVersion) STUB_ZERO;
DUSER_API BOOL WINAPI DUserFlushDeferredMessages() STUB_ZERO;
DUSER_API BOOL WINAPI DUserFlushMessages() STUB_ZERO;
DUSER_API PRID WINAPI DUserGetAlphaPRID() STUB_ZERO;
DUSER_API void* WINAPI DUserGetGutsData(DUser::Gadget* pg, HCLASS hclData) STUB_ZERO;
DUSER_API PRID WINAPI DUserGetRectPRID() STUB_ZERO;
DUSER_API PRID WINAPI DUserGetRotatePRID() STUB_ZERO;
DUSER_API PRID WINAPI DUserGetScalePRID() STUB_ZERO;
DUSER_API BOOL WINAPI DUserInstanceOf(DUser::Gadget* pg, HCLASS hclTest) STUB_ZERO;
DUSER_API HRESULT WINAPI DUserPostEvent(EventMsg* pmsg, UINT nFlags) STUB_ZERO;
DUSER_API HRESULT WINAPI DUserPostMethod(MethodMsg* pmsg) STUB_ZERO;
// DUSER_API HCLASS WINAPI DUserRegisterGuts(DUser::MessageClassGuts* pmcInfo) STUB_ZERO;
// DUSER_API HCLASS WINAPI DUserRegisterStub(DUser::MessageClassStub* pmcInfo) STUB_ZERO;
// DUSER_API HCLASS WINAPI DUserRegisterSuper(DUser::MessageClassSuper* pmcInfo) STUB_ZERO;
DUSER_API HRESULT WINAPI DUserSendEvent(EventMsg* pmsg, UINT nFlags) STUB_ZERO;
DUSER_API HRESULT WINAPI DUserSendMethod(MethodMsg* pmsg) STUB_ZERO;
DUSER_API void WINAPI DUserStopAnimation(DUser::Gadget* pgvSubject, PRID pridAni) STUB_VOID;
DUSER_API BOOL WINAPI DUserStopPVLAnimation(UINT version, HGADGET hgad, UINT nDCProperty, bool fFinal) STUB_ZERO;
DUSER_API BOOL WINAPI DeleteHandle(HANDLE h) STUB_ZERO;
DUSER_API BOOL WINAPI DestroyPendingDCVisuals() STUB_ZERO;
DUSER_API BOOL WINAPI DetachGadgetVisuals(UINT version, HGADGET hgad, DWORD* pdwDetachCookie, IUnknown** ppunkIDCompositionVisual, IUnknown** ppUnkIDCompositionContentVisual, IUnknown** ppUnkIDCompositionBufferVisual, IUnknown** ppIDCompositionDevice) STUB_ZERO;
DUSER_API BOOL WINAPI DetachWndProc(HWND hwnd, ATTACHWNDPROC pfn, void* pvThis) STUB_ZERO;
DUSER_API void WINAPI DisableContainerHwnd(HWND hWnd) STUB_VOID;
// DUSER_API BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) STUB_ZERO;
DUSER_API BOOL WINAPI DrawGadgetTree(HGADGET hgadDraw, HDC hdcDraw, const RECT* prcDraw, UINT nFlags) STUB_ZERO;
DUSER_API BOOL WINAPI EndInputPaneAnimation() STUB_ZERO;
DUSER_API BOOL WINAPI EnsureAnimationsEnabled() STUB_ZERO;
DUSER_API BOOL WINAPI EnsureGadgetTransInitialized() STUB_ZERO;
DUSER_API BOOL WINAPI EnumGadgets(HGADGET hgadEnum, GADGETENUMPROC pfnProc, void* pvData, UINT nFlags) STUB_ZERO;
DUSER_API HGADGET WINAPI FindGadgetFromPoint(HGADGET hgad, POINT ptContainerPxl, UINT nStyle, POINT* pptClientPxl) STUB_ZERO;
DUSER_API BOOL WINAPI FindGadgetMessages(const GUID** rgpguid, MSGID* rgnMsg, int cMsgs) STUB_ZERO;
DUSER_API BOOL WINAPI FindGadgetTargetingInfo(HGADGET hgad, TOUCH_HIT_TESTING_INPUT* pHitTestingInput, POINT ptScreenOffset, UINT nStyle, TOUCH_HIT_TESTING_PROXIMITY_EVALUATION* pProximityEval) STUB_ZERO;
DUSER_API UINT WINAPI FindStdColor(const WCHAR* pszName) STUB_ZERO;
DUSER_API BOOL WINAPI FireGadgetMessages(FGM_INFO* rgFGM, int cMsgs, UINT idQueue) STUB_ZERO;
DUSER_API BOOL WINAPI ForwardGadgetMessage(HGADGET hgadRoot, UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* pr) STUB_ZERO;
DUSER_API BOOL WINAPI FreeGdiDxInteropStagingBuffer() STUB_ZERO;
DUSER_API BOOL WINAPI GadgetTransCompositionChanged(HGADGET) STUB_ZERO;
DUSER_API BOOL WINAPI GadgetTransSettingChanged() STUB_ZERO;
DUSER_API BOOL WINAPI GetActionTimeslice(DWORD* pdwTimeslice) STUB_ZERO;
DUSER_API BOOL WINAPI GetCachedDWriteRenderTarget(REFIID riid, void** ppv) STUB_ZERO;
DUSER_API HMODULE WINAPI GetDUserModule() STUB_ZERO;
DUSER_API void* WINAPI GetDebug() STUB_ZERO;
DUSER_API BOOL WINAPI GetFinalAnimatingPosition(HGADGET hgad, POINT* pptPosition, bool fUseCopyVisual) STUB_ZERO;
DUSER_API HGADGET WINAPI GetGadget(HGADGET hgad, UINT nCmd) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetAnimation(HGADGET, UINT, REFIID, void**) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetBitmap(HGADGET hgad, HBITMAP* phbmp, RECT* prcPxl) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetBufferInfo(HGADGET hgad, BUFFER_INFO* pbi) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetCenterPoint(HGADGET hgad, float* pflX, float* pflY) STUB_ZERO;
DUSER_API UINT WINAPI GetGadgetFlags(HGADGET hgad) STUB_ZERO;
DUSER_API HGADGET WINAPI GetGadgetFocus() STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetLayerInfo(HGADGET hgad, LAYER_INFO* pli) STUB_ZERO;
DUSER_API UINT WINAPI GetGadgetMessageFilter(HGADGET hgad, void* pvCookie) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetProperty(HGADGET hgad, PRID id, void** ppvValue) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetRect(HGADGET hgad, RECT* prcPxl, DWORD nFlags) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetRgn(HGADGET hgad, UINT nRgnType, HRGN hrgn, UINT nFlags) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetRootInfo(HGADGET hgadRoot, ROOT_INFO* pri) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetRotation(HGADGET hgad, float* pflRotationRad) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetScale(HGADGET hgad, float* pflX, float* pflY) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetSize(HGADGET hgad, SIZE* psizeLogicalPxl) STUB_ZERO;
DUSER_API UINT WINAPI GetGadgetStyle(HGADGET hgad) STUB_ZERO;
DUSER_API DWORD WINAPI GetGadgetTicket(HGADGET hgad) STUB_ZERO;
DUSER_API BOOL WINAPI GetGadgetVisual(UINT version, HGADGET hgad, void** ppVisual, void** ppVisualContent, void** ppDevice) STUB_ZERO;
DUSER_API BOOL WINAPI GetMessageExA(MSG* lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax) STUB_ZERO;
DUSER_API BOOL WINAPI GetMessageExW(MSG* lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax) STUB_ZERO;
DUSER_API HBRUSH WINAPI GetStdColorBrushI(UINT c) STUB_ZERO;
DUSER_API COLORREF WINAPI GetStdColorI(UINT c) STUB_ZERO;
DUSER_API const WCHAR* WINAPI GetStdColorName(UINT c) STUB_ZERO;
DUSER_API HPEN WINAPI GetStdColorPenI(UINT c) STUB_ZERO;
DUSER_API HPALETTE WINAPI GetStdPalette() STUB_ZERO;
DUSER_API BOOL WINAPI InitGadgetComponent(UINT nOptionalComponent) STUB_ZERO;
DUSER_API HDCONTEXT WINAPI InitGadgets(INITGADGET* pInit) STUB_ZERO;
DUSER_API BOOL WINAPI InvalidateGadget(HGADGET hgad) STUB_ZERO;
DUSER_API BOOL WINAPI InvalidateLayeredDescendants(HGADGET hgad) STUB_ZERO;
DUSER_API BOOL WINAPI IsGadgetParentChainStyle(HGADGET hgad, UINT nStyle, BOOL* pfChain, UINT nFlags) STUB_ZERO;
DUSER_API BOOL WINAPI IsInsideContext(HANDLE h) STUB_ZERO;
DUSER_API BOOL WINAPI IsStartDelete(HANDLE hobj, BOOL* pfStarted) STUB_ZERO;
DUSER_API HGADGET WINAPI LookupGadgetTicket(DWORD dwTicket) STUB_ZERO;
DUSER_API BOOL WINAPI MapGadgetPoints(HGADGET hgadFrom, HGADGET hgadTo, POINT* rgptClientPxl, int cPts) STUB_ZERO;
DUSER_API BOOL WINAPI PeekMessageExA(MSG* lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg) STUB_ZERO;
DUSER_API BOOL WINAPI PeekMessageExW(MSG* lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg) STUB_ZERO;
DUSER_API MSGID WINAPI RegisterGadgetMessage(const GUID* pguid) STUB_ZERO;
DUSER_API BOOL WINAPI RegisterGadgetMessageString(const WCHAR* pszName) STUB_ZERO;
DUSER_API PRID WINAPI RegisterGadgetProperty(const GUID* pguid) STUB_ZERO;
DUSER_API BOOL WINAPI ReleaseDetachedObjects(UINT version, DWORD dwDetachCookie) STUB_ZERO;
DUSER_API BOOL WINAPI ReleaseLayeredRef(HGADGET hgad) STUB_ZERO;
DUSER_API BOOL WINAPI ReleaseMouseCapture(HGADGET hgad) STUB_ZERO;
DUSER_API BOOL WINAPI RemoveClippingImmunityFromVisual(HGADGET hgad) STUB_ZERO;
DUSER_API BOOL WINAPI RemoveGadgetMessageHandler(HGADGET hgadMsg, MSGID nMsg, HGADGET hgadHandler) STUB_ZERO;
DUSER_API BOOL WINAPI RemoveGadgetProperty(HGADGET hgad, PRID id) STUB_ZERO;
DUSER_API BOOL WINAPI ResetDUserDevice(HGADGET hgad) STUB_ZERO;
DUSER_API BOOL WINAPI ScheduleGadgetTransitions(UINT, UINT, const GTRANS_DESC*, HGADGET, TransitionStoryboardInfo*) STUB_ZERO;
DUSER_API BOOL WINAPI SetActionTimeslice(DWORD dwTimeslice) STUB_ZERO;
DUSER_API BOOL WINAPI SetAtlasingHints(SIZE* psizeAtlas, RECT* prcSmall, RECT* prcWide, RECT* prcApp, RECT* prcSmallWide, RECT* prcSmallApp) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetBufferInfo(HGADGET hgadChange, const BUFFER_INFO* pbi) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetCenterPoint(HGADGET hgadChange, float flX, float flY) STUB_ZERO;
// DUSER_API BOOL WINAPI SetGadgetFillF(HGADGET hgadChange, Gdiplus::Brush* pgpbr) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetFillI(HGADGET hgadChange, HBRUSH hbrFill, BYTE bAlpha, int w, int h) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetFlags(HGADGET hgadChange, UINT nNewFlags, UINT nMask) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetFocus(HGADGET hgadFocus) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetFocusEx(HGADGET hgadFocus, BOOL) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetLayerInfo(HGADGET hgadChange, const LAYER_INFO* pli) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetMessageFilter(HGADGET hgadChange, void* pvCookie, UINT nNewFilter, UINT nMask) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetOrder(HGADGET hgadMove, HGADGET hgadOther, UINT nCmd) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetParent(HGADGET hgadMove, HGADGET hgadParent, HGADGET hgadOther, UINT nCmd) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetProperty(HGADGET hgad, PRID id, void* pvValue) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetRect(HGADGET hgadChange, int x, int y, int w, int h, UINT nFlags) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetRootInfo(HGADGET hgadRoot, const ROOT_INFO* pri) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetRotation(HGADGET hgadChange, float flRotationRad) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetScale(HGADGET hgadChange, float flX, float flY) STUB_ZERO;
DUSER_API BOOL WINAPI SetGadgetStyle(HGADGET hgadChange, UINT nNewStyle, UINT nMask) STUB_ZERO;
DUSER_API BOOL WINAPI SetHardwareDeviceUsage(HMONITOR hmonTarget) STUB_ZERO;
DUSER_API BOOL WINAPI SetMinimumDCompVersion(UINT uVersion) STUB_ZERO;
DUSER_API BOOL WINAPI SetRestoreCachedLayeredRefFlag(HGADGET hgad) STUB_ZERO;
DUSER_API BOOL WINAPI SetTransitionVisualProperties(UINT version, UINT cTrans, const GTRANS_DESC* rgTrans) STUB_ZERO;
DUSER_API BOOL WINAPI SetWindowResizeFlag(HGADGET hgad, UINT nFlags) STUB_ZERO;
DUSER_API BOOL WINAPI UnregisterGadgetMessage(const GUID* pguid) STUB_ZERO;
DUSER_API BOOL WINAPI UnregisterGadgetMessageString(const WCHAR* pszName) STUB_ZERO;
DUSER_API BOOL WINAPI UnregisterGadgetProperty(const GUID* pguid) STUB_ZERO;
DUSER_API HFONT WINAPI UtilBuildFont(LPCWSTR pszName, int idxDeciSize, DWORD nFlags, HDC hdcDevice) STUB_ZERO;
DUSER_API BOOL WINAPI UtilDrawBlendRect(HDC hdcDest, const RECT* prcDest, HBRUSH hbrFill, BYTE bAlpha, int wBrush, int hBrush) STUB_ZERO;
DUSER_API COLORREF WINAPI UtilGetColor(HBITMAP hbmp, POINT* pptPxl) STUB_ZERO;
DUSER_API BOOL WINAPI UtilSetBackground(HGADGET hgadChange, HBRUSH hbrBack) STUB_ZERO;
DUSER_API BOOL WINAPI WaitMessageEx() STUB_ZERO;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}
