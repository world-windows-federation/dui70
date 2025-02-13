#pragma once

#include "InvokeHelper.h"

typedef const DirectUI::PropertyInfo* (WINAPI *PropertyProcT)();

namespace DirectUI
{
	struct UpdateCache
	{
	};

	struct ElementIndexPair
	{
		Element* pElement;
		UINT uIndex;
	};
	
	//32位数据结构大小 0x80
	class UILIB_API Element
	{
	public:
		char fields[0x500];


		Element();
		Element(const Element&);
		//0
		virtual ~Element();

		Element& operator=(const Element &);

		long Initialize(unsigned int, Element*, unsigned long*);
		static long WINAPI Create(unsigned int, Element*parent, unsigned long*, Element**out);
		static long WINAPI UnRegister(IClassInfo**);


		Element * GetParent();
		RECT const * GetPadding(Value * *);
		bool GetOverhang();
		Element * GetMouseWithinChild();
		bool GetMouseWithin();
		bool GetMouseFocused();
		SIZE const * GetMinSize(Value * *);
		RECT const * GetMargin(Value * *);
		POINT const * GetLocation(Value * *);
		int GetLayoutPos();
		Layout * GetLayout(Value * *);
		Element * GetKeyWithinChild();
		bool GetKeyWithin();
		int GetIndex();
		Element * GetImmediateChild(Element *);
		unsigned short GetID();
		bool GetHighDPI();
		int GetHeight();
		int GetForegroundStdColor();
		DirectUI::Fill const * GetForegroundColor(Value * *);
		int GetFontWeight();
		int GetFontStyle();
		int GetFontSize();
		int GetFontQuality();
		unsigned short const * GetFontFace(Value * *);
		unsigned short const * GetFont(Value * *);
		static CRITICAL_SECTION * __stdcall GetFactoryLock();
		SIZE const * GetExtent(Value * *);
		long GetEncodedContentString(unsigned short *, UINT_PTR);
		bool GetEnabled();

		int GetDPI();
		HGADGET GetDisplayNode();
		int GetDirection();
		SIZE const * GetDesiredSize();
		DeferCycle * GetDeferObject();
		unsigned short const * GetContentString(Value * *);
		int GetContentAlign();
		int GetColorize();
		bool GetClickablePoint(POINT *);
		static IClassInfo * __stdcall GetClassInfoPtr();
		unsigned short const * GetClass(Value * *);
		DynamicArray<Element *, 0> * GetChildren(Value * *);
		RECT const * GetBorderThickness(Value * *);
		int GetBorderStyle();
		int GetBorderStdColor();

		

		long AddListener(IElementListener*);

		unsigned long WINAPI AddRef();
		static UID WINAPI AnimationChange();

		void BroadcastEvent(Event*);
		void Detach(DeferCycle*);

		//1
		virtual bool IsRTLReading();

		//2
		virtual bool IsContentProtected();


		//3
		virtual const WCHAR* GetContentStringAsDisplayed(Value**);

		//4
		virtual bool OnPropertyChanging(PropertyInfo*, int, Value*, Value*);
		virtual bool OnPropertyChanging(const PropertyInfo*, int, Value*, Value*);
		//5
		//6
		virtual void OnPropertyChanged(PropertyInfo*, int, Value*, Value*);
		virtual void OnPropertyChanged(const PropertyInfo*, int, Value*, Value*);
		//7
		//8
		virtual void OnGroupChanged(int, bool);
		//9
		virtual void OnInput(InputEvent*);
		//10
		virtual void OnKeyFocusMoved(Element*, Element*);
		//11
		virtual void OnMouseFocusMoved(Element*, Element*);
		//12
		virtual void OnDestroy();
		//13
		virtual void OnEvent(Event*);
		//14
		virtual void Paint(HDC, RECT const*, RECT const*, RECT*, RECT*);

		//15
		virtual SIZE GetContentSize(int, int, Surface*);

		//16
		virtual long Add(Element**, unsigned int);

		HRESULT Add(Element* pe);
		//long Add(Element*, int(__cdecl*)(const void*, const void*));

		//17
		virtual long Insert(Element**, unsigned int, unsigned int);
		//18
		virtual long Remove(Element**, unsigned int);

		//19
		virtual Element* GetAdjacent(Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags);

		//20
		virtual bool EnsureVisible(int, int, int, int);
		virtual void SetKeyFocus();

		virtual long AddBehavior(IDuiBehavior* behavior);
		virtual long RemoveBehavior(IDuiBehavior* behavior);

		//21

		//22
		virtual unsigned int MessageCallback(GMSG*);

		//23
		virtual long WINAPI QueryInterface(GUID const &, void**);

		virtual void GetImmersiveFocusRectOffsets(RECT*);


		long Destroy(bool);
		long DestroyAll(bool);
		void DoubleBuffered(bool);
		void EnableUiaEvents(bool);
		void EndDefer(unsigned long);
		bool EnsureVisible(unsigned int);
		bool EnsureVisible();
		Element* FindDescendent(ATOM id);
		void FireEvent(Event* pEvent, bool fFull, bool fUseSpecifiedTarget);

		bool GetAbsorbsShortcut();
		UCString GetAccDefAction(Value**);
		UCString GetAccDesc(Value**);
		UCString GetAccHelp(Value**);
		UCString GetAccItemStatus(Value**);
		UCString GetAccItemType(Value**);
		UCString GetAccName(Value**);
		UCString GetAccNameAsDisplayed(Value**);
		UCString GetAccValue(Value**);

		int GetAccRole();
		int GetAccState();
		bool GetAccessible();
		int GetActive();
		Element* GetRoot();

		// Properties? wtf is this

		static const PropertyInfo* WINAPI AbsorbsShortcutProp();
		static const PropertyInfo* WINAPI AccDefActionProp();
		static const PropertyInfo* WINAPI AccDescProp();
		static const PropertyInfo* WINAPI AccHelpProp();
		static const PropertyInfo* WINAPI AccItemStatusProp();
		static const PropertyInfo* WINAPI AccItemTypeProp();
		static const PropertyInfo* WINAPI AccNameProp();
		static const PropertyInfo* WINAPI AccRoleProp();
		static const PropertyInfo* WINAPI AccStateProp();
		static const PropertyInfo* WINAPI AccValueProp();
		static const PropertyInfo* WINAPI AccessibleProp();
		static const PropertyInfo* WINAPI ActiveProp();
		static const PropertyInfo* WINAPI AlphaProp();
		static const PropertyInfo* WINAPI AnimationProp();
		static const PropertyInfo* WINAPI BackgroundProp();
		static const PropertyInfo* WINAPI BorderColorProp();
		static const PropertyInfo* WINAPI BorderStyleProp();
		static const PropertyInfo* WINAPI BorderThicknessProp();
		static const PropertyInfo* WINAPI ChildrenProp();
		static const PropertyInfo* WINAPI ClassProp();
		static const PropertyInfo* WINAPI CompositedTextProp();
		static const PropertyInfo* WINAPI ContentAlignProp();

		static const PropertyInfo* WINAPI ContentProp();
		static const PropertyInfo* WINAPI CursorProp();
		static const PropertyInfo* WINAPI CustomProp();
		static const PropertyInfo* WINAPI DPIProp();
		static const PropertyInfo* WINAPI DirectionProp();
		static const PropertyInfo* WINAPI DesiredSizeProp();
		static const PropertyInfo* WINAPI ExtentProp();
		static const PropertyInfo* WINAPI ForegroundProp();
		static const PropertyInfo* WINAPI FontFaceProp();
		static const PropertyInfo* WINAPI FontProp();
		static const PropertyInfo* WINAPI FontQualityProp();
		static const PropertyInfo* WINAPI FontSizeProp();
		static const PropertyInfo* WINAPI FontStyleProp();
		static const PropertyInfo* WINAPI FontWeightProp();
		static const PropertyInfo* WINAPI KeyFocusedProp();
		static const PropertyInfo* WINAPI KeyWithinProp();
		static const PropertyInfo* WINAPI LastDSConstProp();
		static const PropertyInfo* WINAPI LayoutPosProp();
		static const PropertyInfo* WINAPI LayoutProp();
		static const PropertyInfo* WINAPI LocationProp();
		static const PropertyInfo* WINAPI HeightProp();
		static const PropertyInfo* WINAPI HighDPIProp();
		static const PropertyInfo* WINAPI IDProp();
		static const PropertyInfo* WINAPI MinSizeProp();
		static const PropertyInfo* WINAPI MouseFocusedProp();
		static const PropertyInfo* WINAPI MouseWithinProp();
		static const PropertyInfo* WINAPI OverhangProp();
		static const PropertyInfo* WINAPI PaddingProp();
		static const PropertyInfo* WINAPI ParentProp();
		static const PropertyInfo* WINAPI PosInLayoutProp();
		static const PropertyInfo* WINAPI SelectedProp();
		static const PropertyInfo* WINAPI ShadowIntensityProp();
		static const PropertyInfo* WINAPI SheetProp();
		static const PropertyInfo* WINAPI ShortcutProp();
		static const PropertyInfo* WINAPI SizeInLayoutProp();
		static const PropertyInfo* WINAPI TextGlowSizeProp();
		static const PropertyInfo* WINAPI TooltipMaxWidthProp();
		static const PropertyInfo* WINAPI TooltipProp();
		static const PropertyInfo* WINAPI VisibleProp();
		static const PropertyInfo* WINAPI WidthProp();
		static const PropertyInfo* WINAPI WindowActiveProp();
		static const PropertyInfo* WINAPI XProp();
		static const PropertyInfo* WINAPI YProp();

		long GetRootRelativeBounds(LPRECT);
		bool GetSelected();
		int GetShadowIntensity();
		StyleSheet* GetSheet();
		int GetShortcut();
		UChar GetShortcutChar();
		int GetTextGlowSize();
		bool GetTooltip();
		int GetTooltipMaxWidth();
		Element* GetTopLevel();
		float GetTreeAlphaLevel();
		Value* GetValue(PropertyProcT pPropertyProc, int iIndex, UpdateCache* puc);
		Value* GetValue(const PropertyInfo* ppi, int iIndex, UpdateCache* puc);
		bool GetVisible();
		int GetWidth();
		bool GetWindowActive();
		int GetX();
		int GetY();

		bool HasAnimation();
		bool HasBorder();
		bool HasChildren();
		bool HasContent();
		bool HasLayout();
		bool HasMargin();
		bool HasPadding();
		static void WINAPI InitDefaultFontSize();
		static UID WINAPI KeyboardNavigate();

		long Insert(Element*, unsigned int);
		
		void InvokeAnimation(int, unsigned int);
		void InvokeAnimation(unsigned int, unsigned int, float, float, bool);
		bool IsCompositedText();
		
		bool IsDefaultCAlign();
		bool IsDefaultCursor();
		bool IsDescendent(Element*);
		bool IsDestroyed();
		bool IsHosted();
		bool IsRTL();
		
		int IsRoot();
		bool IsSelfLayout();
		bool IsValidAccessor(const PropertyInfo*, int, bool);
		static bool WINAPI IsValidValue(const PropertyInfo*, Value*);
		bool IsWordWrap();
		void MapElementPoint(Element*, POINT const*, LPPOINT);
		static const PropertyInfo* WINAPI MarginProp();

		void MarkNeedsDSUpdate();
		bool NeedsDSUpdate();

		
		

		void PaintBackground(HDC, Value*, RECT const &, RECT const &, RECT const &, RECT const &);
		void PaintBorder(HDC, Value*, RECT*, RECT const &);
		void PaintContent(HDC, RECT const*);
		void PaintFocusRect(HDC, RECT const*, RECT const*);
		void PaintStringContent(HDC, RECT const*, Value*, int);

		void PostEvent(Event*);
		long QueueDefaultAction();
		static long WINAPI Register();
		unsigned long WINAPI Release();
		long Remove(Element*);
		long RemoveAll();
		void RemoveListener(IElementListener*);
		long RemoveLocalValue( const PropertyInfo* (WINAPI*)());
		long RemoveLocalValue(const PropertyInfo*);

		long SetAbsorbsShortcut(bool);
		long SetAccDefAction(UCString);
		long SetAccDesc(UCString);
		long SetAccHelp(UCString);
		long SetAccItemStatus(UCString);
		long SetAccItemType(UCString);
		long SetAccName(UCString);
		long SetAccRole(int);
		long SetAccState(int);
		long SetAccValue(UCString);
		long SetAccessible(bool);
		long SetActive(int);
		long SetAlpha(int);
		long SetAnimation(int);
		long SetBackgroundColor(Fill const &);
		long SetBackgroundColor(unsigned long);
		long SetBackgroundColor(unsigned long, unsigned long, unsigned char);
		long SetBackgroundColor(unsigned long, unsigned long, unsigned long, unsigned char);
		long SetBackgroundColor(UCString, int, int);
		long SetBackgroundStdColor(int);
		long SetBorderColor(unsigned long);
		long SetBorderGradientColor(unsigned long, unsigned long, unsigned char);
		long SetBorderStdColor(int);
		long SetBorderStyle(int);
		long SetBorderThickness(int, int, int, int);
		long SetClass(UCString);
		static void WINAPI SetClassInfoPtr(IClassInfo*);
		long SetCompositedText(bool);
		long SetContentAlign(int);
		long SetContentGraphic(UCString, unsigned char, unsigned int);
		long SetContentGraphic(UCString, unsigned short, unsigned short);
		long SetContentString(UCString);
		long SetCursor(UCString);
		long SetCursorHandle(HICON);
		long SetDirection(int v);
		long SetEnabled(bool);
		long SetEncodedContentString(UCString);
		long SetFont(UCString);
		long SetFontFace(UCString);
		long SetFontQuality(int);
		long SetFontSize(int);
		long SetFontStyle(int);
		long SetFontWeight(int);
		long SetForegroundColor(unsigned long);
		long SetForegroundColor(unsigned long, unsigned long, unsigned char);
		long SetForegroundColor(unsigned long, unsigned long, unsigned long, unsigned char);
		long SetForegroundStdColor(int);
		long SetHeight(int);
		long SetID(UCString);
		long SetLayout(Layout*);
		long SetLayoutPos(int);
		long SetMargin(int, int, int, int);
		long SetMinSize(int, int);
		long SetOverhang(bool);
		long SetPadding(int, int, int, int);
		long SetSelected(bool);
		long SetShadowIntensity(int);
		long SetSheet(StyleSheet*);
		long SetShortcut(int);
		long SetStdCursor(int);
		long SetTextGlowSize(int);
		long SetTooltip(bool);
		long SetTooltipMaxWidth(int);
		long SetValue(PropertyProcT pPropertyProc, int iIndex, Value* pv);
		long SetValue(const PropertyInfo* ppi, int iIndex, Value* pv);
		long SetVisible(bool);
		long SetWidth(int);
		long SetWindowActive(bool);
		long SetX(int);
		long SetY(int);

		long SortChildren(int (*)(void const*, void const*));
		void StartDefer(unsigned long*);
		void StopAnimation(unsigned int);
		DeferCycle* TestDeferObject();
		bool UiaEvents();
		void UpdateLayout();
		static void WINAPI _AddDependency(Element*, const PropertyInfo*, int, DepRecs*, DeferCycle*, long*);
		void _ClearNeedsLayout();
		static long WINAPI _DisplayNodeCallback(HGADGET, void*, EventMsg*);
		void _EndOptimizedLayoutQ();
		int _GetChangesUpdatePass();
		unsigned int _GetNeedsLayout();
		static int WINAPI _MarkElementForDS(Element*);
		static int WINAPI _MarkElementForLayout(Element*, unsigned int);
		static bool WINAPI _SetGroupChanges(Element*, int, DeferCycle*);
		int _SetNeedsLayout(unsigned int);
		void _StartOptimizedLayoutQ();
		static void WINAPI _TransferGroupFlags(Element*, int);
		SIZE _UpdateDesiredSize(int, int, Surface*);
		void _UpdateLayoutPosition(int, int);
		void _UpdateLayoutSize(int, int);
		static PropertyInfo const * __stdcall EnabledProp();
		int GetAlpha();
		int GetAnimation();
		Fill const * GetBackgroundColor(Value * *);
		int GetBackgroundStdColor();
		Fill const * GetBorderColor(Value * *);
	protected:
		//24
		virtual void _SelfLayoutDoLayout(int, int);

		//25
		virtual SIZE _SelfLayoutUpdateDesiredSize(int, int, Surface*);

		//26
		virtual void OnHosted(Element*);
		//27
		virtual void OnUnHosted(Element*);
		//28
		virtual void UpdateTooltip(Element*);
		//29
		virtual void ActivateTooltip(Element*, unsigned long);
		//30
		virtual void RemoveTooltip(Element*);
public:

		//31
		virtual bool GetKeyFocused();

		//32
		virtual IClassInfo* GetClassInfoW();
		//33
		virtual long GetAccessibleImpl(IAccessible**);

		//34
		virtual long DefaultAction();
		virtual long GetUIAElementProvider(GUID const&, void** param2);
		//35
		virtual HRESULT GetElementProviderImpl(class InvokeHelper *, ElementProvider * *);


		//36
		virtual void HandleUiaDestroyListener();
		//37
		virtual void HandleUiaPropertyListener(const PropertyInfo*, int, Value*, Value*);
		//38
		virtual void HandleUiaPropertyChangingListener(const PropertyInfo*);
		//39
		virtual void HandleUiaEventListener(Event*);

		virtual Element* GetUiaFocusDelegate();

		
protected:

		void MarkHosted();
		void MarkSelfLayout();
		static void WINAPI _FlushLayout(Element*, DeferCycle*);
		static void WINAPI _InvalidateCachedDSConstraints(Element*);
		void _OnFontPropChanged(Value*);
		long _RemoveLocalValue( const PropertyInfo* (WINAPI*)(), bool);
		long _RemoveLocalValue(const PropertyInfo*, bool);
		long _SetValue( const PropertyInfo* (WINAPI*)(), int, Value*, bool);
		long _SetValue(const PropertyInfo*, int, Value*, bool);
private:
		Element* FindDescendentWorker(unsigned short);
		void _SyncBackground();
		void _SyncRedrawStyle();
		void _SyncVisible();
		bool IsPointValid(double, double);
		unsigned short* RemoveShortcutFromName(UCString);
		bool TryLinePattern(LPPOINT, const RECT&);
		bool TryPattern(double, double, LPPOINT, const RECT&);
		bool TrySparsePattern(LPPOINT, const RECT&);
		void _BroadcastEventWorker(Event*);
		int _CachedValueIsEqual(const PropertyInfo*, Element*);
		void _GetBuriedSheetDependencies(const PropertyInfo*, Element*, DepRecs*, DeferCycle*, long*);
		void _UpdatePropertyInCache(const PropertyInfo*);
		static void WINAPI _VoidPCNotifyTree(int, DeferCycle*);
		

		void _FlushDS(DeferCycle*);
		Value* _GetComputedValue(const PropertyInfo*, UpdateCache*);
		long _GetDependencies(const PropertyInfo*, int, DepRecs*, int, Value*, DeferCycle*);
		Value* _GetLocalValue(const PropertyInfo*);
		Value* _GetLocalValueFromVM(const PropertyInfo*);
		Value* _GetSpecifiedValue(const PropertyInfo*, UpdateCache*);
		Value* _GetSpecifiedValueIgnoreCache(const PropertyInfo*);
		void _InheritProperties();
		long _PostSourceChange();
		long _PreSourceChange( const PropertyInfo* (WINAPI*)(), int, Value*, Value*);
		long _PreSourceChange(const PropertyInfo*, int, Value*, Value*);

		unsigned int GetCommonDrawTextFlags(int);



		static IClassInfo*s_pClassInfo;

		HGADGET _hgDisplayNode;
		struct BehaviorStore *_pBehaviorStore;
		int _iIndex;
		// struct BTreeLookup<PropertyInfo const *,Value *> *_pvmLocal;
		void *_pvmLocal;
		int _iGCSlot;
		int _iGCLPSlot;
		int _iPCTail;
		DeferCycle *_pDeferCycle;
		// Internal::ListenerData *_pld;
		void *_pld;
		Element *_peInitialParent;
		Element *_peLocParent;
		tagPOINT _ptLocPosInLayt;
		tagSIZE _sizeLocSizeInLayt;
		tagSIZE _sizeLocLastDSConst;
		tagSIZE _sizeLocDesiredSize;
		int _dSpecLayoutPos;
		Value *_pvSpecSheet;
		int _dSpecAlpha;
		int _dPVLAnimationState;
		ATOM _atomSpecID;
		struct _BitMap
		{
			__int8 bLocKeyWithin : 1;
			__int8 bLocMouseWithin : 1;
			__int8 bCmpVisible : 1;
			__int8 bSpecVisible : 1;
			__int8 bSpecSelected : 1;
			__int8 bSpecKeyFocused : 1;
			__int8 bSpecMouseFocused : 1;
			__int8 bSpecAccessible : 1;
			__int8 bSpecEnabled : 1;
			__int8 bHasChildren : 1;
			__int8 bHasLayout : 1;
			__int8 bHasBorder : 1;
			__int8 bHasPadding : 1;
			__int8 bHasMargin : 1;
			__int8 bHasContent : 1;
			__int8 bDefaultCAlign : 1;
			__int8 bWordWrap : 1;
			__int8 bHasAnimation : 1;
			__int8 bDefaultCursor : 1;
			__int8 bDefaultBorderColor : 1;
			__int8 bDefaultForeground : 1;
			__int8 bDefaultFontWeight : 1;
			__int8 bDefaultFontStyle : 1;
			__int8 bDefaultFontQuality : 1;
			__int8 bSelfLayout : 1;
			__int8 bNeedsDSUpdate : 1;
			__int8 bDestroyed : 1;
			__int8 bHosted : 1;
			__int8 bHasTooltip : 1;
			__int8 bCompositedText : 1;
			__int8 bUiaEvents : 1;
			__int8 bPreserveAlphaChannel : 1;
			unsigned __int32 fNeedsLayout : 2;
			unsigned __int32 fSpecActive : 4;
			unsigned __int32 nSpecDirection : 1;
			unsigned __int32 nUseDefaultFontSize : 1;
			unsigned __int32 bHasEdgeHighlight : 1;
			unsigned __int32 nGetsLayoutCompleteGC : 1;
			unsigned __int32 fFontSizeInRP : 1;
			unsigned __int32 nScaleFactor : 10;
			unsigned __int32 bUsesDesktopPerMonitorScaling : 1;
		};
		_BitMap _fBit;
		int _dSpecFontSize;
		Value *_pvSpecFontFace;
		Value *_pvSpecBackground;
		class DuiAccessible *_pDuiAccessible;
		// struct Element::Impl *_pImpl;
		void *_pImpl;
		HWND _rootWindowForTheming;
	};

	class UILIB_API ElementProxy : public IProxy
	{
	public:
		ElementProxy(ElementProxy const &);
		ElementProxy();
		ElementProxy & operator=(ElementProxy const &);

		static ElementProxy * __stdcall Create(Element *);
		//1
		virtual long DoMethod(int, char *);
	protected:
		long GetAutomationId(VARIANT *);
		long GetBoundingRect(UiaRect *);
		long GetContent(VARIANT *, IAccessible *);
		void GetControlType(VARIANT *, IAccessible *);
		long GetFragmentRoot(IRawElementProviderFragmentRoot * *);
		long GetHwnd(HWND *);
		long GetLabel(VARIANT *);
		long GetProperty(VARIANT *, int);
		long GetProviderOptions(ProviderOptions *);
		long GetRuntimeId(SAFEARRAY * *);
		long IsPatternSupported(Schema::Pattern, bool *);
		long Navigate(NavigateDirection, IRawElementProviderFragment**);
		long SetString(VARIANT *, UCString (Element::*)(Value * *));
		int _UsesUIAProxies();

		//2
		virtual void Init(Element *);

	};

	//此类的声明很可能错误
	class UILIB_API ElementProvider
		: public RefcountBase
		, public IRawElementProviderSimple
		, public IRawElementProviderFragment
		, public IRawElementProviderAdviseEvents
	{
	public:
		ElementProvider();
		ElementProvider(const ElementProvider&) = delete;
		virtual ~ElementProvider();

		static long WINAPI Create(Element*, InvokeHelper*, ElementProvider**out);

		long DoInvokeArgs(int, ProviderProxyCall, char*);
		const Element* GetElementKey();
		void TossElement();
		void TossPatternProvider(Schema::Pattern);


		//IUnknown
		virtual unsigned long WINAPI AddRef();
		virtual unsigned long WINAPI Release();
		virtual long WINAPI QueryInterface(const GUID&, void**);

		//IRawElementProviderSimple
		virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProviderOptions(
			/* [retval][out] */ __RPC__out ProviderOptions *pRetVal);

		virtual HRESULT STDMETHODCALLTYPE GetPatternProvider(
			/* [in] */ PATTERNID patternId,
			/* [retval][out] */ __RPC__deref_out_opt IUnknown **pRetVal);

		virtual HRESULT STDMETHODCALLTYPE GetPropertyValue(
			/* [in] */ PROPERTYID propertyId,
			/* [retval][out] */ __RPC__out VARIANT *pRetVal);

		virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_HostRawElementProvider(
			/* [retval][out] */ __RPC__deref_out_opt IRawElementProviderSimple **pRetVal);

		//IRawElementProviderFragment
		virtual HRESULT STDMETHODCALLTYPE Navigate(
			/* [in] */ NavigateDirection direction,
			           /* [retval][out] */ __RPC__deref_out_opt IRawElementProviderFragment **pRetVal);

		virtual HRESULT STDMETHODCALLTYPE GetRuntimeId(
			/* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);

		virtual HRESULT STDMETHODCALLTYPE get_BoundingRectangle(
			/* [retval][out] */ __RPC__out UiaRect *pRetVal);

		virtual HRESULT STDMETHODCALLTYPE GetEmbeddedFragmentRoots(
			/* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *pRetVal);

		virtual HRESULT STDMETHODCALLTYPE SetFocus();

		virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_FragmentRoot(
			/* [retval][out] */ __RPC__deref_out_opt IRawElementProviderFragmentRoot **pRetVal);

		//IRawElementProviderAdviseEvents
		virtual HRESULT STDMETHODCALLTYPE AdviseEventAdded(
			/* [in] */ EVENTID eventId,
			/* [in] */ __RPC__in SAFEARRAY * propertyIDs);

		virtual HRESULT STDMETHODCALLTYPE AdviseEventRemoved(
			/* [in] */ EVENTID eventId,
			/* [in] */ __RPC__in SAFEARRAY * propertyIDs);

		//1 此函数似乎声明不正确
		virtual ProviderProxyCall GetProxyCreator();
		//2
		virtual volatile const Element* GetElement();

	protected:
		//3
		virtual long Init(Element*, InvokeHelper*);
		long DoInvoke(int, ...);
	};
}
