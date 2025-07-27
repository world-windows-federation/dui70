// ReSharper disable CppMemberFunctionMayBeStatic
// ReSharper disable CppParameterNeverUsed
// ReSharper disable CppPossiblyUninitializedMember
#include "DirectUI.h"

#define STUB_ZERO { return {}; }
#define STUB_VOID {}

void WINAPI DumpDuiTree(DirectUI::Element* pe, BOOL fShowProperties) STUB_VOID;
void WINAPI DumpDuiProperties(DirectUI::Element* pe) STUB_VOID;
HRESULT WINAPI DuiCreateObject(REFCLSID rclsid, REFIID riid, void** ppv) STUB_ZERO;

namespace DirectUI
{

DWORD g_dwElSlot;

extern "C"
{
HRESULT WINAPI InitProcessPriv(DWORD dwExpectedVersion, HMODULE hModule, bool fRegisterControls, bool fEnableUIAutomationProvider, bool fInitCommctl) STUB_ZERO;
HRESULT WINAPI UnInitProcessPriv(HMODULE hModule) STUB_ZERO;
HRESULT WINAPI InitThread(UINT nThreadMode) STUB_ZERO;
void WINAPI UnInitThread() STUB_VOID;
HRESULT WINAPI CreateDUIWrapper(Element* pe, IUnknown** ppunk) STUB_ZERO;
HRESULT WINAPI CreateDUIWrapperEx(Element* pe, IXProviderCP* pprovCP, IUnknown** ppunk) STUB_ZERO;
HRESULT WINAPI CreateDUIWrapperFromResource(HINSTANCE hRes, const WCHAR* pszResource, const WCHAR* pszResID, const WCHAR* pszFile, IUnknown** ppunk) STUB_ZERO;
HRESULT WINAPI GetScreenDPI() STUB_ZERO;
HRESULT WINAPI RegisterAllControls() STUB_ZERO;
HRESULT WINAPI RegisterBaseControls() STUB_ZERO;
HRESULT WINAPI RegisterBrowserControls() STUB_ZERO;
HRESULT WINAPI RegisterCommonControls() STUB_ZERO;
HRESULT WINAPI RegisterExtendedControls() STUB_ZERO;
HRESULT WINAPI RegisterMacroControls() STUB_ZERO;
HRESULT WINAPI RegisterMiscControls() STUB_ZERO;
HRESULT WINAPI RegisterStandardControls() STUB_ZERO;
HRESULT WINAPI RegisterXControls() STUB_ZERO;
BOOL WINAPI StartMessagePump() STUB_ZERO;
void WINAPI StopMessagePump() STUB_VOID;
ATOM WINAPI StrToID(const WCHAR* psz) STUB_ZERO;
CHAR* WINAPI UnicodeToMultiByte(const WCHAR* pszUnicode, int cChars, int* pMultiBytes) STUB_ZERO;
WCHAR* WINAPI MultiByteToUnicode(const CHAR* pszMulti, int dBytes, int* pUniChars) STUB_ZERO;
BOOL WINAPI IsAnimationsEnabled() STUB_ZERO;
bool WINAPI IsPalette(HWND hwnd) STUB_ZERO;
BOOL WINAPI IsUIAutomationProviderEnabled() STUB_ZERO;
int WINAPI DUIDrawShadowText(HDC hdc, const WCHAR* pszText, int cch, RECT* prc, DWORD dwFlags, COLORREF crText) STUB_ZERO;
void WINAPI BlurBitmap(UINT* plBitmapBits, int cx, int cy, int cxRow, COLORREF crFill) STUB_VOID;
void WINAPI BlurBitmapNormal(UINT* prgb, int cx, int cy, int cxRow, COLORREF crFill) STUB_VOID;
HBRUSH WINAPI BrushFromEnumI(int c) STUB_ZERO;
COLORREF WINAPI ColorFromEnumI(int c) STUB_ZERO;
COLORREF WINAPI ARGBColorFromEnumI(int c) STUB_ZERO;
DWORD* WINAPI DisableAnimations() STUB_ZERO;
int WINAPI DrawShadowTextEx(HDC hdc, const WCHAR* pszText, int cch, RECT* prc, DWORD dwFlags, COLORREF crText, COLORREF crShadow, int ixOffset, int iyOffset, BYTE bInitialAlpha, BOOL fAPIInit) STUB_ZERO;
Element* WINAPI ElementFromGadget(HGADGET hGadget) STUB_ZERO;
DWORD* WINAPI EnableAnimations() STUB_ZERO;
void WINAPI FlushThemeHandles(WPARAM wParam) STUB_VOID;
void WINAPI ForceDebugBreak() STUB_VOID;
IDataEntry* WINAPI GetElementDataEntry(Element* pe) STUB_ZERO;
Macro* WINAPI GetElementMacro(Element* pe) STUB_ZERO;
void* WINAPI GetFontCache() STUB_ZERO;
float WINAPI GetScaleFactor() STUB_ZERO;
HRESULT WINAPI GetThemeHandle(const WCHAR* pszClass, HTHEME* phTheme) STUB_ZERO;
HRESULT WINAPI HrSysAllocString(const OLECHAR* psz, BSTR* pbstrOut) STUB_ZERO;
HRESULT WINAPI HStrDup(const WCHAR* pszSrc, WCHAR** ppszOut) STUB_ZERO;
BOOL WINAPI InitPreprocessor() STUB_ZERO;
HRESULT WINAPI SetDefAction(Element* pe, DWORD oleacc) STUB_ZERO;
BOOL WINAPI UiaHideOnGetObject(HWND hwnd, WPARAM wParam, LPARAM lParam) STUB_ZERO;
HANDLE WINAPI UiaOnDestroySink(HWND hwnd) STUB_ZERO;
HRESULT WINAPI UiaOnGetObject(Element* pe, WPARAM wParam, LPARAM lParam, bool* pfHandled, int* plResult) STUB_ZERO;
BOOL WINAPI UiaOnToolTip(Element* pe, DWORD dwFlags) STUB_ZERO;
void WINAPI NotifyAccessibilityEvent(DWORD dwEvent, Element* pe) STUB_VOID;
WCHAR* WINAPI PreprocessBuffer(const WCHAR* pszBuf, UINT cchBuf, bool fInsertMainResId) STUB_ZERO;
HBITMAP WINAPI ProcessAlphaBitmapI(HBITMAP hbmSource) STUB_ZERO;
void WINAPI PurgeThemeHandles() STUB_VOID;
HRESULT WINAPI RegisterPVLBehaviorFactory() STUB_ZERO;
void WINAPI DUIStopPVLAnimation(Element* peAnimating, UINT nDCProperty, BOOL fFinal) STUB_VOID;

} // extern "C"

//~ Begin DirectUI::DuiAccessible Class
HRESULT DuiAccessible::Create(Element* pe, DuiAccessible** ppDA) STUB_ZERO;
DuiAccessible::DuiAccessible() STUB_VOID;
HRESULT DuiAccessible::Disconnect() STUB_ZERO;
void DuiAccessible::Initialize(Element* pe) STUB_VOID;
DuiAccessible::~DuiAccessible() STUB_VOID;
HRESULT DuiAccessible::QueryInterface(REFIID riid, void** ppvObj) STUB_ZERO;
ULONG DuiAccessible::AddRef() STUB_ZERO;
ULONG DuiAccessible::Release() STUB_ZERO;
HRESULT DuiAccessible::GetTypeInfoCount(UINT* pctinfo) STUB_ZERO;
HRESULT DuiAccessible::GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo) STUB_ZERO;
HRESULT DuiAccessible::GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId) STUB_ZERO;
HRESULT DuiAccessible::Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) STUB_ZERO;
HRESULT DuiAccessible::get_accParent(IDispatch** ppdispParent) STUB_ZERO;
HRESULT DuiAccessible::get_accChildCount(long* pcountChildren) STUB_ZERO;
HRESULT DuiAccessible::get_accChild(VARIANT varChild, IDispatch** ppdispChild) STUB_ZERO;
HRESULT DuiAccessible::get_accName(VARIANT varChild, BSTR* pszName) STUB_ZERO;
HRESULT DuiAccessible::get_accValue(VARIANT varChild, BSTR* pszValue) STUB_ZERO;
HRESULT DuiAccessible::get_accDescription(VARIANT varChild, BSTR* pszDescription) STUB_ZERO;
HRESULT DuiAccessible::get_accRole(VARIANT varChild, VARIANT* pvarRole) STUB_ZERO;
HRESULT DuiAccessible::get_accState(VARIANT varChild, VARIANT* pvarState) STUB_ZERO;
HRESULT DuiAccessible::get_accHelp(VARIANT varChild, BSTR* pszHelp) STUB_ZERO;
HRESULT DuiAccessible::get_accHelpTopic(BSTR* pszHelpFile, VARIANT varChild, long* pidTopic) STUB_ZERO;
HRESULT DuiAccessible::get_accKeyboardShortcut(VARIANT varChild, BSTR* pszKeyboardShortcut) STUB_ZERO;
HRESULT DuiAccessible::get_accFocus(VARIANT* pvarChild) STUB_ZERO;
HRESULT DuiAccessible::get_accSelection(VARIANT* pvarChildren) STUB_ZERO;
HRESULT DuiAccessible::get_accDefaultAction(VARIANT varChild, BSTR* pszDefaultAction) STUB_ZERO;
HRESULT DuiAccessible::accSelect(long flagsSelect, VARIANT varChild) STUB_ZERO;
HRESULT DuiAccessible::accLocation(long* pxLeft, long* pyTop, long* pcxWidth, long* pcyHeight, VARIANT varChild) STUB_ZERO;
HRESULT DuiAccessible::accNavigate(long navDir, VARIANT varStart, VARIANT* pvarEndUpAt) STUB_ZERO;
HRESULT DuiAccessible::accHitTest(long xLeft, long yTop, VARIANT* pvarChild) STUB_ZERO;
HRESULT DuiAccessible::accDoDefaultAction(VARIANT varChild) STUB_ZERO;
HRESULT DuiAccessible::put_accName(VARIANT varChild, BSTR szName) STUB_ZERO;
HRESULT DuiAccessible::put_accValue(VARIANT varChild, BSTR szValue) STUB_ZERO;
HRESULT DuiAccessible::Next(ULONG celt, VARIANT* rgVar, ULONG* pCeltFetched) STUB_ZERO;
HRESULT DuiAccessible::Skip(ULONG celt) STUB_ZERO;
HRESULT DuiAccessible::Reset() STUB_ZERO;
HRESULT DuiAccessible::Clone(IEnumVARIANT** ppEnum) STUB_ZERO;
HRESULT DuiAccessible::GetWindow(HWND* phwnd) STUB_ZERO;
HRESULT DuiAccessible::ContextSensitiveHelp(BOOL fEnterMode) STUB_ZERO;
HRESULT DuiAccessible::GetIdentityString(DWORD dwIDChild, BYTE** ppIDString, DWORD* pdwIDStringLen) STUB_ZERO;
HRESULT DuiAccessible::QueryService(REFGUID guidService, REFIID riid, void** ppvObject) STUB_ZERO;
HRESULT DuiAccessible::AccNavigate(Element* pe, long navDir, Element** ppe) STUB_ZERO;
Element* DuiAccessible::GetAccessibleParent(Element* pe) STUB_ZERO;
HRESULT DuiAccessible::GetDispatchFromElement(Element* pe, IDispatch** ppDispatch) STUB_ZERO;
HRESULT DuiAccessible::GetAccName(VARIANT varChild, BOOL fAllowSubstitution, BSTR* pbstrName) STUB_ZERO;
HRESULT DuiAccessible::GetAccNameFromContent(BSTR* pbstrName) STUB_ZERO;
//~ End DirectUI::DuiAccessible Class

RefcountBase::RefcountBase()
{
}

RefcountBase::~RefcountBase()
{
}

long RefcountBase::AddRef()
{
	return 0;
}

long RefcountBase::Release()
{
	return 0;
}

HRESULT Button::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT Button::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void Button::OnInput(InputEvent* pie) STUB_VOID;
UID Button::Click() STUB_ZERO;
UID Button::Context() STUB_ZERO;
const PropertyInfo* Button::PressedProp() STUB_ZERO;
const PropertyInfo* Button::CapturedProp() STUB_ZERO;
bool Button::GetPressed() STUB_ZERO;
bool Button::GetCaptured() STUB_ZERO;
HRESULT Button::SetPressed(bool v) STUB_ZERO;
HRESULT Button::SetCaptured(bool v) STUB_ZERO;
IClassInfo* Button::GetClassInfoPtr() STUB_ZERO;
void Button::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Button::s_pClassInfo;
IClassInfo* Button::GetClassInfoW() STUB_ZERO;
HRESULT Button::Register() STUB_ZERO;
void Button::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
bool Button::OnLostDialogFocus(IDialogElement* pDE) STUB_ZERO;
bool Button::OnReceivedDialogFocus(IDialogElement* pDE) STUB_ZERO;
HRESULT Button::DefaultAction() STUB_ZERO;
Button::Button() STUB_VOID;
HRESULT Button::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
Button::~Button() STUB_VOID;

//~ Begin DirectUI::Element Class
HRESULT Element::Create(UINT nCreate, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT Element::Destroy(bool fDelayed) STUB_ZERO;
HRESULT Element::DestroyAll(bool fDelayed) STUB_ZERO;
Element::Element() STUB_VOID;
Element::~Element() STUB_VOID;
HRESULT Element::Initialize(UINT nCreate, Element* peInitialParent, DWORD* pdwDeferCookie) STUB_ZERO;
Value* Element::GetRawValue(const PropertyInfo* ppi, int iIndex, UpdateCache* puc) STUB_ZERO;
Value* Element::GetValue(const PropertyInfo* ppi, int iIndex, UpdateCache* puc) STUB_ZERO;
Value* Element::GetValue(PropertyProcT pPropertyProc, int iIndex, UpdateCache* puc) STUB_ZERO;
HRESULT Element::SetValue(const PropertyInfo* ppi, int iIndex, Value* pv) STUB_ZERO;
HRESULT Element::SetValue(PropertyProcT pPropertyProc, int iIndex, Value* pv) STUB_ZERO;
HRESULT Element::RemoveLocalValue(const PropertyInfo* ppi) STUB_ZERO;
HRESULT Element::RemoveLocalValue(PropertyProcT pPropertyProc) STUB_ZERO;
void Element::StartDefer(DWORD* pdwDeferCookie) STUB_VOID;
void Element::EndDefer(DWORD dwDeferCookie) STUB_VOID;
void Element::UpdateLayout() STUB_VOID;
DeferCycle* Element::GetDeferObject() STUB_ZERO;
DeferCycle* Element::TestDeferObject() STUB_ZERO;
bool Element::IsValidAccessor(const PropertyInfo* ppi, int iIndex, bool bSetting) STUB_ZERO;
bool Element::IsValidValue(const PropertyInfo* ppi, Value* pv) STUB_ZERO;
bool Element::IsRTL() STUB_ZERO;
bool Element::IsRTLReading() STUB_ZERO;
bool Element::IsContentProtected() STUB_ZERO;
const WCHAR* Element::GetContentStringAsDisplayed(Value** ppv) STUB_ZERO;
const WCHAR* Element::GetAccNameAsDisplayed(Value** ppv) STUB_ZERO;
bool Element::OnPropertyChanging(PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
bool Element::OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void Element::OnPropertyChanged(PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void Element::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void Element::OnGroupChanged(int fGroups, bool bLowPri) STUB_VOID;
void Element::OnInput(InputEvent* pInput) STUB_VOID;
void Element::OnKeyFocusMoved(Element* peFrom, Element* peTo) STUB_VOID;
void Element::OnMouseFocusMoved(Element* peFrom, Element* peTo) STUB_VOID;
void Element::OnDestroy() STUB_VOID;
void Element::FireEvent(Event* pEvent, bool fFull, bool fUseSpecifiedTarget) STUB_VOID;
void Element::BroadcastEvent(Event* pEvent) STUB_VOID;
void Element::OnEvent(Event* pEvent) STUB_VOID;
void Element::Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) STUB_VOID;
void Element::PaintContent(HDC hDC, const RECT* prcContent) STUB_VOID;
void Element::PaintStringContent(HDC hDC, const RECT* prcContent, Value* pvContent, int dCAlign) STUB_VOID;
void Element::PaintFocusRect(HDC hDC, const RECT* prcBounds, const RECT* prcContent) STUB_VOID;
void Element::PaintBorder(HDC hDC, Value* pvBackgnd, RECT* prcPaint, const RECT& rcBorder) STUB_VOID;
void Element::PaintBackground(HDC hDC, Value* pvBackgnd, const RECT& rcBounds, const RECT& rcInvalid, const RECT& rcPadding, const RECT& rcBorder) STUB_VOID;
void Element::PaintEdgeHighlight(HDC hDC, const RECT& rcPaint, const RECT& rcInvalid) STUB_VOID;
SIZE Element::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
float Element::GetTreeAlphaLevel() STUB_ZERO;
HRESULT Element::Add(Element* pe) STUB_ZERO;
HRESULT Element::Add(Element** ppe, UINT cCount) STUB_ZERO;
HRESULT Element::Add(Element* pe, CompareCallback lpfnCompare) STUB_ZERO;
HRESULT Element::Insert(Element* pe, UINT iInsertIdx) STUB_ZERO;
HRESULT Element::Insert(Element** ppe, UINT cCount, UINT iInsertIdx) STUB_ZERO;
HRESULT Element::SortChildren(CompareCallback lpfnCompare) STUB_ZERO;
HRESULT Element::ShiftChild(UINT iOldIndex, UINT iNewIndex) STUB_ZERO;
HRESULT Element::Remove(Element* pe) STUB_ZERO;
HRESULT Element::Remove(Element** ppe, UINT cCount) STUB_ZERO;
HRESULT Element::RemoveAll() STUB_ZERO;
Element* Element::FindDescendent(ATOM atomID) STUB_ZERO;
void Element::MapElementPoint(Element* peFrom, const POINT* pptFrom, POINT* pptTo) STUB_VOID;
Element* Element::GetImmediateChild(Element* peFrom) STUB_ZERO;
bool Element::IsDescendent(Element* pe) STUB_ZERO;
Element* Element::GetAdjacent(Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
Element* Element::GetKeyWithinChild() STUB_ZERO;
Element* Element::GetMouseWithinChild() STUB_ZERO;
bool Element::EnsureVisible() STUB_ZERO;
bool Element::EnsureVisible(UINT uChild) STUB_ZERO;
bool Element::EnsureVisible(int x, int y, int cx, int cy) STUB_ZERO;
void Element::SetKeyFocus() STUB_VOID;
HRESULT Element::AddListener(IElementListener* pel) STUB_ZERO;
void Element::RemoveListener(IElementListener* pel) STUB_VOID;
HRESULT Element::AddBehavior(IDuiBehavior* pBehavior) STUB_ZERO;
HRESULT Element::RemoveBehavior(IDuiBehavior* pBehavior) STUB_ZERO;
void Element::InvokeAnimation(int dAni, UINT nTypeMask) STUB_VOID;
void Element::InvokeAnimation(UINT nTypes, UINT nInterpol, float flDuration, float flDelay, bool fPushToChildren) STUB_VOID;
void Element::StopAnimation(UINT nTypes) STUB_VOID;
UINT Element::MessageCallback(GMSG* pgMsg) STUB_ZERO;
SIZE Element::_UpdateDesiredSize(int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
void Element::_UpdateLayoutPosition(int dX, int dY) STUB_VOID;
void Element::_UpdateLayoutSize(int dWidth, int dHeight) STUB_VOID;
void Element::_StartOptimizedLayoutQ() STUB_VOID;
void Element::_EndOptimizedLayoutQ() STUB_VOID;
UINT Element::_GetNeedsLayout() STUB_ZERO;
bool Element::_SetGroupChanges(Element* pe, int fGroups, DeferCycle* pdc) STUB_ZERO;
void Element::_TransferGroupFlags(Element* pe, int fGroups) STUB_VOID;
int Element::_SetNeedsLayout(UINT fNeedsLayout) STUB_ZERO;
int Element::_MarkElementForLayout(Element* pe, UINT fNeedsLayout) STUB_ZERO;
int Element::_MarkElementForDS(Element* pe) STUB_ZERO;
void Element::_ClearNeedsLayout() STUB_VOID;
void Element::_AddDependency(Element* pe, const PropertyInfo* ppi, int iIndex, DepRecs* pdr, DeferCycle* pdc, HRESULT* phr) STUB_VOID;
HRESULT Element::_DisplayNodeCallback(HGADGET hgadCur, void* pvCur, EventMsg* pGMsg) STUB_ZERO;
HRESULT Element::QueryInterface(REFIID riid, void** ppvObject) STUB_ZERO;
ULONG Element::AddRef() STUB_ZERO;
ULONG Element::Release() STUB_ZERO;
int Element::_GetChangesUpdatePass() STUB_ZERO;
void Element::Detach(DeferCycle* pdc) STUB_VOID;
bool Element::UiaEvents() STUB_ZERO;
void Element::EnableUiaEvents(bool fEnable) STUB_VOID;
bool Element::GetClickablePoint(POINT* ptClick) STUB_ZERO;
void Element::GetImmersiveFocusRectOffsets(RECT* prc) STUB_VOID;
Element* Element::FindDescendentWorker(ATOM atomID) STUB_ZERO;
void Element::_GetBuriedSheetDependencies(const PropertyInfo* ppi, Element* peNewParent, DepRecs* pdr, DeferCycle* pdc, HRESULT* phr) STUB_VOID;
HRESULT Element::_GetDependencies(const PropertyInfo* ppi, int iIndex, DepRecs* pdr, int iPCSrcRoot, Value* pvNewRoot, DeferCycle* pdc) STUB_ZERO;
void Element::_VoidPCNotifyTree(int iPCPos, DeferCycle* pdc) STUB_VOID;
int Element::_CachedValueIsEqual(const PropertyInfo* ppi, Element* peParent) STUB_ZERO;
Value* Element::_GetLocalValueFromVM(const PropertyInfo* ppi) STUB_ZERO;
Value* Element::_GetLocalValue(const PropertyInfo* ppi) STUB_ZERO;
Value* Element::_GetSpecifiedValueIgnoreCache(const PropertyInfo* ppi) STUB_ZERO;
Value* Element::_GetSpecifiedValue(const PropertyInfo* ppi, UpdateCache* puc) STUB_ZERO;
Value* Element::_GetComputedValue(const PropertyInfo* ppi, UpdateCache* puc) STUB_ZERO;
void Element::_UpdatePropertyInCache(const PropertyInfo* ppi) STUB_VOID;
void Element::_InheritProperties() STUB_VOID;
void Element::_FlushDS(DeferCycle*) STUB_VOID;
HRESULT Element::_PreSourceChange(PropertyProcT proc, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
HRESULT Element::_PreSourceChange(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
HRESULT Element::_PostSourceChange() STUB_ZERO;
void Element::_BroadcastEventWorker(Event* pEvent) STUB_VOID;
void Element::_PostEvent(Event* pEvent, int nMsg) STUB_VOID;
bool Element::s_HandleDUIEventMessage(Element* pe, EventMsg* pEventMsg) STUB_ZERO;
UINT Element::GetCommonDrawTextFlags(int dCAlign) STUB_ZERO;
WCHAR* Element::RemoveShortcutFromName(const WCHAR* pszName) STUB_ZERO;
void Element::_SyncVisible() STUB_VOID;
void Element::_SyncBackground() STUB_VOID;
void Element::_SyncRedrawStyle() STUB_VOID;
bool Element::IsPointValid(double x, double y) STUB_ZERO;
bool Element::TryLinePattern(POINT* pt, const RECT& rcParent) STUB_ZERO;
bool Element::TryPattern(double x, double y, POINT* pt, const RECT& rcParent) STUB_ZERO;
bool Element::TrySparsePattern(POINT* pt, const RECT& rcParent) STUB_ZERO;
HRESULT Element::_SetRelPixValue(const PropertyInfo* ppi, int nValue) STUB_ZERO;
HRESULT Element::_SetRelPixRect(const PropertyInfo* ppi, int l, int t, int r, int b) STUB_ZERO;
HRESULT Element::GetTheme(const WCHAR* pszClass, HTHEME* phTheme) STUB_ZERO;
void Element::_FlushLayout(Element* pe, DeferCycle* pdc) STUB_VOID;
void Element::_InvalidateCachedDSConstraints(Element* pe) STUB_VOID;
void Element::_SelfLayoutDoLayout(int cx, int cy) STUB_VOID;
SIZE Element::_SelfLayoutUpdateDesiredSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
HRESULT Element::_SetValue(const PropertyInfo* ppi, int iIndex, Value* pv, bool fInternalCall) STUB_ZERO;
HRESULT Element::_SetValue(PropertyProcT pPropertyProc, int iIndex, Value* pv, bool fInternalCall) STUB_ZERO;
HRESULT Element::_RemoveLocalValue(const PropertyInfo* ppi, bool fInternalCall) STUB_ZERO;
HRESULT Element::_RemoveLocalValue(PropertyProcT pPropertyProc, bool fInternalCall) STUB_ZERO;
void Element::OnHosted(Element* peNewRoot) STUB_VOID;
void Element::OnUnHosted(Element* peOldRoot) STUB_VOID;
void Element::MarkHosted() STUB_VOID;
void Element::MarkSelfLayout() STUB_VOID;
void Element::UpdateTooltip(Element* pe) STUB_VOID;
void Element::ActivateTooltip(Element* pe, DWORD dwFlags) STUB_VOID;
void Element::RemoveTooltip(Element* pe) STUB_VOID;
void Element::_OnFontPropChanged(Value* pvFont) STUB_VOID;
void Element::MarkNeedsDSUpdate() STUB_VOID;
bool Element::NeedsDSUpdate() STUB_ZERO;
void Element::DoubleBuffered(bool fEnabled) STUB_VOID;
int Element::IsRoot() STUB_ZERO;
Element* Element::GetRoot() STUB_ZERO;
Element* Element::GetTopLevel() STUB_ZERO;
HRESULT Element::GetRootRelativeBounds(RECT* prc) STUB_ZERO;
RTL_CRITICAL_SECTION* Element::GetFactoryLock() STUB_ZERO;
UID Element::KeyboardNavigate() STUB_ZERO;
UID Element::AnimationChange() STUB_ZERO;
UID Element::DCompDeviceRebuilt() STUB_ZERO;
const PropertyInfo* Element::ParentProp() STUB_ZERO;
const PropertyInfo* Element::ChildrenProp() STUB_ZERO;
const PropertyInfo* Element::VisibleProp() STUB_ZERO;
const PropertyInfo* Element::WidthProp() STUB_ZERO;
const PropertyInfo* Element::HeightProp() STUB_ZERO;
const PropertyInfo* Element::LocationProp() STUB_ZERO;
const PropertyInfo* Element::ExtentProp() STUB_ZERO;
const PropertyInfo* Element::XProp() STUB_ZERO;
const PropertyInfo* Element::YProp() STUB_ZERO;
const PropertyInfo* Element::PosInLayoutProp() STUB_ZERO;
const PropertyInfo* Element::SizeInLayoutProp() STUB_ZERO;
const PropertyInfo* Element::DesiredSizeProp() STUB_ZERO;
const PropertyInfo* Element::LastDSConstProp() STUB_ZERO;
const PropertyInfo* Element::LayoutProp() STUB_ZERO;
const PropertyInfo* Element::LayoutPosProp() STUB_ZERO;
const PropertyInfo* Element::BorderThicknessProp() STUB_ZERO;
const PropertyInfo* Element::BorderStyleProp() STUB_ZERO;
const PropertyInfo* Element::BorderColorProp() STUB_ZERO;
const PropertyInfo* Element::PaddingProp() STUB_ZERO;
const PropertyInfo* Element::MarginProp() STUB_ZERO;
const PropertyInfo* Element::ForegroundProp() STUB_ZERO;
const PropertyInfo* Element::BackgroundProp() STUB_ZERO;
const PropertyInfo* Element::ContentProp() STUB_ZERO;
const PropertyInfo* Element::FontFaceProp() STUB_ZERO;
const PropertyInfo* Element::FontSizeProp() STUB_ZERO;
const PropertyInfo* Element::FontWeightProp() STUB_ZERO;
const PropertyInfo* Element::FontStyleProp() STUB_ZERO;
const PropertyInfo* Element::FontQualityProp() STUB_ZERO;
const PropertyInfo* Element::ActiveProp() STUB_ZERO;
const PropertyInfo* Element::ContentAlignProp() STUB_ZERO;
const PropertyInfo* Element::KeyFocusedProp() STUB_ZERO;
const PropertyInfo* Element::KeyWithinProp() STUB_ZERO;
const PropertyInfo* Element::MouseFocusedProp() STUB_ZERO;
const PropertyInfo* Element::MouseWithinProp() STUB_ZERO;
const PropertyInfo* Element::ClassProp() STUB_ZERO;
const PropertyInfo* Element::IDProp() STUB_ZERO;
const PropertyInfo* Element::SheetProp() STUB_ZERO;
const PropertyInfo* Element::SelectedProp() STUB_ZERO;
const PropertyInfo* Element::AlphaProp() STUB_ZERO;
const PropertyInfo* Element::AnimationProp() STUB_ZERO;
const PropertyInfo* Element::CursorProp() STUB_ZERO;
const PropertyInfo* Element::DirectionProp() STUB_ZERO;
const PropertyInfo* Element::AccessibleProp() STUB_ZERO;
const PropertyInfo* Element::AccRoleProp() STUB_ZERO;
const PropertyInfo* Element::AccStateProp() STUB_ZERO;
const PropertyInfo* Element::AccNameProp() STUB_ZERO;
const PropertyInfo* Element::AccDescProp() STUB_ZERO;
const PropertyInfo* Element::AccValueProp() STUB_ZERO;
const PropertyInfo* Element::AccDefActionProp() STUB_ZERO;
const PropertyInfo* Element::AccHelpProp() STUB_ZERO;
const PropertyInfo* Element::AccItemTypeProp() STUB_ZERO;
const PropertyInfo* Element::AccItemStatusProp() STUB_ZERO;
const PropertyInfo* Element::ShortcutProp() STUB_ZERO;
const PropertyInfo* Element::EnabledProp() STUB_ZERO;
const PropertyInfo* Element::MinSizeProp() STUB_ZERO;
const PropertyInfo* Element::OverhangProp() STUB_ZERO;
const PropertyInfo* Element::TooltipProp() STUB_ZERO;
const PropertyInfo* Element::TooltipMaxWidthProp() STUB_ZERO;
const PropertyInfo* Element::FontProp() STUB_ZERO;
const PropertyInfo* Element::WindowActiveProp() STUB_ZERO;
const PropertyInfo* Element::AbsorbsShortcutProp() STUB_ZERO;
const PropertyInfo* Element::CompositedTextProp() STUB_ZERO;
const PropertyInfo* Element::TextGlowSizeProp() STUB_ZERO;
const PropertyInfo* Element::HighDPIProp() STUB_ZERO;
const PropertyInfo* Element::DPIProp() STUB_ZERO;
const PropertyInfo* Element::CustomProp() STUB_ZERO;
const PropertyInfo* Element::ShadowIntensityProp() STUB_ZERO;
const PropertyInfo* Element::EdgeHighlightThicknessProp() STUB_ZERO;
const PropertyInfo* Element::EdgeHighlightColorProp() STUB_ZERO;
const PropertyInfo* Element::ScaleFactorProp() STUB_ZERO;
const PropertyInfo* Element::UsesDesktopPerMonitorScalingProp() STUB_ZERO;
HGADGET Element::GetDisplayNode() STUB_ZERO;
int Element::GetIndex() STUB_ZERO;
bool Element::IsDestroyed() STUB_ZERO;
bool Element::IsHosted() STUB_ZERO;
bool Element::IsSelfLayout() STUB_ZERO;
bool Element::IsBehaviorLayout() const STUB_ZERO;
bool Element::HasChildren() STUB_ZERO;
bool Element::HasLayout() STUB_ZERO;
bool Element::HasBorder() STUB_ZERO;
bool Element::HasPadding() STUB_ZERO;
bool Element::HasMargin() STUB_ZERO;
bool Element::HasContent() STUB_ZERO;
bool Element::IsDefaultCAlign() STUB_ZERO;
bool Element::IsWordWrap() STUB_ZERO;
bool Element::HasAnimation() STUB_ZERO;
bool Element::IsDefaultCursor() STUB_ZERO;
bool Element::HasEdgeHighlight() STUB_ZERO;
bool Element::HasPVLAnimationState(UINT dState) STUB_ZERO;
void Element::GetRenderBorderThickness(RECT* prc) STUB_VOID;
void Element::GetRenderPadding(RECT* prc) STUB_VOID;
void Element::GetRenderMargin(RECT* prc) STUB_VOID;
void Element::GetRenderEdgeHighlightThickness(RECT* prc) STUB_VOID;
void Element::GetRenderMinSize(SIZE* prc) STUB_VOID;
Element* Element::GetParent() STUB_ZERO;
bool Element::GetVisible() STUB_ZERO;
int Element::GetWidth() STUB_ZERO;
int Element::GetHeight() STUB_ZERO;
DynamicArray<Element*>* Element::GetChildren(Value** ppv) STUB_ZERO;
int Element::GetX() STUB_ZERO;
int Element::GetY() STUB_ZERO;
Layout* Element::GetLayout(Value** ppv) STUB_ZERO;
int Element::GetLayoutPos() STUB_ZERO;
const RECT* Element::GetBorderThickness(Value** ppv) STUB_ZERO;
int Element::GetBorderStyle() STUB_ZERO;
int Element::GetBorderStdColor() STUB_ZERO;
const Fill* Element::GetBorderColor(Value** ppv) STUB_ZERO;
const RECT* Element::GetPadding(Value** ppv) STUB_ZERO;
const RECT* Element::GetMargin(Value** ppv) STUB_ZERO;
const POINT* Element::GetLocation(Value** ppv) STUB_ZERO;
const SIZE* Element::GetExtent(Value** ppv) STUB_ZERO;
const SIZE* Element::GetDesiredSize() STUB_ZERO;
int Element::GetForegroundStdColor() STUB_ZERO;
const Fill* Element::GetForegroundColor(Value** ppv) STUB_ZERO;
int Element::GetBackgroundStdColor() STUB_ZERO;
const Fill* Element::GetBackgroundColor(Value** ppv) STUB_ZERO;
const RECT* Element::GetEdgeHighlightThickness(Value** ppv) STUB_ZERO;
const Fill* Element::GetEdgeHighlightColor(Value** ppv) STUB_ZERO;
float Element::GetElementScaleFactor() STUB_ZERO;
const WCHAR* Element::GetContentString(Value** ppv) STUB_ZERO;
HRESULT Element::GetEncodedContentString(WCHAR*, size_t cchString) STUB_ZERO;
size_t Element::GetEncodedContentStringLength() STUB_ZERO;
const WCHAR* Element::GetFontFace(Value** ppv) STUB_ZERO;
int Element::GetFontSize() STUB_ZERO;
int Element::GetFontWeight() STUB_ZERO;
int Element::GetFontStyle() STUB_ZERO;
int Element::GetFontQuality() STUB_ZERO;
bool Element::IsCompositedText() STUB_ZERO;
int Element::GetTextGlowSize() STUB_ZERO;
int Element::GetActive() STUB_ZERO;
int Element::GetContentAlign() STUB_ZERO;
bool Element::GetKeyFocused() STUB_ZERO;
bool Element::GetKeyWithin() STUB_ZERO;
bool Element::GetMouseFocused() STUB_ZERO;
bool Element::GetMouseWithin() STUB_ZERO;
const WCHAR* Element::GetClass(Value** ppv) STUB_ZERO;
ATOM Element::GetID() STUB_ZERO;
StyleSheet* Element::GetSheet() STUB_ZERO;
bool Element::GetSelected() STUB_ZERO;
int Element::GetAlpha() STUB_ZERO;
bool Element::GetPreserveAlphaChannel() const STUB_ZERO;
void Element::SetPreserveAlphaChannel(bool fPreserveAlpha) STUB_VOID;
int Element::GetAnimation() STUB_ZERO;
int Element::GetPVLAnimationState() STUB_ZERO;
int Element::GetDirection() STUB_ZERO;
bool Element::GetAccessible() STUB_ZERO;
int Element::GetAccRole() STUB_ZERO;
int Element::GetAccState() STUB_ZERO;
const WCHAR* Element::GetAccName(Value** ppv) STUB_ZERO;
const WCHAR* Element::GetAccDesc(Value** ppv) STUB_ZERO;
const WCHAR* Element::GetAccValue(Value** ppv) STUB_ZERO;
const WCHAR* Element::GetAccDefAction(Value** ppv) STUB_ZERO;
const WCHAR* Element::GetAccHelp(Value** ppv) STUB_ZERO;
const WCHAR* Element::GetAccItemType(Value** ppv) STUB_ZERO;
const WCHAR* Element::GetAccItemStatus(Value** ppv) STUB_ZERO;
int Element::GetShortcut() STUB_ZERO;
bool Element::GetEnabled() STUB_ZERO;
const SIZE* Element::GetMinSize(Value** ppv) STUB_ZERO;
bool Element::GetOverhang() STUB_ZERO;
bool Element::GetTooltip() STUB_ZERO;
int Element::GetTooltipMaxWidth() STUB_ZERO;
const WCHAR* Element::GetFont(Value** ppv) STUB_ZERO;
int Element::GetColorize() STUB_ZERO;
bool Element::GetWindowActive() STUB_ZERO;
bool Element::GetAbsorbsShortcut() STUB_ZERO;
bool Element::GetHighDPI() STUB_ZERO;
int Element::GetDPI() STUB_ZERO;
int Element::GetShadowIntensity() STUB_ZERO;
void Element::SetLayoutCompletionNotify(bool v) STUB_VOID;
void Element::SetPVLAnimationState(int v) STUB_VOID;
HRESULT Element::SetVisible(bool v) STUB_ZERO;
HRESULT Element::SetWidth(int v) STUB_ZERO;
HRESULT Element::SetHeight(int v) STUB_ZERO;
HRESULT Element::SetRelPixWidth(int v) STUB_ZERO;
HRESULT Element::SetRelPixHeight(int v) STUB_ZERO;
HRESULT Element::SetX(int v) STUB_ZERO;
HRESULT Element::SetY(int v) STUB_ZERO;
HRESULT Element::SetLayout(Layout* v) STUB_ZERO;
HRESULT Element::SetLayoutPos(int v) STUB_ZERO;
HRESULT Element::SetBorderThickness(int l, int t , int r, int b) STUB_ZERO;
HRESULT Element::SetBorderStyle(int v) STUB_ZERO;
HRESULT Element::SetBorderStdColor(int v) STUB_ZERO;
HRESULT Element::SetBorderColor(COLORREF cr) STUB_ZERO;
HRESULT Element::SetBorderGradientColor(COLORREF cr0, COLORREF cr1, BYTE dType) STUB_ZERO;
HRESULT Element::SetPadding(int l, int t, int r, int b) STUB_ZERO;
HRESULT Element::SetRelPixPadding(int l, int t, int r, int b) STUB_ZERO;
HRESULT Element::SetMargin(int l, int t, int r, int b) STUB_ZERO;
HRESULT Element::SetRelPixMargin(int l, int t, int r, int b) STUB_ZERO;
HRESULT Element::SetForegroundStdColor(int v) STUB_ZERO;
HRESULT Element::SetForegroundColor(COLORREF cr) STUB_ZERO;
HRESULT Element::SetForegroundColor(COLORREF cr0, COLORREF cr1, BYTE dType) STUB_ZERO;
HRESULT Element::SetForegroundColor(COLORREF cr0, COLORREF cr1, COLORREF cr2, BYTE dType) STUB_ZERO;
HRESULT Element::SetBackgroundStdColor(int v) STUB_ZERO;
HRESULT Element::SetBackgroundColor(const Fill& fill) STUB_ZERO;
HRESULT Element::SetBackgroundColor(const WCHAR* pszClassName, int iPartId, int iStateId) STUB_ZERO;
HRESULT Element::SetBackgroundColor(COLORREF cr) STUB_ZERO;
HRESULT Element::SetBackgroundColor(COLORREF cr0, COLORREF cr1, BYTE dType) STUB_ZERO;
HRESULT Element::SetBackgroundColor(COLORREF cr0, COLORREF cr1, COLORREF cr2, BYTE dType) STUB_ZERO;
HRESULT Element::SetContentString(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetEncodedContentString(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetContentGraphic(const WCHAR* v, BYTE dBlendMode, UINT dBlendValue) STUB_ZERO;
HRESULT Element::SetContentGraphic(const WCHAR* v, WORD cxDesired, WORD cyDesired) STUB_ZERO;
HRESULT Element::SetFontFace(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetFontSize(int v) STUB_ZERO;
HRESULT Element::SetFontWeight(int v) STUB_ZERO;
HRESULT Element::SetFontStyle(int v) STUB_ZERO;
HRESULT Element::SetFontQuality(int v) STUB_ZERO;
HRESULT Element::SetActive(int v) STUB_ZERO;
HRESULT Element::SetCompositedText(bool v) STUB_ZERO;
HRESULT Element::SetTextGlowSize(int v) STUB_ZERO;
HRESULT Element::SetContentAlign(int v) STUB_ZERO;
HRESULT Element::SetClass(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetID(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetSheet(StyleSheet* v) STUB_ZERO;
HRESULT Element::SetSelected(bool v) STUB_ZERO;
HRESULT Element::SetAlpha(int v) STUB_ZERO;
HRESULT Element::SetAnimation(int v) STUB_ZERO;
HRESULT Element::SetStdCursor(int v) STUB_ZERO;
HRESULT Element::SetCursor(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetCursorHandle(HCURSOR hCursor) STUB_ZERO;
HRESULT Element::SetDirection(int v) STUB_ZERO;
HRESULT Element::SetAccessible(bool v) STUB_ZERO;
HRESULT Element::SetAccRole(int v) STUB_ZERO;
HRESULT Element::SetAccState(int v) STUB_ZERO;
HRESULT Element::SetAccName(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetAccDesc(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetAccValue(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetAccDefAction(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetAccHelp(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetAccItemType(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetAccItemStatus(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetShortcut(int v) STUB_ZERO;
HRESULT Element::SetEnabled(bool v) STUB_ZERO;
HRESULT Element::SetMinSize(int cx, int cy) STUB_ZERO;
HRESULT Element::SetOverhang(bool v) STUB_ZERO;
HRESULT Element::SetTooltip(bool v) STUB_ZERO;
HRESULT Element::SetTooltipMaxWidth(int v) STUB_ZERO;
HRESULT Element::SetFont(const WCHAR* v) STUB_ZERO;
HRESULT Element::SetWindowActive(bool v) STUB_ZERO;
HRESULT Element::SetAbsorbsShortcut(bool v) STUB_ZERO;
HRESULT Element::SetEdgeHighlightThickness(int l, int t, int r, int b) STUB_ZERO;
HRESULT Element::SetEdgeHighlightColor(COLORREF cr) STUB_ZERO;
WCHAR Element::GetShortcutChar() STUB_ZERO;
HRESULT Element::SetShadowIntensity(int v) STUB_ZERO;
IClassInfo* Element::GetClassInfoPtr() STUB_ZERO;
void Element::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Element::s_pClassInfo;
IClassInfo* Element::GetClassInfoW() STUB_ZERO;
HRESULT Element::Register() STUB_ZERO;
HRESULT Element::UnRegister(IClassInfo** ppClassInfo) STUB_ZERO;
HRESULT Element::GetAccessibleImpl(IAccessible** ppAccessible) STUB_ZERO;
HRESULT Element::QueueDefaultAction() STUB_ZERO;
HRESULT Element::DefaultAction() STUB_ZERO;
HRESULT Element::GetUIAElementProvider(REFIID riid, void** ppv) STUB_ZERO;
HRESULT Element::GetElementProviderImpl(InvokeHelper* pih, ElementProvider** ppprv) STUB_ZERO;
void Element::HandleUiaDestroyListener() STUB_VOID;
void Element::HandleUiaPropertyListener(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void Element::HandleUiaPropertyChangingListener(const PropertyInfo* ppi) STUB_VOID;
void Element::HandleUiaEventListener(Event* pEvent) STUB_VOID;
Element* Element::GetUiaFocusDelegate() STUB_ZERO;
void Element::SetOverrideScaleFactor(float flscale) STUB_VOID;
void Element::_Fill(HDC hDC, DWORD crFill, int left, int top, int right, int bottom, bool fForceOpaque) STUB_VOID;
//~ End DirectUI::Element Class

class __Element_Check final : public Element
{
#ifdef _WIN64
	static_assert(sizeof(Element) == 0xC8, "Error");
	static_assert(__builtin_offsetof(Element, _rootWindowForTheming) == 0xC0, "Error");
#else
	static_assert(sizeof(Element) == 0x84);
	static_assert(__builtin_offsetof(Element, _rootWindowForTheming) == 0x80);
#endif
};

//~ Begin DirectUI::ElementWithHWND Class
HRESULT WINAPI ElementWithHWND::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HWND ElementWithHWND::GetHWND() STUB_ZERO;
IClassInfo* WINAPI ElementWithHWND::GetClassInfoPtr() STUB_ZERO;
void WINAPI ElementWithHWND::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* ElementWithHWND::s_pClassInfo;
IClassInfo* ElementWithHWND::GetClassInfoW() STUB_ZERO;
HRESULT WINAPI ElementWithHWND::Register() STUB_ZERO;
//~ End DirectUI::ElementWithHWND Class

//~ Begin DirectUI::DUIXmlParser Class
DUIXmlParser::DUIXmlParser() STUB_VOID;
DUIXmlParser::~DUIXmlParser() STUB_VOID;
HRESULT WINAPI DUIXmlParser::Create(DUIXmlParser** ppParserOut, PXMLGETSHEETCB pfnGetSheetCallback, void* sheetParam, PXMLPARSEERRORCB, void* parseErrorParam) STUB_ZERO;
void DUIXmlParser::Destroy() STUB_VOID;
HRESULT DUIXmlParser::_InitializeTables() STUB_ZERO;
void DUIXmlParser::_DestroyTables() STUB_VOID;
HRESULT DUIXmlParser::SetXML(const WCHAR* pBuffer, HINSTANCE hResourceInstance, HINSTANCE hControlsInstance) STUB_ZERO;
HRESULT DUIXmlParser::SetPreprocessedXML(const WCHAR*, HINSTANCE hResourceInstance, HINSTANCE hControlsInstance) STUB_ZERO;
HRESULT DUIXmlParser::SetXMLFromResourceWithTheme(UINT uRCID, HINSTANCE hResInstance, HINSTANCE hResTheme, HINSTANCE hControlsInstance) STUB_ZERO;
HRESULT DUIXmlParser::SetXMLFromResource(const WCHAR* pszResource, const WCHAR* pszResType, HINSTANCE hResourceInstance, HINSTANCE hControlsInstance) STUB_ZERO;
HRESULT DUIXmlParser::SetXMLFromResource(const WCHAR* pszResid, HINSTANCE hResInstance, HINSTANCE hControlsInstance) STUB_ZERO;
HRESULT DUIXmlParser::SetXMLFromResource(UINT uRCID, const WCHAR* pszResType, HINSTANCE hResInstance, HINSTANCE hControlsInstance) STUB_ZERO;
HRESULT DUIXmlParser::SetXMLFromResource(UINT uRCID, HINSTANCE hResInstance, HINSTANCE hControlsInstance) STUB_ZERO;
void DUIXmlParser::SetRootWindowForTheming(HWND) STUB_VOID;
Value* DUIXmlParser::GetMappedValue(WCHAR*) STUB_ZERO;
HRESULT DUIXmlParser::CreateElement(const WCHAR* pszResID, Element* pEleSubstitute, Element* pParent, DWORD* pdwDeferCookie, Element** ppElementOut) STUB_ZERO;
HRESULT DUIXmlParser::GetSheet(const WCHAR* pszResID, Value** ppValueOut) STUB_ZERO;
void DUIXmlParser::SetParseErrorCallback(PXMLPARSEERRORCB pfnErrorCallback, void* pContext) STUB_VOID;
void DUIXmlParser::SetGetSheetCallback(PXMLGETSHEETCB pfnGetSheetCallback, void* pContext) STUB_VOID;
PXMLGETSHEETCB DUIXmlParser::GetGetSheetCallback() STUB_ZERO;
void* DUIXmlParser::GetSheetContext() STUB_ZERO;
void DUIXmlParser::EnableDesignMode() STUB_VOID;
void DUIXmlParser::SetUnknownAttrCallback(PUNKNOWNATTRCB pfnUnknownAttrCallback, void* pContext) STUB_VOID;
HINSTANCE DUIXmlParser::GetResourceHInstance() STUB_ZERO;
HINSTANCE DUIXmlParser::GetHInstance() STUB_ZERO;
HRESULT DUIXmlParser::LookupElement(LINEINFO li, const WCHAR* pszElem, HINSTANCE hControlsInstance, IClassInfo** ppciOut) STUB_ZERO;
HRESULT DUIXmlParser::LookupElement(IXmlReader* pReader, const WCHAR* pszElem, HINSTANCE hInstance, IClassInfo** ppciOut) STUB_ZERO;
HRESULT DUIXmlParser::UpdateSheets(Element* pe) STUB_ZERO;
void DUIXmlParser::SetDefaultHInstance(HINSTANCE hInst) STUB_VOID;
void DUIXmlParser::SetUnavailableIcon(HICON hIcon) STUB_VOID;
void DUIXmlParser::SetScaleFactor(float scaleFactor) STUB_VOID;
void DUIXmlParser::SetDynamicScaling(DynamicScaleParsing dsp) STUB_VOID;
bool DUIXmlParser::IsDynamicScaling() STUB_ZERO;
HRESULT DUIXmlParser::CopySheets(DynamicArray<Value*>** ppdaSheets) STUB_ZERO;
void DUIXmlParser::SetOverrideScaleFactor(float scaleFactor) STUB_VOID;
bool DUIXmlParser::GetOverrideScaleFactor(float* pScaleFactor) const STUB_ZERO;
HRESULT DUIXmlParser::Initialize() STUB_ZERO;
HRESULT DUIXmlParser::InitializeParserFromXmlReader(IXmlReader* pReader, HINSTANCE hResourceInstance, HINSTANCE hControlsInstance) STUB_ZERO;
HRESULT DUIXmlParser::ParseStyleSheets(IXmlReader* pReader) STUB_ZERO;
HRESULT DUIXmlParser::ParseStyleSheets() STUB_ZERO;
HRESULT DUIXmlParser::_EnterOnCurrentThread() STUB_ZERO;
void DUIXmlParser::_LeaveOnCurrentThread() STUB_VOID;
HRESULT DUIXmlParser::GetXmlLiteDll(HMODULE* phXmlLiteDll) STUB_ZERO;
HRESULT DUIXmlParser::CreateXmlReader(IXmlReader** ppReader) STUB_ZERO;
HRESULT DUIXmlParser::CreateXmlReaderFromHGLOBAL(HGLOBAL hglob, IXmlReader** ppReader) STUB_ZERO;
HRESULT DUIXmlParser::CreateXmlReaderInputWithEncodingName(IStream* pInput, const WCHAR* pszEncodingName, IUnknown** ppReaderInput) STUB_ZERO;
HRESULT DUIXmlParser::_SetXMLFromResource(const WCHAR* pszResource, const WCHAR* pszResType, HINSTANCE hResourceInstance, HINSTANCE hControlsInstance, HINSTANCE hResTheme) STUB_ZERO;
HRESULT DUIXmlParser::_SetBinaryXml(const BYTE* pBuffer, UINT cbBuffer, HINSTANCE hControlsInstance) STUB_ZERO;
HRESULT DUIXmlParser::_BuildFromBinary(Element* peSub, Element* peParent, const WCHAR* pszResource, DWORD* pdwDefer, Element** ppElement) STUB_ZERO;
HRESULT DUIXmlParser::_BuildElement(IXmlReader* pReader, Element* peParent, Element** ppElement) STUB_ZERO;
HRESULT DUIXmlParser::_BuildChildren(IXmlReader* pReader, Element* peParent) STUB_ZERO;
HRESULT DUIXmlParser::_SetProperties(IXmlReader* pReader, IClassInfo* pClassInfo, Element* peTarget) STUB_ZERO;
HRESULT DUIXmlParser::_ParseLayout(const WCHAR* pszLayoutString, Value** ppvLayout) STUB_ZERO;
HRESULT DUIXmlParser::_ParseBehavior(Element* pTarget, const WCHAR* pszBehavior) STUB_ZERO;
HRESULT DUIXmlParser::_CreateValue(const WCHAR* pszValue, const PropertyInfo* pPropInfo, Value** ppValue) STUB_ZERO;
HRESULT DUIXmlParser::_GetClassForElement(IXmlReader* pReader, IClassInfo** ppClassInfo) STUB_ZERO;
HRESULT DUIXmlParser::_GetClassForElementByName(const WCHAR* pszName, IClassInfo** ppClassInfo) STUB_ZERO	;
HRESULT DUIXmlParser::_GetPropertyForAttribute(IXmlReader* pReader, IClassInfo* pClassInfo, const PropertyInfo** ppPropInfo) STUB_ZERO;
HRESULT DUIXmlParser::_BuildStyles(IXmlReader* pReader) STUB_ZERO;
HRESULT DUIXmlParser::_GetValueForStyleSheet(IClassInfo* pClassInfo, const WCHAR* pszName, const WCHAR* pszValue, const PropertyInfo** ppPropInfo, Value** ppValue) STUB_ZERO;
LINEINFO DUIXmlParser::_GetLineInfo(IXmlReader* pReader) STUB_ZERO;
HRESULT DUIXmlParser::_SetupParserState(HINSTANCE hResourceInstance, HINSTANCE hControlsInstance) STUB_ZERO;
HRESULT DUIXmlParser::_RecordElementTrees(IXmlReader* pReader) STUB_ZERO;
HRESULT DUIXmlParser::_RecordElementWithChildren(IXmlReader* pReader, bool fEmptyElem, WCHAR** ppszElemName) STUB_ZERO;
HRESULT DUIXmlParser::_RecordInstantiateElement(IXmlReader* pReader, WCHAR** ppszElemName) STUB_ZERO;
HRESULT DUIXmlParser::_RecordSetElementProperties(IXmlReader* pReader) STUB_ZERO;
HRESULT DUIXmlParser::_RecordElementLayout(IXmlReader* pReader, const WCHAR* pszValue) STUB_ZERO;
HRESULT DUIXmlParser::_RecordElementBehaviors(IXmlReader* pReader, const WCHAR* pszValue) STUB_ZERO;
HRESULT DUIXmlParser::_RecordSetValue(IXmlReader* pReader, const WCHAR* pszName, const WCHAR* pszValue) STUB_ZERO;
HRESULT DUIXmlParser::_RecordElementStyleSheet(const WCHAR* pszSheetName, bool fIgnoreMissingSheet) STUB_ZERO;
HRESULT DUIXmlParser::CreateStyleSheet(IXmlReader* pReader, const WCHAR* pszSheetResid, StyleSheet** ppSheet) STUB_ZERO;
HRESULT DUIXmlParser::AddRulesToStyleSheet(IXmlReader* pReader, StyleSheet* pSheet, const WCHAR* pszSheetResid, DynamicArray<XMLParserCond>* pdaXMLConds, DynamicArray<WCHAR*>* pdaCondStrings) STUB_ZERO;
HRESULT DUIXmlParser::_ResolveStyleSheet(const WCHAR* pszReference, Value** ppvSheet, UINT* pSheetId) STUB_ZERO;
HRESULT DUIXmlParser::MapPropertyNameToPropertyInfo(LINEINFO li, IClassInfo* pci, const WCHAR* pszName, const PropertyInfo** ppInfo) STUB_ZERO;
HRESULT DUIXmlParser::GetPropValPairInfo(LINEINFO li, IClassInfo* pci, const WCHAR* pszProperty, const WCHAR* pszValue, const PropertyInfo** ppInfo, Value** ppValue) STUB_ZERO;
HRESULT DUIXmlParser::GetPropValPairInfo(IXmlReader* pReader, IClassInfo* pci, const WCHAR* pszProperty, const WCHAR* pszValue, const PropertyInfo** ppInfo, Value** ppValue) STUB_ZERO;
HRESULT DUIXmlParser::_ParseValue(const PropertyInfo* ppi, WCHAR* pszValue, Value** ppValue) STUB_ZERO;
void DUIXmlParser::SendParseError(const WCHAR* pszError, const WCHAR* pszToken, int dLine, int dCol, HRESULT hr) STUB_VOID;
void DUIXmlParser::SendParseError(const WCHAR* pszError, const WCHAR* pszToken, IXmlReader* pReader, HRESULT hr) STUB_VOID;
int DUIXmlParser::QuerySysMetric(int idx, bool* pfDynamicScaling) STUB_ZERO;
const WCHAR* DUIXmlParser::QuerySysMetricStr(int idx, WCHAR* pszMetric, UINT c) STUB_ZERO;
HRESULT DUIXmlParser::ParseArgs(const ParserTools::ExprNode* pen, ParsedArg* rgpa, UINT cpa, const CHAR* pszSignature) STUB_ZERO;
HRESULT DUIXmlParser::ParseFunction(const WCHAR* pszName, const ParserTools::ExprNode* pen, ParsedArg* rgpa, UINT cpa, const CHAR* pszSignature) STUB_ZERO;
bool DUIXmlParser::IsThemeClassName(const ParserTools::ExprNode* pen) STUB_ZERO;
HRESULT DUIXmlParser::ParseMagnitude(const WCHAR* pszMag, int* pMagOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseMagnitudeFloat(const WCHAR* pszMag, float* pMagOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseLiteralNumber(const WCHAR* psz, int* pnOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseColorInt(const WCHAR*, int*) STUB_ZERO;
HRESULT DUIXmlParser::ParseLiteralColorInt(const WCHAR* pszValue, int* piOut) STUB_ZERO;
HRESULT DUIXmlParser::ParseLiteralColor(const WCHAR* pszValue, COLORREF* pclrOut) STUB_ZERO;
HRESULT DUIXmlParser::ParseSysMetricInt(const ParserTools::ExprNode* pen, int* piOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseGTMetInt(const ParserTools::ExprNode* pen, int* piOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseARGBColor(const ParserTools::ExprNode* pen, COLORREF* pclrOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseRGBColor(const ParserTools::ExprNode* pen, COLORREF* pclrOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseGTCColor(const ParserTools::ExprNode* pen, COLORREF* pclrOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseResStr(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseSysMetricStr(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseGTFStr(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseRectRect(const ParserTools::ExprNode* pen, ScaledRECT* prcOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseGTMarRect(const ParserTools::ExprNode* pen, ScaledRECT* prcOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseSizeSize(const ParserTools::ExprNode* pen, ScaledSIZE* pszOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseGTPartSize(const ParserTools::ExprNode* pen, ScaledSIZE* pszOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseSGraphicHelper(bool, const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseSGraphicGraphic(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseGraphicHelper(bool fGraphic, const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseGraphicGraphic(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseImageGraphic(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseIconGraphic(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseLiteral(const ParserTools::ExprNode* pen, const WCHAR** ppszOut) STUB_ZERO;
HRESULT DUIXmlParser::ParseNumber(const ParserTools::ExprNode* pen, int* pnOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseFloat(const ParserTools::ExprNode* pen, float* pflOut, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseColor(const ParserTools::ExprNode* pen, COLORREF* pclrOut) STUB_ZERO;
HRESULT DUIXmlParser::ParseQuotedString(const ParserTools::ExprNode* pen, WCHAR** ppszOut) STUB_ZERO;
HRESULT DUIXmlParser::ParseResid(const ParserTools::ExprNode* pen, const WCHAR** ppszOut) STUB_ZERO;
HRESULT DUIXmlParser::ParseTheme(const ParserTools::ExprNode* pen, bool use96dpi, HTHEME* phtheme) STUB_ZERO;
HRESULT DUIXmlParser::ParseLibrary(const ParserTools::ExprNode* pen, HMODULE* phmod) STUB_ZERO;
HRESULT DUIXmlParser::ParseRect(const ParserTools::ExprNode* pen, ScaledRECT* prcOut) STUB_ZERO;
HRESULT DUIXmlParser::ParseSize(const ParserTools::ExprNode* pen, ScaledSIZE* pszOut) STUB_ZERO;
HRESULT DUIXmlParser::ParseGradientFill(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseDFCFill(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::ParseDTBFill(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling) STUB_ZERO;
HRESULT DUIXmlParser::CreateLayout(const ParserTools::ExprNode* pen, PLAYTCREATE pfnCreate) STUB_ZERO;
HRESULT DUIXmlParser::ParseIntValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseFloatValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseBoolValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseStringValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseRectValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseSizeValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParsePointValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseFillValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseLayoutValue(const ParserTools::ExprNode* pen) STUB_ZERO;
HRESULT DUIXmlParser::ParseGraphicValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseSheetValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseAtomValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseCursorValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseBehaviorArgValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::ParseBehavior(const ParserTools::ExprNode* pen) STUB_ZERO;
HRESULT DUIXmlParser::ParseDoubleListValue(const ParserTools::ExprNode* pen, Value** ppVal) STUB_ZERO;
HRESULT DUIXmlParser::MapPropertyEnumValue(const EnumMap* pMap, const WCHAR* pszValue, int* piVal) STUB_ZERO;
HRESULT DUIXmlParser::GetValueParser(ParserTools::ValueParser** ppvp) STUB_ZERO;
void DUIXmlParser::ReturnValueParser(ParserTools::ValueParser* pvp) STUB_VOID;
HRESULT DUIXmlParser::GetParserCommon(DUIXmlParser** ppParserCommon) STUB_ZERO;
float DUIXmlParser::_ScaleRelativePixels(float nRelPix) STUB_ZERO;
int DUIXmlParser::_ScaleRelativePixels(int nRelPix) STUB_ZERO;
float DUIXmlParser::_ScalePointsToPixels(float flPoint) STUB_ZERO;
int DUIXmlParser::_ScalePointsToPixels(int nPoint) STUB_ZERO;
void DUIXmlParser::SetParseState(DUI_PARSE_STATE eParseState) STUB_VOID;
//~ End DirectUI::DUIXmlParser Class

//~ Begin DirectUI::NativeHWNDHost Class
UINT NativeHWNDHost::DestroyMsg() STUB_ZERO;
HRESULT NativeHWNDHost::Create(const WCHAR* pszTitle, HWND hWndParent, HICON hIcon, int dX, int dY, int dWidth, int dHeight, int iExStyle, int iStyle, UINT nOptions, NativeHWNDHost** ppHost) STUB_ZERO;
HRESULT NativeHWNDHost::Create(const WCHAR* pszClassName, const WCHAR* pszTitle, HWND hWndParent, HICON hIcon, int dX, int dY, int dWidth, int dHeight, int iExStyle, int iStyle, HINSTANCE hInstance, UINT nOptions, NativeHWNDHost** ppHost) STUB_ZERO;
void NativeHWNDHost::Destroy() STUB_VOID;
HWND NativeHWNDHost::GetHWND() STUB_ZERO;
Element* NativeHWNDHost::GetElement() STUB_ZERO;
void NativeHWNDHost::Host(Element* pe) STUB_VOID;
void NativeHWNDHost::ShowWindow(int iShow) STUB_VOID;
void NativeHWNDHost::HideWindow() STUB_VOID;
void NativeHWNDHost::DestroyWindow() STUB_VOID;
void NativeHWNDHost::SyncDestroyWindow() STUB_VOID;
LRESULT NativeHWNDHost::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) STUB_ZERO;
NativeHWNDHost::NativeHWNDHost() STUB_VOID;
HRESULT NativeHWNDHost::Initialize(const WCHAR* pszTitle, HWND hWndParent, HICON hIcon, int dX, int dY, int dWidth, int dHeight, int iExStyle, int iStyle, UINT nOptions) STUB_ZERO;
HRESULT NativeHWNDHost::Initialize(const WCHAR* pszClassName, const WCHAR* pszTitle, HWND hWndParent, HICON hIcon, int dX, int dY, int dWidth, int dHeight, int iExStyle, int iStyle, HINSTANCE hInstance, UINT nOptions) STUB_ZERO;
NativeHWNDHost::~NativeHWNDHost() STUB_VOID;
void NativeHWNDHost::SetDefaultFocusID(const WCHAR*) STUB_VOID;
void NativeHWNDHost::SaveFocus() STUB_VOID;
int NativeHWNDHost::RestoreFocus() STUB_ZERO;
HWND NativeHWNDHost::CreateHostWindow(DWORD dwExStyle, const WCHAR* lpClassName, const WCHAR* lpWindowName, DWORD dwStyle, int nX, int nY, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam) STUB_ZERO;
HRESULT NativeHWNDHost::OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
//~ End DirectUI::NativeHWNDHost Class

//~ Begin DirectUI::HWNDHostAccessible Class
HRESULT HWNDHostAccessible::Create(Element* pe, IAccessible* pCtrl, DuiAccessible** ppDA) STUB_ZERO;
HWNDHostAccessible::HWNDHostAccessible() STUB_VOID;
HRESULT HWNDHostAccessible::Disconnect() STUB_ZERO;
HRESULT HWNDHostAccessible::Initialize(Element* pe, IAccessible* pCtrl) STUB_ZERO;
HWNDHostAccessible::~HWNDHostAccessible() STUB_VOID;
HRESULT HWNDHostAccessible::QueryInterface(REFIID riid, void** ppvObj) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accParent(IDispatch** ppdispParent) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accChildCount(long* pcountChildren) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accChild(VARIANT varChild, IDispatch** ppdispChild) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accName(VARIANT varChild, BSTR* pszName) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accValue(VARIANT varChild, BSTR* pszValue) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accDescription(VARIANT varChild, BSTR* pszDescription) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accRole(VARIANT varChild, VARIANT* pvarRole) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accState(VARIANT varChild, VARIANT* pvarState) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accHelp(VARIANT varChild, BSTR* pszHelp) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accHelpTopic(BSTR* pszHelpFile, VARIANT varChild, long* pidTopic) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accKeyboardShortcut(VARIANT varChild, BSTR* pszKeyboardShortcut) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accFocus(VARIANT* pvarChild) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accSelection(VARIANT* pvarChildren) STUB_ZERO;
HRESULT HWNDHostAccessible::get_accDefaultAction(VARIANT varChild, BSTR* pszDefaultAction) STUB_ZERO;
HRESULT HWNDHostAccessible::accSelect(long flagsSelect, VARIANT varChild) STUB_ZERO;
HRESULT HWNDHostAccessible::accLocation(long* pxLeft, long* pyTop, long* pcxWidth, long* pcyHeight, VARIANT varChild) STUB_ZERO;
HRESULT HWNDHostAccessible::accNavigate(long navDir, VARIANT varStart, VARIANT* pvarEndUpAt) STUB_ZERO;
HRESULT HWNDHostAccessible::accHitTest(long xLeft, long yTop, VARIANT* pvarChild) STUB_ZERO;
HRESULT HWNDHostAccessible::accDoDefaultAction(VARIANT varChild) STUB_ZERO;
HRESULT HWNDHostAccessible::put_accName(VARIANT varChild, BSTR szName) STUB_ZERO;
HRESULT HWNDHostAccessible::put_accValue(VARIANT varChild, BSTR szValue) STUB_ZERO;
HRESULT HWNDHostAccessible::Next(ULONG celt, VARIANT* rgVar, ULONG* pCeltFetched) STUB_ZERO;
HRESULT HWNDHostAccessible::Skip(ULONG celt) STUB_ZERO;
HRESULT HWNDHostAccessible::Reset() STUB_ZERO;
HRESULT HWNDHostAccessible::Clone(IEnumVARIANT** ppEnum) STUB_ZERO;
HRESULT HWNDHostAccessible::GetWindow(HWND* phwnd) STUB_ZERO;
HRESULT HWNDHostAccessible::ContextSensitiveHelp(BOOL fEnterMode) STUB_ZERO;
HRESULT HWNDHostAccessible::GetIdentityString(DWORD dwIDChild, BYTE** ppIDString, DWORD* pdwIDStringLen) STUB_ZERO;
HRESULT HWNDHostAccessible::QueryService(REFGUID guidService, REFIID riid, void** ppvObject) STUB_ZERO;
//~ End DirectUI::HWNDHostAccessible Class

//~ Begin DirectUI::HWNDHostClientAccessible Class
HRESULT HWNDHostClientAccessible::Create(Element* pe, IAccessible* pCtrl, DuiAccessible** ppDA) STUB_ZERO;
HRESULT HWNDHostClientAccessible::get_accParent(IDispatch** ppdispParent) STUB_ZERO;
HRESULT HWNDHostClientAccessible::get_accRole(VARIANT varChild, VARIANT* pvarRole) STUB_ZERO;
HRESULT HWNDHostClientAccessible::accNavigate(long navDir, VARIANT varStart, VARIANT* pvarEndUpAt) STUB_ZERO
//~ End DirectUI::HWNDHostClientAccessible Class

//~ Begin DirectUI::HWNDElementAccessible Class
HRESULT HWNDElementAccessible::Create(HWNDElement* pe, DuiAccessible** ppDA) STUB_ZERO;
HWNDElementAccessible::HWNDElementAccessible() STUB_VOID;
HRESULT HWNDElementAccessible::Disconnect() STUB_ZERO;
HRESULT HWNDElementAccessible::Initialize(HWNDElement* pe) STUB_ZERO;
HWNDElementAccessible::~HWNDElementAccessible() STUB_VOID;
HRESULT HWNDElementAccessible::get_accParent(IDispatch** ppdispParent) STUB_ZERO;
//~ End DirectUI::HWNDElementAccessible Class

//~ Begin DirectUI::AccessibleButton Class
HRESULT AccessibleButton::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT AccessibleButton::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
void AccessibleButton::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void AccessibleButton::Recalc() STUB_VOID;
IClassInfo* AccessibleButton::GetClassInfoPtr() STUB_ZERO;
void AccessibleButton::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* AccessibleButton::s_pClassInfo;
IClassInfo* AccessibleButton::GetClassInfoW() STUB_ZERO;
HRESULT AccessibleButton::Register() STUB_ZERO;
AccessibleButton::AccessibleButton() STUB_VOID;

const DirectUI::AccessibleButton::ACCESSIBLEROLE c_rgar[] =
{
  { 43, 0, -792, 0, -792 },
  { 44, 0, -791, 16, -790 },
  { 45, 0, -791, 16, -791 },
  { 64, 1024, -795, 512, -794 },
  { 30, 4194304, -793, 4194304, -793 }
};

const AccessibleButton::ACCESSIBLEROLE* AccessibleButton::FindAccessibleRole(int role) STUB_ZERO;
void AccessibleButton::UpdateState(ACCESSIBLEROLE*) STUB_VOID;
//~ End DirectUI::AccessibleButton Class

//~ Begin DirectUI::AutoButton Class
HRESULT AutoButton::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT AutoButton::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
void AutoButton::OnEvent(Event* pEvent) STUB_VOID;
UID AutoButton::Toggle() STUB_ZERO;
IClassInfo* AutoButton::GetClassInfoPtr() STUB_ZERO;
void AutoButton::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* AutoButton::s_pClassInfo;
IClassInfo* AutoButton::GetClassInfoW() STUB_ZERO;
HRESULT AutoButton::Register() STUB_ZERO;
//~ End DirectUI::AutoButton Class

//~ Begin DirectUI::AutoLock Class
AutoLock::AutoLock(CRITICAL_SECTION* pacs) STUB_VOID;
AutoLock::~AutoLock() STUB_VOID;
//~ End DirectUI::AutoLock Class

//~ Begin DirectUI::AutoThread Class
AutoThread::AutoThread() STUB_VOID
AutoThread::~AutoThread() STUB_VOID
HRESULT AutoThread::Init() STUB_ZERO
//~ End DirectUI::AutoThread Class

//~ Begin DirectUI::AutoVariant Class
AutoVariant::AutoVariant() STUB_VOID
AutoVariant::~AutoVariant() STUB_VOID
//~ End DirectUI::AutoVariant Class

//~ Begin DirectUI::Layout Class
HRESULT Layout::Create(Layout** ppLayout) STUB_ZERO;
void Layout::Destroy() STUB_VOID;
void Layout::DoLayout(Element* pec, int dWidth, int dHeight) STUB_VOID;
SIZE Layout::UpdateDesiredSize(Element* pec, int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
void Layout::OnAdd(Element* pec, Element** ppeAdd, UINT cCount) STUB_VOID;
void Layout::OnRemove(Element* pec, Element** ppeRemove, UINT cCount) STUB_VOID;
void Layout::OnLayoutPosChanged(Element* pec, Element* peChanged, int dOldLP, int dNewLP) STUB_VOID;
void Layout::Attach(Element* pec) STUB_VOID;
void Layout::Detach(Element* pec) STUB_VOID;
UINT Layout::GetLayoutChildCount(Element* pec) STUB_ZERO;
int Layout::GetLayoutIndexFromChild(Element* pec, Element* peChild) STUB_ZERO;
Element* Layout::GetChildFromLayoutIndex(Element* pec, int iLayoutIdx, DynamicArray<Element*>* peList) STUB_ZERO;
Element* Layout::GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
Layout::Layout() STUB_VOID;
void Layout::Initialize() STUB_VOID;
Layout::~Layout() STUB_VOID;
void Layout::UpdateLayoutRect(Element* pec, int cxContainer, int cyContainer, Element* peChild, int xElement, int yElement, int cxElement, int cyElement) STUB_VOID;
bool Layout::IsCacheDirty() STUB_ZERO;
void Layout::SetCacheDirty() STUB_VOID;
void Layout::ClearCacheDirty() STUB_VOID;
//~ End DirectUI::Layout Class

//~ Begin DirectUI::BorderLayout Class
HRESULT BorderLayout::Create(int dNumParams, int* pParams, Value** ppValue) STUB_ZERO;
HRESULT BorderLayout::Create(Layout** ppLayout) STUB_ZERO;
void BorderLayout::DoLayout(Element* pec, int cx, int cy) STUB_VOID;
SIZE BorderLayout::UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
void BorderLayout::OnAdd(Element* pec, Element** ppeAdd, UINT cCount) STUB_VOID;
void BorderLayout::OnRemove(Element* pec, Element** ppeRemove, UINT cCount) STUB_VOID;
void BorderLayout::OnLayoutPosChanged(Element* pec, Element* peChanged, int dOldLP, int dNewLP) STUB_VOID;
Element* BorderLayout::GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
BorderLayout::BorderLayout() STUB_VOID;
void BorderLayout::Initialize() STUB_VOID;
BorderLayout::~BorderLayout() STUB_VOID;
SIZE BorderLayout::GetMaxCenter(Element* pec, int x, int y, int cw, int ch, int mTop, int mLeft, int mRight, int mBottom, bool setValues, HDC hDC) STUB_ZERO;
SIZE BorderLayout::GetMaxLeftRight(Element* pec, int current, int x, int y, int cw, int ch, int mTop, int mLeft, int mRight, int mBottom, bool setValues, HDC hDC) STUB_ZERO;
SIZE BorderLayout::GetMaxTopBottom(Element* pec, int current, int x, int y, int cw, int ch, int mTop, int mLeft, int mRight, int mBottom, bool setValues, HDC hDC) STUB_ZERO;
int BorderLayout::NextChild(int i, Element* pec, Element** ppeCurrent, int* playoutPos) STUB_ZERO;
void BorderLayout::SetClient(Element* pe) STUB_VOID;
//~ End DirectUI::BorderLayout Class

//~ Begin DirectUI::FillLayout Class
HRESULT FillLayout::Create(int dNumParams, int* pParams, Value** ppValue) STUB_ZERO;
HRESULT FillLayout::Create(Layout** ppLayout) STUB_ZERO;
void FillLayout::DoLayout(Element* pec, int cx, int cy) STUB_VOID;
SIZE FillLayout::UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
Element* FillLayout::GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
FillLayout::FillLayout() STUB_VOID;
void FillLayout::Initialize() STUB_VOID;
FillLayout::~FillLayout() STUB_VOID;
//~ End DirectUI::FillLayout Class

//~ Begin DirectUI::GridLayout Class
HRESULT GridLayout::Create(int dNumParams, int* pParams, Value** ppValue) STUB_ZERO;
HRESULT GridLayout::Create(int iRows, int iCols, Layout** ppLayout) STUB_ZERO;
void GridLayout::DoLayout(Element* pec, int cx, int cy) STUB_VOID;
SIZE GridLayout::UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
Element* GridLayout::GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
GridLayout::GridLayout() STUB_VOID;
void GridLayout::Initialize(int iRows, int iCols) STUB_VOID;
GridLayout::~GridLayout() STUB_VOID;
UINT GridLayout::GetCurrentRows(Element* pec) STUB_ZERO;
UINT GridLayout::GetCurrentRows(int c) STUB_ZERO;
UINT GridLayout::GetCurrentCols(Element* pec) STUB_ZERO;
UINT GridLayout::GetCurrentCols(int c) STUB_ZERO;
//~ End DirectUI::GridLayout Class

//~ Begin DirectUI::FlowLayout Class
HRESULT FlowLayout::Create(int dNumParams, int* pParams, Value** ppValue) STUB_ZERO;
HRESULT FlowLayout::Create(bool fWrap, UINT uYAlign, UINT uXLineAlign, UINT uYLineAlign, Layout** ppLayout) STUB_ZERO;
void FlowLayout::DoLayout(Element* pec, int cx, int cy) STUB_VOID;
SIZE FlowLayout::UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
Element* FlowLayout::GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
int FlowLayout::GetLine(Element* pec, Element* pe) STUB_ZERO;
FlowLayout::FlowLayout() STUB_VOID;
void FlowLayout::Initialize(bool fWrap, UINT uYAlign, UINT uXLineAlign, UINT uYLineAlign) STUB_VOID;
FlowLayout::~FlowLayout() STUB_VOID;
SIZE BuildCacheInfo(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf, bool fRealSize) STUB_ZERO;
SIZE SizeZero() STUB_ZERO;
//~ End DirectUI::FlowLayout Class

//~ Begin DirectUI::RowLayout Class
HRESULT RowLayout::Create(int dNumParams, int* pParams, Value** ppValue) STUB_ZERO;
HRESULT RowLayout::Create(UINT uXAlign, UINT uYAlign, Layout** ppLayout) STUB_ZERO;
HRESULT RowLayout::Create(int idShare, UINT uXAlign, UINT uYAlign, Layout** ppLayout) STUB_ZERO;
void RowLayout::DoLayout(Element* pec, int cx, int cy) STUB_VOID;
SIZE RowLayout::UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
Element* RowLayout::GetAdjacent(Element* pec, Element*, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
RowLayout::RowLayout() STUB_VOID;
HRESULT RowLayout::Initialize(int idShare, UINT uXAlign, UINT uYAlign) STUB_ZERO;
RowLayout::~RowLayout() STUB_VOID;
//~ End DirectUI::RowLayout Class

//~ Begin DirectUI::NineGridLayout Class
HRESULT NineGridLayout::Create(int dNumParams, int* pParams, Value** ppValue) STUB_ZERO;
HRESULT NineGridLayout::Create(Layout** ppLayout) STUB_ZERO;
void NineGridLayout::DoLayout(Element* pec, int cx, int cy) STUB_VOID;
SIZE NineGridLayout::UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
void NineGridLayout::OnAdd(Element* pec, Element** ppeAdd, UINT cCount) STUB_VOID;
void NineGridLayout::OnRemove(Element* pec, Element** ppeRemove, UINT cCount) STUB_VOID;
void NineGridLayout::OnLayoutPosChanged(Element* pec, Element* peChanged, int dOldLP, int dNewLP) STUB_VOID;
Element* NineGridLayout::GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
NineGridLayout::NineGridLayout() STUB_VOID;
void NineGridLayout::Initialize() STUB_VOID;
NineGridLayout::~NineGridLayout() STUB_VOID;
void NineGridLayout::_UpdateTileList(int iTile, Element* pe) STUB_VOID;
//~ End DirectUI::NineGridLayout Class

//~ Begin DirectUI::ShellBorderLayout Class
HRESULT ShellBorderLayout::Create(int dNumParams, int* pParams, Value** ppValue) STUB_ZERO;
HRESULT ShellBorderLayout::Create(Layout** ppLayout) STUB_ZERO;
void ShellBorderLayout::OnAdd(Element* pec, Element** ppeAdd, UINT cCount) STUB_VOID;
void ShellBorderLayout::OnRemove(Element* pec, Element** ppeRemove, UINT cCount) STUB_VOID;
void ShellBorderLayout::OnLayoutPosChanged(Element* pec, Element* peChanged, int dOldLP, int dNewLP) STUB_VOID;
Element* ShellBorderLayout::GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
ShellBorderLayout::ShellBorderLayout() STUB_VOID;
ShellBorderLayout::~ShellBorderLayout() STUB_VOID;
void ShellBorderLayout::_Reset() STUB_VOID;
HRESULT ShellBorderLayout::_CalcTabOrder(Element* pec) STUB_ZERO;
//~ End DirectUI::ShellBorderLayout Class

//~ Begin DirectUI::TableLayout
HRESULT TableLayout::Create(int dNumParams, int* pParams, Value** ppValue) STUB_ZERO;
void TableLayout::DoLayout(Element* pec, int cx, int cy) STUB_VOID;
SIZE TableLayout::UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
Element* TableLayout::GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
HRESULT TableLayout::InternalCreate(int flags, int cxMinWidth, int dNumParams, int* pParams, Layout** ppLayout) STUB_ZERO;
void TableLayout::Initialize(int flags, int cxMinWidth, int dNumParams, int* pParams) STUB_VOID;
TableLayout::~TableLayout() STUB_VOID;
CellInfo* TableLayout::GetCellInfo(int nColumn) STUB_ZERO;
//~ End DirectUI::TableLayout Class

//~ Begin DirectUI::VerticalFlowLayout Class
HRESULT VerticalFlowLayout::Create(int dNumParams, int* pParams, Value** ppValue) STUB_ZERO;
HRESULT VerticalFlowLayout::Create(bool fWrap, UINT uXAlign, UINT uXLineAlign, UINT uYLineAlign, Layout** ppLayout) STUB_ZERO;
void VerticalFlowLayout::DoLayout(Element* pec, int cx, int cy) STUB_VOID;
SIZE VerticalFlowLayout::UpdateDesiredSize(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
Element* VerticalFlowLayout::GetAdjacent(Element* pec, Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
int VerticalFlowLayout::GetLine(Element* pec, Element* pe) STUB_ZERO;
VerticalFlowLayout::VerticalFlowLayout() STUB_VOID;
void VerticalFlowLayout::Initialize(bool fWrap, UINT uXAlign, UINT uXLineAlign, UINT uYLineAlign) STUB_VOID;
VerticalFlowLayout::~VerticalFlowLayout() STUB_VOID;
SIZE VerticalFlowLayout::BuildCacheInfo(Element* pec, int cxConstraint, int cyConstraint, Surface* psrf, bool fRealSize) STUB_ZERO;
SIZE VerticalFlowLayout::SizeZero() STUB_ZERO;
//~ End DirectUI::VerticalFlowLayout Class

//~ Begin DirectUI::AnimationStrip Class
HRESULT AnimationStrip::LoadCommonControlExports() STUB_ZERO;
void AnimationStrip::UnloadCommonControlExports() STUB_VOID;
HRESULT AnimationStrip::Start() STUB_ZERO;
void AnimationStrip::Stop() STUB_VOID;
IClassInfo* AnimationStrip::GetClassInfoPtr() STUB_ZERO;
void AnimationStrip::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* AnimationStrip::s_pClassInfo;
IClassInfo* AnimationStrip::GetClassInfoW() STUB_ZERO;
HRESULT AnimationStrip::Register() STUB_ZERO;
HRESULT AnimationStrip::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT AnimationStrip::Initialize(UINT) STUB_ZERO;
HRESULT AnimationStrip::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
AnimationStrip::AnimationStrip() STUB_VOID;
AnimationStrip::~AnimationStrip() STUB_VOID;
const PropertyInfo* AnimationStrip::FrameWidthProp() STUB_ZERO;
const PropertyInfo* AnimationStrip::FrameDurationProp() STUB_ZERO;
const PropertyInfo* AnimationStrip::FrameIndexProp() STUB_ZERO;
const PropertyInfo* AnimationStrip::PlayProp() STUB_ZERO;
int AnimationStrip::GetFrameWidth() STUB_ZERO;
int AnimationStrip::GetFrameDuration() STUB_ZERO;
int AnimationStrip::GetFrameIndex() STUB_ZERO;
bool AnimationStrip::GetPlay() STUB_ZERO;
HRESULT AnimationStrip::SetFrameWidth(int v) STUB_ZERO;
HRESULT AnimationStrip::SetFrameDuration(int v) STUB_ZERO;
HRESULT AnimationStrip::SetFrameIndex(int v) STUB_ZERO;
HRESULT AnimationStrip::SetPlay(bool v) STUB_ZERO;
void AnimationStrip::Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) STUB_VOID;
void AnimationStrip::OnDestroy() STUB_VOID;
void AnimationStrip::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
HRESULT AnimationStrip::LoadImagesIntoAnimationStrip() STUB_ZERO;
void AnimationStrip::AdvanceFrame() STUB_VOID;
void AnimationStrip::OnAction(GMA_ACTIONINFO* pActionInfo) STUB_VOID;
void AnimationStrip::RawActionProc(GMA_ACTIONINFO* pActionInfo) STUB_VOID;
//~ End DirectUI::AnimationStrip Class

//~ Begin DirectUI::ClassInfoBase Class
ClassInfoBase::ClassInfoBase() STUB_VOID;
ClassInfoBase::~ClassInfoBase() STUB_VOID;
HRESULT ClassInfoBase::Initialize(HINSTANCE hModule, const WCHAR* pszName, bool fGlobal, const PropertyInfo* const* ppPI, UINT cPI) STUB_ZERO;
HRESULT ClassInfoBase::Register() STUB_ZERO;
bool ClassInfoBase::ClassExist(IClassInfo** ppCI, const PropertyInfo* const* ppPI, UINT cPI, IClassInfo* pCIBase, HMODULE hModule, const WCHAR* pszName, bool fGlobal) STUB_ZERO;
void ClassInfoBase::AddRef() STUB_VOID;
int ClassInfoBase::Release() STUB_ZERO;
const PropertyInfo* ClassInfoBase::EnumPropertyInfo(UINT) STUB_ZERO;
const PropertyInfo* ClassInfoBase::GetByClassIndex(UINT) STUB_ZERO;
UINT ClassInfoBase::GetPICount() const STUB_ZERO;
UINT ClassInfoBase::GetGlobalIndex() const STUB_ZERO;
const WCHAR* ClassInfoBase::GetName() const STUB_ZERO;
bool ClassInfoBase::IsValidProperty(const PropertyInfo* ppi) const STUB_ZERO;
bool ClassInfoBase::IsSubclassOf(IClassInfo* pci) const STUB_ZERO;
void ClassInfoBase::Destroy() STUB_VOID;
HINSTANCE ClassInfoBase::GetModule() const STUB_ZERO;
bool ClassInfoBase::IsGlobal() const STUB_ZERO;
void ClassInfoBase::AddChild() STUB_VOID;
void ClassInfoBase::RemoveChild() STUB_VOID;
int ClassInfoBase::GetChildren() const STUB_ZERO;
void ClassInfoBase::AssertPIZeroRef() const STUB_VOID;
//~ End DirectUI::ClassInfoBase Class

//~ Begin DirectUI::BaseScrollBar Class
UID BaseScrollBar::Scroll() STUB_ZERO;
bool BaseScrollBar::OnPositionChanging(Value* pvNew) STUB_ZERO;
bool BaseScrollBar::OnPageChanging(Value* pvNew) STUB_ZERO;
void BaseScrollBar::OnPositionChanged(Value* pvNew) STUB_VOID;
void BaseScrollBar::OnMinimumChanged(Value* pvNew) STUB_VOID;
void BaseScrollBar::OnMaximumChanged(Value* pvNew) STUB_VOID;
void BaseScrollBar::OnPageChanged(Value* pvNew) STUB_VOID;
void BaseScrollBar::LineUp(UINT nCount) STUB_VOID;
void BaseScrollBar::LineDown(UINT nCount) STUB_VOID;
void BaseScrollBar::PageUp(UINT nCount) STUB_VOID;
void BaseScrollBar::PageDown(UINT nCount) STUB_VOID;
void BaseScrollBar::Home() STUB_VOID;
void BaseScrollBar::End() STUB_VOID;
bool BaseScrollBar::IsScrollable() STUB_ZERO;
bool BaseScrollBar::IsPinned() STUB_ZERO;
void BaseScrollBar::SetPinned(bool fPinned) STUB_VOID;
int BaseScrollBar::GetPageInc() STUB_ZERO;
//~ End DirectUI::BaseScrollBar Class

//~ Begin DirectUI::BaseScrollViewer Class
BaseScrollViewer::BaseScrollViewer() STUB_VOID;
BaseScrollViewer::~BaseScrollViewer() STUB_VOID;
HRESULT BaseScrollViewer::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
void BaseScrollViewer::OnEvent(Event* pEvent) STUB_VOID;
void BaseScrollViewer::OnInput(InputEvent* pie) STUB_VOID;
bool BaseScrollViewer::OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void BaseScrollViewer::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
HRESULT BaseScrollViewer::Add(Element** ppe, UINT cCount) STUB_ZERO;
void BaseScrollViewer::OnListenerAttach(Element* peFrom) STUB_VOID;
void BaseScrollViewer::OnListenerDetach(Element* peFrom) STUB_VOID;
bool BaseScrollViewer::OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void BaseScrollViewer::OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void BaseScrollViewer::OnListenedInput(Element* peFrom, InputEvent* pInput) STUB_VOID;
void BaseScrollViewer::OnListenedEvent(Element* peFrom, Event* pEvent) STUB_VOID;
const PropertyInfo* BaseScrollViewer::XOffsetProp() STUB_ZERO;
const PropertyInfo* BaseScrollViewer::YOffsetProp() STUB_ZERO;
const PropertyInfo* BaseScrollViewer::XScrollableProp() STUB_ZERO;
const PropertyInfo* BaseScrollViewer::YScrollableProp() STUB_ZERO;
const PropertyInfo* BaseScrollViewer::XBarVisibilityProp() STUB_ZERO;
const PropertyInfo* BaseScrollViewer::YBarVisibilityProp() STUB_ZERO;
const PropertyInfo* BaseScrollViewer::PinningProp() STUB_ZERO;
int BaseScrollViewer::GetXOffset() STUB_ZERO;
int BaseScrollViewer::GetYOffset() STUB_ZERO;
bool BaseScrollViewer::GetXScrollable() STUB_ZERO;
bool BaseScrollViewer::GetYScrollable() STUB_ZERO;
int BaseScrollViewer::GetXBarVisibility() STUB_ZERO;
int BaseScrollViewer::GetYBarVisibility() STUB_ZERO;
int BaseScrollViewer::GetPinning() STUB_ZERO;
int BaseScrollViewer::GetXScrollHeight() STUB_ZERO;
int BaseScrollViewer::GetYScrollWidth() STUB_ZERO;
HRESULT BaseScrollViewer::SetXOffset(int v) STUB_ZERO;
HRESULT BaseScrollViewer::SetYOffset(int v) STUB_ZERO;
HRESULT BaseScrollViewer::SetXScrollable(bool v) STUB_ZERO;
HRESULT BaseScrollViewer::SetYScrollable(bool v) STUB_ZERO;
HRESULT BaseScrollViewer::SetXBarVisibility(int v) STUB_ZERO;
HRESULT BaseScrollViewer::SetYBarVisibility(int v) STUB_ZERO;
HRESULT BaseScrollViewer::SetPinning(int v) STUB_ZERO;
IClassInfo* BaseScrollViewer::GetClassInfoPtr() STUB_ZERO;
void BaseScrollViewer::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* BaseScrollViewer::s_pClassInfo;
IClassInfo* BaseScrollViewer::GetClassInfoW() STUB_ZERO;
HRESULT BaseScrollViewer::Register() STUB_ZERO;
void BaseScrollViewer::FireAnimationChangeEvent(bool fStart) STUB_VOID;
void BaseScrollViewer::CheckScroll(BaseScrollBar* psb, BOOL fScrollable, int iVisibility, BOOL fPreventLoop) STUB_VOID;
//~ End DirectUI::BaseScrollViewer Class

//~ Begin DirectUI::Bind Class
HRESULT Bind::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT Bind::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
const PropertyInfo* Bind::ConnectProp() STUB_ZERO;
const PropertyInfo* Bind::PropertyProp() STUB_ZERO;
const WCHAR* Bind::GetConnect(Value** ppv) STUB_ZERO;
HRESULT Bind::SetConnect(const WCHAR* v) STUB_ZERO;
const WCHAR* Bind::GetProperty(Value** ppv) STUB_ZERO;
HRESULT Bind::SetProperty(const WCHAR* v) STUB_ZERO;
IClassInfo* Bind::GetClassInfoPtr() STUB_ZERO;
void Bind::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Bind::s_pClassInfo;
IClassInfo* Bind::GetClassInfoW() STUB_ZERO;
HRESULT Bind::Register() STUB_ZERO;
//~ End DirectUI::Bind Class

//~ Begin DirectUI::Browser Class
HRESULT Browser::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT Browser::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
UID Browser::StartNavigate() STUB_ZERO;
UID Browser::Entered() STUB_ZERO;
UID Browser::Leaving() STUB_ZERO;
void Browser::OnEvent(Event* pEvent) STUB_VOID;
void Browser::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
IClassInfo* Browser::GetClassInfoPtr() STUB_ZERO;
void Browser::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Browser::s_pClassInfo;
IClassInfo* Browser::GetClassInfoW() STUB_ZERO;
HRESULT Browser::Register() STUB_ZERO;
Element* Browser::GetCurrentPage() STUB_ZERO;
ATOM Browser::GetCurrentPageID() STUB_ZERO;
Pages* Browser::GetPages() STUB_ZERO;
int Browser::FireNavigate(ATOM aNewPage) STUB_ZERO;
//~ End DirectUI::Browser Class

//~ Begin DirectUI::CallstackTracker Class
CallstackTracker::CallstackTracker() STUB_VOID;
CallstackTracker::~CallstackTracker() STUB_VOID;
int CallstackTracker::CaptureCallstackFrames() STUB_ZERO;
int CallstackTracker::EnumCallstackFrames(PENUMFRAMESCALLBACK pfnEnumFramesCallback) STUB_ZERO;
int CallstackTracker::Init() STUB_ZERO;
void CallstackTracker::Uninit() STUB_VOID;
const int CallstackTracker::INITIALSTACKSKIP = 0;
const int CallstackTracker::STACKDEPTH = 0;
void CallstackTracker::FillSymbolInfo(STACK_SYMBOL_INFO* psi, DWORD_PTR dwAddr) STUB_VOID;
DWORD_PTR CallstackTracker::GetModuleBase(HANDLE hProcess, DWORD_PTR dwAddr) STUB_ZERO;

CallstackTracker::IMGHLPFN_LOAD CallstackTracker::s_ImageHlpFuncList[] =
{
	{ "ImagehlpApiVersionEx", (void**)&CallstackTracker::s_pfnImagehlpApiVersionEx },
	{ "SymGetModuleInfo64", (void**)&CallstackTracker::s_pfnSymGetModuleInfo64 },
	{ "SymFromAddr", (void**)&CallstackTracker::s_pfnSymFromAddr },
	{ "SymInitialize", (void**)&CallstackTracker::s_pfnSymInitialize },
	{ "SymLoadModule64", (void**)&CallstackTracker::s_pfnSymLoadModule64 },
	{ "SymSetOptions", (void**)&CallstackTracker::s_pfnSymSetOptions }
};

pfnNtDll_RtlCaptureStackBackTrace CallstackTracker::s_pfnRtlCaptureStackBackTrace;
pfnImgHlp_ImagehlpApiVersionEx CallstackTracker::s_pfnImagehlpApiVersionEx;
pfnImgHlp_SymGetModuleInfo64 CallstackTracker::s_pfnSymGetModuleInfo64;
pfnImgHlp_SymFromAddr CallstackTracker::s_pfnSymFromAddr;
pfnImgHlp_SymInitialize CallstackTracker::s_pfnSymInitialize;
pfnImgHlp_SymLoadModule64 CallstackTracker::s_pfnSymLoadModule64;
pfnImgHlp_SymSetOptions CallstackTracker::s_pfnSymSetOptions;
HINSTANCE CallstackTracker::s_hinstImageHlp;
HINSTANCE CallstackTracker::s_hinstNtDll;
RTL_RUN_ONCE CallstackTracker::s_initonceInit;
HANDLE CallstackTracker::s_hProcess;
BOOL CallstackTracker::DllsLoaded() STUB_ZERO;
int CallstackTracker::InitOnceCallback(RTL_RUN_ONCE*, void*, void**) STUB_ZERO;
int CallstackTracker::InitializeDllInfo() STUB_ZERO;
BOOL CallstackTracker::IsCorrectImageHlpVersion() STUB_ZERO;
int CallstackTracker::InitializeSymbols() STUB_ZERO;
//~ End DirectUI::CallstackTracker Class

//~ Begin DirectUI::CCAVI Class
CCAVI::CCAVI() STUB_VOID;
HRESULT CCAVI::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCAVI::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
IClassInfo* CCAVI::GetClassInfoPtr() STUB_ZERO;
void CCAVI::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCAVI::s_pClassInfo;
IClassInfo* CCAVI::GetClassInfoW() STUB_ZERO;
HRESULT CCAVI::Register() STUB_ZERO;
void CCAVI::Play(HWND hwnd) STUB_VOID;
void CCAVI::Stop() STUB_VOID;
void CCAVI::PostCreate(HWND hwnd) STUB_VOID;
void CCAVI::OpenAnimation(HWND hwnd) STUB_VOID;
//~ End DirectUI::CCAVI Class

//~ Begin DirectUI::CCBase Class
CCBase::CCBase(DWORD dwStyle, const WCHAR* psz) STUB_VOID;
CCBase::~CCBase() STUB_VOID;
HRESULT CCBase::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCBase::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCBase::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
void CCBase::OnInput(InputEvent* pie) STUB_VOID;
void CCBase::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
bool CCBase::OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
bool CCBase::OnCustomDraw(NMCUSTOMDRAW* pnmcd, LRESULT* plRet) STUB_ZERO;
bool CCBase::OnLostDialogFocus(IDialogElement* pDE) STUB_ZERO;
bool CCBase::OnReceivedDialogFocus(IDialogElement* pDE) STUB_ZERO;
SIZE CCBase::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
HWND CCBase::CreateHWND(HWND hwndParent) STUB_ZERO;
IClassInfo* CCBase::GetClassInfoPtr() STUB_ZERO;
void CCBase::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCBase::s_pClassInfo;
IClassInfo* CCBase::GetClassInfoW() STUB_ZERO;
HRESULT CCBase::Register() STUB_ZERO;
int CCBase::AddString(const WCHAR* pszString) STUB_ZERO;
UID CCBase::WinStyleChange() STUB_ZERO;
const PropertyInfo* CCBase::WinStyleProp() STUB_ZERO;
int CCBase::GetWinStyle() STUB_ZERO;
HRESULT CCBase::SetWinStyle(int v) STUB_ZERO;
void CCBase::SetNotifyHandler(NOTIFYHANDLER pfnnh, HCONTEXT pContext) STUB_VOID;
HRESULT CCBase::DefaultAction() STUB_ZERO;
void CCBase::PostCreate(HWND hwnd) STUB_VOID;
//~ End DirectUI::CCBase Class

//~ Begin DirectUI::CCBaseCheckRadioButton Class
CCBaseCheckRadioButton::CCBaseCheckRadioButton(DWORD dwStyle) STUB_VOID;
IClassInfo* CCBaseCheckRadioButton::GetClassInfoPtr() STUB_ZERO;
void CCBaseCheckRadioButton::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCBaseCheckRadioButton::s_pClassInfo;
IClassInfo* CCBaseCheckRadioButton::GetClassInfoW() STUB_ZERO;
HRESULT CCBaseCheckRadioButton::Register() STUB_ZERO;
void CCBaseCheckRadioButton::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
SIZE CCBaseCheckRadioButton::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
bool CCBaseCheckRadioButton::OnLostDialogFocus(IDialogElement* pDE) STUB_ZERO;
bool CCBaseCheckRadioButton::OnReceivedDialogFocus(IDialogElement* pDE) STUB_ZERO;
void CCBaseCheckRadioButton::PostCreate(HWND hwnd) STUB_VOID;
//~ End DirectUI::CCBaseCheckRadioButton Class

//~ Begin DirectUI::CCBaseScrollBar Class
CCBaseScrollBar::CCBaseScrollBar(DWORD dwStyle) STUB_VOID;
HRESULT CCBaseScrollBar::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
HWND CCBaseScrollBar::CreateHWND(HWND hwndParent) STUB_ZERO;
void CCBaseScrollBar::SyncScrollBar() STUB_VOID;
bool CCBaseScrollBar::OnMessage(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
bool CCBaseScrollBar::OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void CCBaseScrollBar::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
const PropertyInfo* CCBaseScrollBar::PositionProp() STUB_ZERO;
const PropertyInfo* CCBaseScrollBar::MinimumProp() STUB_ZERO;
const PropertyInfo* CCBaseScrollBar::MaximumProp() STUB_ZERO;
const PropertyInfo* CCBaseScrollBar::PageProp() STUB_ZERO;
const PropertyInfo* CCBaseScrollBar::LineProp() STUB_ZERO;
const PropertyInfo* CCBaseScrollBar::TrackingProp() STUB_ZERO;
Element* CCBaseScrollBar::GetElement() STUB_ZERO;
int CCBaseScrollBar::GetPosition() STUB_ZERO;
int CCBaseScrollBar::GetMaximum() STUB_ZERO;
int CCBaseScrollBar::GetMinimum() STUB_ZERO;
int CCBaseScrollBar::GetPage() STUB_ZERO;
int CCBaseScrollBar::GetLine() STUB_ZERO;
HRESULT CCBaseScrollBar::SetPosition(int v) STUB_ZERO;
HRESULT CCBaseScrollBar::SetMaximum(int v) STUB_ZERO;
HRESULT CCBaseScrollBar::SetMinimum(int v) STUB_ZERO;
HRESULT CCBaseScrollBar::SetPage(int v) STUB_ZERO;
HRESULT CCBaseScrollBar::SetLine(int v) STUB_ZERO;
bool CCBaseScrollBar::GetProportional() STUB_ZERO;
bool CCBaseScrollBar::GetTracking() STUB_ZERO;
HRESULT CCBaseScrollBar::SetTracking(bool v) STUB_ZERO;
IClassInfo* CCBaseScrollBar::GetClassInfoPtr() STUB_ZERO;
void CCBaseScrollBar::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCBaseScrollBar::s_pClassInfo;
IClassInfo* CCBaseScrollBar::GetClassInfoW() STUB_ZERO;
HRESULT CCBaseScrollBar::Register() STUB_ZERO;
//~ End DirectUI::CCBaseScrollBar Class

//~ Begin DirectUI::CCCheckBox Class
CCCheckBox::CCCheckBox(DWORD dwStyle): CCBaseCheckRadioButton(NULL) STUB_VOID;
HRESULT CCCheckBox::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCCheckBox::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
IClassInfo* CCCheckBox::GetClassInfoPtr() STUB_ZERO;
void CCCheckBox::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCCheckBox::s_pClassInfo;
IClassInfo* CCCheckBox::GetClassInfoW() STUB_ZERO;
HRESULT CCCheckBox::Register() STUB_ZERO;
void CCCheckBox::OnInput(InputEvent* pInputEvent) STUB_VOID;
bool CCCheckBox::OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
//~ End DirectUI::CCCheckBox Class

//~ Begin DirectUI::CCCommandLink Class
CCCommandLink::CCCommandLink(DWORD dwStyle) STUB_VOID;
HRESULT CCCommandLink::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCCommandLink::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
IClassInfo* CCCommandLink::GetClassInfoPtr() STUB_ZERO;
void CCCommandLink::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCCommandLink::s_pClassInfo;
IClassInfo* CCCommandLink::GetClassInfoW() STUB_ZERO;
HRESULT CCCommandLink::Register() STUB_ZERO;
const PropertyInfo* CCCommandLink::NoteProp() STUB_ZERO;
const WCHAR* CCCommandLink::GetNote(Value** ppv) STUB_ZERO;
HRESULT CCCommandLink::SetNote(const WCHAR* v) STUB_ZERO;
void CCCommandLink::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void CCCommandLink::OnSelectedPropertyChanged() STUB_VOID;
SIZE CCCommandLink::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
void CCCommandLink::PostCreate(HWND hwnd) STUB_VOID;
void CCCommandLink::SyncNoteAndGlyph(HWND hwnd) STUB_VOID;
//~ End DirectUI::CCCommandLink Class

//~ Begin DirectUI::CCSysLink Class
CCSysLink::CCSysLink() STUB_VOID;
HRESULT CCSysLink::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCSysLink::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
IClassInfo* CCSysLink::GetClassInfoPtr() STUB_ZERO;
void CCSysLink::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCSysLink::s_pClassInfo;
IClassInfo* CCSysLink::GetClassInfoW() STUB_ZERO;
HRESULT CCSysLink::Register() STUB_ZERO;
SIZE CCSysLink::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
void CCSysLink::OnInput(InputEvent* pInputEvent) STUB_VOID;
bool CCSysLink::OnLostDialogFocus(IDialogElement* pDE) STUB_ZERO;
bool CCSysLink::OnReceivedDialogFocus(IDialogElement* pDE) STUB_ZERO;
//~ End DirectUI::CCSysLink Class

//~ Begin DirectUI::CheckBoxGlyph Class
HRESULT CheckBoxGlyph::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CheckBoxGlyph::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CheckBoxGlyph::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
IClassInfo* CheckBoxGlyph::GetClassInfoPtr() STUB_ZERO;
void CheckBoxGlyph::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CheckBoxGlyph::GetClassInfoW() STUB_ZERO;
HRESULT CheckBoxGlyph::Register() STUB_ZERO;
bool CheckBoxGlyph::OnLostDialogFocus(IDialogElement* pDE) STUB_ZERO;
bool CheckBoxGlyph::OnReceivedDialogFocus(IDialogElement* pDE) STUB_ZERO;
//~ End DirectUI::CheckBoxGlyph Class

//~ Begin DirectUI::CCHScrollBar Class
CCHScrollBar::CCHScrollBar() STUB_VOID;
HRESULT CCHScrollBar::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCHScrollBar::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
SIZE CCHScrollBar::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
IClassInfo* CCHScrollBar::GetClassInfoPtr() STUB_ZERO;
void CCHScrollBar::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCHScrollBar::s_pClassInfo;
IClassInfo* CCHScrollBar::GetClassInfoW() STUB_ZERO;
HRESULT CCHScrollBar::Register() STUB_ZERO;
//~ End DirectUI::CCHScrollBar Class

//~ Begin DirectUI::Clipper Class
HRESULT Clipper::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void Clipper::_SelfLayoutDoLayout(int cx, int cy) STUB_VOID;
SIZE Clipper::_SelfLayoutUpdateDesiredSize(int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
IClassInfo* Clipper::GetClassInfoPtr() STUB_ZERO;
void Clipper::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Clipper::s_pClassInfo;
IClassInfo* Clipper::GetClassInfoW() STUB_ZERO;
HRESULT Clipper::Register() STUB_ZERO;
HRESULT Clipper::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
//~ End DirectUI::Clipper Class

//~ Begin DirectUI::CCListBox Class
CCListBox::CCListBox() STUB_VOID;
HRESULT CCListBox::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCListBox::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
IClassInfo* CCListBox::GetClassInfoPtr() STUB_ZERO;
void CCListBox::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCListBox::s_pClassInfo;
IClassInfo* CCListBox::GetClassInfoW() STUB_ZERO;
HRESULT CCListBox::Register() STUB_ZERO;
int CCListBox::AddString(const WCHAR* pszString) STUB_ZERO;
int CCListBox::DeleteString(int iDelete) STUB_ZERO;
int CCListBox::GetCount() STUB_ZERO;
SIZE CCListBox::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
//~ End DirectUI::CCListBox Class

//~ Begin DirectUI::CCListView Class
CCListView::CCListView() STUB_VOID;
HRESULT CCListView::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCListView::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
SIZE CCListView::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
HRESULT CCListView::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
IClassInfo* CCListView::GetClassInfoPtr() STUB_ZERO;
void CCListView::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCListView::s_pClassInfo;
IClassInfo* CCListView::GetClassInfoW() STUB_ZERO;
HRESULT CCListView::Register() STUB_ZERO;
//~ End DirectUI::CCListView Class

//~ Begin DirectUI::Combobox Class
HRESULT Combobox::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT Combobox::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void Combobox::OnInput(InputEvent* pInput) STUB_VOID;
void Combobox::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void Combobox::OnHosted(Element* peNewHost) STUB_VOID;
bool Combobox::OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
int Combobox::OnAdjustWindowSize(int x, int y, UINT uFlags) STUB_ZERO;
SIZE Combobox::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
IClassInfo* Combobox::GetClassInfoPtr() STUB_ZERO;
void Combobox::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Combobox::s_pClassInfo;
IClassInfo* Combobox::GetClassInfoW() STUB_ZERO;
HRESULT Combobox::Register() STUB_ZERO;
int Combobox::AddString(const WCHAR* lpszString) STUB_ZERO;
UID Combobox::SelectionChange() STUB_ZERO;
const PropertyInfo* Combobox::SelectionProp() STUB_ZERO;
int Combobox::GetSelection() STUB_ZERO;
HRESULT Combobox::SetSelection(int v) STUB_ZERO;
Combobox::Combobox() STUB_VOID;
Combobox::~Combobox() STUB_VOID;
HRESULT Combobox::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
HWND Combobox::CreateHWND(HWND hwndParent) STUB_ZERO;
//~ End DirectUI::Combobox Class

//~ Begin DirectUI::CCProgressBar Class
CCProgressBar::CCProgressBar() STUB_VOID;
HRESULT CCProgressBar::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCProgressBar::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCProgressBar::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
IClassInfo* CCProgressBar::GetClassInfoPtr() STUB_ZERO;
void CCProgressBar::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCProgressBar::s_pClassInfo;
IClassInfo* CCProgressBar::GetClassInfoW() STUB_ZERO;
HRESULT CCProgressBar::Register() STUB_ZERO;
void CCProgressBar::OnInput(InputEvent* pInputEvent) STUB_VOID;
//~ End DirectUI::CCProgressBar Class

//~ Begin DirectUI::CCPushButton Class
CCPushButton::CCPushButton(DWORD dwStyle) STUB_VOID;
HRESULT CCPushButton::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCPushButton::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
IClassInfo* CCPushButton::GetClassInfoPtr() STUB_ZERO;
void CCPushButton::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCPushButton::s_pClassInfo;
IClassInfo* CCPushButton::GetClassInfoW() STUB_ZERO;
HRESULT CCPushButton::Register() STUB_ZERO;
const PropertyInfo* CCPushButton::OverrideButtonBackgroundProp() STUB_ZERO;
const PropertyInfo* CCPushButton::HasShieldProp() STUB_ZERO;
bool CCPushButton::GetOverrideButtonBackground() STUB_ZERO;
bool CCPushButton::GetHasShield() STUB_ZERO;
HRESULT CCPushButton::SetOverrideButtonBackground(bool v) STUB_ZERO;
bool CCPushButton::OnMessage(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
bool CCPushButton::GetButtonColor(HDC hdc, HBRUSH* phbrush) STUB_ZERO;
void CCPushButton::OnInput(InputEvent* pInputEvent) STUB_VOID;
bool CCPushButton::OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
void CCPushButton::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void CCPushButton::OnSelectedPropertyChanged() STUB_VOID;
SIZE CCPushButton::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
SIZE CCPushButton::EstimateContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
bool CCPushButton::OnLostDialogFocus(IDialogElement* pDE) STUB_ZERO;
bool CCPushButton::OnReceivedDialogFocus(IDialogElement* pDE) STUB_ZERO;
HRESULT CCPushButton::DefaultAction() STUB_ZERO;
void CCPushButton::SetDefaultState(DWORD dwTypeNormal, DWORD dwTypeDefault) STUB_VOID;
//~ End DirectUI::CCPushButton Class

//~ Begin DirectUI::CCRadioButton Class
CCRadioButton::CCRadioButton(): CCBaseCheckRadioButton(NULL) STUB_VOID;
HRESULT CCRadioButton::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCRadioButton::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
IClassInfo* CCRadioButton::GetClassInfoPtr() STUB_ZERO;
void CCRadioButton::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCRadioButton::s_pClassInfo;
IClassInfo* CCRadioButton::GetClassInfoW() STUB_ZERO;
HRESULT CCRadioButton::Register() STUB_ZERO;
const PropertyInfo* CCRadioButton::AutoGroupingProp() STUB_ZERO;
bool CCRadioButton::GetAutoGrouping() STUB_ZERO;
HRESULT CCRadioButton::SetAutoGrouping(bool v) STUB_ZERO;
void CCRadioButton::OnInput(InputEvent* pInputEvent) STUB_VOID;
bool CCRadioButton::OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
//~ Begin DirectUI::CCRadioButton Class

//~ Begin DirectUI::CCTrackBar Class
CCTrackBar::CCTrackBar() STUB_VOID;
HRESULT CCTrackBar::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCTrackBar::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
IClassInfo* CCTrackBar::GetClassInfoPtr() STUB_ZERO;
void CCTrackBar::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCTrackBar::s_pClassInfo;
IClassInfo* CCTrackBar::GetClassInfoW() STUB_ZERO;
HRESULT CCTrackBar::Register() STUB_ZERO;
const PropertyInfo* CCTrackBar::RangeMinProp() STUB_ZERO;
const PropertyInfo* CCTrackBar::RangeMaxProp() STUB_ZERO;
const PropertyInfo* CCTrackBar::LineSizeProp() STUB_ZERO;
const PropertyInfo* CCTrackBar::ThumbPositionProp() STUB_ZERO;
int CCTrackBar::GetRangeMin() STUB_ZERO;
int CCTrackBar::GetRangeMax() STUB_ZERO;
int CCTrackBar::GetLineSize() STUB_ZERO;
int CCTrackBar::GetThumbPosition() STUB_ZERO;
HRESULT CCTrackBar::SetRangeMin(int v) STUB_ZERO;
HRESULT CCTrackBar::SetRangeMax(int v) STUB_ZERO;
HRESULT CCTrackBar::SetLineSize(int v) STUB_ZERO;
HRESULT CCTrackBar::SetThumbPosition(int v) STUB_ZERO;
bool CCTrackBar::OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void CCTrackBar::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
bool CCTrackBar::OnMessage(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
void CCTrackBar::PostCreate(HWND hwnd) STUB_VOID;
//~ End DirectUI::CCTrackBar Class

//~ Begin DirectUI::CCTreeView Class
CCTreeView::CCTreeView(DWORD dwStyle) STUB_VOID;
HRESULT CCTreeView::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCTreeView::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
bool CCTreeView::OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO ;
SIZE CCTreeView::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO ;
DWORD CCTreeView::GetStyle() STUB_ZERO;
DWORD CCTreeView::SetStyle(DWORD dwStyle) STUB_ZERO;
UINT CCTreeView::GetItemState(const HTREEITEM hItem) STUB_ZERO;
void CCTreeView::SetItemState(HTREEITEM hItem, UINT uState) STUB_VOID;
HTREEITEM CCTreeView::InsertItem(const TVINSERTSTRUCT* pInsertStruct) STUB_ZERO;
HTREEITEM CCTreeView::InsertItem(WCHAR* pszItem, UINT uState, const HTREEITEM htiParent, const HTREEITEM htiInsertAfter) STUB_ZERO;
IClassInfo* CCTreeView::GetClassInfoPtr() STUB_ZERO;
void CCTreeView::SetClassInfoPtr(IClassInfo*) STUB_VOID;
IClassInfo* CCTreeView::s_pClassInfo;
IClassInfo* CCTreeView::GetClassInfoW() STUB_ZERO ;
HRESULT CCTreeView::Register() STUB_ZERO;
HRESULT CCTreeView::_OnGetInfoTip(const NMTVGETINFOTIP*) STUB_ZERO;
HRESULT CCTreeView::_OnItemChanged(const NMTVITEMCHANGE*) STUB_ZERO;
//~ End DirectUI::CCTreeView Class

//~ Begin DirectUI::CCVScrollBar Class
CCVScrollBar::CCVScrollBar() STUB_VOID;
HRESULT CCVScrollBar::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT CCVScrollBar::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
SIZE CCVScrollBar::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO ;
IClassInfo* CCVScrollBar::GetClassInfoPtr() STUB_ZERO;
void CCVScrollBar::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* CCVScrollBar::s_pClassInfo;
IClassInfo* CCVScrollBar::GetClassInfoW() STUB_ZERO ;
HRESULT CCVScrollBar::Register() STUB_ZERO;
//~ End DirectUI::CCVScrollBar Class

//~ Begin DirectUI::DialogElementCore Class
void DialogElementCore::Initialize(IDialogElement* pIDialogElement, IElementListener* pIParentListener) STUB_VOID;
Element* DialogElementCore::GetDefaultButton() STUB_ZERO;
bool DialogElementCore::ClickDefaultButton() STUB_ZERO;
void DialogElementCore::OnRegisteredDefaultButtonChanged(Value* pvOld, Value* pvNew) STUB_VOID;
void DialogElementCore::OnDefaultButtonTrackingChanged(Value* pvNew) STUB_VOID;
void DialogElementCore::OnKeyFocusMoved(Element* peFrom, Element* peTo) STUB_VOID;
void DialogElementCore::UpdateChildFocus(Element* peFrom, Element* peTo) STUB_VOID;
bool DialogElementCore::OnChildLostFocus(Element* peFrom) STUB_ZERO;
bool DialogElementCore::OnChildReceivedFocus(Element* peTo) STUB_ZERO;
void DialogElementCore::OnGetDlgCode(MSG* pmsg, LRESULT* plResult) STUB_VOID;
void DialogElementCore::OnInput(InputEvent* pie) STUB_VOID;
void DialogElementCore::OnListenerDetach(Element* pe) STUB_VOID;
void DialogElementCore::OnDestroy() STUB_VOID;
void DialogElementCore::SetRegisteredDefaultButtonSelectedState(bool fSelected) STUB_VOID;
bool DialogElementCore::IsButtonEnabledAndVisible(Element* pe) STUB_ZERO;
//~ End DirectUI::DialogElementCore Class

//~ Begin DirectUI::DialogElement Class
DialogElement::DialogElement() STUB_VOID;
HRESULT DialogElement::Create(HWND hwndParent, bool fDblBuffer, UINT nCreate, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
Element* DialogElement::GetDefaultButton() STUB_ZERO;
bool DialogElement::ClickDefaultButton() STUB_ZERO;
void DialogElement::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void DialogElement::OnKeyFocusMoved(Element* peFrom, Element* peTo) STUB_VOID;
void DialogElement::OnInput(InputEvent* pie) STUB_VOID;
void DialogElement::OnGetDlgCode(MSG* pmsg, LRESULT* plResult) STUB_VOID;
void DialogElement::OnDestroy() STUB_VOID;
bool DialogElement::OnChildLostFocus(Element* peFrom) STUB_ZERO;
bool DialogElement::OnChildReceivedFocus(Element* peTo) STUB_ZERO;
const PropertyInfo* DialogElement::DefaultButtonTrackingProp() STUB_ZERO;
const PropertyInfo* DialogElement::RegisteredDefaultButtonProp() STUB_ZERO;
const PropertyInfo* DialogElement::HandleEnterKeyProp() STUB_ZERO;
const PropertyInfo* DialogElement::ButtonClassAcceptsEnterKeyProp() STUB_ZERO;
bool DialogElement::GetDefaultButtonTracking() STUB_ZERO;
Element* DialogElement::GetRegisteredDefaultButton() STUB_ZERO;
bool DialogElement::GetHandleEnterKey() STUB_ZERO;
bool DialogElement::GetButtonClassAcceptsEnterKey() STUB_ZERO;
HRESULT DialogElement::SetDefaultButtonTracking(bool v) STUB_ZERO;
HRESULT DialogElement::SetRegisteredDefaultButton(Element* v) STUB_ZERO;
HRESULT DialogElement::SetHandleEnterKey(bool v) STUB_ZERO;
HRESULT DialogElement::SetButtonClassAcceptsEnterKey(bool v) STUB_ZERO;
Element* DialogElement::GetKeyFocusedElement() STUB_ZERO;
IClassInfo* DialogElement::GetClassInfoPtr() STUB_ZERO;
void DialogElement::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* DialogElement::s_pClassInfo;
IClassInfo* DialogElement::GetClassInfoW() STUB_ZERO;
HRESULT DialogElement::Register() STUB_ZERO;
void DialogElement::OnListenerAttach(Element* peFrom) STUB_VOID;
void DialogElement::OnListenerDetach(Element* peFrom) STUB_VOID;
bool DialogElement::OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void DialogElement::OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void DialogElement::OnListenedInput(Element* peFrom, InputEvent* pInput) STUB_VOID;
void DialogElement::OnListenedEvent(Element* peFrom, Event* pEvent) STUB_VOID;
//~ End DirectUI::DialogElement Class

//~ Begin DirectUI::DuiNavigate Class
Element* DuiNavigate::Navigate(Element* peFrom, DynamicArray<Element*>* pelConsider, int nNavDir) STUB_ZERO;
//~ End DirectUI::DuiNavigate Class

//~ Begin DirectUI::Edit Class
HRESULT Edit::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT Edit::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void Edit::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void Edit::OnInput(InputEvent*) STUB_VOID;
bool Edit::OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
UINT Edit::MessageCallback(GMSG* pGMsg) STUB_ZERO;
bool Edit::IsContentProtected() STUB_ZERO;
const WCHAR* Edit::GetContentStringAsDisplayed(Value** ppv) STUB_ZERO;
SIZE Edit::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
UID Edit::Enter() STUB_ZERO;
const PropertyInfo* Edit::MultilineProp() STUB_ZERO;
const PropertyInfo* Edit::PasswordCharacterProp() STUB_ZERO;
const PropertyInfo* Edit::DirtyProp() STUB_ZERO;
const PropertyInfo* Edit::MaxLengthProp() STUB_ZERO;
const PropertyInfo* Edit::ThemedBorderProp() STUB_ZERO;
const PropertyInfo* Edit::WantTabsProp() STUB_ZERO;
int Edit::GetPasswordCharacter() STUB_ZERO;
bool Edit::GetMultiline() STUB_ZERO;
bool Edit::GetDirty() STUB_ZERO;
bool Edit::GetThemedBorder() STUB_ZERO;
int Edit::GetMaxLength() STUB_ZERO;
bool Edit::GetWantTabs() STUB_ZERO;
HRESULT Edit::SetPasswordCharacter(int v) STUB_ZERO;
HRESULT Edit::SetMultiline(bool v) STUB_ZERO;
HRESULT Edit::SetDirty(bool v) STUB_ZERO;
HRESULT Edit::SetThemedBorder(bool v) STUB_ZERO;
HRESULT Edit::SetMaxLength(int v) STUB_ZERO;
HRESULT Edit::SetWantTabs(bool v) STUB_ZERO;
IClassInfo* Edit::GetClassInfoPtr() STUB_ZERO;
void Edit::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Edit::s_pClassInfo;
IClassInfo* Edit::GetClassInfoW() STUB_ZERO;
HRESULT Edit::Register() STUB_ZERO;
Edit::Edit() STUB_VOID;
Edit::~Edit() STUB_VOID;
HRESULT Edit::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
HWND Edit::CreateHWND(HWND hwndParent) STUB_ZERO;
HWND Edit::CreateHWND(HWND hwndParent, bool bPassword) STUB_ZERO;
void Edit::PropertyChangedCore(const PropertyInfo* ppi, int iIndex, Value* pvNew, HWND hwnd) STUB_VOID;
UINT Edit::GetTextHeight() STUB_ZERO;
//~ End DirectUI::Edit Class

//~ Begin DirectUI::EventManager Class
HRESULT EventManager::Init() STUB_ZERO;
void EventManager::Close() STUB_VOID;
HRESULT EventManager::AdviseEventAdded(int id, SAFEARRAY* propertyIds) STUB_ZERO;
HRESULT EventManager::AdviseEventRemoved(int id, SAFEARRAY* propertyIds) STUB_ZERO;
HRESULT EventManager::OnToolTip(Element* pe, DWORD dwFlags) STUB_ZERO;
void EventManager::DestroyListener(Element* pe) STUB_VOID;
HRESULT EventManager::PropertyListener(Element* pe, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
HRESULT EventManager::PropertyChangingListener(Element* pe, const PropertyInfo* ppi, bool* pfHandled) STUB_ZERO;
HRESULT EventManager::EventListener(Element* pe, Event* pEvent) STUB_ZERO;
HRESULT EventManager::EndDefer(Element* pe) STUB_ZERO;
bool EventManager::FWantAnyEvent(Element* pe) STUB_ZERO;
HRESULT EventManager::FireStructureChangedEvent(Element* pe, StructureChangeType type) STUB_ZERO;
bool EventManager::WantEvent(Schema::Event event) STUB_ZERO;
bool EventManager::WantEvent(Schema::Event e, int propertyId) STUB_ZERO;
bool EventManager::WantPropertyEvent(int propertyId) STUB_ZERO;
HRESULT EventManager::HandleAccChange(Element* pe, IRawElementProviderSimple* pprv, Value* pvNew, Value* pvOld) STUB_ZERO;
HRESULT EventManager::HandleAccStateChange(IRawElementProviderSimple* pprv, UINT diff, UINT state, int id, VARIANT* pvarOld, VARIANT* pvarNew, bool fInvertValue) STUB_ZERO;
HRESULT EventManager::HandleAccPatternChange(Element* pe, IRawElementProviderSimple* pprv, UINT diff, UINT state, int id, VARIANT* pvarOld, VARIANT* pvarNew, PfnSetState pfn) STUB_ZERO;
HRESULT EventManager::HandleAccDesc(Element* pe, IRawElementProviderSimple* pprv, Value* pvOld, Value* pvNew) STUB_ZERO;
HRESULT EventManager::HandleChildrenEvent(Element* pe, Value* pvOld, Value* pvNew) STUB_ZERO;
HRESULT EventManager::HandleAccRoleEvent(IRawElementProviderSimple* pprv, Value* pvOld, Value* pvNew) STUB_ZERO;
HRESULT EventManager::HandleScrollPos(Element* peScrollBar, IRawElementProviderSimple* pprv, Value* pvOld, Value* pvNew) STUB_ZERO;
HRESULT EventManager::HandleBoolProp(Element* pe, bool (*)(Element*), IRawElementProviderSimple* pprv, int id, Value* pvOld, Value* pvNew) STUB_ZERO;
HRESULT EventManager::HandleVisibilityChange(Element* pe, UINT diff) STUB_ZERO;
HRESULT EventManager::HandleStringProp(IRawElementProviderSimple* pprv, int id, Value* pvOld, Value* pvNew) STUB_ZERO;
HRESULT EventManager::HandleRangeValue(Element* pe, IRawElementProviderSimple* pprv, Value* pvOld, Value* pvNew) STUB_ZERO;
HRESULT EventManager::HandleToggleValue(Element* pe, IRawElementProviderSimple* pprv, Value* pvOld, Value* pvNew) STUB_ZERO;
HRESULT EventManager::GetString(VARIANT* pvar, Value* pv) STUB_ZERO;
HRESULT EventManager::GetBool(VARIANT* pvar, Value* pv) STUB_ZERO;
HRESULT EventManager::GetInt(VARIANT* pvar, Value* pv) STUB_ZERO;
void EventManager::GetToggleState(VARIANT* pvar) STUB_VOID;
void EventManager::GetExpandCollapseState(VARIANT* pvar) STUB_VOID;
HRESULT EventManager::RaiseStructureChangedEvent(Element* pe, StructureChangeType type) STUB_ZERO;
HRESULT EventManager::RaiseChildRemovedEvent(const ElementRuntimeId& runtimeId, Element* peParent) STUB_ZERO;
HRESULT EventManager::RaiseGeometryEvents() STUB_ZERO;
HRESULT EventManager::RaiseStructureEvents() STUB_ZERO;
HRESULT EventManager::RaiseVisibilityEvents() STUB_ZERO;
HRESULT EventManager::AddRectangleChange(Element* pe, bool fWantRect, bool fWantOffScreen) STUB_ZERO;
HRESULT EventManager::RaiseGeometryEventWorker(RectangleChange* prc, bool fWantRect, bool fWantHorizontal, bool fWantVertical, bool fWantOffScreen) STUB_ZERO;
HRESULT EventManager::HandleSelectedChange(IRawElementProviderSimple* pPrv, Value* pvNew) STUB_ZERO;
//~ End DirectUI::EventManager Class

//~ Begin DirectUI::Expandable Class
HRESULT Expandable::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
const PropertyInfo* Expandable::ExpandedProp() STUB_ZERO;
bool Expandable::GetExpanded() STUB_ZERO;
HRESULT Expandable::SetExpanded(bool v) STUB_ZERO;
IClassInfo* Expandable::GetClassInfoPtr() STUB_ZERO;
void Expandable::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Expandable::s_pClassInfo;
IClassInfo* Expandable::GetClassInfoW() STUB_ZERO;
HRESULT Expandable::Register() STUB_ZERO;
//~ End DirectUI::Expandable Class

ExpandCollapseProvider::ExpandCollapseProvider(void)
{
}

PfnCreateProxy ExpandCollapseProvider::GetProxyCreator(void)
{
	return PfnCreateProxy();
}

HRESULT ExpandCollapseProvider::QueryInterface(REFIID riid, void** ppvObject)
{
	return E_NOTIMPL;
}

ULONG ExpandCollapseProvider::AddRef(void)
{
	return 0;
}

ULONG ExpandCollapseProvider::Release(void)
{
	return 0;
}

HRESULT ExpandCollapseProvider::Expand(void)
{
	return E_NOTIMPL;
}

HRESULT ExpandCollapseProvider::Collapse(void)
{
	return E_NOTIMPL;
}

HRESULT ExpandCollapseProvider::get_ExpandCollapseState(ExpandCollapseState* pRetVal)
{
	return E_NOTIMPL;
}

ExpandCollapseProxy::ExpandCollapseProxy(void)
{
}

ExpandCollapseProxy* ExpandCollapseProxy::Create(Element*)
{
	return nullptr;
}

long ExpandCollapseProxy::DoMethod(int, char*)
{
	return 0;
}

bool ExpandCollapseProxy::IsPatternSupported(Element*)
{
	return false;
}

void ExpandCollapseProxy::Init(Element*)
{
}

//~ Begin DirectUI::Expando Class
HRESULT Expando::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void Expando::OnEvent(Event* pEvent) STUB_VOID;
void Expando::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
HRESULT Expando::Add(Element** ppe, UINT cCount) STUB_ZERO;
IClassInfo* Expando::GetClassInfoPtr() STUB_ZERO;
void Expando::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Expando::s_pClassInfo;
IClassInfo* Expando::GetClassInfoW() STUB_ZERO;
HRESULT Expando::Register() STUB_ZERO;
HRESULT Expando::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
ATOM Expando::Arrow() STUB_ZERO;
ATOM Expando::Clipper() STUB_ZERO;
void Expando::UpdateChildren(Value* pvNew) STUB_VOID;
ATOM Expando::_atmArrow;
ATOM Expando::_atmClipper;
//~ End DirectUI::Expando Class

//~ Begin DirectUI::ExpandoButtonGlyph Class
HRESULT ExpandoButtonGlyph::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT ExpandoButtonGlyph::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT ExpandoButtonGlyph::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
IClassInfo* ExpandoButtonGlyph::GetClassInfoPtr() STUB_ZERO;
void ExpandoButtonGlyph::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* ExpandoButtonGlyph::s_pClassInfo;
IClassInfo* ExpandoButtonGlyph::GetClassInfoW() STUB_ZERO;
HRESULT ExpandoButtonGlyph::Register() STUB_ZERO;
bool ExpandoButtonGlyph::OnLostDialogFocus(IDialogElement* pDE) STUB_ZERO;
bool ExpandoButtonGlyph::OnReceivedDialogFocus(IDialogElement* pDE) STUB_ZERO;
//~ End DirectUI::ExpandoButtonGlyph Class

//~ Begin DirectUI::FontCache Class
HRESULT FontCache::InitProcess() STUB_ZERO
HRESULT FontCache::InitThread() STUB_ZERO
void FontCache::UninitProcess() STUB_VOID
void FontCache::UninitThread() STUB_VOID
HFONT FontCache::CheckOutFont(LPCWSTR szFamily, int dSize, int dWeight, int dStyle, int dQuality, int dAngle) STUB_ZERO
void FontCache::CheckInFont() STUB_VOID
HBRUSH FontCache::AcquireBrush(HBITMAP hbmp, HBRUSH hbrush) STUB_ZERO
void FontCache::ReleaseBrush() STUB_VOID
//~ End DirectUI::FontCache Class

FontCheckOut::FontCheckOut(Element*, HDC)
{
}

FontCheckOut::~FontCheckOut(void)
{
}

FontCheckOut& FontCheckOut::operator=(FontCheckOut const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

GridProvider::GridProvider(void)
{
}

unsigned long GridProvider::AddRef(void)
{
	return 0;
}

long GridProvider::GetItem(int, int, IRawElementProviderSimple**)
{
	return 0;
}

PfnCreateProxy GridProvider::GetProxyCreator(void)
{
	return PfnCreateProxy();
}

long GridProvider::QueryInterface(GUID const&, void**)
{
	return 0;
}

unsigned long GridProvider::Release(void)
{
	return 0;
}

long GridProvider::get_ColumnCount(int*)
{
	return 0;
}

long GridProvider::get_RowCount(int*)
{
	return 0;
}

GridProxy::GridProxy()
{
}

GridProxy* GridProxy::Create(Element*)
{
	return nullptr;
}

bool GridProxy::IsPatternSupported(Element*)
{
	return false;
}

long GridProxy::DoMethod(int, char*)
{
	return 0;
}

void GridProxy::Init(Element*)
{
}

long GridProxy::GetColumnCount(int*)
{
	return 0;
}

long GridProxy::GetItem(unsigned int, unsigned int, IRawElementProviderSimple**)
{
	return 0;
}

long GridProxy::GetRowCount(int*)
{
	return 0;
}

GridItemProvider::GridItemProvider(void)
{
}

unsigned long GridItemProvider::AddRef(void)
{
	return 0;
}

PfnCreateProxy GridItemProvider::GetProxyCreator(void)
{
	return PfnCreateProxy();
}

long GridItemProvider::QueryInterface(GUID const&, void**)
{
	return 0;
}

unsigned long GridItemProvider::Release(void)
{
	return 0;
}

long GridItemProvider::get_Column(int*)
{
	return 0;
}

long GridItemProvider::get_ColumnSpan(int*)
{
	return 0;
}

long GridItemProvider::get_ContainingGrid(IRawElementProviderSimple**)
{
	return 0;
}

long GridItemProvider::get_Row(int*)
{
	return 0;
}

long GridItemProvider::get_RowSpan(int*)
{
	return 0;
}

GridItemProxy::GridItemProxy(void)
{
}

GridItemProxy* GridItemProxy::Create(Element*)
{
	return nullptr;
}

bool GridItemProxy::IsPatternSupported(Element*)
{
	return false;
}

long GridItemProxy::DoMethod(int, char*)
{
	return 0;
}

void GridItemProxy::Init(Element*)
{
}

long GridItemProxy::GetColumn(int*)
{
	return 0;
}

long GridItemProxy::GetContainingGrid(IRawElementProviderSimple**)
{
	return 0;
}

long GridItemProxy::GetRow(int*)
{
	return 0;
}

//~ Begin DirectUI::XHost Class
XHost::XHost() STUB_VOID;
XHost::~XHost() STUB_VOID;
HRESULT XHost::Initialize(IXElementCP* pcp) STUB_ZERO;
HRESULT XHost::Create(IXElementCP* pcp, XHost** ppHost) STUB_ZERO;
void XHost::Destroy() STUB_VOID;
HWND XHost::GetHWND() STUB_ZERO;
Element* XHost::GetElement() STUB_ZERO;
void XHost::Host(Element* pe) STUB_VOID;
void XHost::ShowWindow(int iShow) STUB_VOID;
void XHost::HideWindow() STUB_VOID;
void XHost::DestroyWindow() STUB_VOID;
LRESULT XHost::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) STUB_ZERO;
//~ End DirectUI::XHost Class

//~ Begin DirectUI::HWNDElement Class
HRESULT WINAPI HWNDElement::Create(HWND hParent, bool fDblBuffer, UINT nCreate, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void HWNDElement::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void HWNDElement::OnGroupChanged(int fGroups, bool bLowPri) STUB_VOID;
void HWNDElement::OnDestroy() STUB_VOID;
void HWNDElement::OnEvent(Event* pEvent) STUB_VOID;
void HWNDElement::OnThemeChanged(ThemeChangedEvent* pev) STUB_VOID;
void HWNDElement::OnImmersiveColorSchemeChanged() STUB_VOID;
void HWNDElement::OnInput(InputEvent* pie) STUB_VOID;
void HWNDElement::OnNoChildWithShortcutFound(KeyboardEvent* pke) STUB_VOID;
void HWNDElement::OnGetDlgCode(MSG* msg, LRESULT* plResult) STUB_VOID;
void HWNDElement::OnWmThemeChanged(WPARAM wParam, LPARAM lParam) STUB_VOID;
void HWNDElement::OnWmSettingChanged(WPARAM wParam, LPARAM lParam) STUB_VOID;
void HWNDElement::OnCompositionChanged() STUB_VOID;
bool HWNDElement::CanSetFocus() STUB_ZERO;
bool HWNDElement::IsMSAAEnabled() STUB_ZERO;
void HWNDElement::UpdateTooltip(Element* pe) STUB_VOID;
void HWNDElement::ActivateTooltip(Element* pe, DWORD dwFlags) STUB_VOID;
void HWNDElement::RemoveTooltip(Element* pe) STUB_VOID;
void HWNDElement::DelayActivateTooltip() STUB_VOID;
HRESULT HWNDElement::CreateStyleParser(DUIXmlParser** ppParser) STUB_ZERO;
Element* HWNDElement::ElementFromPoint(POINT* ppt) STUB_ZERO;
LRESULT HWNDElement::StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) STUB_ZERO;
LRESULT HWNDElement::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) STUB_ZERO;
void HWNDElement::FlushWorkingSet() STUB_VOID;
HWND HWNDElement::GetHWND() STUB_ZERO;
void HWNDElement::GetWindowClassNameAndStyle(const WCHAR** ppchClassName, UINT* puiClassStyle) STUB_VOID;
Element* WINAPI HWNDElement::GetKeyFocusedElement() STUB_ZERO;
HWNDElement* WINAPI HWNDElement::GetFocusedHWNDElement() STUB_ZERO;
bool WINAPI HWNDElement::FindShortcut(WCHAR ch, Element* pe, Element** ppeFound, BOOL* pfMultiple, BOOL* pfUseNext, BOOL fSysKey) STUB_ZERO;
bool HWNDElement::IsFirstElement(Element* peTarget) STUB_ZERO;
bool HWNDElement::IsLastElement(Element* peTarget) STUB_ZERO;
void HWNDElement::SetFocus(bool fFirstElement) STUB_VOID;
void HWNDElement::ToggleUIState(bool fUpdateAccel, bool fUpdateFocus) STUB_VOID;
void HWNDElement::ShowUIState(bool fUpdateAccel, bool fUpdateFocus) STUB_VOID;
WORD HWNDElement::GetUIState() STUB_ZERO;
bool HWNDElement::ShowAccel() STUB_ZERO;
bool HWNDElement::ShowFocus() STUB_ZERO;
void HWNDElement::SetParentSizeControl(bool bParentSizeControl) STUB_VOID;
void HWNDElement::SetScreenCenter(bool bScreenCenter) STUB_VOID;
bool HWNDElement::ShouldUseDesktopPerMonitorScaling() STUB_ZERO;
UID WINAPI HWNDElement::ThemeChange() STUB_ZERO;
UID WINAPI HWNDElement::CompositionChange() STUB_ZERO;
UID WINAPI HWNDElement::ImmersiveColorSchemeChange() STUB_ZERO;
UID WINAPI HWNDElement::WindowDpiChanged() STUB_ZERO;
const PropertyInfo* WINAPI HWNDElement::WrapKeyboardNavigateProp() STUB_ZERO;
bool HWNDElement::GetWrapKeyboardNavigate() STUB_ZERO;
HRESULT HWNDElement::SetWrapKeyboardNavigate(bool v) STUB_ZERO;
IClassInfo* WINAPI HWNDElement::GetClassInfoPtr() STUB_ZERO;
void WINAPI HWNDElement::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* HWNDElement::s_pClassInfo;
IClassInfo* HWNDElement::GetClassInfoW() STUB_ZERO;
HRESULT WINAPI HWNDElement::Register() STUB_ZERO;
HRESULT HWNDElement::GetAccessibleImpl(IAccessible**) STUB_ZERO;
HWNDElement::HWNDElement() STUB_VOID;
HWNDElement::~HWNDElement() STUB_VOID;
HRESULT HWNDElement::Initialize(HWND hParent, bool fDblBuffer, UINT nCreate, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
bool WINAPI HWNDElement::FindShortcutRecursive(WCHAR ch, Element* pe, Element** ppeFound, BOOL* pfMultiple, BOOL* pfUseNext, BOOL fSysKey) STUB_ZERO;
void HWNDElement::UpdateStyleSheets() STUB_VOID;
void HWNDElement::_OnUIStateChanged(WORD wUIStateOld, WORD wUIStateNew) STUB_VOID;
void HWNDElement::_HandleImmersiveColorSchemeChange() STUB_VOID;
int HWNDElement::_GetPerMonitorScaleFactorForDesktopWindow(HWND hwnd) STUB_ZERO;
void HWNDElement::_FireWindowDpiChangeEvent() STUB_VOID;
int HWNDElement::_UpdateDesktopScaleFactor() STUB_ZERO;
//~ End DirectUI::HWNDElement Class

//~ Begin DirectUI::HWNDElementProvider Class
PfnCreateProxy HWNDElementProvider::GetProxyCreator() STUB_ZERO;
HRESULT HWNDElementProvider::Create(HWNDElement* pe, InvokeHelper* pih, HWNDElementProvider** ppprv) STUB_ZERO;
HWNDElementProvider::HWNDElementProvider() STUB_VOID;
ULONG HWNDElementProvider::AddRef() STUB_ZERO;
ULONG HWNDElementProvider::Release() STUB_ZERO;
HRESULT HWNDElementProvider::QueryInterface(REFIID riid, void** ppvObject) STUB_ZERO;
HRESULT HWNDElementProvider::ElementProviderFromPoint(double x, double y, IRawElementProviderFragment** ppprv) STUB_ZERO;
HRESULT HWNDElementProvider::GetFocus(IRawElementProviderFragment** ppprv) STUB_ZERO;
HRESULT HWNDElementProvider::Init(HWNDElement* pe, InvokeHelper* pih) STUB_ZERO;
//~ End DirectUI::HWNDElementProvider Class

//~ Begin DirectUI::HWNDElementProxy Class
HWNDElementProxy* HWNDElementProxy::Create(HWNDElement* pe) STUB_ZERO;
void HWNDElementProxy::Init(HWNDElement* pe) STUB_VOID;
HRESULT HWNDElementProxy::DoMethod(MethodId methodId, va_list args) STUB_ZERO;
HWNDElementProxy::HWNDElementProxy() STUB_VOID;
HRESULT HWNDElementProxy::ElementFromPoint(double x, double y, IRawElementProviderFragment** ppprv) STUB_ZERO;
HRESULT HWNDElementProxy::GetFocus(IRawElementProviderFragment** ppprv) STUB_ZERO;
//~ End DirectUI::HWNDElementProxy Class

//~ Begin DirectUI::HWNDHost Class
HRESULT HWNDHost::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT HWNDHost::Create(UINT nCreate, UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void HWNDHost::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void HWNDHost::OnInput(InputEvent* pInput) STUB_VOID;
void HWNDHost::OnEvent(Event* pEvent) STUB_VOID;
void HWNDHost::OnDestroy() STUB_VOID;
bool HWNDHost::OnNotify(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
bool HWNDHost::OnMessage(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
bool HWNDHost::OnSysChar(WCHAR chKeyCode) STUB_ZERO;
bool HWNDHost::OnSinkThemeChanged(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
bool HWNDHost::OnCtrlThemeChanged(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
void HWNDHost::OnWindowStyleChanged(WPARAM wParam, const STYLESTRUCT* pstylestruct) STUB_VOID;
int HWNDHost::OnAdjustWindowSize(int x, int y, UINT uFlags) STUB_ZERO;
UINT HWNDHost::MessageCallback(GMSG* pmsg) STUB_ZERO;
void HWNDHost::Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) STUB_VOID;
bool HWNDHost::GetKeyFocused() STUB_ZERO;
void HWNDHost::SetKeyFocus() STUB_VOID;
void HWNDHost::SetWindowDirection(HWND hwnd) STUB_VOID;
HWND HWNDHost::GetHWND() STUB_ZERO;
HWND HWNDHost::GetHWNDParent() STUB_ZERO;
void HWNDHost::Detach() STUB_VOID;
const PropertyInfo* HWNDHost::TransparentProp() STUB_ZERO;
const PropertyInfo* HWNDHost::BackgroundOwnerIDProp() STUB_ZERO;
const PropertyInfo* HWNDHost::OptimizeMoveProp() STUB_ZERO;
const PropertyInfo* HWNDHost::ThemeChangedProp() STUB_ZERO;
bool HWNDHost::GetTransparent() STUB_ZERO;
HRESULT HWNDHost::SetTransparent(bool v) STUB_ZERO;
ATOM HWNDHost::GetBackgroundOwnerID() STUB_ZERO;
HRESULT HWNDHost::SetBackgroundOwnerID(const WCHAR* v) STUB_ZERO;
bool HWNDHost::GetOptimizeMove() STUB_ZERO;
HRESULT HWNDHost::SetOptimizeMove(bool v) STUB_ZERO;
IClassInfo* HWNDHost::GetClassInfoPtr() STUB_ZERO;
void HWNDHost::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* HWNDHost::s_pClassInfo;
IClassInfo* HWNDHost::GetClassInfoW() STUB_ZERO;
HRESULT HWNDHost::Register() STUB_ZERO;
HRESULT HWNDHost::GetAccessibleImpl(IAccessible** ppAccessible, bool fWindow) STUB_ZERO;
HRESULT HWNDHost::GetAccessibleImpl(IAccessible** ppAccessible) STUB_ZERO;
HRESULT HWNDHost::GetClientAccessibleImpl(IAccessible** ppAccessible) STUB_ZERO;
HWNDHost::HWNDHost() STUB_VOID;
HRESULT HWNDHost::Initialize(UINT nCreate, UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
HWNDHost::~HWNDHost() STUB_VOID;
int HWNDHost::GetThemeChanged() STUB_ZERO;
HRESULT HWNDHost::SetThemeChanged(int v) STUB_ZERO;
void HWNDHost::OnHosted(Element* peNewHost) STUB_VOID;
void HWNDHost::OnUnHosted(Element* peOldHost) STUB_VOID;
HWND HWNDHost::CreateHWND(HWND hwndParent) STUB_ZERO;
void HWNDHost::AttachCtrlSubclassProc(HWND hwnd) STUB_VOID;
LRESULT HWNDHost::CtrlSubclassProc(HWND hwnd, UINT uiMsg, WPARAM wParam, LPARAM lParam) STUB_ZERO;
HWND HWNDHost::CreateAccNameLabel(HWND hwndParent) STUB_ZERO;
void HWNDHost::SyncRect(UINT nChangeFlags, bool bForceSync) STUB_VOID;
void HWNDHost::SyncParent() STUB_VOID;
void HWNDHost::SyncStyle() STUB_VOID;
void HWNDHost::SyncVisible() STUB_VOID;
void HWNDHost::SyncDirection() STUB_VOID;
void HWNDHost::SyncFont() STUB_VOID;
HFONT HWNDHost::GetFont() STUB_ZERO;
void HWNDHost::SyncBackground() STUB_VOID;
void HWNDHost::SyncForeground() STUB_VOID;
void HWNDHost::SyncText() STUB_VOID;
bool HWNDHost::GetStaticColor(HDC hdcCtl, HBRUSH* phbrush) STUB_ZERO;
void HWNDHost::PrintRTLControl(HDC hDC, HDC hdcBuffer, const RECT& rcSkipContent) STUB_VOID;
bool HWNDHost::EraseBkgnd(HDC hdcCtl, LRESULT* lpRet) STUB_ZERO;
Element* HWNDHost::GetBackgroundOwner() STUB_ZERO;
bool HWNDHost::IsMoveDeferred() STUB_ZERO;
int HWNDHost::VerifyParentage() STUB_ZERO;
BOOL HWNDHost::_SinkWndProc(void* pThis, HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
BOOL HWNDHost::_CtrlWndProc(void* pThis, HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
void HWNDHost::_DeleteCtrlWnd() STUB_VOID;
void HWNDHost::SyncColorsAndFonts() STUB_VOID;
void HWNDHost::UnvirtualizePosition() STUB_VOID;
void HWNDHost::ApplySinkRegion(const RECT* prcSink, bool bForceSync) STUB_VOID;
void HWNDHost::GetSinkRect(const RECT* prcConPxl, RECT* prcSink) STUB_VOID;
bool HWNDHost::HaveWin32Focus() STUB_ZERO;
const UINT HWNDHost::g_rgMouseMap[8][3] = {};
//~ End DirectUI::HWNDHost Class

Proxy::Proxy(void)
{
}

Proxy::~Proxy(void)
{
}
long Proxy::SyncCallback(HGADGET__*, void*, EventMsg*)
{
	return 0;
}

void Proxy::Invoke(unsigned int, void*)
{
}

void Proxy::OnInvoke(unsigned int, void*)
{
}

void ProviderProxy::Init(Element* pe) STUB_VOID;
ProviderProxy::ProviderProxy() STUB_VOID;

IProvider::IProvider(IProvider const&)
{
}

IProvider::IProvider(void)
{
}

IProvider& IProvider::operator=(IProvider const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

IXProviderCP::IXProviderCP(IXProviderCP const&)
{
}

IXProviderCP::IXProviderCP(void)
{
}

IXProviderCP& IXProviderCP::operator=(IXProviderCP const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

IXElementCP::IXElementCP(IXElementCP const&)
{
}

IXElementCP::IXElementCP(void)
{
}

IXElementCP& IXElementCP::operator=(IXElementCP const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

HRESULT StyleSheet::Create(StyleSheet** ppSheet) STUB_ZERO;

//~ Begin DirectUI::InvokeHelper Class
InvokeHelper::InvokeHelper() STUB_VOID;
InvokeHelper::~InvokeHelper() STUB_VOID;
int InvokeHelper::Init(ULONG idThread) STUB_ZERO;
void InvokeHelper::Uninit() STUB_VOID;
HRESULT InvokeHelper::DoInvoke(MethodId methodId, ElementProvider* pElementProvider, PfnCreateProxy pfnCreate, va_list args) STUB_ZERO;
InvokeHelper::InvokeArgs::InvokeArgs(MethodId methodId, ElementProvider* pElementProvider, PfnCreateProxy pfnCreate, va_list args) STUB_VOID;
const UINT InvokeHelper::s_uInvokeHelperMsg = RegisterWindowMessage(L"DUI_UIA_InvokeHelperMsg");
int InvokeHelper::_WndProc(void* pThis, HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
void InvokeHelper::OnInvoke(InvokeArgs* pInvokeArgs) STUB_VOID;
//~ End DirectUI::InvokeHelper Class

//~ Begin DirectUI::InvokeManager Class
HRESULT InvokeManager::GetInvokeHelper(InvokeHelper** ppih) STUB_ZERO;
void InvokeManager::CloseThread() STUB_VOID;
HRESULT InvokeManager::Init() STUB_ZERO;
void InvokeManager::Close() STUB_VOID;
InvokeHelper* InvokeManager::FindInvokeHelper(UINT* idThread) STUB_ZERO;
//~ End DirectUI::InvokeManager Class

//~ Begin DirectUI::InvokeProvider Class
InvokeProvider::InvokeProvider() STUB_VOID;
PfnCreateProxy InvokeProvider::GetProxyCreator() STUB_ZERO;
HRESULT InvokeProvider::QueryInterface(REFIID riid, void** ppvObj) STUB_ZERO;
ULONG InvokeProvider::AddRef() STUB_ZERO;
ULONG InvokeProvider::Release() STUB_ZERO;
HRESULT InvokeProvider::Invoke() STUB_ZERO;
//~ End DirectUI::InvokeProvider Class

//~ Begin DirectUI::InvokeProxy Class
InvokeProxy* InvokeProxy::Create(Element* pe) STUB_ZERO;
InvokeProxy::InvokeProxy() STUB_VOID;
HRESULT InvokeProxy::DoMethod(MethodId methodId, va_list args) STUB_ZERO;
bool InvokeProxy::IsPatternSupported(Element* pe) STUB_ZERO;
void InvokeProxy::Init(Element* pe) STUB_VOID;
//~ End DirectUI::InvokeProxy Class

//~ Begin DirectUI::LinkedList Class
LinkedList::LinkedList() STUB_VOID;
LinkedList::~LinkedList() STUB_VOID;
void LinkedList::Add(LinkedListNode* pNode) STUB_VOID;
void LinkedList::Remove(LinkedListNode* pNode) STUB_VOID;
LinkedListNode* LinkedList::RemoveTail() STUB_ZERO;
//~ End DirectUI::LinkedList Class

HRESULT Macro::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT Macro::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
const PropertyInfo* Macro::ExpandProp() STUB_ZERO;
const WCHAR* Macro::GetExpand(Value** ppv) STUB_ZERO;
HRESULT Macro::SetExpand(const WCHAR* v) STUB_ZERO;
void Macro::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
HRESULT Macro::Add(Element** ppe, UINT cCount) STUB_ZERO;
IClassInfo* Macro::GetClassInfoPtr() STUB_ZERO;
void Macro::SetClassInfoPtr(IClassInfo*) STUB_VOID;
IClassInfo* Macro::s_pClassInfo;
IClassInfo* Macro::GetClassInfoW() STUB_ZERO;
HRESULT Macro::Register() STUB_ZERO;
void Macro::SetDataEntry(IDataEntry* pide, Element* peBindings) STUB_VOID;
IDataEntry* Macro::GetDataEntry() STUB_ZERO;
void Macro::SetParser(DUIXmlParser* pParser) STUB_VOID;
void Macro::SetDefaultGraphicType(BYTE defaultGraphicType, bool fOffOpaqueGraphicType) STUB_VOID;
HRESULT Macro::BuildElement() STUB_ZERO;
void Macro::ResolveBindings() STUB_VOID;
void Macro::_BitAccurateFillRect(HDC hDC, int x, int y, int w, int h, BYTE r, BYTE g, BYTE b, BYTE a, DWORD dwROP) STUB_VOID;
bool Macro::_GetBitmapSize(HBITMAP hBitmap, SIZE* pSize) STUB_ZERO;
Value* Macro::_LoadImage32BitsPerPixel(const WCHAR* pszPath) STUB_ZERO;

CritSecLock::CritSecLock(CRITICAL_SECTION* pacs) STUB_VOID;
CritSecLock::~CritSecLock() STUB_VOID;
void CritSecLock::Unlock() STUB_VOID;

//~ Begin DirectUI::Expression Class
void Expression::Destroy() STUB_VOID;
//~ End DirectUI::Expression Class

//~ Begin DirectUI::Surface Class
Surface::Surface() STUB_VOID;
Surface::~Surface() STUB_VOID;
Surface::EType Surface::GetType() const STUB_ZERO;
Surface::EType Surface::GetSurfaceType(UINT nSurfaceType) STUB_ZERO;
UINT Surface::GetSurfaceType(EType type) STUB_ZERO;
//~ End DirectUI::Surface Class

//~ Begin DirectUI::DCSurface Class
DCSurface::DCSurface(HDC hdc) STUB_VOID;
DCSurface::~DCSurface() STUB_VOID;
DCSurface::EType DCSurface::GetType() const STUB_ZERO;
HDC DCSurface::GetHDC() STUB_ZERO;
//~ End DirectUI::DCSurface Class

//~ Begin DirectUI::ResourceModuleHandles Class
ResourceModuleHandles::ResourceModuleHandles(void) STUB_VOID;
ResourceModuleHandles::~ResourceModuleHandles(void) STUB_VOID;
HRESULT ResourceModuleHandles::GetHandle(LPCWSTR pszFile, HMODULE* phModule) STUB_ZERO;
long volatile ResourceModuleHandles::g_cRefCount STUB_VOID;
//~ End DirectUI::ResourceModuleHandles Class

//~ Begin DirectUI::Movie Class
Movie::Movie() STUB_VOID;
Movie::~Movie() STUB_VOID;
HRESULT Movie::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT Movie::Create(UINT nActive, Element*, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
UID Movie::AdvanceFrame() STUB_ZERO;
IClassInfo* Movie::GetClassInfoPtr() STUB_ZERO;
void Movie::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Movie::s_pClassInfo;
IClassInfo* Movie::GetClassInfoW() STUB_ZERO;
HRESULT Movie::Register() STUB_ZERO;
const PropertyInfo* Movie::PathProp() STUB_ZERO;
const WCHAR* Movie::GetPath(Value** ppv) STUB_ZERO;
HRESULT Movie::SetPath(const WCHAR* v) STUB_ZERO;
const PropertyInfo* Movie::AutoStartProp() STUB_ZERO;
bool Movie::GetAutoStart() STUB_ZERO;
HRESULT Movie::SetAutoStart(bool v) STUB_ZERO;
const PropertyInfo* Movie::AutoStopProp() STUB_ZERO;
bool Movie::GetAutoStop() STUB_ZERO;
HRESULT Movie::SetAutoStop(bool v) STUB_ZERO;
const PropertyInfo* Movie::RepeatProp() STUB_ZERO;
bool Movie::GetRepeat() STUB_ZERO;
HRESULT Movie::SetRepeat(bool v) STUB_ZERO;
const PropertyInfo* Movie::DrawOutlinesProp() STUB_ZERO;
bool Movie::GetDrawOutlines() STUB_ZERO;
HRESULT Movie::SetDrawOutlines(bool v) STUB_ZERO;
const PropertyInfo* Movie::CompositingQualityProp() STUB_ZERO;
int Movie::GetCompositingQuality() STUB_ZERO;
HRESULT Movie::SetCompositingQuality(int v) STUB_ZERO;
const PropertyInfo* Movie::InterpolationModeProp() STUB_ZERO;
int Movie::GetInterpolationMode() STUB_ZERO;
HRESULT Movie::SetInterpolationMode(int v) STUB_ZERO;
const PropertyInfo* Movie::PixelOffsetModeProp() STUB_ZERO;
int Movie::GetPixelOffsetMode() STUB_ZERO;
HRESULT Movie::SetPixelOffsetMode(int v) STUB_ZERO;
const PropertyInfo* Movie::PlayAllFramesModeProp() STUB_ZERO;
bool Movie::GetPlayAllFramesMode() STUB_ZERO;
HRESULT Movie::SetPlayAllFramesMode(bool v) STUB_ZERO;
const PropertyInfo* Movie::SmoothingModeProp() STUB_ZERO;
int Movie::GetSmoothingMode() STUB_ZERO;
HRESULT Movie::SetSmoothingMode(int v) STUB_ZERO;
void Movie::Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) STUB_VOID;
void Movie::OnHosted(Element* peNewRoot) STUB_VOID;
void Movie::OnEvent(Event* pEvent) STUB_VOID;
void Movie::OnDestroy() STUB_VOID;
void Movie::RawActionProc(GMA_ACTIONINFO* pActionInfo) STUB_VOID;
void Movie::doAction(GMA_ACTIONINFO* pActionInfo) STUB_VOID;
HRESULT Movie::LoadFromResource(HINSTANCE hinst, int iResourceId) STUB_ZERO;
HRESULT Movie::LoadFromPath(const WCHAR* pszPath) STUB_ZERO;
void Movie::Play() STUB_VOID;
void Movie::Pause() STUB_VOID;
void Movie::Resume() STUB_VOID;
void Movie::Rewind() STUB_VOID;
void Movie::Forward() STUB_VOID;
void Movie::advanceFrameActionStart() STUB_VOID;
void Movie::advanceFrameActionStop() STUB_VOID;
//~ End DirectUI::Movie Class

//~ Begin DirectUI::Navigator Class
HRESULT Navigator::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT Navigator::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
Browser* Navigator::GetBrowser() STUB_ZERO;
UID Navigator::ActionInitiated() STUB_ZERO;
const PropertyInfo* Navigator::TargetPageProp() STUB_ZERO;
const WCHAR* Navigator::GetTargetPage(Value** ppv) STUB_ZERO;
HRESULT Navigator::SetTargetPage(const WCHAR* v) STUB_ZERO;
void Navigator::OnEvent(Event* pev) STUB_VOID;
IClassInfo* Navigator::GetClassInfoPtr() STUB_ZERO;
void Navigator::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Navigator::s_pClassInfo;
IClassInfo* Navigator::GetClassInfoW() STUB_ZERO;
HRESULT Navigator::Register() STUB_ZERO;
void Navigator::FireNavigationEvent() STUB_VOID;
//~ End DirectUI::Navigator Class

NavigatorSelectionItemProxy::NavigatorSelectionItemProxy(NavigatorSelectionItemProxy const&)
{
}

NavigatorSelectionItemProxy::NavigatorSelectionItemProxy(void)
{
}

NavigatorSelectionItemProxy& NavigatorSelectionItemProxy::operator=(NavigatorSelectionItemProxy const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

long NavigatorSelectionItemProxy::DoMethod(int, char*)
{
	return 0;
}

void NavigatorSelectionItemProxy::Init(Element*)
{
}

long NavigatorSelectionItemProxy::AddToSelection(Browser*)
{
	return 0;
}

long NavigatorSelectionItemProxy::GetIsSelected(Browser*, int*)
{
	return 0;
}

void NavScoring::Init(Element*, int, NavReference const*)
{
}

NavScoring& NavScoring::operator=(NavScoring const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

int NavScoring::TrackScore(Element*, Element*)
{
	return 0;
}

int NavScoring::Try(Element*, int, NavReference const*, unsigned long)
{
	return 0;
}

Page::Page(Page const&)
{
}

Page::Page(void)
{
}

Page::~Page(void)
{
}

Page& Page::operator=(Page const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

long Page::Create(Element*, unsigned long*, Element**)
{
	return 0;
}

IClassInfo* Page::GetClassInfoPtr(void)
{
	return nullptr;
}

long Page::Register(void)
{
	return 0;
}

void Page::SetClassInfoPtr(IClassInfo*)
{
}

long Page::Initialize(Element*, unsigned long*)
{
	return 0;
}

IClassInfo* Page::GetClassInfoW(void)
{
	return nullptr;
}

IClassInfo* Page::s_pClassInfo;

Pages::Pages(Pages const&)
{
}

Pages::Pages(void)
{
}

Pages::~Pages(void)
{
}

Pages& Pages::operator=(Pages const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

long Pages::Create(Element*, unsigned long*, Element**)
{
	return 0;
}

IClassInfo* Pages::GetClassInfoPtr(void)
{
	return nullptr;
}

long Pages::Register(void)
{
	return 0;
}

void Pages::SetClassInfoPtr(IClassInfo*)
{
}

unsigned int Pages::GetCount(void)
{
	return 0;
}

Element* Pages::GetPage(unsigned int)
{
	return nullptr;
}

Element* Pages::GetPage(unsigned short const*)
{
	return nullptr;
}

long Pages::Initialize(Element*, unsigned long*)
{
	return 0;
}

void Pages::SetNoBrowseOnFirstAdd(void)
{
}

long Pages::Add(Element**, unsigned int)
{
	return 0;
}

IClassInfo* Pages::GetClassInfoW(void)
{
	return nullptr;
}

IClassInfo* Pages::s_pClassInfo;

// Schema& Schema::operator=(Schema const&)
// {
// 	return *this;
// }

HRESULT Schema::CreatePatternProvider(Pattern, ElementProvider*, IUnknown**) STUB_ZERO
Schema::Event Schema::EventFromEventId(int) STUB_ZERO
HRESULT Schema::Init() STUB_ZERO
int Schema::LookupAccessibleRole(int, bool*) STUB_ZERO
Schema::Pattern Schema::PatternFromPatternId(int) STUB_ZERO
PfnIsPatternSupported Schema::PfnIsSupportedFromPattern(Pattern) STUB_ZERO
HRESULT Schema::LookupControlInfos() STUB_ZERO
HRESULT Schema::LookupEventInfos() STUB_ZERO
HRESULT Schema::LookupPatternInfos() STUB_ZERO
HRESULT Schema::LookupPropertyInfos() STUB_ZERO
HRESULT Schema::GetProcs() STUB_ZERO

int Schema::AcceleratorKeyProperty;
int Schema::AccessKeyProperty;
int Schema::AsyncContentLoadedEvent;
int Schema::AutomationFocusChangedEvent;
int Schema::AutomationIdProperty;
int Schema::AutomationPropertyChangedEvent;
int Schema::BoundingRectangleProperty;
int Schema::ButtonControlType;
int Schema::CalendarControlType;
int Schema::CheckBoxControlType;
int Schema::ClassNameProperty;
int Schema::ClickablePointProperty;
int Schema::ComboBoxControlType;
int Schema::ControlTypeProperty;
int Schema::CultureProperty;
int Schema::CustomControlType;
int Schema::DataGridControlType;
int Schema::DataItemControlType;
int Schema::DockPattern;
int Schema::DocumentControlType;
int Schema::EditControlType;
int Schema::ExpandCollapsePattern;
int Schema::ExpandCollapse_ExpandCollapseState_Property;
int Schema::FrameworkId;
int Schema::GridItemPattern;
int Schema::GridItem_ColumnSpan_Property;
int Schema::GridItem_Column_Property;
int Schema::GridItem_Parent_Property;
int Schema::GridItem_RowSpan_Property;
int Schema::GridItem_Row_Property;
int Schema::GridPattern;
int Schema::Grid_ColumnCount_Property;
int Schema::Grid_RowCount_Property;
int Schema::GroupControlType;
int Schema::HasKeyboardFocusProperty;
int Schema::HeaderControlType;
int Schema::HeaderItemControlType;
int Schema::HelpTextProperty;
int Schema::HyperlinkControlType;
int Schema::ImageControlType;
int Schema::InvokeInvokedEvent;
int Schema::InvokePattern;
int Schema::IsContentElementProperty;
int Schema::IsControlElementProperty;
int Schema::IsEnabledProperty;
int Schema::IsKeyboardFocusableProperty;
int Schema::IsOffscreen;
int Schema::IsPasswordProperty;
int Schema::ItemContainerPattern;
int Schema::ItemStatusProperty;
int Schema::ItemTypeProperty;
int Schema::LabeledByProperty;
int Schema::LayoutInvalidatedEvent;
int Schema::ListControlType;
int Schema::ListItemControlType;
int Schema::LocalizedControlTypeProperty;
int Schema::MenuBarControlType;
int Schema::MenuClosedEvent;
int Schema::MenuControlType;
int Schema::MenuItemControlType;
int Schema::MenuOpenedEvent;
int Schema::MultipleViewPattern;
int Schema::NameProperty;
int Schema::NewNativeWindowHandleProperty;
int Schema::NullControlType;
int Schema::Orientation;
int Schema::PaneControlType;
int Schema::ProcessIdProperty;
int Schema::ProgressBarControlType;
int Schema::RadioButtonControlType;
int Schema::RangeValuePattern;
int Schema::RangeValue_IsReadOnly_Property;
int Schema::RangeValue_LargeChange_Property;
int Schema::RangeValue_Maximum_Property;
int Schema::RangeValue_Minimum_Property;
int Schema::RangeValue_SmallChange_Property;
int Schema::RangeValue_Value_Property;
int Schema::RuntimeIdProperty;
int Schema::ScrollBarControlType;
int Schema::ScrollItemPattern;
int Schema::ScrollPattern;
int Schema::Scroll_HorizontalScrollPercent_Property;
int Schema::Scroll_HorizontalViewSize_Property;
int Schema::Scroll_HorizontallyScrollable_Property;
int Schema::Scroll_VerticalScrollPercent_Property;
int Schema::Scroll_VerticalViewSize_Property;
int Schema::Scroll_VerticallyScrollable_Property;
int Schema::SelectionInvalidatedEvent;
int Schema::SelectionItemElementAddedToSelectionEvent;
int Schema::SelectionItemElementRemovedFromSelectionEvent;
int Schema::SelectionItemElementSelectedEvent;
int Schema::SelectionItemPattern;
int Schema::SelectionItem_IsSelected_Property;
int Schema::SelectionItem_SelectionContainer_Property;
int Schema::SelectionPattern;
int Schema::Selection_CanSelectMultiple_Property;
int Schema::Selection_IsSelectionRequired_Property;
int Schema::Selection_Selection_Property;
int Schema::SeparatorControlType;
int Schema::SliderControlType;
int Schema::SpinnerControlType;
int Schema::SplitButtonControlType;
int Schema::StatusBarControlType;
int Schema::StructureChangedEvent;
int Schema::TabControlType;
int Schema::TabItemControlType;
int Schema::TableControlType;
int Schema::TableItemPattern;
int Schema::TableItem_ColumnHeaderItems_Property;
int Schema::TableItem_RowHeaderItems_Property;
int Schema::TablePattern;
int Schema::Table_ColumnHeaders_Property;
int Schema::Table_RowHeaders_Property;
int Schema::Table_RowOrColumnMajor_Property;
int Schema::TextControlType;
int Schema::TextPattern;
int Schema::TextTextSelectionChangedEvent;
int Schema::ThumbControlType;
int Schema::TitleBarControlType;
int Schema::TogglePattern;
int Schema::Toggle_ToggleState_Property;
int Schema::ToolBarControlType;
int Schema::ToolTipClosedEvent;
int Schema::ToolTipControlType;
int Schema::ToolTipOpenedEvent;
int Schema::TransformPattern;
int Schema::TreeControlType;
int Schema::TreeItemControlType;

PfnUiaLookupId Schema::UiaLookupId;
PfnUiaReturnRawElementProvider Schema::UiaReturnRawElementProvider;
PfnUiaRaiseAutomationPropertyChangedEvent Schema::UiaRaiseAutomationPropertyChangedEvent;
PfnUiaRaiseAutomationEvent Schema::UiaRaiseAutomationEvent;
PfnUiaRaiseStructureChangedEvent Schema::UiaRaiseStructureChangedEvent;
PfnUiaHostProviderFromHwnd Schema::UiaHostProviderFromHwnd;	
	
// HRESULT (__stdcall*Schema::UiaHostProviderFromHwnd)(HWND hwnd, IRawElementProviderSimple** ppProvider);
// int (__stdcall*Schema::UiaLookupId)(AutomationIdentifierType type, const GUID* pGuid);
// HRESULT (__stdcall*Schema::UiaRaiseAutomationEvent)(IRawElementProviderSimple* pProvider, EVENTID id);
// HRESULT (__stdcall*Schema::UiaRaiseAutomationPropertyChangedEvent)(IRawElementProviderSimple* pProvider, PROPERTYID id, VARIANT oldValue, VARIANT newValue);
// HRESULT (__stdcall*Schema::UiaRaiseStructureChangedEvent)(IRawElementProviderSimple* pProvider, StructureChangeType structureChangeType, int* pRuntimeId, int cRuntimeIdLen);
// LRESULT (__stdcall*Schema::UiaReturnRawElementProvider)(HWND hwnd, WPARAM wParam, LPARAM lParam, IRawElementProviderSimple* el);
	
int Schema::ValuePattern;
int Schema::Value_IsReadOnly_Property;
int Schema::Value_Value_Property;
int Schema::VirtualizedItemPattern;
int Schema::WindowControlType;
int Schema::WindowPattern;
int Schema::WindowWindowClosedEvent;
int Schema::WindowWindowOpenedEvent;

// Schema::RoleMap const* __ptr32 const Schema::_roleMapping = NULL;
// Schema::ControlInfo const* __ptr32 const Schema::g_controlInfoTable = NULL;
// Schema::EventInfo const* __ptr32 const Schema::g_eventInfoTable = NULL;
// Schema::EventMap const* __ptr32 const Schema::g_eventMapping = NULL;
// bool Schema::g_fInited;
// Schema::PatternInfo const* __ptr32 const Schema::g_patternInfoTable = NULL;
// Schema::PatternMap const* __ptr32 const Schema::g_patternMapping = NULL;
// const Schema::PropertyInfo* __ptr32 const Schema::g_propertyInfoTable = NULL;

void NavReference::Init(Element* pe, RECT* prc) STUB_VOID;

//~ Begin DirectUI::Progress Class
HRESULT Progress::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void Progress::Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) STUB_VOID;
SIZE Progress::GetContentSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
const PropertyInfo* Progress::PositionProp() STUB_ZERO;
const PropertyInfo* Progress::MinimumProp() STUB_ZERO;
const PropertyInfo* Progress::MaximumProp() STUB_ZERO;
int Progress::GetPosition() STUB_ZERO;
int Progress::GetMaximum() STUB_ZERO;
int Progress::GetMinimum() STUB_ZERO;
HRESULT Progress::SetPosition(int v) STUB_ZERO;
HRESULT Progress::SetMaximum(int v) STUB_ZERO;
HRESULT Progress::SetMinimum(int v) STUB_ZERO;
IClassInfo* Progress::GetClassInfoPtr() STUB_ZERO;
void Progress::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Progress::s_pClassInfo;
IClassInfo* Progress::GetClassInfoW() STUB_ZERO;
HRESULT Progress::Register() STUB_ZERO;
Progress::Progress() STUB_VOID;
HRESULT Progress::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
//~ End DirectUI::Progress Class

ProgressRangeValueProxy::ProgressRangeValueProxy(void)
{
}

long ProgressRangeValueProxy::DoMethod(int, char*)
{
	return 0;
}

void ProgressRangeValueProxy::Init(Element*)
{
}

// Begin DirectUI::XResourceProvider Class
HRESULT XResourceProvider::CreateDUICP(HWNDElement* peHWNDElement, HWND hwndParent, HWND hwndHost, Element** ppe, DUIXmlParser** ppParser) STUB_ZERO;
HRESULT XResourceProvider::CreateParserCP(DUIXmlParser** ppParser) STUB_ZERO;
void XResourceProvider::DestroyCP() STUB_VOID;
HRESULT XResourceProvider::Create(XResourceProvider** pprprov) STUB_ZERO;
HRESULT XResourceProvider::Create(HINSTANCE hRes, const WCHAR* pszResource, const WCHAR* pszResID, const WCHAR* pszFile, XResourceProvider** pprprov) STUB_ZERO;
HRESULT XResourceProvider::Initialize(HINSTANCE hRes, const WCHAR* pszResource, const WCHAR* pszResid, const WCHAR* pszFile) STUB_ZERO;
//~ End DirectUI::XResourceProvider Class

PText::~PText(void)
{
}

long PText::Create(Element*, unsigned long*, Element**)
{
	return 0;
}

IClassInfo* PText::GetClassInfoPtr(void)
{
	return nullptr;
}

long PText::Register(void)
{
	return 0;
}

void PText::SetClassInfoPtr(IClassInfo*)
{
}

long PText::Initialize(Element*, unsigned long*)
{
	return 0;
}

void PText::SetDataEntry(IDataEntry*)
{
}

IClassInfo* PText::GetClassInfoW(void)
{
	return nullptr;
}

bool PText::OnPropertyChanging(PropertyInfo const*, int, Value*, Value*)
{
	return false;
}

IClassInfo* PText::s_pClassInfo;

//~ Begin DirectUI::PushButton Class
HRESULT PushButton::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
const PropertyInfo* PushButton::EnforceSizeProp() STUB_ZERO;
bool PushButton::GetEnforceSize() STUB_ZERO;
HRESULT PushButton::SetEnforceSize(bool v) STUB_ZERO;
UID PushButton::Hosted() STUB_ZERO;
SIZE PushButton::GetContentSize(int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
void PushButton::OnHosted(Element* peNewHost) STUB_VOID;
void PushButton::OnUnHosted(Element* peOldHost) STUB_VOID;
IClassInfo* PushButton::GetClassInfoPtr() STUB_ZERO;
void PushButton::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* PushButton::s_pClassInfo;
IClassInfo* PushButton::GetClassInfoW() STUB_ZERO;
HRESULT PushButton::Register() STUB_ZERO;
void PushButton::FireHostEvent(Element* peTarget, bool fHosted) STUB_VOID;
//~ End DirectUI::PushButton Class

//~ Begin DirectUI::RadioButtonGlyph Class
HRESULT RadioButtonGlyph::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT RadioButtonGlyph::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT RadioButtonGlyph::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
IClassInfo* RadioButtonGlyph::GetClassInfoPtr() STUB_ZERO;
void RadioButtonGlyph::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* RadioButtonGlyph::GetClassInfoW() STUB_ZERO;
HRESULT RadioButtonGlyph::Register() STUB_ZERO;
bool RadioButtonGlyph::OnLostDialogFocus(IDialogElement* pDE) STUB_ZERO;
bool RadioButtonGlyph::OnReceivedDialogFocus(IDialogElement* pDE) STUB_ZERO;
//~ End DirectUI::RadioButtonGlyph Class

RangeValueProvider::RangeValueProvider(void)
{
}

unsigned long RangeValueProvider::AddRef(void)
{
	return 0;
}

PfnCreateProxy RangeValueProvider::GetProxyCreator(void)
{
	return PfnCreateProxy();
}

long RangeValueProvider::QueryInterface(GUID const&, void**)
{
	return 0;
}

unsigned long RangeValueProvider::Release(void)
{
	return 0;
}

long RangeValueProvider::SetValue(double)
{
	return 0;
}

long RangeValueProvider::get_IsReadOnly(int*)
{
	return 0;
}

long RangeValueProvider::get_LargeChange(double*)
{
	return 0;
}

long RangeValueProvider::get_Maximum(double*)
{
	return 0;
}

long RangeValueProvider::get_Minimum(double*)
{
	return 0;
}

long RangeValueProvider::get_SmallChange(double*)
{
	return 0;
}

long RangeValueProvider::get_Value(double*)
{
	return 0;
}

RangeValueProxy* RangeValueProxy::Create(Element*)
{
	return nullptr;
}

long RangeValueProxy::DoMethod(int, char*)
{
	return 0;
}

RangeValueProxy::RangeValueProxy(void)
{
}

bool RangeValueProxy::IsPatternSupported(Element*)
{
	return false;
}

void RangeValueProxy::Init(Element*)
{
}

RefPointElement::RefPointElement(RefPointElement const&)
{
}

RefPointElement::RefPointElement(void)
{
}

RefPointElement::~RefPointElement(void)
{
}

RefPointElement& RefPointElement::operator=(RefPointElement const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

PropertyInfo const* RefPointElement::ActualReferencePointProp(void)
{
	return nullptr;
}

long RefPointElement::Create(unsigned int, Element*, unsigned long*, Element**)
{
	return 0;
}

long RefPointElement::Create(Element*, unsigned long*, Element**)
{
	return 0;
}

Element* RefPointElement::FindRefPoint(Element*, POINT*)
{
	return nullptr;
}

IClassInfo* RefPointElement::GetClassInfoPtr(void)
{
	return nullptr;
}

PropertyInfo const* RefPointElement::ReferencePointProp(void)
{
	return nullptr;
}

long RefPointElement::Register(void)
{
	return 0;
}

void RefPointElement::SetClassInfoPtr(IClassInfo*)
{
}

RefPointElement* RefPointElement::Locate(Element*)
{
	return nullptr;
}

POINT const* RefPointElement::GetActualReferencePoint(Value**)
{
	return nullptr;
}

POINT const* RefPointElement::GetReferencePoint(Value**)
{
	return nullptr;
}

long RefPointElement::Initialize(unsigned int, Element*, unsigned long*)
{
	return 0;
}

long RefPointElement::SetReferencePoint(int, int)
{
	return 0;
}

IClassInfo* RefPointElement::GetClassInfoW(void)
{
	return nullptr;
}

void RefPointElement::OnPropertyChanged(PropertyInfo const*, int, Value*, Value*)
{
}

IClassInfo* RefPointElement::s_pClassInfo;

//~ Begin DirectUI::RepeatButton Class
HRESULT RepeatButton::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT RepeatButton::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void RepeatButton::OnInput(InputEvent* pie) STUB_VOID;
IClassInfo* RepeatButton::GetClassInfoPtr() STUB_ZERO;
void RepeatButton::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* RepeatButton::s_pClassInfo;
IClassInfo* RepeatButton::GetClassInfoW() STUB_ZERO;
HRESULT RepeatButton::Register() STUB_ZERO;
RepeatButton::RepeatButton() STUB_VOID;
HRESULT RepeatButton::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
RepeatButton::~RepeatButton() STUB_VOID;
void RepeatButton::SetStopThumbBehavior() STUB_VOID;
void RepeatButton::_RepeatButtonActionCallback(GMA_ACTIONINFO* pmai) STUB_VOID;
//~ End DirectUI::RepeatButton Class

HRESULT Repeater::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT Repeater::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
IClassInfo* Repeater::GetClassInfoPtr() STUB_ZERO;
void Repeater::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Repeater::s_pClassInfo;
IClassInfo* Repeater::GetClassInfoW() STUB_ZERO;
HRESULT Repeater::Register() STUB_ZERO;
void Repeater::SetDataEngine(IDataEngine* pie) STUB_VOID;
void Repeater::SetGraphicType(BYTE dDefaultGraphicType) STUB_VOID;
HRESULT Repeater::BuildElement() STUB_ZERO;

ScrollProvider::ScrollProvider(void)
{
}

ScrollProvider::~ScrollProvider(void)
{
}

unsigned long ScrollProvider::AddRef(void)
{
	return 0;
}

PfnCreateProxy ScrollProvider::GetProxyCreator(void)
{
	return PfnCreateProxy();
}

long ScrollProvider::QueryInterface(_GUID const&, void**)
{
	return 0;
}

unsigned long ScrollProvider::Release(void)
{
	return 0;
}

long ScrollProvider::Scroll(ScrollAmount, ScrollAmount)
{
	return 0;
}

long ScrollProvider::SetScrollPercent(double, double)
{
	return 0;
}

long ScrollProvider::get_HorizontalScrollPercent(double*)
{
	return 0;
}

long ScrollProvider::get_HorizontalViewSize(double*)
{
	return 0;
}

long ScrollProvider::get_HorizontallyScrollable(int*)
{
	return 0;
}

long ScrollProvider::get_VerticalScrollPercent(double*)
{
	return 0;
}

long ScrollProvider::get_VerticalViewSize(double*)
{
	return 0;
}

long ScrollProvider::get_VerticallyScrollable(int*)
{
	return 0;
}

ScrollProxy::ScrollProxy(ScrollProxy const&)
{
}

ScrollProxy::ScrollProxy(void)
{
}

ScrollProxy& ScrollProxy::operator=(ScrollProxy const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

ScrollProxy* ScrollProxy::Create(Element*)
{
	return nullptr;
}

bool ScrollProxy::IsPatternSupported(Element*)
{
	return false;
}

long ScrollProxy::DoMethod(int, char*)
{
	return 0;
}

void ScrollProxy::Init(Element*)
{
}

BaseScrollBar* ScrollProxy::GetScrollBar(bool)
{
	return nullptr;
}

long ScrollProxy::GetScrollPercent(bool, double*)
{
	return 0;
}

long ScrollProxy::GetScrollable(bool, int*)
{
	return 0;
}

long ScrollProxy::GetViewSize(bool, double*)
{
	return 0;
}

long ScrollProxy::GetViewer(Viewer**)
{
	return 0;
}

long ScrollProxy::Scroll(ScrollAmount, ScrollAmount)
{
	return 0;
}

long ScrollProxy::ScrollLine(bool, bool)
{
	return 0;
}

long ScrollProxy::ScrollPage(bool, bool)
{
	return 0;
}

long ScrollProxy::ScrollToHorizontalPosition(int, bool)
{
	return 0;
}

long ScrollProxy::ScrollToVerticalPosition(int, bool)
{
	return 0;
}

long ScrollProxy::SetPercent(BaseScrollBar*, double)
{
	return 0;
}

long ScrollProxy::SetScrollPercent(double, double)
{
	return 0;
}

HRESULT ScrollBar::Create(bool, Element*, DWORD*, Element**) STUB_ZERO;
HRESULT ScrollBar::Create(Element*, DWORD*, Element**) STUB_ZERO;
void ScrollBar::OnEvent(Event* pEvent) STUB_VOID;
bool ScrollBar::OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void ScrollBar::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void ScrollBar::_SelfLayoutDoLayout(int cx, int cy) STUB_VOID;
SIZE ScrollBar::_SelfLayoutUpdateDesiredSize(int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
const PropertyInfo* ScrollBar::PositionProp() STUB_ZERO;
const PropertyInfo* ScrollBar::MinimumProp() STUB_ZERO;
const PropertyInfo* ScrollBar::MaximumProp() STUB_ZERO;
const PropertyInfo* ScrollBar::PageProp() STUB_ZERO;
const PropertyInfo* ScrollBar::LineProp() STUB_ZERO;
const PropertyInfo* ScrollBar::VerticalProp() STUB_ZERO;
const PropertyInfo* ScrollBar::ProportionalProp() STUB_ZERO;
const PropertyInfo* ScrollBar::OrderProp() STUB_ZERO;
Element* ScrollBar::GetElement() STUB_ZERO;
int ScrollBar::GetPosition() STUB_ZERO;
int ScrollBar::GetMaximum() STUB_ZERO;
int ScrollBar::GetMinimum() STUB_ZERO;
int ScrollBar::GetPage() STUB_ZERO;
int ScrollBar::GetLine() STUB_ZERO;
HRESULT ScrollBar::SetPosition(int v) STUB_ZERO;
HRESULT ScrollBar::SetMaximum(int v) STUB_ZERO;
HRESULT ScrollBar::SetMinimum(int v) STUB_ZERO;
HRESULT ScrollBar::SetPage(int v) STUB_ZERO;
HRESULT ScrollBar::SetLine(int v) STUB_ZERO;
bool ScrollBar::GetProportional() STUB_ZERO;
int ScrollBar::GetOrder() STUB_ZERO;
bool ScrollBar::GetVertical() STUB_ZERO;
HRESULT ScrollBar::SetOrder(int v) STUB_ZERO;
HRESULT ScrollBar::SetProportional(bool v) STUB_ZERO;
HRESULT ScrollBar::SetVertical(bool v) STUB_ZERO;
IClassInfo* ScrollBar::GetClassInfoPtr() STUB_ZERO;
void ScrollBar::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* ScrollBar::s_pClassInfo;
IClassInfo* ScrollBar::GetClassInfoW() STUB_ZERO;
HRESULT ScrollBar::Register() STUB_ZERO;
ScrollBar::ScrollBar() STUB_VOID;
HRESULT ScrollBar::Initialize(bool fBuildSubTree, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
ScrollBar::~ScrollBar() STUB_VOID;
HRESULT ScrollBar::CreateButtons() STUB_ZERO;

ScrollBarRangeValueProxy::ScrollBarRangeValueProxy() STUB_VOID;
HRESULT ScrollBarRangeValueProxy::DoMethod(MethodId methodId, va_list args) STUB_ZERO;
void ScrollBarRangeValueProxy::Init(Element*) STUB_VOID;

ScrollItemProvider::ScrollItemProvider(void)
{
}

ScrollItemProvider::~ScrollItemProvider(void)
{
}

unsigned long ScrollItemProvider::AddRef(void)
{
	return 0;
}

PfnCreateProxy ScrollItemProvider::GetProxyCreator(void)
{
	return PfnCreateProxy();
}

long ScrollItemProvider::QueryInterface(_GUID const&, void**)
{
	return 0;
}

unsigned long ScrollItemProvider::Release(void)
{
	return 0;
}

long ScrollItemProvider::ScrollIntoView(void)
{
	return 0;
}

ScrollItemProxy::ScrollItemProxy(ScrollItemProxy const&)
{
}

ScrollItemProxy::ScrollItemProxy(void)
{
}

ScrollItemProxy& ScrollItemProxy::operator=(ScrollItemProxy const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

ScrollItemProxy* ScrollItemProxy::Create(Element*)
{
	return nullptr;
}

bool ScrollItemProxy::IsPatternSupported(Element*)
{
	return false;
}

long ScrollItemProxy::DoMethod(int, char*)
{
	return 0;
}

void ScrollItemProxy::Init(Element*)
{
}

ScrollViewer::ScrollViewer(ScrollViewer const&)
{
}

ScrollViewer::ScrollViewer(void)
{
}

ScrollViewer::~ScrollViewer(void)
{
}

ScrollViewer& ScrollViewer::operator=(ScrollViewer const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

long ScrollViewer::Create(Element*, unsigned long*, Element**)
{
	return 0;
}

IClassInfo* ScrollViewer::GetClassInfoPtr(void)
{
	return nullptr;
}

long ScrollViewer::Register(void)
{
	return 0;
}

void ScrollViewer::SetClassInfoPtr(IClassInfo*)
{
}

IClassInfo* ScrollViewer::GetClassInfoW(void)
{
	return nullptr;
}

void ScrollViewer::OnListenedPropertyChanged(Element*, PropertyInfo const*, int, Value*, Value*)
{
}

void ScrollViewer::OnPropertyChanged(PropertyInfo const*, int, Value*, Value*)
{
}

long ScrollViewer::CreateScrollBars(void)
{
	return 0;
}

long ScrollViewer::AddChildren(void)
{
	return 0;
}

BaseScrollBar* ScrollViewer::GetHScroll(void)
{
	return nullptr;
}

BaseScrollBar* ScrollViewer::GetVScroll(void)
{
	return nullptr;
}

IClassInfo* ScrollViewer::s_pClassInfo;

SelectionProvider::SelectionProvider(void)
{
}

SelectionProvider::~SelectionProvider(void)
{
}

unsigned long SelectionProvider::AddRef(void)
{
	return 0;
}

PfnCreateProxy SelectionProvider::GetProxyCreator(void)
{
	return PfnCreateProxy();
}

long SelectionProvider::GetSelection(SAFEARRAY**)
{
	return 0;
}

long SelectionProvider::QueryInterface(GUID const&, void**)
{
	return 0;
}

unsigned long SelectionProvider::Release(void)
{
	return 0;
}

long SelectionProvider::get_CanSelectMultiple(int*)
{
	return 0;
}

long SelectionProvider::get_IsSelectionRequired(int*)
{
	return 0;
}

SelectionProxy::SelectionProxy(void)
{
}

SelectionProxy::SelectionProxy(SelectionProxy const&)
{
}

SelectionProxy& SelectionProxy::operator=(SelectionProxy const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

SelectionProxy* SelectionProxy::Create(Element*)
{
	return nullptr;
}

bool SelectionProxy::IsPatternSupported(Element*)
{
	return false;
}

long SelectionProxy::DoMethod(int, char*)
{
	return 0;
}

void SelectionProxy::Init(Element*)
{
}

SelectionItemProvider::SelectionItemProvider(void)
{
}

SelectionItemProvider::~SelectionItemProvider(void)
{
}

unsigned long SelectionItemProvider::AddRef(void)
{
	return 0;
}

long SelectionItemProvider::AddToSelection(void)
{
	return 0;
}

PfnCreateProxy SelectionItemProvider::GetProxyCreator(void)
{
	return PfnCreateProxy();
}

long SelectionItemProvider::QueryInterface(GUID const&, void**)
{
	return 0;
}

unsigned long SelectionItemProvider::Release(void)
{
	return 0;
}

long SelectionItemProvider::RemoveFromSelection(void)
{
	return 0;
}

long SelectionItemProvider::Select(void)
{
	return 0;
}

long SelectionItemProvider::get_IsSelected(int*)
{
	return 0;
}

long SelectionItemProvider::get_SelectionContainer(IRawElementProviderSimple**)
{
	return 0;
}

SelectionItemProxy::SelectionItemProxy(void)
{
}

SelectionItemProxy::SelectionItemProxy(SelectionItemProxy const&)
{
}

SelectionItemProxy& SelectionItemProxy::operator=(SelectionItemProxy const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

SelectionItemProxy* SelectionItemProxy::Create(Element*)
{
	return nullptr;
}

bool SelectionItemProxy::IsPatternSupported(Element*)
{
	return false;
}

long SelectionItemProxy::DoMethod(int, char*)
{
	return 0;
}

void SelectionItemProxy::Init(Element*)
{
}

Selector::Selector(void)
{
}

long Selector::Create(Element*, unsigned long*, Element**)
{
	return 0;
}

long Selector::Register(void)
{
	return 0;
}

UID Selector::SelectionChange(void)
{
	return UID();
}

PropertyInfo const* Selector::SelectionProp(void)
{
	return nullptr;
}

void Selector::SetClassInfoPtr(IClassInfo*)
{
}

IClassInfo* Selector::GetClassInfoPtr(void)
{
	return nullptr;
}

Element* Selector::GetSelection(void)
{
	return nullptr;
}

long Selector::Initialize(Element*, unsigned long*)
{
	return 0;
}

Element* Selector::GetAdjacent(Element*, int, NavReference const*, unsigned long)
{
	return nullptr;
}

IClassInfo* Selector::GetClassInfoW(void)
{
	return nullptr;
}

void Selector::OnEvent(Event*)
{
}

void Selector::OnInput(InputEvent*)
{
}

void Selector::OnKeyFocusMoved(Element*, Element*)
{
}

void Selector::OnPropertyChanged(PropertyInfo const*, int, Value*, Value*)
{
}

long Selector::SetSelection(Element*)
{
	return 0;
}

IClassInfo* Selector::s_pClassInfo;
	
SelectorNoDefault::SelectorNoDefault(void)
{
}

long SelectorNoDefault::Create(Element*, unsigned long*, Element**)
{
	return 0;
}

IClassInfo* SelectorNoDefault::GetClassInfoPtr(void)
{
	return nullptr;
}

long SelectorNoDefault::Register(void)
{
	return 0;
}

void SelectorNoDefault::SetClassInfoPtr(IClassInfo*)
{
}

long SelectorNoDefault::Initialize(Element*, unsigned long*)
{
	return 0;
}

IClassInfo* SelectorNoDefault::GetClassInfoW(void)
{
	return nullptr;
}

void SelectorNoDefault::OnEvent(Event*)
{
}

void SelectorNoDefault::OnKeyFocusMoved(Element*, Element*)
{
}

long SelectorNoDefault::SetSelection(Element*)
{
	return 0;
}

IClassInfo* SelectorNoDefault::s_pClassInfo;

IClassInfo* ItemList::GetClassInfoPtr() STUB_ZERO;
IClassInfo* ItemList::GetClassInfoW() STUB_ZERO;
ItemList::ItemList() STUB_VOID;
ItemList::~ItemList() STUB_VOID;
HRESULT ItemList::SetReorderable(bool v) STUB_ZERO;
bool ItemList::IsReorderable() STUB_ZERO;
HRESULT ItemList::Register() STUB_ZERO;
HRESULT ItemList::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void ItemList::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
Element* ItemList::GetAdjacent(Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;

SelectorSelectionProxy::SelectorSelectionProxy(SelectorSelectionProxy const&)
{
}

SelectorSelectionProxy::SelectorSelectionProxy(void)
{
}

SelectorSelectionProxy& SelectorSelectionProxy::operator=(SelectorSelectionProxy const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

long SelectorSelectionProxy::DoMethod(int, char*)
{
	return 0;
}

void SelectorSelectionProxy::Init(Element*)
{
}

long SelectorSelectionProxy::GetIsSelectionRequired(int*)
{
	return 0;
}

SelectorSelectionItemProxy::SelectorSelectionItemProxy(SelectorSelectionItemProxy const&)
{
}

SelectorSelectionItemProxy::SelectorSelectionItemProxy(void)
{
}

SelectorSelectionItemProxy& SelectorSelectionItemProxy::operator=(SelectorSelectionItemProxy const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

long SelectorSelectionItemProxy::DoMethod(int, char*)
{
	return 0;
}

void SelectorSelectionItemProxy::Init(Element*)
{
}

long SelectorSelectionItemProxy::AddToSelection(void)
{
	return 0;
}

long SelectorSelectionItemProxy::GetSelectionContainer(IRawElementProviderSimple**)
{
	return 0;
}

long SelectorSelectionItemProxy::Select(void)
{
	return 0;
}

//~ Begin DirectUI::StyledScrollViewer Class
StyledScrollViewer::StyledScrollViewer() STUB_VOID;
StyledScrollViewer::~StyledScrollViewer() STUB_VOID;
HRESULT StyledScrollViewer::Create(Element* peParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void StyledScrollViewer::OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
IClassInfo* StyledScrollViewer::GetClassInfoPtr() STUB_ZERO;
void StyledScrollViewer::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* StyledScrollViewer::s_pClassInfo;
IClassInfo* StyledScrollViewer::GetClassInfoW() STUB_ZERO;
HRESULT StyledScrollViewer::Register() STUB_ZERO;
HRESULT StyledScrollViewer::CreateScrollBars() STUB_ZERO;
HRESULT StyledScrollViewer::AddChildren() STUB_ZERO;
BaseScrollBar* StyledScrollViewer::GetHScroll() STUB_ZERO;
BaseScrollBar* StyledScrollViewer::GetVScroll() STUB_ZERO;
//~ End DirectUI::StyledScrollViewer Class

TableProvider::TableProvider(void)
{
}

unsigned long TableProvider::AddRef(void)
{
	return 0;
}

long TableProvider::GetColumnHeaders(SAFEARRAY**)
{
	return 0;
}

PfnCreateProxy TableProvider::GetProxyCreator(void)
{
	return PfnCreateProxy();
}

long TableProvider::GetRowHeaders(SAFEARRAY**)
{
	return 0;
}

long TableProvider::QueryInterface(GUID const&, void**)
{
	return 0;
}

unsigned long TableProvider::Release(void)
{
	return 0;
}

long TableProvider::get_RowOrColumnMajor(RowOrColumnMajor*)
{
	return 0;
}

TableProxy::TableProxy()
{
}

TableProxy* TableProxy::Create(Element*)
{
	return nullptr;
}

bool TableProxy::IsPatternSupported(Element*)
{
	return false;
}

long TableProxy::DoMethod(int, char*)
{
	return 0;
}

void TableProxy::Init(Element*)
{
}

TableItemProvider::TableItemProvider()
{
}

TableItemProvider::~TableItemProvider(void)
{
}

unsigned long TableItemProvider::AddRef(void)
{
	return 0;
}

long TableItemProvider::GetColumnHeaderItems(SAFEARRAY**)
{
	return 0;
}

PfnCreateProxy TableItemProvider::GetProxyCreator(void)
{
	return PfnCreateProxy();
}

long TableItemProvider::GetRowHeaderItems(SAFEARRAY**)
{
	return 0;
}

long TableItemProvider::QueryInterface(GUID const&, void**)
{
	return 0;
}

unsigned long TableItemProvider::Release(void)
{
	return 0;
}

TableItemProxy::TableItemProxy(TableItemProxy const&)
{
}

TableItemProxy::TableItemProxy()
{
}

TableItemProxy& TableItemProxy::operator=(TableItemProxy const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

TableItemProxy* TableItemProxy::Create(Element*)
{
	return nullptr;
}

bool TableItemProxy::IsPatternSupported(Element*)
{
	return false;
}

long TableItemProxy::DoMethod(int, char*)
{
	return 0;
}

void TableItemProxy::Init(Element*)
{
}

//~ Begin DirectUI::TaskPage Class
TaskPage::TaskPage() STUB_VOID;
TaskPage::~TaskPage() STUB_VOID;
HRESULT TaskPage::DUICreatePropertySheetPage(HINSTANCE hInstance) STUB_ZERO;
TaskPage::operator HPROPSHEETPAGE() STUB_ZERO;
HWND TaskPage::GetParentHWND() STUB_ZERO;
LRESULT TaskPage::PropSheet_SendMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) STUB_ZERO;
Element* TaskPage::GetElement() STUB_ZERO;
HRESULT TaskPage::LoadParser(DUIXmlParser** ppParser) STUB_ZERO;
HRESULT TaskPage::LoadPage(Element** ppe, Element* pParent, DUIXmlParser** ppParser) STUB_ZERO;
HRESULT TaskPage::LoadPage(HWNDElement* peRoot, HINSTANCE hInstance, Element** ppe, DUIXmlParser** ppParser) STUB_ZERO;
UINT TaskPage::GetPageRCID() STUB_ZERO;
const WCHAR* TaskPage::GetPageResID() STUB_ZERO;
void TaskPage::InitPropSheetPage(PROPSHEETPAGE*) STUB_VOID;
LRESULT TaskPage::OnKillActive() STUB_ZERO;
LRESULT TaskPage::OnQueryCancel() STUB_ZERO;
LRESULT TaskPage::OnReset() STUB_ZERO;
LRESULT TaskPage::OnSetActive() STUB_ZERO;
LRESULT TaskPage::OnWizBack() STUB_ZERO;
LRESULT TaskPage::OnWizFinish() STUB_ZERO;
LRESULT TaskPage::OnWizNext() STUB_ZERO;
Element* TaskPage::OnQueryInitialFocus() STUB_ZERO;
bool TaskPage::OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
void TaskPage::OnListenerAttach(Element* peFrom) STUB_VOID;
void TaskPage::OnListenerDetach(Element* peFrom) STUB_VOID;
bool TaskPage::OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void TaskPage::OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void TaskPage::OnListenedInput(Element* peFrom, InputEvent* pInput) STUB_VOID;
void TaskPage::OnListenedEvent(Element* peFrom, Event* pEvent) STUB_VOID;
HRESULT TaskPage::CreateDUICP(HWNDElement* peRoot, HWND hwndParent, HWND hwndHost, Element** ppe, DUIXmlParser** ppParser) STUB_ZERO;
HRESULT TaskPage::CreateParserCP(DUIXmlParser** ppParser) STUB_ZERO;
void TaskPage::DestroyCP() STUB_VOID;
int TaskPage::OnWndMsg(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
HRESULT TaskPage::LoadComCtl32() STUB_ZERO;
void TaskPage::FreeComCtl32() STUB_VOID;
void TaskPage::StaticXmlParserError(const WCHAR* pszError, const WCHAR* pszToken, int dLine, void* pContext) STUB_VOID;
LRESULT TaskPage::StaticXHostSubclassProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) STUB_ZERO;
//~ End DirectUI::TaskPage Class

long TextGraphic::Create(Element*, unsigned long*, Element**)
{
	return 0;
}

IClassInfo* TextGraphic::GetClassInfoPtr(void)
{
	return nullptr;
}

long TextGraphic::Register(void)
{
	return 0;
}

void TextGraphic::SetClassInfoPtr(IClassInfo*)
{
}

PropertyInfo const* TextGraphic::SideGraphicProp(void)
{
	return nullptr;
}

long TextGraphic::Initialize(Element*, unsigned long*)
{
	return 0;
}

IClassInfo* TextGraphic::GetClassInfoW(void)
{
	return nullptr;
}

const WCHAR* TextGraphic::GetContentStringAsDisplayed(Value**)
{
	return nullptr;
}

void TextGraphic::OnPropertyChanged(PropertyInfo const*, int, Value*, Value*)
{
}

bool TextGraphic::OnPropertyChanging(PropertyInfo const*, int, Value*, Value*)
{
	return false;
}

IClassInfo* TextGraphic::s_pClassInfo;

Thumb::Thumb(Thumb const&)
{
}

Thumb::Thumb()
{
}

Thumb::~Thumb(void)
{
}

Thumb& Thumb::operator=(Thumb const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

long Thumb::Create(unsigned int, Element*, unsigned long*, Element**)
{
	return 0;
}

long Thumb::Create(Element*, unsigned long*, Element**)
{
	return 0;
}

UID Thumb::Drag(void)
{
	return UID();
}

IClassInfo* Thumb::GetClassInfoPtr(void)
{
	return nullptr;
}

long Thumb::Register(void)
{
	return 0;
}

void Thumb::SetClassInfoPtr(IClassInfo*)
{
}

long Thumb::Initialize(unsigned int, Element*, unsigned long*)
{
	return 0;
}

IClassInfo* Thumb::GetClassInfoW(void)
{
	return nullptr;
}

void Thumb::OnInput(InputEvent*)
{
}

IClassInfo* Thumb::s_pClassInfo;

ToggleProvider::ToggleProvider()
{
}

unsigned long ToggleProvider::AddRef(void)
{
	return 0;
}

PfnCreateProxy ToggleProvider::GetProxyCreator(void)
{
	return PfnCreateProxy();
}

long ToggleProvider::QueryInterface(GUID const&, void**)
{
	return 0;
}

unsigned long ToggleProvider::Release(void)
{
	return 0;
}

long ToggleProvider::Toggle(void)
{
	return 0;
}

long ToggleProvider::get_ToggleState(ToggleState*)
{
	return 0;
}

ToggleProxy::ToggleProxy()
{
}

ToggleProxy* ToggleProxy::Create(Element*)
{
	return nullptr;
}

bool ToggleProxy::IsPatternSupported(Element*)
{
	return false;
}

long ToggleProxy::DoMethod(int, char*)
{
	return 0;
}

void ToggleProxy::Init(Element*)
{
}

long ToggleProxy::GetToggleState(ToggleState*)
{
	return 0;
}

//~ Begin DirectUI::UnknownElement Class
HRESULT UnknownElement::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT UnknownElement::Create(UINT nActive, Element*, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
IClassInfo* UnknownElement::GetClassInfoPtr() STUB_ZERO;
void UnknownElement::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* UnknownElement::s_pClassInfo;
IClassInfo* UnknownElement::GetClassInfoW() STUB_ZERO;
HRESULT UnknownElement::Register() STUB_ZERO;
//~ End DirectUI::UnknownElement Class

//~ Begin DirectUI::Value Class
void Value::_ZeroRelease() STUB_VOID
HRESULT Value::StrDupW(const WCHAR* pszIn, WCHAR** pszOut) STUB_ZERO
Value* Value::CreateInt(int dValue, DynamicScaleValue dsv) STUB_ZERO
Value* Value::CreateFloat(float flValue, DynamicScaleValue dsv) STUB_ZERO
Value* Value::CreateBool(bool bValue) STUB_ZERO
Value* Value::CreateElementRef(Element* peValue) STUB_ZERO
Value* Value::CreateElementList(DynamicArray<Element*>* peListValue) STUB_ZERO
Value* Value::CreateString(const WCHAR* pszValue, HINSTANCE hResLoad) STUB_ZERO
Value* Value::CreateEncodedString(const WCHAR* pszValue) STUB_ZERO
Value* Value::CreatePoint(int x, int y, DynamicScaleValue dsv) STUB_ZERO
Value* Value::CreateSize(int cx, int cy, DynamicScaleValue dsv) STUB_ZERO
Value* Value::CreateRect(int left, int top, int right, int bottom, DynamicScaleValue dsv) STUB_ZERO
Value* Value::CreateColor(COLORREF cr) STUB_ZERO
Value* Value::CreateColor(COLORREF cr0, COLORREF cr1, BYTE dType) STUB_ZERO
Value* Value::CreateColor(COLORREF cr0, COLORREF cr1, COLORREF cr2, BYTE dType) STUB_ZERO
Value* Value::CreateFill(const Fill& fill) STUB_ZERO
Value* Value::CreateDFCFill(UINT uType, UINT uState) STUB_ZERO
Value* Value::CreateDTBFill(const WCHAR* pszClassName, int iPartId, int iStateId) STUB_ZERO
Value* Value::CreateLayout(Layout* plValue) STUB_ZERO
Value* Value::CreateGraphic(ISharedBitmap* pBitmap, BYTE dBlendMode, UINT dBlendValue) STUB_ZERO;
Value* Value::CreateGraphic(HBITMAP hBitmap, BYTE dBlendMode, UINT dBlendValue, bool bFlip, bool bRTL, bool bPremultiplied) STUB_ZERO;
Value* Value::CreateGraphic(HICON hIcon, bool bFlip, bool bRTL, bool bShared) STUB_ZERO;
Value* Value::CreateGraphic(const WCHAR* pszBMP, BYTE dBlendMode, UINT dBlendValue, USHORT cx, USHORT cy, HINSTANCE hResLoad, bool bFlip, bool bRTL) STUB_ZERO;
Value* Value::CreateGraphic(const WCHAR* pszICO, USHORT cxDesired, USHORT cyDesired, HINSTANCE hResLoad, bool bFlip, bool bRTL) STUB_ZERO;
Value* Value::CreateGraphic(HENHMETAFILE hEnhMetaFile, HENHMETAFILE hAltEnhMetaFile) STUB_ZERO;
Value* Value::CreateGraphic(const WCHAR* pszICO, ScaledSIZE szDesired, HINSTANCE hResLoad, bool bFlip, bool bRTL) STUB_ZERO;
Value* Value::CreateIconGraphicHelper(HICON hIcon, bool bFlip, bool bRTL, bool bShared) STUB_ZERO
HICON Value::ReloadIcon(Graphic* pGraphic, float fScaleFactor) STUB_ZERO
Value* Value::CreateStyleSheet(StyleSheet* ppsValue) STUB_ZERO
Value* Value::CreateExpression(Expression* pexValue) STUB_ZERO
Value* Value::CreateAtom(const WCHAR* pszValue) STUB_ZERO
Value* Value::CreateAtom(ATOM atom) STUB_ZERO
Value* Value::CreateCursor(const WCHAR* pszValue) STUB_ZERO
Value* Value::CreateCursor(HCURSOR hValue) STUB_ZERO
Value* Value::CreateValueList(ValueList* pvListValue) STUB_ZERO
Value* Value::CreateValueList(Value* pvValue) STUB_ZERO
Value* Value::CreateDoubleList(DynamicArray<double>* pdblListValue) STUB_ZERO
Value* Value::CreateDoubleList(const double* rgdbl, int cdbl) STUB_ZERO
Value* Value::CreateStringRP(const WCHAR* pszValue, HINSTANCE hResLoad) STUB_ZERO
Value* Value::CreateScaledValue(float flScaleFactor, Value* pvIn) STUB_ZERO
Value* Value::CreateElementScaledValue(Element* pe, Value* pvIn) STUB_ZERO
void Value::AddRef() STUB_VOID
void Value::Release() STUB_VOID
int Value::GetRefCount() const STUB_ZERO
int Value::GetType() const STUB_ZERO
void* Value::GetImage(bool bGetRTL, float fScaleFactor) STUB_ZERO
int Value::GetInt() STUB_ZERO
ScaledInt* Value::GetScaledInt() STUB_ZERO
int Value::GetScaledInt(float flScaleFactor) STUB_ZERO
float Value::GetFloat() STUB_ZERO
bool Value::GetBool() STUB_ZERO
Element* Value::GetElement() STUB_ZERO
DynamicArray<Element*>* Value::GetElementList() STUB_ZERO
const WCHAR* Value::GetString() STUB_ZERO
HRESULT Value::GetEncodedString(WCHAR* pszBuf, size_t cchBuf) STUB_ZERO
size_t Value::GetEncodedStringLength() STUB_ZERO
const POINT* Value::GetPoint() STUB_ZERO
const SIZE* Value::GetSize() STUB_ZERO
const RECT* Value::GetRect() STUB_ZERO
const Fill* Value::GetFill() STUB_ZERO
Layout* Value::GetLayout() STUB_ZERO
Graphic* Value::GetGraphic() STUB_ZERO
StyleSheet* Value::GetStyleSheet() STUB_ZERO
Expression* Value::GetExpression() STUB_ZERO
ATOM Value::GetAtom() STUB_ZERO
Cursor* Value::GetCursor() STUB_ZERO
ValueList* Value::GetValueList() STUB_ZERO
DynamicArray<double>* Value::GetDoubleList() STUB_ZERO
WCHAR* Value::GetStringDynamicScaling() STUB_ZERO
int Value::GetElementScaledInt(Element* pe) STUB_ZERO
void Value::GetScaledPoint(float flScaleFactor, POINT* ppt) STUB_VOID
void Value::GetElementScaledPoint(Element* pe, POINT* ppt) STUB_VOID
void Value::GetScaledSize(float flScaleFactor, SIZE* psize) STUB_VOID
void Value::GetElementScaledSize(Element* pe, SIZE* psize) STUB_VOID
void Value::GetScaledRect(float flScaleFactor, RECT* prc) STUB_VOID
void Value::GetElementScaledRect(Element* pe, RECT* prc) STUB_VOID
float Value::GetScaledFloat(float flScaleFactor) STUB_ZERO
float Value::GetElementScaledFloat(Element* pe) STUB_ZERO
bool Value::IsDynamicScaled() STUB_ZERO
bool Value::IsEqual(Value* pv) STUB_ZERO
WCHAR* Value::ToString(WCHAR* psz, UINT) const STUB_ZERO
void Value::SetLayoutPointerToNull() STUB_VOID
Value*Value::GetUnavailable() STUB_ZERO
Value*Value::GetNull() STUB_ZERO
Value*Value::GetUnset() STUB_ZERO
Value*Value::GetElementNull() STUB_ZERO
Value*Value::GetElListNull() STUB_ZERO
Value*Value::GetBoolTrue() STUB_ZERO
Value*Value::GetBoolFalse() STUB_ZERO
Value*Value::GetStringNull() STUB_ZERO
Value*Value::GetPointZero() STUB_ZERO
Value*Value::GetSizeZero() STUB_ZERO
Value*Value::GetRectZero() STUB_ZERO
Value*Value::GetIntZero() STUB_ZERO
Value*Value::GetIntMinusOne() STUB_ZERO
Value*Value::GetFloatZero() STUB_ZERO
Value*Value::GetFloatOne() STUB_ZERO
Value*Value::GetLayoutNull() STUB_ZERO
Value*Value::GetSheetNull() STUB_ZERO
Value*Value::GetExprNull() STUB_ZERO
Value*Value::GetAtomZero() STUB_ZERO
Value*Value::GetCursorNull() STUB_ZERO
Value*Value::GetColorTrans() STUB_ZERO
Value*Value::GetDblListEmpty() STUB_ZERO
Value* Value::GetStringRPNull() STUB_ZERO
//~ End DirectUI::Value Class

//~ Begin DirectUI::ValueProvider Class
ValueProvider::ValueProvider() STUB_VOID;
PfnCreateProxy ValueProvider::GetProxyCreator() STUB_ZERO;
HRESULT ValueProvider::QueryInterface(REFIID riid, void** ppvObject) STUB_ZERO;
ULONG ValueProvider::AddRef() STUB_ZERO;
ULONG ValueProvider::Release() STUB_ZERO;
HRESULT ValueProvider::SetValue(LPCWSTR val) STUB_ZERO;
HRESULT ValueProvider::get_Value(BSTR* pRetVal) STUB_ZERO;
HRESULT ValueProvider::get_IsReadOnly(BOOL* pRetVal) STUB_ZERO;
//~ End DirectUI::ValueProvider Class

//~ Begin DirectUI::ValueProxy Class
ValueProxy::ValueProxy()
{
}

ValueProxy* ValueProxy::Create(Element* pe)
{
	return nullptr;
}

bool ValueProxy::IsPatternSupported(Element* pe)
{
	return false;
}

HRESULT ValueProxy::DoMethod(int, char*)
{
	return 0;
}

void ValueProxy::Init(Element* pe)
{
}

HRESULT ValueProxy::GetIsReadOnly(int*)
{
	return 0;
}

HRESULT ValueProxy::GetValue(BSTR* pRetVal)
{
	return 0;
}

HRESULT ValueProxy::SetValue(const unsigned short*)
{
	return 0;
}

//~ End ValueProxy Class

//~ Begin DirectUI::Viewer Class
HRESULT Viewer::Create(Element* peParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void Viewer::OnEvent(Event* pEvent) STUB_VOID;
void Viewer::OnInput(InputEvent* pie) STUB_VOID;
bool Viewer::OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void Viewer::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void Viewer::_SelfLayoutDoLayout(int cx, int cy) STUB_VOID;
SIZE Viewer::_SelfLayoutUpdateDesiredSize(int cxConstraint, int cyConstraint, Surface* psrf) STUB_ZERO;
const PropertyInfo* Viewer::XOffsetProp() STUB_ZERO;
const PropertyInfo* Viewer::YOffsetProp() STUB_ZERO;
const PropertyInfo* Viewer::XScrollableProp() STUB_ZERO;
const PropertyInfo* Viewer::YScrollableProp() STUB_ZERO;
int Viewer::GetXOffset() STUB_ZERO;
int Viewer::GetYOffset() STUB_ZERO;
bool Viewer::GetXScrollable() STUB_ZERO;
bool Viewer::GetYScrollable() STUB_ZERO;
HRESULT Viewer::SetXOffset(int v) STUB_ZERO;
HRESULT Viewer::SetYOffset(int v) STUB_ZERO;
HRESULT Viewer::SetXScrollable(bool v) STUB_ZERO;
HRESULT Viewer::SetYScrollable(bool v) STUB_ZERO;
IClassInfo* Viewer::GetClassInfoPtr() STUB_ZERO;
void Viewer::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* Viewer::s_pClassInfo;
IClassInfo* Viewer::GetClassInfoW() STUB_ZERO;
HRESULT Viewer::Register() STUB_ZERO;
bool Viewer::EnsureVisible(int x, int y, int cx, int cy) STUB_ZERO;
Viewer::Viewer() STUB_VOID;
HRESULT Viewer::Initialize(Element* pParent, DWORD* pdwDeferCooke) STUB_ZERO;
Viewer::~Viewer() STUB_VOID;
void Viewer::SetEnsureVisibleUseLayoutCoordinates(bool fUseLayoutCoordinates) STUB_VOID;
Element* Viewer::_GetContent() STUB_ZERO;
bool Viewer::_InternalEnsureVisible(int x, int y, int cx, int cy) STUB_ZERO;
//~ End DirectUI::Viewer Class

//~ Begin DirectUI::XBaby Class
XBaby::~XBaby() STUB_VOID;
HRESULT WINAPI XBaby::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppe) STUB_ZERO;
HRESULT WINAPI XBaby::Create(IXElementCP* pcp, XProvider* pprov, HWND hwndParent, Element* pParent, DWORD* pdwDeferCookie, Element** ppe) STUB_ZERO;
IClassInfo* WINAPI XBaby::GetClassInfoPtr() STUB_ZERO;
void WINAPI XBaby::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* XBaby::s_pClassInfo;
IClassInfo* XBaby::GetClassInfoW() STUB_ZERO;
HRESULT WINAPI XBaby::Register() STUB_ZERO;
Element* XBaby::GetAdjacent(Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) STUB_ZERO;
void XBaby::OnEvent(Event* pEvent) STUB_VOID;
void XBaby::OnThemeChanged(ThemeChangedEvent* pev) STUB_VOID;
void XBaby::OnNoChildWithShortcutFound(KeyboardEvent* pke) STUB_VOID;
bool XBaby::OnChildLostFocus(Element* peFrom) STUB_ZERO;
bool XBaby::OnChildReceivedFocus(Element* peTo) STUB_ZERO;
HRESULT XBaby::CreateStyleParser(DUIXmlParser** ppParser) STUB_ZERO;
void XBaby::OnWmThemeChanged(WPARAM wParam, LPARAM lParam) STUB_VOID;
Element* XBaby::GetFocusableElement() STUB_ZERO;
void XBaby::SetKeyFocus() STUB_VOID;
HRESULT XBaby::GetElementProviderImpl(InvokeHelper* pih, ElementProvider** ppprv) STUB_ZERO;
HWNDElement* XBaby::GetXBabyElement() STUB_ZERO;
void XBaby::CacheParser(DUIXmlParser* pParserNew) STUB_VOID;
HRESULT XBaby::SetToHost(Element* peToHost) STUB_ZERO;
SIZE XBaby::GetContentDesiredSize(int cxConstraint, int cyConstraint) STUB_ZERO;
bool XBaby::CanSetFocus() STUB_ZERO;
HRESULT XBaby::GetHostedElementID(ATOM* patomID) STUB_ZERO;
void XBaby::ForceThemeChange(WPARAM wParam, LPARAM lParam) STUB_VOID;
bool XBaby::GetDefaultButtonTracking() STUB_ZERO;
HRESULT XBaby::SetDefaultButtonTracking(bool v) STUB_ZERO;
HRESULT XBaby::SetButtonClassAcceptsEnterKey(bool v) STUB_ZERO;
bool XBaby::ClickDefaultButton() STUB_ZERO;
HRESULT XBaby::SetRegisteredDefaultButton(Element* v) STUB_ZERO;
HRESULT XBaby::SetHandleEnterKey(bool v) STUB_ZERO;
HRESULT XBaby::Initialize(IXElementCP* pcp, XProvider* pprov, HWND hwndParent, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
//~ End DirectUI::XBaby Class

// Begin DirectUI::XElement Class
HWND XElement::GetNotificationSinkHWND() STUB_ZERO;
UINT XElement::GetCreationFlags() STUB_ZERO;
const UINT XElement::s_uNavigateOutMsg = RegisterWindowMessage(L"XElementNavigateOut");
const UINT XElement::s_uButtonFocusChangeMsg = RegisterWindowMessage(L"XElementButtonFocusChange");
const UINT XElement::s_uUnhandledSyscharMsg = RegisterWindowMessage(L"XElementUnhandledSyschar");
UID XElement::UnhandledSyschar() STUB_ZERO;
XElement::XElement() STUB_VOID;
XElement::~XElement() STUB_VOID;
HRESULT XElement::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT XElement::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void XElement::OnInput(InputEvent* pie) STUB_VOID;
bool XElement::OnMessage(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
bool XElement::OnSysChar(WCHAR chKeyCode) STUB_ZERO;
bool XElement::OnSinkThemeChanged(UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet) STUB_ZERO;
void XElement::OnEvent(Event* pEvent) STUB_VOID;
HRESULT XElement::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
HWND XElement::CreateHWND(HWND hwndParent) STUB_ZERO;
void XElement::SetKeyFocus() STUB_VOID;
IClassInfo* XElement::GetClassInfoPtr() STUB_ZERO;
void XElement::SetClassInfoPtr(IClassInfo* pClass) STUB_VOID;
IClassInfo* XElement::s_pClassInfo;
IClassInfo* XElement::GetClassInfoW() STUB_ZERO;
HRESULT XElement::Register() STUB_ZERO;
IXProvider* XElement::GetProvider() STUB_ZERO;
HRESULT XElement::SetProvider(IUnknown* punk) STUB_ZERO;
void XElement::FreeProvider() STUB_VOID;
bool XElement::IsDescendent(Element* pe) STUB_ZERO;
HWND XElement::GetInnerHWND() STUB_ZERO;
//~ End DirectUI::XElement Class

HRESULT XProvider::QueryInterface(REFIID iid, void** ppv) STUB_ZERO;
ULONG XProvider::AddRef() STUB_ZERO;
ULONG XProvider::Release() STUB_ZERO;
HRESULT XProvider::CreateDUI(IXElementCP* pcp, HWND* phwnd) STUB_ZERO;
HRESULT XProvider::SetParameter(REFGUID, void*) STUB_ZERO;
HRESULT XProvider::GetDesiredSize(int cxConstraint, int cyConstraint, SIZE* ps) STUB_ZERO;
HRESULT XProvider::IsDescendent(Element* pe, bool* pbHandled) STUB_ZERO;
HRESULT XProvider::SetFocus(Element* pe) STUB_ZERO;
HRESULT XProvider::Navigate(int iNavDir, bool* pbHandled) STUB_ZERO;
HRESULT XProvider::CanSetFocus(bool* pfCanSetFocus) STUB_ZERO;
BOOL XProvider::FindElementWithShortcutAndDoDefaultAction(WCHAR ch, BOOL fSysKey) STUB_ZERO;
HRESULT XProvider::GetHostedElementID(ATOM* patomID) STUB_ZERO;
HRESULT XProvider::ForceThemeChange(WPARAM wParam, LPARAM lParam) STUB_ZERO;
HRESULT XProvider::SetDefaultButtonTracking(bool fEnabled) STUB_ZERO;
BOOL XProvider::ClickDefaultButton() STUB_ZERO;
HRESULT XProvider::SetRegisteredDefaultButton(Element* peDefaultButton) STUB_ZERO;
HRESULT XProvider::SetButtonClassAcceptsEnterKey(bool fEnabled) STUB_ZERO;
HRESULT XProvider::Create(Element* pe, IXProviderCP* pprovCP, XProvider** ppxp) STUB_ZERO;
HRESULT XProvider::Initialize(Element* pe, IXProviderCP* pprovCP) STUB_ZERO;
HRESULT XProvider::CreateXBaby(IXElementCP* pcp, HWND hwndParent, Element* pParent, DWORD* pdwDeferCookie, IXBaby** ppIXBaby) STUB_ZERO;
HRESULT XProvider::CreateParser(DUIXmlParser** ppParser) STUB_ZERO;
XProvider::XProvider() STUB_VOID;
XProvider::~XProvider() STUB_VOID;
Element* XProvider::GetRoot() STUB_ZERO;
void XProvider::SetHandleEnterKey(bool fHandle) STUB_VOID;

ElementProvider::ElementProvider() STUB_VOID;
ElementProvider::~ElementProvider() STUB_VOID;
PfnCreateProxy ElementProvider::GetProxyCreator() STUB_ZERO;
const Element* ElementProvider::GetElementKey() STUB_ZERO;
const volatile Element* ElementProvider::GetElement() STUB_ZERO;
void ElementProvider::TossPatternProvider(const Schema::Pattern pattern) STUB_VOID;
void ElementProvider::TossElement() STUB_VOID;
HRESULT ElementProvider::Create(Element* pe, InvokeHelper* pih, ElementProvider** ppprv) STUB_ZERO;
HRESULT ElementProvider::QueryInterface(REFIID riid, void** ppvObject) STUB_ZERO;
ULONG ElementProvider::AddRef() STUB_ZERO;
ULONG ElementProvider::Release() STUB_ZERO;
HRESULT ElementProvider::get_ProviderOptions(ProviderOptions* pRetVal) STUB_ZERO;
HRESULT ElementProvider::GetPatternProvider(PATTERNID id, IUnknown** ppunk) STUB_ZERO;
HRESULT ElementProvider::GetPropertyValue(PROPERTYID propertyID, VARIANT* pvar) STUB_ZERO;
HRESULT ElementProvider::get_HostRawElementProvider(IRawElementProviderSimple** ppprv) STUB_ZERO;
HRESULT ElementProvider::ShowContextMenu() STUB_ZERO;
HRESULT ElementProvider::Navigate(NavigateDirection direction, IRawElementProviderFragment** ppprv) STUB_ZERO;
HRESULT ElementProvider::GetRuntimeId(SAFEARRAY** pparray) STUB_ZERO;
HRESULT ElementProvider::get_BoundingRectangle(UiaRect* prect) STUB_ZERO;
HRESULT ElementProvider::GetEmbeddedFragmentRoots(SAFEARRAY** pRetVal) STUB_ZERO;
HRESULT ElementProvider::SetFocus() STUB_ZERO;
HRESULT ElementProvider::get_FragmentRoot(IRawElementProviderFragmentRoot** ppprv) STUB_ZERO;
HRESULT ElementProvider::AdviseEventAdded(EVENTID id, SAFEARRAY* propertyIds) STUB_ZERO;
HRESULT ElementProvider::AdviseEventRemoved(EVENTID id, SAFEARRAY* propertyIds) STUB_ZERO;
HRESULT ElementProvider::DoInvokeArgs(MethodId methodId, PfnCreateProxy pfnCreate, va_list args) STUB_ZERO;
HRESULT ElementProvider::Init(Element* pe, InvokeHelper* pih) STUB_ZERO;
HRESULT ElementProvider::DoInvoke(MethodId methodId, ...) STUB_ZERO;

ElementProxy* ElementProxy::Create(Element* pe) STUB_ZERO;
HRESULT ElementProxy::DoMethod(MethodId methodId, va_list args) STUB_ZERO;
ElementProxy::ElementProxy() STUB_VOID;
void ElementProxy::Init(Element* pe) STUB_VOID;
HRESULT ElementProxy::Navigate(NavigateDirection direction, IRawElementProviderFragment** ppprv) STUB_ZERO;
HRESULT ElementProxy::GetBoundingRect(UiaRect* prect) STUB_ZERO;
HRESULT ElementProxy::GetProperty(VARIANT* pvar, PROPERTYID propertyId) STUB_ZERO;
HRESULT ElementProxy::GetRuntimeId(SAFEARRAY** ppArray) STUB_ZERO;
HRESULT ElementProxy::SetString(VARIANT* pvar, PfnStringVal pfn) STUB_ZERO;
HRESULT ElementProxy::GetFragmentRoot(IRawElementProviderFragmentRoot** ppprv) STUB_ZERO;
HRESULT ElementProxy::IsPatternSupported(Schema::Pattern pattern, bool* pf) STUB_ZERO;
HRESULT ElementProxy::GetLabel(VARIANT* pvar) STUB_ZERO;
HRESULT ElementProxy::GetContent(VARIANT* pvar, IAccessible* pAccessible) STUB_ZERO;
HRESULT ElementProxy::GetProviderOptions(ProviderOptions* ppo) STUB_ZERO;
HRESULT ElementProxy::GetHwnd(HWND* phwnd) STUB_ZERO;
HRESULT ElementProxy::GetAutomationId(VARIANT* pvar) STUB_ZERO;
void ElementProxy::GetControlType(VARIANT* pvar, IAccessible* pAccessible) STUB_VOID;
BOOL ElementProxy::_UsesUIAProxies() STUB_ZERO;
bool ElementProxy::_IsSemanticZoomControl(int id) STUB_ZERO;
bool ElementProxy::_IsWindowHostUsingDoNotStealFocusFlag() STUB_ZERO;

ElementProviderManager& ElementProviderManager::operator=(class DirectUI::ElementProviderManager const&)
{
	return *this;
}

long WINAPI ElementProviderManager::Add(ElementProvider*)
{
	return 0;
}

void __stdcall ElementProviderManager::Close()
{
}

ElementProvider*__stdcall ElementProviderManager::Find(Element*)
{
	return NULL;
}

bool __stdcall ElementProviderManager::FindProviderCallback(ElementProvider*, void*)
{
	return 0;
}

long __stdcall ElementProviderManager::Init()
{
	return 0;
}

void __stdcall ElementProviderManager::Remove(ElementProvider*)
{
}

CRITICAL_SECTION ElementProviderManager::g_cs;
UiaArray<ElementProvider*>* ElementProviderManager::g_pArrayPprv;


DUIFactory::DUIFactory(HWND hwnd) STUB_VOID
DUIFactory::~DUIFactory() STUB_VOID

DUIFactory& DUIFactory::operator=(DUIFactory const&)
{
	return *this;
}

HRESULT DUIFactory::CreateParser() STUB_ZERO
	
DUIXmlParser* DUIFactory::DetachParser()
{
	return nullptr;
}

DUIXmlParser* DUIFactory::GetParser()
{
	return nullptr;
}

HRESULT DUIFactory::LoadFromBuffer(const WCHAR*, UINT cchBuf, const WCHAR*, Element*, DWORD*, Element**) STUB_ZERO
HRESULT DUIFactory::LoadFromFile(LPCWSTR, LPCWSTR, Element*, DWORD*, Element**) STUB_ZERO
HRESULT DUIFactory::LoadFromResource(HINSTANCE, LPCWSTR, LPCWSTR, Element*, DWORD*, Element**, LPCWSTR) STUB_ZERO
void DUIFactory::SetError(LPCWSTR, ...) STUB_VOID
void DUIFactory::s_XMLParseError(const WCHAR*, const WCHAR*, int, DUIFactory*) STUB_VOID
void DUIFactory::ClearParser() STUB_VOID

BrowserSelectionProxy::BrowserSelectionProxy(BrowserSelectionProxy const&)
{
}

BrowserSelectionProxy::BrowserSelectionProxy(void)
{
}

BrowserSelectionProxy& BrowserSelectionProxy::operator=(BrowserSelectionProxy const&)
{
	// TODO: 在此处插入 return 语句
	return *this;
}

long BrowserSelectionProxy::DoMethod(int, char*)
{
	return 0;
}

void BrowserSelectionProxy::Init(Element*)
{
}

long BrowserSelectionProxy::GetIsSelectionRequired(int*)
{
	return 0;
}

long BrowserSelectionProxy::GetSelection(SAFEARRAY**)
{
	return 0;
}

IClassInfo* RichText::GetClassInfoPtr() STUB_ZERO;
IClassInfo* RichText::GetClassInfoW() STUB_ZERO;
RichText::RichText() STUB_VOID;
RichText::~RichText() STUB_VOID;
HRESULT RichText::Register() STUB_ZERO;
HRESULT RichText::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT RichText::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
void RichText::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void RichText::OnEvent(Event* pEvent) STUB_VOID;
void RichText::OnHosted(Element* peNew) STUB_VOID;
void RichText::Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) STUB_VOID;
SIZE RichText::GetContentSize(int pxConstW, int pxConstH, Surface* psrf) STUB_ZERO;
const PropertyInfo* RichText::FontColorRunsProp() STUB_ZERO;
const PropertyInfo* RichText::FontSizeRunsProp() STUB_ZERO;
const PropertyInfo* RichText::FontWeightRunsProp() STUB_ZERO;
const PropertyInfo* RichText::OverhangOffsetProp() STUB_ZERO;
const PropertyInfo* RichText::TypographyProp() STUB_ZERO;
const PropertyInfo* RichText::TypographyRunsProp() STUB_ZERO;
const PropertyInfo* RichText::LocaleProp() STUB_ZERO;
const PropertyInfo* RichText::BaselineProp() STUB_ZERO;
const PropertyInfo* RichText::LineSpacingProp() STUB_ZERO;
const PropertyInfo* RichText::AliasedRenderingProp() STUB_ZERO;
const PropertyInfo* RichText::DisableAccTextExtendProp() STUB_ZERO;
const PropertyInfo* RichText::MapRunsToClustersProp() STUB_ZERO;
const PropertyInfo* RichText::VerticalScriptProp() STUB_ZERO;
const PropertyInfo* RichText::ConstrainLayoutProp() STUB_ZERO;
const PropertyInfo* RichText::ColorFontPaletteIndexProp() STUB_ZERO;
HRESULT RichText::SetFontColorRuns(const WCHAR* v) STUB_ZERO;
HRESULT RichText::SetFontSizeRuns(const WCHAR* v) STUB_ZERO;
HRESULT RichText::SetFontWeightRuns(const WCHAR* v) STUB_ZERO;
HRESULT RichText::SetTypography(const WCHAR* v) STUB_ZERO;
HRESULT RichText::SetTypographyRuns(const WCHAR* v) STUB_ZERO;
HRESULT RichText::SetLocale(const WCHAR* v) STUB_ZERO;
HRESULT RichText::SetBaseline(int v) STUB_ZERO;
HRESULT RichText::SetLineSpacing(int v) STUB_ZERO;
HRESULT RichText::SetOverhangOffset(int v) STUB_ZERO;
HRESULT RichText::SetAliasedRendering(bool v) STUB_ZERO;
HRESULT RichText::SetDisableAccTextExtend(bool v) STUB_ZERO;
HRESULT RichText::SetMapRunsToClusters(bool v) STUB_ZERO;
HRESULT RichText::SetVerticalScript(bool v) STUB_ZERO;
HRESULT RichText::SetConstrainLayout(int v) STUB_ZERO;
HRESULT RichText::SetColorFontPaletteIndex(int v) STUB_ZERO;
HRESULT RichText::GetForegroundColorRef(COLORREF* pclrForeground) STUB_ZERO;
WCHAR RichText::GetShortcutChar() STUB_ZERO;
void RichText::SetDWriteTextLayout(IDWriteTextLayout* pdwTextLayout) STUB_VOID;
DWORD RichText::GetTrimmedLineCount() STUB_ZERO;
DWORD RichText::GetLineCount() STUB_ZERO;
IDWriteFactory* RichText::GetFactory() STUB_ZERO;
void RichText::SetDWriteFontCollection(IDWriteFontCollection* pdwFontCollection) STUB_VOID;
void RichText::SetMaxLineCount(UINT cLinesMax) STUB_VOID;
HRESULT RichText::CreateCache(UINT cAverageNumberOfEntries, IDUIRichTextCache** ppCache) STUB_ZERO;
void RichText::SetCache(DWORD dwKey, IDUIRichTextCache* pCache) STUB_VOID;
void RichText::StopUsingCache() STUB_VOID;

UID PVLAnimation::NotifyStart() STUB_ZERO;
UID PVLAnimation::NotifyComplete() STUB_ZERO;
UID PVLAnimation::NotifyImplicit() STUB_ZERO;
UID PVLAnimation::NotifyStoryboardComplete() STUB_ZERO;
UID PVLAnimation::ManualStoryboardVerify() STUB_ZERO;
UID PVLAnimation::ReflowStyle() STUB_ZERO;
UID PVLAnimation::CustomReflowHint() STUB_ZERO;
UID PVLAnimation::CustomDragDropScalingHint() STUB_ZERO;
UID PVLAnimation::CustomTapHint() STUB_ZERO;
UID PVLAnimation::TriggeredAnimationComplete() STUB_ZERO;
UID PVLAnimation::AnimationStatusChange() STUB_ZERO;

IClassInfo* ModernProgressBar::GetClassInfoPtr() STUB_ZERO;
IClassInfo* ModernProgressBar::GetClassInfoW() STUB_ZERO;
ModernProgressBar::ModernProgressBar() STUB_VOID;
ModernProgressBar::~ModernProgressBar() STUB_VOID;
const PropertyInfo* ModernProgressBar::PositionProp() STUB_ZERO;
const PropertyInfo* ModernProgressBar::MinimumProp() STUB_ZERO;
const PropertyInfo* ModernProgressBar::MaximumProp() STUB_ZERO;
const PropertyInfo* ModernProgressBar::StateProp() STUB_ZERO;
const PropertyInfo* ModernProgressBar::DeterminateProp() STUB_ZERO;
int ModernProgressBar::GetPosition() STUB_ZERO;
int ModernProgressBar::GetMaximum() STUB_ZERO;
int ModernProgressBar::GetMinimum() STUB_ZERO;
int ModernProgressBar::GetState() STUB_ZERO;
bool ModernProgressBar::IsDeterminate() STUB_ZERO;
bool ModernProgressBar::IsActivityOccuring() STUB_ZERO;
bool ModernProgressBar::IsAutoHeight() STUB_ZERO;
bool ModernProgressBar::IsSmoothFillAnimation() STUB_ZERO;
bool ModernProgressBar::IsAddLayeredRef() STUB_ZERO;
bool ModernProgressBar::IsIndependentAnimations() STUB_ZERO;
HRESULT ModernProgressBar::SetPosition(int v) STUB_ZERO;
HRESULT ModernProgressBar::SetMaximum(int v) STUB_ZERO;
HRESULT ModernProgressBar::SetMinimum(int v) STUB_ZERO;
HRESULT ModernProgressBar::SetState(int v) STUB_ZERO;
HRESULT ModernProgressBar::SetDeterminate(bool v) STUB_ZERO;
HRESULT ModernProgressBar::SetActivityOccuring(bool v) STUB_ZERO;
HRESULT ModernProgressBar::SetAutoHeight(bool v) STUB_ZERO;
HRESULT ModernProgressBar::SetSmoothFillAnimation(bool v) STUB_ZERO;
HRESULT ModernProgressBar::SetAddLayeredRef(bool v) STUB_ZERO;
HRESULT ModernProgressBar::SetIndependentAnimations(bool v) STUB_ZERO;
HRESULT ModernProgressBar::Register() STUB_ZERO;
HRESULT ModernProgressBar::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void ModernProgressBar::OnDestroy() STUB_VOID;
void ModernProgressBar::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void ModernProgressBar::Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) STUB_VOID;
void ModernProgressBar::OnHosted(Element* peNewHost) STUB_VOID;
void ModernProgressBar::OnUnHosted(Element* peOldHost) STUB_VOID;

HRESULT TouchButton::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT TouchButton::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void TouchButton::OnHosted(Element* peNewRoot) STUB_VOID;
void TouchButton::OnUnHosted(Element* peOldRoot) STUB_VOID;
void TouchButton::OnInput(InputEvent* pie) STUB_VOID;
void TouchButton::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void TouchButton::OnEvent(Event* pEvent) STUB_VOID;
HRESULT TouchButton::DefaultAction() STUB_ZERO;
void TouchButton::GetImmersiveFocusRectOffsets(RECT* prc) STUB_VOID;
HRESULT TouchButton::GetForegroundColorRef(COLORREF* pclrForeground) STUB_ZERO;
UID TouchButton::Click() STUB_ZERO;
UID TouchButton::MultipleClick() STUB_ZERO;
UID TouchButton::RightClick() STUB_ZERO;
const PropertyInfo* TouchButton::PressedProp() STUB_ZERO;
bool TouchButton::GetPressed() STUB_ZERO;
HRESULT TouchButton::SetPressed(bool v) STUB_ZERO;
const PropertyInfo* TouchButton::CapturedProp() STUB_ZERO;
bool TouchButton::GetCaptured() STUB_ZERO;
HRESULT TouchButton::SetCaptured(bool v) STUB_ZERO;
const PropertyInfo* TouchButton::HandleEnterProp() STUB_ZERO;
bool TouchButton::GetHandleEnter() STUB_ZERO;
HRESULT TouchButton::SetHandleEnter(bool v) STUB_ZERO;
const PropertyInfo* TouchButton::ShowKeyFocusProp() STUB_ZERO;
bool TouchButton::GetShowKeyFocus() STUB_ZERO;
HRESULT TouchButton::SetShowKeyFocus(bool v) STUB_ZERO;
const PropertyInfo* TouchButton::TreatRightMouseButtonAsLeftProp() STUB_ZERO;
bool TouchButton::GetTreatRightMouseButtonAsLeft() STUB_ZERO;
HRESULT TouchButton::SetTreatRightMouseButtonAsLeft(bool v) STUB_ZERO;
const PropertyInfo* TouchButton::HandleGlobalEnterProp() STUB_ZERO;
bool TouchButton::GetHandleGlobalEnter() STUB_ZERO;
HRESULT TouchButton::SetHandleGlobalEnter(bool v) STUB_ZERO;
IClassInfo* TouchButton::GetClassInfoPtr() STUB_ZERO;
void TouchButton::SetClassInfoPtr(IClassInfo*) STUB_VOID;
IClassInfo* TouchButton::GetClassInfoW() STUB_ZERO;
HRESULT TouchButton::Register() STUB_ZERO;
TouchButton::TouchButton() STUB_VOID;
HRESULT TouchButton::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
bool TouchButton::CancelClick(ClickDevice nClickDevice) STUB_ZERO;
TouchButton::ClickDevice TouchButton::GetClickDevice() STUB_ZERO;
TouchButton::~TouchButton() STUB_VOID;
void TouchButton::FireClickEvent(UINT cClick, UINT uModifiers, ClickDevice clickDevice, POINT* ppt) STUB_VOID;
void TouchButton::FireRightClickEvent(UINT uModifiers, POINT* ppt) STUB_VOID;
TouchButton::TouchButtonListenerHelper::TouchButtonListenerHelper() STUB_VOID
void TouchButton::TouchButtonListenerHelper::OnListenedInput(Element* peFrom, InputEvent* pInput) STUB_VOID;

HRESULT TouchCheckBox::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT TouchCheckBox::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void TouchCheckBox::Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) STUB_VOID;
bool TouchCheckBox::OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void TouchCheckBox::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void TouchCheckBox::OnEvent(Event* pEvent) STUB_VOID;
HRESULT TouchCheckBox::Insert(Element** ppe, UINT cCount, UINT iInsertIdx) STUB_ZERO;
void TouchCheckBox::GetImmersiveFocusRectOffsets(RECT* prc) STUB_VOID;
const PropertyInfo* TouchCheckBox::CheckedStateProp() STUB_ZERO;
CheckedStateFlags TouchCheckBox::GetCheckedState() STUB_ZERO;
HRESULT TouchCheckBox::SetCheckedState(CheckedStateFlags v) STUB_ZERO;
const PropertyInfo* TouchCheckBox::ToggleOnClickProp() STUB_ZERO;
bool TouchCheckBox::GetToggleOnClick() STUB_ZERO;
HRESULT TouchCheckBox::SetToggleOnClick(bool v) STUB_ZERO;
IClassInfo* TouchCheckBox::GetClassInfoPtr() STUB_ZERO;
IClassInfo* TouchCheckBox::GetClassInfoW() STUB_ZERO;
HRESULT TouchCheckBox::Register() STUB_ZERO;
TouchCheckBox::TouchCheckBox() STUB_VOID;
HRESULT TouchCheckBox::Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
TouchCheckBox::~TouchCheckBox() STUB_VOID;

HRESULT TouchHWNDElement::Create(HWND hwndParent, bool fDblBuffer, UINT nCreate, Element* peParent, DWORD* pdwDeferCookie, Element** ppe) STUB_ZERO;
UID TouchHWNDElement::TooltipTimerStarting() STUB_ZERO;
UID TouchHWNDElement::TextTooltipShowing() STUB_ZERO;
UID TouchHWNDElement::RichTooltipShowing() STUB_ZERO;
UID TouchHWNDElement::ForwardingWindowMessage() STUB_ZERO;
UID TouchHWNDElement::ProcessingKeyboardNavigation() STUB_ZERO;
UID TouchHWNDElement::ScaleChanged() STUB_ZERO;
UID TouchHWNDElement::MonitorPowerSettingsChange() STUB_ZERO;
UID TouchHWNDElement::IHMNotify() STUB_ZERO;
const PropertyInfo* TouchHWNDElement::FlagsProp() STUB_ZERO;
TouchHWNDElementFlags TouchHWNDElement::GetFlags() STUB_ZERO;
HRESULT TouchHWNDElement::SetFlags(TouchHWNDElementFlags v, TouchHWNDElementFlags vmask) STUB_ZERO;
const PropertyInfo* TouchHWNDElement::WindowAccessGradientColorProp() STUB_ZERO;
Value* TouchHWNDElement::GetWindowAccessGradientColor() STUB_ZERO;
HRESULT TouchHWNDElement::SetWindowAccessGradientColor(Value* v) STUB_ZERO;
const PropertyInfo* TouchHWNDElement::TooltipMaximumLineCountProp() STUB_ZERO;
int TouchHWNDElement::GetTooltipMaximumLineCount() STUB_ZERO;
HRESULT TouchHWNDElement::SetTooltipMaximumLineCount(int v) STUB_ZERO;
const PropertyInfo* TouchHWNDElement::LightDismissIHMProp() STUB_ZERO;
bool TouchHWNDElement::GetLightDismissIHM() STUB_ZERO;
HRESULT TouchHWNDElement::SetLightDismissIHM(bool v) STUB_ZERO;
HRESULT TouchHWNDElement::Initialize(HWND hwndParent, bool fDblBuffer, UINT nCreate, Element* peParent, DWORD* pdwDeferCookie) STUB_ZERO;
UINT TouchHWNDElement::MessageCallback(GMSG* pGMsg) STUB_ZERO;
void TouchHWNDElement::OnInput(InputEvent* pInput) STUB_VOID;
void TouchHWNDElement::OnEvent(Event* pEvent) STUB_VOID;
void TouchHWNDElement::OnKeyFocusMoved(Element* peFrom, Element* peTo) STUB_VOID;
void TouchHWNDElement::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
LRESULT TouchHWNDElement::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) STUB_ZERO;
bool TouchHWNDElement::IsMSAAEnabled() STUB_ZERO;
void TouchHWNDElement::OnDestroy() STUB_VOID;
void TouchHWNDElement::UpdateTooltip(Element* pe) STUB_VOID;
void TouchHWNDElement::ActivateTooltip(Element*, DWORD dwFlags) STUB_VOID;
void TouchHWNDElement::RemoveTooltip(Element* pe) STUB_VOID;
HRESULT TouchHWNDElement::StartRichTooltipTimer(TOUCHTOOLTIP_INPUT touchTooltipInput) STUB_ZERO;
HRESULT TouchHWNDElement::ShowRichTooltip(TOUCHTOOLTIP_INPUT touchTooltipInput, TOUCHTOOLTIP_OPTION_FLAGS touchTooltipOptions, Element* peTooltipContents) STUB_ZERO;
HRESULT TouchHWNDElement::HideTouchTooltip() STUB_ZERO;
HRESULT TouchHWNDElement::RegisterForMonitorPowerChanges() STUB_ZERO;
HRESULT TouchHWNDElement::UnregisterForMonitorPowerChanges() STUB_ZERO;
bool TouchHWNDElement::ShouldUsePerMonitorScaling() STUB_ZERO;
void TouchHWNDElement::UsePerMonitorScaling(HMONITOR hMon) STUB_VOID;
HRESULT TouchHWNDElement::RegisterForIHMChanges() STUB_ZERO;
void TouchHWNDElement::UnregisterForIHMChanges() STUB_VOID;
HRESULT TouchHWNDElement::GetIHMRect(RECT* prc) STUB_ZERO;
IHMState TouchHWNDElement::GetIHMState() STUB_ZERO;
HRESULT TouchHWNDElement::DismissIHMAsync() STUB_ZERO;
void TouchHWNDElement::RegisterForAnimationStatusChanges() STUB_VOID;
void TouchHWNDElement::UnregisterForAnimationStatusChanges() STUB_VOID;
bool TouchHWNDElement::IsRegisteredForAnimationStatusChanges() STUB_ZERO;
IClassInfo* TouchHWNDElement::GetClassInfoPtr() STUB_ZERO;
IClassInfo* TouchHWNDElement::GetClassInfoW() STUB_ZERO;
HRESULT TouchHWNDElement::Register() STUB_ZERO;
TouchHWNDElement::TouchHWNDElement() STUB_VOID;
TouchHWNDElement::~TouchHWNDElement() STUB_VOID;
void TouchHWNDElement::_OnUIStateChanged(WORD wUIStateOld, WORD wUIStateNew) STUB_VOID;
void TouchHWNDElement::_ClearTooltipState() STUB_VOID;
void TouchHWNDElement::_DestroyTooltip() STUB_VOID;

void TouchHWNDElement::ElementWithTooltipListener::OnListenerDetach(Element* peFrom) STUB_VOID;

UID TouchScrollBar::InteractionStart() STUB_ZERO;
UID TouchScrollBar::InteractionEnd() STUB_ZERO;
UID TouchScrollBar::ActiveStateChanged() STUB_ZERO;
UID TouchScrollBar::AnimateScroll() STUB_ZERO;
HRESULT TouchScrollBar::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT TouchScrollBar::Initialize(bool fBuildSubTree, Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
void TouchScrollBar::OnInput(InputEvent* pInput) STUB_VOID;
void TouchScrollBar::OnEvent(Event* pEvent) STUB_VOID;
void TouchScrollBar::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void TouchScrollBar::OnHosted(Element* peNewHost) STUB_VOID;
void TouchScrollBar::_SelfLayoutDoLayout(int cx, int cy) STUB_VOID;
SIZE TouchScrollBar::_SelfLayoutUpdateDesiredSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;
TouchScrollBar::TouchScrollBar() STUB_VOID;
TouchScrollBar::~TouchScrollBar() STUB_VOID;
IClassInfo* TouchScrollBar::GetClassInfoPtr() STUB_ZERO;
IClassInfo* TouchScrollBar::GetClassInfoW() STUB_ZERO;
HRESULT TouchScrollBar::Register() STUB_ZERO;
ActiveState TouchScrollBar::GetActiveState() STUB_ZERO;
void TouchScrollBar::SetActiveState(ActiveState newActiveState, bool fNoAnimation) STUB_VOID;
bool TouchScrollBar::IsThumbActive() STUB_ZERO;
Element* TouchScrollBar::GetThumb() STUB_ZERO;
HRESULT TouchScrollBar::CreateButtons() STUB_ZERO;
void TouchScrollBar::LineUp(UINT nCount) STUB_VOID;
void TouchScrollBar::LineDown(UINT nCount) STUB_VOID;
void TouchScrollBar::PageUp(UINT nCount) STUB_VOID;
void TouchScrollBar::PageDown(UINT nCount) STUB_VOID;
TouchScrollBar::InnerTouchScrollBarListener::InnerTouchScrollBarListener() STUB_VOID;
void TouchScrollBar::InnerTouchScrollBarListener::OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;

UID TouchScrollViewer::ManipulationStarting() STUB_ZERO;
UID TouchScrollViewer::ManipulationStarted() STUB_ZERO;
UID TouchScrollViewer::ManipulationDelta() STUB_ZERO;
UID TouchScrollViewer::ManipulationCompleted() STUB_ZERO;
UID TouchScrollViewer::SemanticChange() STUB_ZERO;
UID TouchScrollViewer::SnapshotTransformElement() STUB_ZERO;
UID TouchScrollViewer::ReleaseSnapshot() STUB_ZERO;
UID TouchScrollViewer::MapContentVisuals() STUB_ZERO;
UID TouchScrollViewer::SetContactNeeded() STUB_ZERO;
UID TouchScrollViewer::SetContactNotify() STUB_ZERO;
UID TouchScrollViewer::UpdateView() STUB_ZERO;
UID TouchScrollViewer::UpdateContentSize() STUB_ZERO;
HRESULT TouchScrollViewer::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
const PropertyInfo* TouchScrollViewer::SnapModeProp() STUB_ZERO;
const PropertyInfo* TouchScrollViewer::ScrollPaddingProp() STUB_ZERO;
const PropertyInfo* TouchScrollViewer::SnapIntervalXProp() STUB_ZERO;
const PropertyInfo* TouchScrollViewer::SnapOffsetXProp() STUB_ZERO;
const PropertyInfo* TouchScrollViewer::SnapPointCollectionXProp() STUB_ZERO;
const PropertyInfo* TouchScrollViewer::SnapIntervalYProp() STUB_ZERO;
const PropertyInfo* TouchScrollViewer::SnapOffsetYProp() STUB_ZERO;
const PropertyInfo* TouchScrollViewer::SnapPointCollectionYProp() STUB_ZERO;
const PropertyInfo* TouchScrollViewer::ManipulationVerticalAlignmentProp() STUB_ZERO;
const PropertyInfo* TouchScrollViewer::ManipulationHorizontalAlignmentProp() STUB_ZERO;
int TouchScrollViewer::GetInteractionMode() STUB_ZERO;
HRESULT TouchScrollViewer::SetInteractionMode(int v) STUB_ZERO;
int TouchScrollViewer::GetSnapMode() STUB_ZERO;
HRESULT TouchScrollViewer::SetSnapMode(int v) STUB_ZERO;
bool TouchScrollViewer::GetAllowArrowOut() STUB_ZERO;
HRESULT TouchScrollViewer::SetAllowArrowOut(bool v) STUB_ZERO;
const RECT* TouchScrollViewer::GetScrollPadding(Value** ppv) STUB_ZERO;
HRESULT TouchScrollViewer::SetScrollPadding(int l, int t, int r, int b) STUB_ZERO;
float TouchScrollViewer::GetZoomMinimum() STUB_ZERO;
HRESULT TouchScrollViewer::SetZoomMinimum(float v) STUB_ZERO;
float TouchScrollViewer::GetZoomMaximum() STUB_ZERO;
HRESULT TouchScrollViewer::SetZoomMaximum(float v) STUB_ZERO;
float TouchScrollViewer::GetSnapIntervalX() STUB_ZERO;
float TouchScrollViewer::GetSnapOffsetX() STUB_ZERO;
DynamicArray<double>* TouchScrollViewer::GetSnapPointCollectionX(Value** ppv) STUB_ZERO;
float TouchScrollViewer::GetSnapIntervalY() STUB_ZERO;
float TouchScrollViewer::GetSnapOffsetY() STUB_ZERO;
DynamicArray<double>* TouchScrollViewer::GetSnapPointCollectionY(Value** ppv) STUB_ZERO;
bool TouchScrollViewer::GetLinkIndicatorsToContent() STUB_ZERO;
HRESULT TouchScrollViewer::SetSnapIntervalX(float v) STUB_ZERO;
HRESULT TouchScrollViewer::SetSnapOffsetX(float v) STUB_ZERO;
HRESULT TouchScrollViewer::SetSnapPointCollectionX(const double* rgdbl, int cdbl) STUB_ZERO;
HRESULT TouchScrollViewer::SetSnapPointCollectionX(DynamicArray<double>* v) STUB_ZERO;
HRESULT TouchScrollViewer::SetSnapIntervalY(float v) STUB_ZERO;
HRESULT TouchScrollViewer::SetSnapOffsetY(float v) STUB_ZERO;
HRESULT TouchScrollViewer::SetSnapPointCollectionY(const double* rgdbl, int cdbl) STUB_ZERO;
HRESULT TouchScrollViewer::SetSnapPointCollectionY(DynamicArray<double>* v) STUB_ZERO;
HRESULT TouchScrollViewer::SetLinkIndicatorsToContent(bool v) STUB_ZERO;
HRESULT TouchScrollViewer::SetContact(UINT uiPointerID, bool fRelease) STUB_ZERO;
HRESULT TouchScrollViewer::ZoomToRect(const RECT* pcrcTarget, bool fAnimate) STUB_ZERO;
bool TouchScrollViewer::CanPerformManualVisualSwap() STUB_ZERO;
bool TouchScrollViewer::IsManualVisualSwapInProgress() STUB_ZERO;
HRESULT TouchScrollViewer::ZoomToRectManualVisualSwap(float left, float top, float right, float bottom, const int* pnHorizontalDelta, float panX, float panY, float scaleDestination, bool fAnimate) STUB_ZERO;
HRESULT TouchScrollViewer::PrepareManualSwapDeferredZoomToRect(const RECT* pcrcTarget, const float* ppanX, const float* ppanY, float* centerXOverride, float* centerYOverride, float scaleDestination) STUB_ZERO;
HRESULT TouchScrollViewer::ExecuteManualSwapDeferredZoomToRect(bool fAnimate) STUB_ZERO;
HRESULT TouchScrollViewer::SetSuppressSetContact(bool fDisable) STUB_ZERO;
HRESULT TouchScrollViewer::ResetManipulations() STUB_ZERO;
HRESULT TouchScrollViewer::ResetInputState() STUB_ZERO;
HRESULT TouchScrollViewer::SetVirtualizeElements(bool fVirtualize) STUB_ZERO;
void TouchScrollViewer::SetDisableOffscreenCaching(bool fDisableOffscreen) STUB_VOID;
int TouchScrollViewer::GetManipulationVerticalAlignment() STUB_ZERO;
HRESULT TouchScrollViewer::SetManipulationVerticalAlignment(int v) STUB_ZERO;
int TouchScrollViewer::GetManipulationHorizontalAlignment() STUB_ZERO;
HRESULT TouchScrollViewer::SetManipulationHorizontalAlignment(int v) STUB_ZERO;
HRESULT TouchScrollViewer::SetDelegateEventHandler(IUnknown* punk) STUB_ZERO;
HRESULT TouchScrollViewer::GetVScrollbar(Element** ppeScrollbar) STUB_ZERO;
HRESULT TouchScrollViewer::GetHScrollbar(Element** ppeScrollbar) STUB_ZERO;
void TouchScrollViewer::GetInertiaEndpointVisibleRect(RECT* pRectEndpoint) STUB_VOID;
float TouchScrollViewer::GetInertiaEndpointZoomLevel(float defaultZoomLevel) STUB_ZERO;
void TouchScrollViewer::GetVisibleRect(RECT* pRectVisibleRegion) STUB_VOID;
void TouchScrollViewer::GetPredictedVisibleRect(RECT* pRectVisibleRegion) STUB_VOID;
bool TouchScrollViewer::GetMouseWithinHorizontalScrollRegion() STUB_ZERO;
HRESULT TouchScrollViewer::SetScrollControlHost(Element* peHost) STUB_ZERO;
void TouchScrollViewer::GetTranslatedTileRects(RECT* prgrcTranslatedTiles, UINT* prguiIds, UINT uiBufferSize) STUB_VOID;
bool TouchScrollViewer::IsTileMember(UINT uiTileID, Element* pe) STUB_ZERO;
bool TouchScrollViewer::IsCrossfadeInProgress() STUB_ZERO;
HRESULT TouchScrollViewer::OverrideZoomThreshold(float upperThresholdDelta, float lowerThresholdDelta, int flags) STUB_ZERO;
float TouchScrollViewer::GetContentCrossfadeOpacity() STUB_ZERO;
IClassInfo* TouchScrollViewer::GetClassInfoPtr() STUB_ZERO;
IClassInfo* TouchScrollViewer::GetClassInfoW() STUB_ZERO;
IDirectManipulationManager* TouchScrollViewer::GetManipulationManager() STUB_ZERO;
IDirectManipulationViewport* TouchScrollViewer::GetManipulationViewport(bool) STUB_ZERO;
IDirectManipulationCompositor* TouchScrollViewer::GetManipulationCompositor() STUB_ZERO;
void TouchScrollViewer::NewChildElementsAdded() STUB_VOID;
HRESULT TouchScrollViewer::TelemetrySetDescription(const WCHAR* pszDescription) STUB_ZERO;

IClassInfo* TouchSelectItem::GetClassInfoPtr() STUB_ZERO;
IClassInfo* TouchSelectItem::GetClassInfoW() STUB_ZERO;
HRESULT TouchSelectItem::Register() STUB_ZERO;
HRESULT TouchSelectItem::Create(Element* peParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
TouchSelectItem::TouchSelectItem() STUB_VOID;
TouchSelectItem::~TouchSelectItem() STUB_VOID;
const PropertyInfo* TouchSelectItem::TextContentOverrideProp() STUB_ZERO;
const WCHAR* TouchSelectItem::GetTextContentOverride(Value** ppv) STUB_ZERO;
HRESULT TouchSelectItem::SetTextContentOverride(const WCHAR* psz) STUB_ZERO;
HRESULT TouchSelectItem::GetItemData(IUnknown** ppunkData) STUB_ZERO;
HRESULT TouchSelectItem::SetItemData(IUnknown* punkData) STUB_ZERO;

IClassInfo* TouchSelect::GetClassInfoPtr() STUB_ZERO;
IClassInfo* TouchSelect::GetClassInfoW() STUB_ZERO;
HRESULT TouchSelect::Register() STUB_ZERO;
HRESULT TouchSelect::Create(Element* peParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT TouchSelect::Initialize(Element* peParent, DWORD* pdwDeferCookie) STUB_ZERO;
TouchSelect::TouchSelect() STUB_VOID;
TouchSelect::~TouchSelect() STUB_VOID;
UID TouchSelect::SelectionChange() STUB_ZERO;
UID TouchSelect::PopupChange() STUB_ZERO;
const PropertyInfo* TouchSelect::SelectionProp() STUB_ZERO;
Element* TouchSelect::GetSelection() STUB_ZERO;
HRESULT TouchSelect::SetSelection(Element* peNew) STUB_ZERO;
const PropertyInfo* TouchSelect::ItemHeightInPopupProp() STUB_ZERO;
int TouchSelect::GetItemHeightInPopup() STUB_ZERO;
HRESULT TouchSelect::SetItemHeightInPopup(int v) STUB_ZERO;
const PropertyInfo* TouchSelect::PopupBoundsProp() STUB_ZERO;
const RECT* TouchSelect::GetPopupBounds(Value** ppv) STUB_ZERO;
HRESULT TouchSelect::SetPopupBounds(int l, int t, int r, int b) STUB_ZERO;
const PropertyInfo* TouchSelect::AnimatePopupOnDismissProp() STUB_ZERO;
bool TouchSelect::GetAnimatePopupOnDismiss() STUB_ZERO;
HRESULT TouchSelect::SetAnimatePopupOnDismiss(bool v) STUB_ZERO;
HRESULT TouchSelect::AddString(const WCHAR* pszString) STUB_ZERO;
HRESULT TouchSelect::AddString(const WCHAR* pszString, Element** ppeItem) STUB_ZERO;
HRESULT TouchSelect::AddStringWithLabelOverride(const WCHAR* pszString, const WCHAR* pszLabel, Element** ppeItem) STUB_ZERO;
HRESULT TouchSelect::AddElement(Element* pe, const WCHAR* pszTextContent) STUB_ZERO;
HRESULT TouchSelect::RemoveItem(int iIndex) STUB_ZERO;
HRESULT TouchSelect::UpdateElement(int iIndex, Element* pe, const WCHAR* pszTextContent) STUB_ZERO;
HRESULT TouchSelect::UpdateString(int iIndex, const WCHAR* pszString) STUB_ZERO;
DWORD TouchSelect::GetItemCount() STUB_ZERO;
HRESULT TouchSelect::GetItemData(int iIndex, IUnknown** ppunkData) STUB_ZERO;
HRESULT TouchSelect::SetItemData(int iIndex, IUnknown* punkData) STUB_ZERO;
void TouchSelect::RemoveAll() STUB_VOID;
int TouchSelect::GetSelectionIndex() STUB_ZERO;
HRESULT TouchSelect::SetSelectionIndex(int iSelection) STUB_ZERO;
bool TouchSelect::IsPopupOpen() STUB_ZERO;
HRESULT TouchSelect::OpenPopup() STUB_ZERO;
void TouchSelect::ClosePopup() STUB_VOID;
HRESULT TouchSelect::GetElementProviderImpl(InvokeHelper* pih, ElementProvider** ppprv) STUB_ZERO;
void TouchSelect::OnHosted(Element* peNewHost) STUB_VOID;
void TouchSelect::OnUnHosted(Element* peOldHost) STUB_VOID;
void TouchSelect::OnEvent(Event* pEvent) STUB_VOID;
void TouchSelect::OnInput(InputEvent* pie) STUB_VOID;
bool TouchSelect::OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void TouchSelect::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
HRESULT TouchSelect::Add(Element** ppe, UINT cCount) STUB_ZERO;
HRESULT TouchSelect::Insert(Element** ppe, UINT cCount, UINT iInsertIdx) STUB_ZERO;
void TouchSelect::_SelfLayoutDoLayout(int cx, int cy) STUB_VOID;
SIZE TouchSelect::_SelfLayoutUpdateDesiredSize(int dConstW, int dConstH, Surface* psrf) STUB_ZERO;

TouchSelect::TouchSelectListener::TouchSelectListener() STUB_VOID;
void TouchSelect::TouchSelectListener::OnListenedEvent(Element* peFrom, Event* pEvent) STUB_VOID;
void TouchSelect::TouchSelectListener::OnListenerDetach(Element* peFrom) STUB_VOID;

UID TouchEditBase::Enter() STUB_ZERO;
UID TouchEditBase::Paste() STUB_ZERO;
UID TouchEditBase::Cut() STUB_ZERO;
UID TouchEditBase::CaretMoved() STUB_ZERO;
UID TouchEditBase::UserTextChanged() STUB_ZERO;
UID TouchEditBase::UserTextUpdateNoChange() STUB_ZERO;
const PropertyInfo* TouchEditBase::PasswordCharacterProp() STUB_ZERO;
int TouchEditBase::GetPasswordCharacter() STUB_ZERO;
HRESULT TouchEditBase::SetPasswordCharacter(int v) STUB_ZERO;
const PropertyInfo* TouchEditBase::MaxLengthProp() STUB_ZERO;
int TouchEditBase::GetMaxLength() STUB_ZERO;
HRESULT TouchEditBase::SetMaxLength(int v) STUB_ZERO;
const PropertyInfo* TouchEditBase::MultilineProp() STUB_ZERO;
bool TouchEditBase::GetMultiline() STUB_ZERO;
HRESULT TouchEditBase::SetMultiline(bool v) STUB_ZERO;
const PropertyInfo* TouchEditBase::ReadOnlyProp() STUB_ZERO;
bool TouchEditBase::GetReadOnly() STUB_ZERO;
HRESULT TouchEditBase::SetReadOnly(bool v) STUB_ZERO;
const PropertyInfo* TouchEditBase::TextModeProp() STUB_ZERO;
TouchEditTextMode TouchEditBase::GetTextMode() STUB_ZERO;
HRESULT TouchEditBase::SetTextMode(TouchEditTextMode v) STUB_ZERO;
const PropertyInfo* TouchEditBase::SelectionForegroundColorProp() STUB_ZERO;
Value* TouchEditBase::GetSelectionForegroundColor() STUB_ZERO;
HRESULT TouchEditBase::SetSelectionForegroundColor(Value* v) STUB_ZERO;
const PropertyInfo* TouchEditBase::SelectionBackgroundColorProp() STUB_ZERO;
Value* TouchEditBase::GetSelectionBackgroundColor() STUB_ZERO;
HRESULT TouchEditBase::SetSelectionBackgroundColor(Value* v) STUB_ZERO;
const PropertyInfo* TouchEditBase::IgnoredKeyCombosProp() STUB_ZERO;
TouchEditFilteredKeyComboFlags TouchEditBase::GetIgnoredKeyCombos() STUB_ZERO;
HRESULT TouchEditBase::SetIgnoredKeyCombos(TouchEditFilteredKeyComboFlags v, TouchEditFilteredKeyComboFlags vmask) STUB_ZERO;
const PropertyInfo* TouchEditBase::KeyboardNavigationCaptureProp() STUB_ZERO;
TouchEditKeyboardNavigationCapture TouchEditBase::GetKeyboardNavigationCapture() STUB_ZERO;
HRESULT TouchEditBase::SetKeyboardNavigationCapture(TouchEditKeyboardNavigationCapture v) STUB_ZERO;
const PropertyInfo* TouchEditBase::IMEComposingProp() STUB_ZERO;
bool TouchEditBase::GetIMEComposing() STUB_ZERO;
HRESULT TouchEditBase::SetIMEComposing(bool v) STUB_ZERO;
const PropertyInfo* TouchEditBase::SyncContentWhileIMEComposingProp() STUB_ZERO;
bool TouchEditBase::GetSyncContentWhileIMEComposing() STUB_ZERO;
HRESULT TouchEditBase::SetSyncContentWhileIMEComposing(bool v) STUB_ZERO;
const PropertyInfo* TouchEditBase::ElementMovesOnIHMNotifyProp() STUB_ZERO;
bool TouchEditBase::GetElementMovesOnIHMNotify() STUB_ZERO;
HRESULT TouchEditBase::SetElementMovesOnIHMNotify(bool v) STUB_ZERO;
const PropertyInfo* TouchEditBase::FilterOnPasteProp() STUB_ZERO;
bool TouchEditBase::GetFilterOnPaste() STUB_ZERO;
HRESULT TouchEditBase::SetFilterOnPaste(bool v) STUB_ZERO;
const PropertyInfo* TouchEditBase::MoveCaretToEndOnSyncContentProp() STUB_ZERO;
bool TouchEditBase::GetMoveCaretToEndOnSyncContent() STUB_ZERO;
HRESULT TouchEditBase::SetMoveCaretToEndOnSyncContent(bool v) STUB_ZERO;
const PropertyInfo* TouchEditBase::IntegrateIMECandidateListProp() STUB_ZERO;
bool TouchEditBase::GetIntegrateIMECandidateList() STUB_ZERO;
HRESULT TouchEditBase::SetIntegrateIMECandidateList(bool v) STUB_ZERO;
const PropertyInfo* TouchEditBase::ForceEditTextToLTRProp() STUB_ZERO;
bool TouchEditBase::GetForceEditTextToLTR() STUB_ZERO;
HRESULT TouchEditBase::SetForceEditTextToLTR(bool v) STUB_ZERO;
const PropertyInfo* TouchEditBase::PreventFormatChangeUpdatingModifiedStateProp() STUB_ZERO;
bool TouchEditBase::GetPreventFormatChangeUpdatingModifiedState() STUB_ZERO;
HRESULT TouchEditBase::SetPreventFormatChangeUpdatingModifiedState(bool v) STUB_ZERO;
IClassInfo* TouchEditBase::GetClassInfoPtr() STUB_ZERO;
IClassInfo* TouchEditBase::GetClassInfoW() STUB_ZERO;
HRESULT TouchEditBase::Register() STUB_ZERO;
HRESULT TouchEditBase::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
bool TouchEditBase::OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void TouchEditBase::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
bool TouchEditBase::IsContentProtected() STUB_ZERO;
const WCHAR* TouchEditBase::GetContentStringAsDisplayed(Value** ppv) STUB_ZERO;
HRESULT TouchEditBase::Insert(Element** ppe, UINT cCount, UINT iInsertIdx) STUB_ZERO;
void TouchEditBase::SetKeyFocus() STUB_VOID;
HRESULT TouchEditBase::GetTextDocument(ITextDocument** pptd) STUB_ZERO;
HRESULT TouchEditBase::GetTextServices(ITextServices** ppts) STUB_ZERO;
HRESULT TouchEditBase::RefreshContent() STUB_ZERO;
HRESULT TouchEditBase::FinalizeCurrentIMEComposition() STUB_ZERO;
HRESULT TouchEditBase::GetControllerFor(IUnknown**) STUB_ZERO
TouchEditBase::TouchEditBase() STUB_VOID;

UID TouchEdit2::ClearButtonClicked() STUB_ZERO;
UID TouchEdit2::ContextMenuRequested() STUB_ZERO;
const PropertyInfo* TouchEdit2::PromptTextProp() STUB_ZERO;
const WCHAR* TouchEdit2::GetPromptText(Value** ppv) STUB_ZERO;
HRESULT TouchEdit2::SetPromptText(const WCHAR* psz) STUB_ZERO;
const PropertyInfo* TouchEdit2::PromptWithCaretProp() STUB_ZERO;
bool TouchEdit2::GetPromptWithCaret() STUB_ZERO;
HRESULT TouchEdit2::SetPromptWithCaret(bool v) STUB_ZERO;
const PropertyInfo* TouchEdit2::SuppressClearButtonProp() STUB_ZERO;
bool TouchEdit2::GetSuppressClearButton() STUB_ZERO;
HRESULT TouchEdit2::SetSuppressClearButton(bool v) STUB_ZERO;
const PropertyInfo* TouchEdit2::ShowClearButtonMinWidthProp() STUB_ZERO;
int TouchEdit2::GetShowClearButtonMinWidth() STUB_ZERO;
HRESULT TouchEdit2::SetShowClearButtonMinWidth(int v) STUB_ZERO;
const PropertyInfo* TouchEdit2::PasswordRevealModeProp() STUB_ZERO;
TouchEditPasswordRevealMode TouchEdit2::GetPasswordRevealMode() STUB_ZERO;
HRESULT TouchEdit2::SetPasswordRevealMode(TouchEditPasswordRevealMode v) STUB_ZERO;
const PropertyInfo* TouchEdit2::InnerBorderThicknessProp() STUB_ZERO;
const RECT* TouchEdit2::GetInnerBorderThickness(Value** ppv) STUB_ZERO;
HRESULT TouchEdit2::SetInnerBorderThickness(int l, int t, int r, int b) STUB_ZERO;
IClassInfo* TouchEdit2::GetClassInfoPtr() STUB_ZERO;
IClassInfo* TouchEdit2::GetClassInfoW() STUB_ZERO;
HRESULT TouchEdit2::Register() STUB_ZERO;
HRESULT TouchEdit2::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT TouchEdit2::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
TouchEdit2::TouchEdit2() STUB_VOID;
void TouchEdit2::OnHosted(Element* peNewHost) STUB_VOID;
void TouchEdit2::OnInput(InputEvent* pie) STUB_VOID;
bool TouchEdit2::OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_ZERO;
void TouchEdit2::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void TouchEdit2::OnEvent(Event* pEvent) STUB_VOID;
void TouchEdit2::Paint(HDC hdc, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) STUB_VOID;
HRESULT TouchEdit2::Add(Element** ppe, UINT cCount) STUB_ZERO;
HRESULT TouchEdit2::GetAccessibleImpl(IAccessible** ppAccessible) STUB_ZERO;
Element* TouchEdit2::GetUiaFocusDelegate() STUB_ZERO;
HRESULT TouchEdit2::GetTextDocument(ITextDocument** pptd) STUB_ZERO;
HRESULT TouchEdit2::GetTextServices(ITextServices** ppts) STUB_ZERO;
HRESULT TouchEdit2::RefreshContent() STUB_ZERO;
HRESULT TouchEdit2::FinalizeCurrentIMEComposition() STUB_ZERO;
HRESULT TouchEdit2::GetTextHost(ITextHost** ppth) STUB_ZERO;
HRESULT TouchEdit2::GetTextSelection(ITextSelection** pptsel) STUB_ZERO;
HRESULT TouchEdit2::PasteText(const WCHAR* pszText) STUB_ZERO;
HRESULT TouchEdit2::GetSelection(long* piStart, long* pcchSel) STUB_ZERO;
HRESULT TouchEdit2::SetSelection(long iStart, long cch) STUB_ZERO;
HRESULT TouchEdit2::SetCaretPosition(long iPos) STUB_ZERO;
InputScope TouchEdit2::GetInputScope() STUB_ZERO;
HRESULT TouchEdit2::SetInputScope(InputScope inputscope) STUB_ZERO;
bool TouchEdit2::HasSelection() STUB_ZERO;
HRESULT TouchEdit2::SelectAll() STUB_ZERO;
HRESULT TouchEdit2::SelectNone() STUB_ZERO;
void TouchEdit2::DisableSelectionHandlesOnEmptyContent() STUB_VOID
void TouchEdit2::OnListenerDetach(Element* peFrom) STUB_VOID;
void TouchEdit2::OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;

HRESULT TouchSlider::Register() STUB_ZERO
IClassInfo* TouchSlider::GetClassInfoPtr() STUB_ZERO;
IClassInfo* TouchSlider::GetClassInfoW() STUB_ZERO;
HRESULT TouchSlider::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT TouchSlider::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
const PropertyInfo* TouchSlider::IsVerticalProp() STUB_ZERO;
const PropertyInfo* TouchSlider::MeteringProp() STUB_ZERO;
const PropertyInfo* TouchSlider::BufferingProp() STUB_ZERO;
const PropertyInfo* TouchSlider::TickCountProp() STUB_ZERO;
const PropertyInfo* TouchSlider::ShowTickProp() STUB_ZERO;
const PropertyInfo* TouchSlider::IsContinuousProp() STUB_ZERO;
const PropertyInfo* TouchSlider::IsShowOnOffFeedbackProp() STUB_ZERO;
const PropertyInfo* TouchSlider::VisualStateProp() STUB_ZERO;
const PropertyInfo* TouchSlider::IsPressedProp() STUB_ZERO;
const PropertyInfo* TouchSlider::ThumbPositionProp() STUB_ZERO;
bool TouchSlider::GetIsVertical() STUB_ZERO;
int TouchSlider::GetMetering() STUB_ZERO;
int TouchSlider::GetBuffering() STUB_ZERO;
int TouchSlider::GetTickCount() STUB_ZERO;
bool TouchSlider::GetShowTick() STUB_ZERO;
bool TouchSlider::GetIsPressed() STUB_ZERO;
bool TouchSlider::GetIsContinuous() STUB_ZERO;
bool TouchSlider::GetIsShowOnOffFeedback() STUB_ZERO;
int TouchSlider::GetVisualState() STUB_ZERO;
HRESULT TouchSlider::SetIsVertical(bool v) STUB_ZERO;
HRESULT TouchSlider::SetMetering(int v) STUB_ZERO;
HRESULT TouchSlider::SetBuffering(int v) STUB_ZERO;
HRESULT TouchSlider::SetTickCount(int v) STUB_ZERO;
HRESULT TouchSlider::SetShowTick(bool v) STUB_ZERO;
HRESULT TouchSlider::SetIsPressed(bool v) STUB_ZERO;
HRESULT TouchSlider::SetIsContinuous(bool v) STUB_ZERO;
HRESULT TouchSlider::SetIsShowOnOffFeedback(bool v) STUB_ZERO;
void TouchSlider::SetRespondToMouseScroll(bool respondToMouseScroll) STUB_VOID;
void TouchSlider::SetFireContinuousSliderEvent(bool fireContinuousSliderEvent) STUB_VOID;
UID TouchSlider::SliderUpdated() STUB_ZERO;
UID TouchSlider::MouseOrPointerReleased() STUB_ZERO;
int TouchSlider::GetRangeMin() STUB_ZERO;
int TouchSlider::GetRangeMax() STUB_ZERO;
int TouchSlider::GetStepCount() STUB_ZERO;
int TouchSlider::GetThumbValue() STUB_ZERO;
void TouchSlider::SetRangeMinAndRangeMax(int RangeMin, int RangeMax) STUB_VOID;
void TouchSlider::SetRangeMin(int RangeMin) STUB_VOID;
void TouchSlider::SetRangeMax(int RangeMax) STUB_VOID;
void TouchSlider::SetStepCount(int StepCount) STUB_VOID;
void TouchSlider::SetThumbValue(int ThumbValue, bool RaiseEvent) STUB_VOID;
void TouchSlider::SetThumbValue(int ThumbValue, bool RaiseEvent, bool fForce) STUB_VOID;
Element* TouchSlider::GetTrackElement() STUB_ZERO;
Button* TouchSlider::GetThumbElement() STUB_ZERO;
Element* TouchSlider::GetFillpartElement() STUB_ZERO;
void TouchSlider::RemoveRichDuiTooltip() STUB_VOID;
void TouchSlider::SetTooltipText(const WCHAR* pszTooltipText) STUB_VOID;
int TouchSlider::TranslateThumbPositionToThumbValue(int ThumbPosition) STUB_ZERO;
void TouchSlider::FireEventOnMouseOrPointerRelease() STUB_VOID;
void TouchSlider::SetRespectLanguageDirection(bool fRespectLanguageDirection) STUB_VOID;
void TouchSlider::EraseFeedback() STUB_VOID;
void TouchSlider::UseFixedTooltipOffset() STUB_VOID;
void TouchSlider::ShowTooltipOnRightForLTRBuild() STUB_VOID;
void TouchSlider::CancelCurrentDrag() STUB_VOID;

//~ Begin DirectUI::TouchSwitch Class
HRESULT TouchSwitch::Register() STUB_ZERO;
IClassInfo* TouchSwitch::GetClassInfoPtr() STUB_ZERO;
IClassInfo* TouchSwitch::GetClassInfoW() STUB_ZERO;
HRESULT TouchSwitch::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT TouchSwitch::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
void TouchSwitch::SetOnOffText(const WCHAR* OnText, const WCHAR* OffText) STUB_VOID;
void TouchSwitch::SetToggleSwitchText(const WCHAR* TitleText) STUB_VOID;
const PropertyInfo* TouchSwitch::OnTextProp() STUB_ZERO;
const WCHAR* TouchSwitch::GetOnText(Value** ppv) STUB_ZERO;
HRESULT TouchSwitch::SetOnText(const WCHAR* psz) STUB_ZERO;
const PropertyInfo* TouchSwitch::OffTextProp() STUB_ZERO;
const WCHAR* TouchSwitch::GetOffText(Value** ppv) STUB_ZERO;
HRESULT TouchSwitch::SetOffText(const WCHAR* psz) STUB_ZERO;
const PropertyInfo* TouchSwitch::TitleTextProp() STUB_ZERO;
const WCHAR* TouchSwitch::GetTitleText(Value** ppv) STUB_ZERO;
HRESULT TouchSwitch::SetTitleText(const WCHAR* psz) STUB_ZERO;
void TouchSwitch::SetToggleValue(int ToggleValue) STUB_VOID;
void TouchSwitch::SetToggleValue(int ToggleValue, bool RaiseEvent) STUB_VOID;
void TouchSwitch::SetToggleValue(int ToggleValue, bool fRaiseEvent, bool fForce) STUB_VOID;
int TouchSwitch::GetToggleValue() STUB_ZERO;
//~ End DirectUI::TouchSwitch Class
	
UID SemanticZoomToggle::Toggle() STUB_ZERO;
HRESULT SemanticZoomToggle::Register() STUB_ZERO;
IClassInfo* SemanticZoomToggle::GetClassInfoPtr() STUB_ZERO;
IClassInfo* SemanticZoomToggle::GetClassInfoW() STUB_ZERO;
HRESULT SemanticZoomToggle::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT SemanticZoomToggle::Initialize(Element* pParent, DWORD* pdwDeferCookie) STUB_ZERO;
void SemanticZoomToggle::UpdateToggleState(SemanticZoomToggleState sztsNew, bool fEnabled) STUB_VOID;
HRESULT SemanticZoomToggle::DefaultAction() STUB_ZERO;

HRESULT ContextMenuBehavior::Create(IDuiBehavior** ppBehavior) STUB_ZERO;
UID ContextMenuBehavior::ContextMenuRequested() STUB_ZERO;
UID ContextMenuBehavior::ContextMenuHintShowing() STUB_ZERO;

HRESULT TouchHyperLink::Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
HRESULT TouchHyperLink::Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) STUB_ZERO;
void TouchHyperLink::OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) STUB_VOID;
void TouchHyperLink::GetImmersiveFocusRectOffsets(RECT* lprc) STUB_VOID;
const PropertyInfo* TouchHyperLink::VisitedProp() STUB_ZERO;
bool TouchHyperLink::GetVisited() STUB_ZERO;
HRESULT TouchHyperLink::SetVisited(bool v) STUB_ZERO;
IClassInfo* TouchHyperLink::GetClassInfoPtr() STUB_ZERO;
IClassInfo* TouchHyperLink::s_pClassInfo;
IClassInfo* TouchHyperLink::GetClassInfoW() STUB_ZERO;
HRESULT TouchHyperLink::Register() STUB_ZERO;
TouchHyperLink::TouchHyperLink() STUB_VOID;
TouchHyperLink::~TouchHyperLink() STUB_VOID;
} // namespace DirectUI

HRESULT CSafeElementProxy::CreateInstance(DirectUI::Element* pe, CSafeElementProxy** ppProxy) STUB_ZERO;
void CSafeElementProxy::Detach() STUB_VOID;
HRESULT CSafeElementProxy::s_SyncCallback(HGADGET, void*, EventMsg* pmsg) STUB_ZERO;
HRESULT CSafeElementProxy::Initialize(DirectUI::Element*) STUB_ZERO;
