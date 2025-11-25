#pragma once

#include <Windows.h>
#include <oleacc.h>
#include <objbase.h>
#include <initguid.h>
#include <Commctrl.h>
#include <UIAutomationCore.h>
#include <UIAutomationCoreApi.h>
#include <DbgHelp.h>
#include <thumbcache.h>
#include <XmlLite.h>
#include <InputScope.h> // for InputScope enum
#include <intsafe.h>
#include <crtdbg.h>
#include <directmanipulation.h>
#include <Corecrt_math.h>

#include "../DUser/DUser.h"

#if	defined(DIRECTUI_EXPORTS)
#define UILIB_API __declspec(dllexport)
#else
#define UILIB_API __declspec(dllimport)
#endif

EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)

#define DUI_VERSION 14

#define DUICLASS(className) class UILIB_API className
#define DUICLASS_(className, baseClass) class UILIB_API className : public baseClass

#include "Types.h"
#include "Extensions\Misc.h"
#include "Base\Alloc.h"
#include "Base\DynamicArray.h"
#include "Base\Surface.h"
#include "Base\SBAlloc.h"
#include "Core\Event.h"
#include "Interfaces.h"

// Layout
#include "Core\Layout.h"
#include "Layout\BorderLayout.h"
#include "Layout\ShellBorderLayout.h"
#include "Layout\VerticalFlowLayout.h"
#include "Layout\FlowLayout.h"
#include "Layout\NineGridLayout.h"
#include "Layout\FillLayout.h"
#include "Layout\TableLayout.h"
#include "Layout\RowLayout.h"
#include "Layout\GridLayout.h"

#include "AutoLock.h"
#include "AutoThread.h"
#include "AutoVariant.h"
#include "SafeElementPtr.h"
#include "SimpleTimer.h"
#include "UIAutomation\RefcountBase.h"

#include "Primitives.h"
#include "DuiProxy.h"
#include "UIAutomation\UiaSchema.h"
#include "Core\Element.h"
#include "UIAutomation\ElementProvider.h"
#include "UIAutomation\PatternProvider.h"
#include "PropNotify.h"
#include "Core\Expression.h"
#include "Core\Value.h"
#include "UIAutomation\ValueProvider.h"
#include "ValuePtr.h"
#include "Core\Thread.h"
#include "Parser\XmlParser.h"
#include "Core\Sheet.h"
#include "Extensions\Browser.h"
#include "Bind.h"
#include "Control\AnimationStrip.h"
#include "Control\Button.h"
#include "Base.h"
#include "ClassInfo.h"
#include "Core\ElementHelpers.h"
#include "Extensions\AccessibleButton.h"
#include "Extensions\AutoButton.h"
#include "Extensions\PushButton.h"
#include "Extensions\XHost.h"
#include "Core\Accessibility.h"
#include "Provider.h"
#include "Control\Movie.h"
#include "Control\ElementWithHWND.h"
#include "Core\Host.h"
#include "Extensions\DialogElement.h"
#include "Control\NativeHWNDHost.h"
#include "Control\HWNDHost.h"

#include "Extensions\CommonControls\CBase.h"
#include "Extensions\CommonControls\CAVI.h"
#include "Extensions\CommonControls\CPushButton.h"
#include "Extensions\CommonControls\CBaseCheckRadioButton.h"
#include "Extensions\CommonControls\CBaseScrollBar.h"
#include "Extensions\CommonControls\CHScrollBar.h"
#include "Extensions\CommonControls\CCheckBox.h"
#include "Extensions\CommonControls\CCommandLink.h"
#include "Extensions\CommonControls\CListBox.h"
#include "Extensions\CommonControls\CListView.h"
#include "Extensions\CommonControls\CProgressBar.h"
#include "Extensions\CommonControls\CRadioButton.h"
#include "Extensions\CommonControls\CCSysLink.h"
#include "Extensions\CommonControls\CTrackBar.h"
#include "Extensions\CommonControls\CTreeView.h"
#include "Extensions\CommonControls\CVScrollBar.h"

#include "Core\CallstackTracker.h"
#include "CheckBoxGlyph.h"
#include "Control\Expandable.h"
#include "Clipper.h"
#include "Control\Combobox.h"
#include "Core\Navigation.h"
#include "Control\Edit.h"
#include "UIAutomation\EventManager.h"
#include "UIAutomation\ExpandCollapseProvider.h"
#include "Expando.h"
#include "ExpandoButtonGlyph.h"
#include "Base\FontCache.h"
#include "FontCheckOut.h"
#include "UIAutomation\GridItemProvider.h"
#include "UIAutomation\GridProvider.h"
#include "UIAutomation\HWNDElementProvider.h"
#include "UIAutomation\InvokeManager.h"
#include "UIAutomation\InvokeProvider.h"
#include "Base\LinkedList.h"
#include "Extensions\Macro.h"
#include "NavScoring.h"
#include "Navigator.h"
#include "TextGraphic.h"
#include "PText.h"
#include "Page.h"
#include "Control\Progress.h"
#include "RadioButtonGlyph.h"
#include "UIAutomation\RangeValueProvider.h"
#include "Control\RefPointElement.h"
#include "Control\RepeatButton.h"
#include "Repeater.h"
#include "Control\ScrollBar.h"
#include "UIAutomation\ScrollItemProvider.h"
#include "UIAutomation\ScrollProvider.h"
#include "Control\ScrollViewer.h"
#include "UIAutomation\SelectionItemProvider.h"
#include "UIAutomation\SelectionProvider.h"
#include "Control\Selector.h"
#include "SelectorNoDefault.h"
#include "Control\ItemList.h"
#include "SelectorSelectionItem.h"
#include "SelectorSelection.h"
#include "StyledScrollViewer.h"
#include "UIAutomation\TableItemProvider.h"
#include "UIAutomation\TableProvider.h"
#include "Extensions\WizPageBase.h"
#include "Control\Thumb.h"
#include "UIAutomation\ToggleProvider.h"
#include "Core\UnknownElement.h"
#include "Control\Viewer.h"
#include "Extensions\XBaby.h"
#include "Extensions\XElement.h"
#include "Extensions\XProvider.h"
#include "BrowserSelection.h"
#include "Control\RichText.h"
#include "Control\SemanticController.h"
#include "Control\ManipulationHelper.h"
#include "PromptText.h"
//#include "Core\IDuiLauncherAnimationTriggers.h"
#include "DuiAnimation.h"

// Touch elements
#include "Control\ModernProgressBar.h"
#include "Control\TouchButton.h"
#include "Control\TouchCheckBox.h"
#include "Control\TouchHWNDElement.h"
#include "Control\TouchScrollBar.h"
#include "Control\TouchScrollViewer.h"
#include "Control\TouchSelect.h"
#include "Control\TouchSelectProvider.h"
#include "Control\TouchSlider.h"
#include "Control\TouchSwitch.h"
#include "Control\TouchTooltip.h"
#include "Control\TouchEditBase.h"
#include "Control\TouchEditInner.h"
#include "Control\TouchEdit2.h"
#include "Control\TouchHyperLink.h"

#include "SemanticZoomToggle.h"
#include "ElementProviderManager.h"

#include "Control\ModernProgressRing.h"

//UnknownElement

UILIB_API void WINAPI DumpDuiTree(DirectUI::Element* pe, BOOL fShowProperties);
UILIB_API void WINAPI DumpDuiProperties(DirectUI::Element* pe);

extern "C" UILIB_API HRESULT WINAPI DuiCreateObject(REFCLSID rclsid, REFIID riid, void** ppv);

#include "PVLTrigger.h"
#include "PVLLauncherTrigger.h"
#include "Core\BehaviorEngine.h"
#include "Core\BehaviorEngineHelper.h"
#include "StockBehaviors\ContextMenuBehavior.h"

namespace DirectUI
{
	extern UILIB_API DWORD g_dwElSlot;

	extern "C"
	{
		// @Careful: fInitCommctl is new in Windows 10
		HRESULT WINAPI InitProcessPriv(DWORD dwExpectedVersion, HMODULE hModule, bool fRegisterControls, bool fEnableUIAutomationProvider, bool fInitCommctl);

		FORCEINLINE HRESULT WINAPI InitProcess(DWORD dwExpectedVersion, bool fEnableUIAutomationProvider = true, bool fInitCommctl = true)
		{
			return InitProcessPriv(dwExpectedVersion, HINST_THISCOMPONENT, true, fEnableUIAutomationProvider, fInitCommctl);
		}

		HRESULT WINAPI UnInitProcessPriv(HMODULE hModule);
		FORCEINLINE HRESULT WINAPI UnInitProcess() { return UnInitProcessPriv(HINST_THISCOMPONENT); }
		HRESULT WINAPI InitThread(UINT nThreadMode);
		void WINAPI UnInitThread();

		HRESULT WINAPI CreateDUIWrapper(Element* pe, IUnknown** ppunk);
		HRESULT WINAPI CreateDUIWrapperEx(Element* pe, IXProviderCP* pprovCP, IUnknown** ppunk);
		HRESULT WINAPI CreateDUIWrapperFromResource(HINSTANCE hRes, const WCHAR* pszResource, const WCHAR* pszResID, const WCHAR* pszFile, IUnknown** ppunk);

		// int WINAPI GetScreenDPI();

		HRESULT WINAPI RegisterAllControls();
		HRESULT WINAPI RegisterBaseControls();
		HRESULT WINAPI RegisterBrowserControls();
		HRESULT WINAPI RegisterCommonControls();
		HRESULT WINAPI RegisterExtendedControls();
		HRESULT WINAPI RegisterMacroControls();
		HRESULT WINAPI RegisterMiscControls();
		HRESULT WINAPI RegisterStandardControls();
		HRESULT WINAPI RegisterXControls();

		BOOL WINAPI StartMessagePump();
		void WINAPI StopMessagePump();

		ATOM WINAPI StrToID(const WCHAR* psz);
		CHAR* WINAPI UnicodeToMultiByte(const WCHAR* pszUnicode, int cChars, int* pMultiBytes);
		WCHAR* WINAPI MultiByteToUnicode(const CHAR* pszMulti, int dBytes, int* pUniChars);

		BOOL WINAPI IsAnimationsEnabled();
		bool WINAPI IsPalette(HWND hwnd);
		BOOL WINAPI IsUIAutomationProviderEnabled();
		int WINAPI DUIDrawShadowText(HDC hdc, const WCHAR* pszText, int cch, RECT* prc, DWORD dwFlags, COLORREF crText);

		void WINAPI BlurBitmap(UINT* plBitmapBits, int cx, int cy, int cxRow, COLORREF crFill);
		void WINAPI BlurBitmapNormal(UINT* prgb, int cx, int cy, int cxRow, COLORREF crFill);

		HBRUSH WINAPI BrushFromEnumI(int c);
		COLORREF WINAPI ColorFromEnumI(int c);
		COLORREF WINAPI ARGBColorFromEnumI(int c);

		DWORD* WINAPI DisableAnimations();
		int WINAPI DrawShadowTextEx(HDC hdc, const WCHAR *pszText, int cch, RECT* prc, DWORD dwFlags, COLORREF crText, COLORREF crShadow, int ixOffset, int iyOffset, BYTE bInitialAlpha, BOOL fAPIInit);
		Element* WINAPI ElementFromGadget(HGADGET hGadget);
		DWORD* WINAPI EnableAnimations();
		void WINAPI FlushThemeHandles(WPARAM wParam);

		void WINAPI ForceDebugBreak();

		IDataEntry* WINAPI GetElementDataEntry(Element* pe);
		Macro* WINAPI GetElementMacro(Element* pe);
		void* WINAPI GetFontCache();

		HRESULT WINAPI GetThemeHandle(const WCHAR* pszClass, HTHEME *phTheme);

		HRESULT WINAPI HrSysAllocString(const OLECHAR* psz, BSTR* ppbstrOut);
		HRESULT WINAPI HStrDup(const WCHAR* pszSrc, WCHAR** ppszOut);

		BOOL WINAPI InitPreprocessor();

		HRESULT WINAPI SetDefAction(Element* pe, DWORD oleacc);

		BOOL WINAPI UiaHideOnGetObject(HWND hwnd, WPARAM wParam, LPARAM lParam);
		HANDLE WINAPI UiaOnDestroySink(HWND hwnd);
		HRESULT WINAPI UiaOnGetObject(Element* pe, WPARAM wParam, LPARAM lParam, bool* pfHandled, int* plResult);
		BOOL WINAPI UiaOnToolTip(Element* pe, DWORD dwFlags);

		void WINAPI NotifyAccessibilityEvent(DWORD dwEvent, Element* pe);
		WCHAR* WINAPI PreprocessBuffer(const WCHAR* pszBuf, UINT cchBuf, bool fInsertMainResId);
		HBITMAP WINAPI ProcessAlphaBitmapI(HBITMAP hbmSource);
		void WINAPI PurgeThemeHandles();

		HRESULT WINAPI RegisterPVLBehaviorFactory();
		void WINAPI DUIStopPVLAnimation(Element* peAnimating, UINT nDCProperty, BOOL fFinal);
		HRESULT WINAPI DuiCreateObject(REFCLSID rclsid, REFIID riid, void** ppv);

		UILIB_API float WINAPI GetScaleFactor();
	}

	inline int RelPixToPixel(int nRelPix)
	{
		return (int)floor((GetScaleFactor() * (float)nRelPix) + 0.5f);
	}

	inline int GetPixelHelper(Element* pe, const PropertyInfo* ppi, bool fUseDefault)
	{
		CValuePtr spv(pe->GetRawValue(ppi, 2, nullptr));
		return spv->GetElementScaledInt(pe);
	}
}
