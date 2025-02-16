#pragma once

namespace DirectUI
{
	// Forward declaration of unexported class
	class DUIParsePlayer;
	class DUIParseRecorder;

	typedef HRESULT (CALLBACK* PLAYTCREATE)(int, int*, Value** ppVal);
	typedef HRESULT (CALLBACK* PfnCreate)(ElementProvider*, IUnknown** ppunk);
	typedef bool (CALLBACK* PfnIsPatternSupported)(Element*);

	enum DynamicScaleParsing
	{
		DSP_None = 0,
		DSP_Enabled = 1
	};

	typedef enum _DUI_PARSE_STATE
	{
		DPS_CalculateStringLength = 0,
		DPS_GlobalAllocStringCopy = 1,
		DPS_GlobalLockStringCopy = 2,
		DPS_StringCopy = 3,
		DPS_CreateXmlReaderFromHGlobal = 4,
		DPS_CreateStreamOnHGlobal = 5,
		DPS_CreateXmlReader = 6,
		DPS_CreateXmlReaderInputWithEncodingName = 7,
		DPS_SetInput = 8,
		DPS_InitializeParserFromXmlLiteReader = 9,
		DPS_CreateBinaryXmlReader = 10,
		DPS_BuildStylesFromBinary = 11,
		DPS_ReadyOnBinarySource = 12
	} DUI_PARSE_STATE;

	struct LINEINFO
	{
		WORD iLine;
		WORD iCol;
	};

	enum LogicalOperators
	{
		PSLO_NULL = 0,
		PSLO_Equal = 1,
		PSLO_NotEqual = 2,
		PSLO_Greater = 3,
		PSLO_GreaterEqual = 4,
		PSLO_Lesser = 5,
		PSLO_LesserEqual = 6
	};

	struct XMLParserCond
	{
		LogicalOperators nLogOp;
		WCHAR* szProp;
		WCHAR* szVal;
	};

	class Schema
	{
	public:
		enum Pattern
		{
			First = 0,
			Invoke = 0,
			ExpandCollapse = 1,
			GridItem = 2,
			Grid = 3,
			RangeValue = 4,
			Scroll = 5,
			ScrollItem = 6,
			SelectionItem = 7,
			Selection = 8,
			Table = 9,
			TableItem = 10,
			Toggle = 11,
			Value = 12,
			Dock = 13,
			Drag = 14,
			MultipleView = 15,
			Text = 16,
			Transform = 17,
			Window = 18,
			ItemContainer = 19,
			VirtualizedItem = 20,
			PatternCount = 21
		};

		enum Event
		{
			FirstEvent = 0,
			ToolTipOpened = 0,
			ToolTipClosed = 1,
			StructureChanged = 2,
			MenuOpened = 3,
			AutomationPropertyChanged = 4,
			AutomationFocusChanged = 5,
			AsyncContentLoaded = 6,
			DragDragStart = 7,
			DragDragComplete = 8,
			DragDragCancel = 9,
			MenuClosed = 10,
			InvokeInvoked = 11,
			SelectionItemElementAddedToSelection = 12,
			SelectionItemElementRemovedFromSelection = 13,
			SelectionItemElementSelected = 14,
			SelectionInvalidated = 15,
			TextTextSelectionChanged = 16,
			WindowWindowOpened = 17,
			WindowWindowClosed = 18,
			LayoutInvalidated = 19,
			SystemAlert = 20,
			EventCount = 21
		};
		
		UILIB_API static HRESULT WINAPI Init();
		UILIB_API static int LookupAccessibleRole(int, bool*);
		UILIB_API static HRESULT WINAPI CreatePatternProvider(Pattern pattern, ElementProvider* pprv, IUnknown** ppunk);
		UILIB_API static Pattern WINAPI PatternFromPatternId(int id);
		UILIB_API static Event WINAPI EventFromEventId(int id);
		UILIB_API static PfnIsPatternSupported PfnIsSupportedFromPattern(Pattern pattern);

		UILIB_API static PfnUiaLookupId UiaLookupId;
		UILIB_API static PfnUiaReturnRawElementProvider UiaReturnRawElementProvider;
		UILIB_API static PfnUiaRaiseAutomationPropertyChangedEvent UiaRaiseAutomationPropertyChangedEvent;
		UILIB_API static PfnUiaRaiseAutomationEvent UiaRaiseAutomationEvent;
		UILIB_API static PfnUiaRaiseStructureChangedEvent UiaRaiseStructureChangedEvent;
		UILIB_API static PfnUiaHostProviderFromHwnd UiaHostProviderFromHwnd;
		
		UILIB_API static int RuntimeIdProperty;
		UILIB_API static int BoundingRectangleProperty;
		UILIB_API static int ProcessIdProperty;
		UILIB_API static int ControlTypeProperty;
		UILIB_API static int LocalizedControlTypeProperty;
		UILIB_API static int NameProperty;
		UILIB_API static int AcceleratorKeyProperty;
		UILIB_API static int AccessKeyProperty;
		UILIB_API static int HasKeyboardFocusProperty;
		UILIB_API static int IsKeyboardFocusableProperty;
		UILIB_API static int IsEnabledProperty;
		UILIB_API static int AutomationIdProperty;
		UILIB_API static int ClassNameProperty;
		UILIB_API static int HelpTextProperty;
		UILIB_API static int ClickablePointProperty;
		UILIB_API static int CultureProperty;
		UILIB_API static int IsControlElementProperty;
		UILIB_API static int IsContentElementProperty;
		UILIB_API static int LabeledByProperty;
		UILIB_API static int IsPasswordProperty;
		UILIB_API static int NewNativeWindowHandleProperty;
		UILIB_API static int ItemTypeProperty;
		UILIB_API static int ItemStatusProperty;
		UILIB_API static int IsOffscreen;
		UILIB_API static int Orientation;
		UILIB_API static int FrameworkId;
		UILIB_API static int IsPeripheral;
		UILIB_API static int Drag_IsGrabbed_Property;
		UILIB_API static int Drag_DropEffect_Property;
		UILIB_API static int Drag_DropEffects_Property;
		UILIB_API static int ExpandCollapse_ExpandCollapseState_Property;
		UILIB_API static int Grid_ColumnCount_Property;
		UILIB_API static int Grid_RowCount_Property;
		UILIB_API static int GridItem_Column_Property;
		UILIB_API static int GridItem_ColumnSpan_Property;
		UILIB_API static int GridItem_Parent_Property;
		UILIB_API static int GridItem_Row_Property;
		UILIB_API static int GridItem_RowSpan_Property;
		UILIB_API static int RangeValue_IsReadOnly_Property;
		UILIB_API static int RangeValue_LargeChange_Property;
		UILIB_API static int RangeValue_Maximum_Property;
		UILIB_API static int RangeValue_Minimum_Property;
		UILIB_API static int RangeValue_SmallChange_Property;
		UILIB_API static int RangeValue_Value_Property;
		UILIB_API static int Scroll_HorizontalScrollPercent_Property;
		UILIB_API static int Scroll_HorizontallyScrollable_Property;
		UILIB_API static int Scroll_HorizontalViewSize_Property;
		UILIB_API static int Scroll_VerticalScrollPercent_Property;
		UILIB_API static int Scroll_VerticallyScrollable_Property;
		UILIB_API static int Scroll_VerticalViewSize_Property;
		UILIB_API static int Selection_CanSelectMultiple_Property;
		UILIB_API static int Selection_IsSelectionRequired_Property;
		UILIB_API static int Selection_Selection_Property;
		UILIB_API static int SelectionItem_IsSelected_Property;
		UILIB_API static int SelectionItem_SelectionContainer_Property;
		UILIB_API static int Table_ColumnHeaders_Property;
		UILIB_API static int Table_RowHeaders_Property;
		UILIB_API static int Table_RowOrColumnMajor_Property;
		UILIB_API static int TableItem_RowHeaderItems_Property;
		UILIB_API static int TableItem_ColumnHeaderItems_Property;
		UILIB_API static int Toggle_ToggleState_Property;
		UILIB_API static int Value_Value_Property;
		UILIB_API static int Value_IsReadOnly_Property;
		UILIB_API static int NullControlType;
		UILIB_API static int ButtonControlType;
		UILIB_API static int CalendarControlType;
		UILIB_API static int CheckBoxControlType;
		UILIB_API static int ComboBoxControlType;
		UILIB_API static int CustomControlType;
		UILIB_API static int DataGridControlType;
		UILIB_API static int DataItemControlType;
		UILIB_API static int DocumentControlType;
		UILIB_API static int EditControlType;
		UILIB_API static int GroupControlType;
		UILIB_API static int HeaderControlType;
		UILIB_API static int HeaderItemControlType;
		UILIB_API static int HyperlinkControlType;
		UILIB_API static int ImageControlType;
		UILIB_API static int ListControlType;
		UILIB_API static int ListItemControlType;
		UILIB_API static int MenuBarControlType;
		UILIB_API static int MenuControlType;
		UILIB_API static int MenuItemControlType;
		UILIB_API static int PaneControlType;
		UILIB_API static int ProgressBarControlType;
		UILIB_API static int RadioButtonControlType;
		UILIB_API static int ScrollBarControlType;
		UILIB_API static int SeparatorControlType;
		UILIB_API static int SliderControlType;
		UILIB_API static int SpinnerControlType;
		UILIB_API static int SplitButtonControlType;
		UILIB_API static int StatusBarControlType;
		UILIB_API static int TabControlType;
		UILIB_API static int TabItemControlType;
		UILIB_API static int TableControlType;
		UILIB_API static int TextControlType;
		UILIB_API static int ThumbControlType;
		UILIB_API static int TitleBarControlType;
		UILIB_API static int ToolBarControlType;
		UILIB_API static int ToolTipControlType;
		UILIB_API static int TreeControlType;
		UILIB_API static int TreeItemControlType;
		UILIB_API static int WindowControlType;
		UILIB_API static int SemanticZoomControlType;
		UILIB_API static int InvokePattern;
		UILIB_API static int ExpandCollapsePattern;
		UILIB_API static int GridItemPattern;
		UILIB_API static int GridPattern;
		UILIB_API static int RangeValuePattern;
		UILIB_API static int ScrollPattern;
		UILIB_API static int ScrollItemPattern;
		UILIB_API static int SelectionItemPattern;
		UILIB_API static int SelectionPattern;
		UILIB_API static int TablePattern;
		UILIB_API static int TableItemPattern;
		UILIB_API static int TogglePattern;
		UILIB_API static int ValuePattern;
		UILIB_API static int DockPattern;
		UILIB_API static int DragPattern;
		UILIB_API static int MultipleViewPattern;
		UILIB_API static int TextPattern;
		UILIB_API static int TransformPattern;
		UILIB_API static int WindowPattern;
		UILIB_API static int ItemContainerPattern;
		UILIB_API static int VirtualizedItemPattern;
		UILIB_API static int ToolTipOpenedEvent;
		UILIB_API static int ToolTipClosedEvent;
		UILIB_API static int StructureChangedEvent;
		UILIB_API static int MenuOpenedEvent;
		UILIB_API static int AutomationPropertyChangedEvent;
		UILIB_API static int AutomationFocusChangedEvent;
		UILIB_API static int AsyncContentLoadedEvent;
		UILIB_API static int DragDragStartEvent;
		UILIB_API static int DragDragCompleteEvent;
		UILIB_API static int DragDragCancelEvent;
		UILIB_API static int MenuClosedEvent;
		UILIB_API static int InvokeInvokedEvent;
		UILIB_API static int SelectionItemElementAddedToSelectionEvent;
		UILIB_API static int SelectionItemElementRemovedFromSelectionEvent;
		UILIB_API static int SelectionItemElementSelectedEvent;
		UILIB_API static int SelectionInvalidatedEvent;
		UILIB_API static int TextTextSelectionChangedEvent;
		UILIB_API static int WindowWindowOpenedEvent;
		UILIB_API static int WindowWindowClosedEvent;
		UILIB_API static int LayoutInvalidatedEvent;
		UILIB_API static int SystemAlertEvent;

	private:
		UILIB_API static HRESULT WINAPI GetProcs();

		struct PropertyInfo
		{
			int* _pPropertyId;
			const GUID* _pguid;
		};

		static const PropertyInfo g_propertyInfoTable[];
		UILIB_API static HRESULT WINAPI LookupPropertyInfos();

		struct ControlInfo
		{
			int* _pControlTypeId;
			const GUID* _pguid;
		};

		static const ControlInfo g_controlInfoTable[];
		UILIB_API static HRESULT WINAPI LookupControlInfos();

		struct PatternInfo
		{
			int* _pPatternId;
			const GUID* _pguid;
		};

		static const PatternInfo g_patternInfoTable[];
		UILIB_API static HRESULT WINAPI LookupPatternInfos();

		struct EventInfo
		{
			int* _pEventId;
			const GUID* _pguid;
		};

		static const EventInfo g_eventInfoTable[];
		UILIB_API static HRESULT WINAPI LookupEventInfos();

		struct RoleMap
		{
			int _accRole;
			bool _fIsContentElement;
			const int* _pid;
		};

		static const RoleMap _roleMapping[];

		struct PatternMap
		{
			const int* _pid;
			PfnCreate _pfnCreate;
			PfnIsPatternSupported _pfnSupported;;
		};

		static const PatternMap g_patternMapping[];

		struct EventMap
		{
			const int* _pid;
		};

		static const EventMap g_eventMapping[];
		static bool g_fInited;
	};

	namespace ParserTools
	{
		enum ExprNodeType
		{
			ENT_LITERAL = 0,
			ENT_STRING = 1,
			ENT_FUNCALL = 2,
			ENT_OR = 3
		};

		struct ExprNode
		{
			ExprNodeType ent;
			WCHAR* pszName;
			UINT cArgs;
			ExprNode* pArgs;
			UINT uiArgs;
		};

		enum TokenType
		{
			ttInvalid = 0,
			ttLiteral = 1,
			ttString = 2,
			ttEOI = 3
		};

		class Tokenizer
		{
		public:
			void Initialize(WCHAR*);
			TokenType Next();
			WCHAR PeekChar();
			void SkipChar(WCHAR);
			WCHAR* CurrentName();
			bool IsWhiteSpace(WCHAR);
			bool IsLiteralChar(WCHAR wch);
			void SkipWhiteSpace();

		private:
			WCHAR* _psz;
			WCHAR* _pszLast;
			WCHAR _wchSave;
		};

		class ValueParser : Tokenizer
		{
		public:
			ValueParser();
			~ValueParser();
			static HRESULT Create(ValueParser** ppvp);
			void Destroy();
			HRESULT Parse(const WCHAR* pszValue, const ExprNode** ppenRoot);

		private:
			HRESULT Initialize();
			HRESULT ParseWorker();
			HRESULT ParseFuncall();
			HRESULT ParseOr();
			HRESULT FinishComplexNodeT(UINT uiFirstArgT);
			HRESULT AddExprNodeT(ExprNodeType);
			HRESULT InsertExprNodeT(ExprNodeType ent, int iDelta);
			HRESULT TransferNodes(UINT uiStartT);
			void ResetBuf();
			DynamicArray<ExprNode>* _pdaNodes;
			DynamicArray<ExprNode>* _pdaNodesT;
			WCHAR* _pszBuf;
			WCHAR _szBuf[260];
		};


		struct ClassicValue
		{
			const WCHAR* pszClass;
			int iPart;
			int iState;
			int iProp;
			const Value* pvParsed;
			const ExprNode* pen;
		};
	}

	typedef Value* (CALLBACK* PXMLGETSHEETCB)(const WCHAR*, void* pContext);
	typedef void (CALLBACK* PXMLPARSEERRORCB)(const WCHAR* pszError, const WCHAR* pszToken, int dLine, void* pContext);
	typedef bool (CALLBACK* PUNKNOWNATTRCB)(const WCHAR*, void* pContext);

	class UILIB_API DUIXmlParser
	{
	public:
		DUIXmlParser(const DUIXmlParser&);
		DUIXmlParser();
		virtual ~DUIXmlParser();

		static HRESULT WINAPI Create(DUIXmlParser** ppParserOut, PXMLGETSHEETCB pfnGetSheetCallback, void* pGetSheetContext, PXMLPARSEERRORCB pfnErrorCallback, void* pErrorContext);
		void Destroy();

		HRESULT _InitializeTables();
		void _DestroyTables();

		HRESULT SetXML(const WCHAR* pBuffer, HINSTANCE hResourceInstance, HINSTANCE hControlsInstance);
		HRESULT SetPreprocessedXML(const WCHAR* pPreProcessed, HINSTANCE hResourceInstance, HINSTANCE hControlsInstance);
		HRESULT SetXMLFromResourceWithTheme(UINT uRCID, HINSTANCE hResInstance, HINSTANCE hResTheme, HINSTANCE hControlsInstance);
		HRESULT SetXMLFromResource(const WCHAR* pszResource, const WCHAR* pszResType, HINSTANCE hResourceInstance, HINSTANCE hControlsInstance);
		HRESULT SetXMLFromResource(const WCHAR* pszResid, HINSTANCE hResInstance, HINSTANCE hControlsInstance);
		HRESULT SetXMLFromResource(UINT uRCID, const WCHAR* pszResType, HINSTANCE hResInstance, HINSTANCE hControlsInstance);
		HRESULT SetXMLFromResource(UINT uRCID, HINSTANCE hResInstance, HINSTANCE hControlsInstance);
		
		void SetRootWindowForTheming(HWND);
		Value* GetMappedValue(WCHAR*);

		HRESULT CreateElement(const WCHAR* pszResID, Element* pEleSubstitute, Element* pParent, DWORD* pdwDeferCookie, Element** ppElementOut);

		HRESULT GetSheet(const WCHAR* pszResID, Value** ppValueOut);

		void SetParseErrorCallback(PXMLPARSEERRORCB pfnErrorCallback, void* pContext);
		void SetGetSheetCallback(PXMLGETSHEETCB pfnGetSheetCallback, void* pContext);

		PXMLGETSHEETCB GetGetSheetCallback();
		void* GetSheetContext();
		void EnableDesignMode();
		void SetUnknownAttrCallback(PUNKNOWNATTRCB pfnUnknownAttrCallback, void* pContext);
		HINSTANCE GetResourceHInstance();
		HINSTANCE GetHInstance();
		HRESULT LookupElement(LINEINFO li, const WCHAR* pszElem, HINSTANCE hControlsInstance, IClassInfo** ppciOut);
		HRESULT LookupElement(IXmlReader* pReader, const WCHAR* pszElem, HINSTANCE hInstance, IClassInfo** ppciOut);
		HRESULT UpdateSheets(Element* pe);

		void SetDefaultHInstance(HINSTANCE hInst);
		void SetUnavailableIcon(HICON hIcon);
		void SetScaleFactor(float scaleFactor);
		void SetDynamicScaling(DynamicScaleParsing dsp);
		bool IsDynamicScaling();
		HRESULT CopySheets(DynamicArray<Value*>** ppdaSheets);
		void SetOverrideScaleFactor(float scaleFactor);
		bool GetOverrideScaleFactor(float* pScaleFactor);

	protected:
		HRESULT Initialize();
		HRESULT InitializeParserFromXmlReader(IXmlReader* pReader, HINSTANCE hResourceInstance, HINSTANCE hControlsInstance);

		HRESULT ParseStyleSheets(IXmlReader* pReader);
		HRESULT ParseStyleSheets();

		HRESULT _EnterOnCurrentThread();
		void _LeaveOnCurrentThread();

		static HRESULT GetXmlLiteDll(HMODULE* phXmlLiteDll);
		HRESULT CreateXmlReader(IXmlReader** ppReader);
		HRESULT CreateXmlReaderFromHGLOBAL(HGLOBAL hglob, IXmlReader** ppReader);
		HRESULT CreateXmlReaderInputWithEncodingName(IStream* pInput, const WCHAR* pszEncodingName, IUnknown** ppReaderInput);

		HRESULT _SetXMLFromResource(const WCHAR* pszResource, const WCHAR* pszResType, HINSTANCE hResourceInstance, HINSTANCE hControlsInstance, HINSTANCE hResTheme);
		HRESULT _SetBinaryXml(const BYTE* pBuffer, UINT cbBuffer, HINSTANCE hControlsInstance);
		HRESULT _BuildFromBinary(Element* peSub, Element* peParent, const WCHAR* pszResource, DWORD* pdwDefer, Element** ppElement);
		HRESULT _BuildElement(IXmlReader* pReader, Element* peParent, Element** ppElement);
		HRESULT _BuildChildren(IXmlReader* pReader, Element* peParent);
		HRESULT _SetProperties(IXmlReader* pReader, IClassInfo* pClassInfo, Element* peTarget);
		HRESULT _ParseLayout(const WCHAR* pszLayoutString, Value** ppvLayout);
		HRESULT _ParseBehavior(Element* pTarget, const WCHAR* pszBehavior);
		HRESULT _CreateValue(const WCHAR* pszValue, const PropertyInfo* pPropInfo, Value** ppValue);
		HRESULT _GetClassForElement(IXmlReader* pReader, IClassInfo** ppClassInfo);
		HRESULT _GetClassForElementByName(const WCHAR* pszName, IClassInfo** ppClassInfo);
		HRESULT _GetPropertyForAttribute(IXmlReader* pReader, IClassInfo* pClassInfo, const PropertyInfo** ppPropInfo);
		HRESULT _BuildStyles(IXmlReader* pReader);
		HRESULT _GetValueForStyleSheet(IClassInfo* pClassInfo, const WCHAR* pszName, const WCHAR* pszValue, const PropertyInfo** ppPropInfo, Value** ppValue);
		LINEINFO _GetLineInfo(IXmlReader* pReader);
		HRESULT _SetupParserState(HINSTANCE hResourceInstance, HINSTANCE hControlsInstance);

		HRESULT _RecordElementTrees(IXmlReader* pReader);
		HRESULT _RecordElementWithChildren(IXmlReader* pReader, bool fEmptyElem, WCHAR** ppszElemName);
		HRESULT _RecordInstantiateElement(IXmlReader* pReader, WCHAR** ppszElemName);
		HRESULT _RecordSetElementProperties(IXmlReader* pReader);
		HRESULT _RecordElementLayout(IXmlReader* pReader, const WCHAR* pszValue);
		HRESULT _RecordElementBehaviors(IXmlReader* pReader, const WCHAR* pszValue);
		HRESULT _RecordSetValue(IXmlReader* pReader, const WCHAR* pszName, const WCHAR* pszValue);
		HRESULT _RecordElementStyleSheet(const WCHAR* pszSheetName, bool fIgnoreMissingSheet);

		HRESULT CreateStyleSheet(IXmlReader* pReader, const WCHAR* pszSheetResid, StyleSheet** ppSheet);
		HRESULT AddRulesToStyleSheet(IXmlReader* pReader, StyleSheet* pSheet, const WCHAR* pszSheetResid, DynamicArray<XMLParserCond>* pdaXMLConds, DynamicArray<WCHAR*>* pdaCondStrings);
		HRESULT _ResolveStyleSheet(const WCHAR* pszReference, Value** ppvSheet, UINT* pSheetId);


		HRESULT MapPropertyNameToPropertyInfo(LINEINFO li, IClassInfo* pci, const WCHAR* pszName, const PropertyInfo** ppInfo);
		HRESULT GetPropValPairInfo(LINEINFO li, IClassInfo* pci, const WCHAR* pszProperty, const WCHAR* pszValue, const PropertyInfo** ppInfo, Value** ppValue);
		HRESULT GetPropValPairInfo(IXmlReader* pReader, IClassInfo* pci, const WCHAR* pszProperty, const WCHAR* pszValue, const PropertyInfo** ppInfo, Value** ppValue);

		HRESULT _ParseValue(const PropertyInfo* ppi, WCHAR* pszValue, Value** ppValue);

		void SendParseError(const WCHAR* pszError, const WCHAR* pszToken, int dLine, int dCol, HRESULT hr);
		void SendParseError(const WCHAR* pszError, const WCHAR* pszToken, IXmlReader* pReader, HRESULT hr);
		int QuerySysMetric(int idx, bool* pfDynamicScaling);
		const WCHAR* QuerySysMetricStr(int idx, WCHAR* pszMetric, UINT c);

		
		template <typename T>
		struct UILIB_API FunctionDefinition
		{
			typedef HRESULT (*FUNCPARSER)(const ParserTools::ExprNode* pen, T*, bool*);

			const WCHAR* pszName;
			FUNCPARSER pfnParse;
		};

		static const FunctionDefinition<int> s_fdInt[3];
		static const FunctionDefinition<COLORREF> s_fdClr[4];
		static const FunctionDefinition<Value*> s_fdString[4];
		static const FunctionDefinition<ScaledRECT> s_fdRect[3];
		static const FunctionDefinition<ScaledSIZE> s_fdSize[3];
		static const FunctionDefinition<Value*> s_fdFill[4];
		static const FunctionDefinition<Value*> s_fdGraphic[5];

		struct NUMBER
		{
			int i;
			bool fDynamicScaling;
		};

		union ParsedArg
		{
			NUMBER number;
			LPCWSTR psz;
			COLORREF clr;
			HTHEME htheme;
			HMODULE hmod;
			HINSTANCE hinst;
			const ParserTools::ExprNode* pen;
		};

		HRESULT ParseArgs(const ParserTools::ExprNode* pen, ParsedArg* rgpa, UINT cpa, const CHAR* pszSignature);
		HRESULT ParseFunction(const WCHAR* pszName, const ParserTools::ExprNode* pen, ParsedArg* rgpa, UINT cpa, const CHAR* pszSignature);

		static bool WINAPI IsThemeClassName(const ParserTools::ExprNode* pen);

		HRESULT ParseMagnitude(const WCHAR* pszMag, int* pMagOut, bool* pfDynamicScaling);
		HRESULT ParseMagnitudeFloat(const WCHAR* pszMag, float* pMagOut, bool* pfDynamicScaling);

		HRESULT ParseLiteralNumber(const WCHAR* psz, int* pnOut, bool* pfDynamicScaling);
		HRESULT ParseColorInt(WCHAR*, int*);
		HRESULT ParseLiteralColorInt(const WCHAR* pszValue, int* piOut);
		HRESULT ParseLiteralColor(const WCHAR* pszValue, COLORREF* pclrOut);

		HRESULT ParseSysMetricInt(const ParserTools::ExprNode* pen, int* piOut, bool* pfDynamicScaling);
		HRESULT ParseGTMetInt(const ParserTools::ExprNode* pen, int* piOut, bool* pfDynamicScaling);

		HRESULT ParseARGBColor(const ParserTools::ExprNode* pen, COLORREF* pclrOut, bool* pfDynamicScaling);
		HRESULT ParseRGBColor(const ParserTools::ExprNode* pen, COLORREF* pclrOut, bool* pfDynamicScaling);
		HRESULT ParseGTCColor(const ParserTools::ExprNode* pen, COLORREF* pclrOut, bool* pfDynamicScaling);

		HRESULT ParseResStr(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling);
		HRESULT ParseSysMetricStr(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling);
		HRESULT ParseGTFStr(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling);

		HRESULT ParseRectRect(const ParserTools::ExprNode* pen, ScaledRECT* prcOut, bool* pfDynamicScaling);
		HRESULT ParseGTMarRect(const ParserTools::ExprNode* pen, ScaledRECT* prcOut, bool* pfDynamicScaling);

		HRESULT ParseSizeSize(const ParserTools::ExprNode* pen, ScaledSIZE* pszOut, bool* pfDynamicScaling);
		HRESULT ParseGTPartSize(const ParserTools::ExprNode* pen, ScaledSIZE* pszOut, bool* pfDynamicScaling);

		HRESULT ParseSGraphicHelper(bool fGraphic, const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseSGraphicGraphic(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling);

		HRESULT ParseGraphicHelper(bool fGraphic, const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseGraphicGraphic(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling);

		HRESULT ParseImageGraphic(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling);
		HRESULT ParseIconGraphic(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling);

		HRESULT ParseLiteral(const ParserTools::ExprNode* pen, const WCHAR** ppszOut);
		HRESULT ParseNumber(const ParserTools::ExprNode* pen, int* pnOut, bool* pfDynamicScaling);
		HRESULT ParseFloat(const ParserTools::ExprNode* pen, float* pflOut, bool* pfDynamicScaling);
		HRESULT ParseColor(const ParserTools::ExprNode* pen, COLORREF* pclrOut);
		HRESULT ParseQuotedString(const ParserTools::ExprNode* pen, WCHAR** ppszOut);
		HRESULT ParseResid(const ParserTools::ExprNode* pen, const WCHAR** ppszOut);
		HRESULT ParseTheme(const ParserTools::ExprNode* pen, bool use96dpi, HTHEME* phtheme);
		HRESULT ParseLibrary(const ParserTools::ExprNode* pen, HMODULE* phmod);

		HRESULT ParseRect(const ParserTools::ExprNode* pen, ScaledRECT* prcOut);
		HRESULT ParseSize(const ParserTools::ExprNode* pen, ScaledSIZE* pszOut);

		HRESULT ParseGradientFill(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling);
		HRESULT ParseDFCFill(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling);
		HRESULT ParseDTBFill(const ParserTools::ExprNode* pen, Value** ppVal, bool* pfDynamicScaling);

		HRESULT CreateLayout(const ParserTools::ExprNode* pen, PLAYTCREATE pfnCreate);

		HRESULT ParseIntValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseFloatValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseBoolValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseStringValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseRectValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseSizeValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParsePointValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseFillValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseLayoutValue(const ParserTools::ExprNode* pen);
		HRESULT ParseGraphicValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseSheetValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseAtomValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseCursorValue(const ParserTools::ExprNode* pen, Value** ppVal);

		HRESULT ParseBehaviorArgValue(const ParserTools::ExprNode* pen, Value** ppVal);
		HRESULT ParseBehavior(const ParserTools::ExprNode* pen);
		HRESULT ParseDoubleListValue(const ParserTools::ExprNode* pen, Value** ppVal);

		HRESULT MapPropertyEnumValue(const EnumMap* pMap, const WCHAR* pszValue, int* piVal);
		HRESULT GetValueParser(ParserTools::ValueParser** ppvp);
		void ReturnValueParser(ParserTools::ValueParser* pvp);
		HRESULT GetParserCommon(DUIXmlParser** ppParserCommon);

		HMODULE _hXmlLiteDll;
		HINSTANCE _hControlsInstance;
		HANDLE _hDefault;
		HICON _hUnavailableIcon;

		PXMLPARSEERRORCB _pfnErrorCB;
		PXMLGETSHEETCB _pfnGetSheetCB;
		PUNKNOWNATTRCB _pfnUnknownAttrCallback;
		
		void* _pErrorContext;
		void* _pGetSheetContext;
		void* _pfnUnknownAttrContext;

		DynamicScaleParsing _dynamicScaleParsing;
		float _flScaleFactor;
		bool _fScaleFactorSet;
		bool _fParseErrorSent;
		bool _fDesignMode;
		int _fThemed;
		int _fHighContrast;
		int _fComposited;
		bool _fOverrideScale;
		
		const PropertyInfo* _ppiValue;
		const WCHAR* _pszError;
		
		ParserTools::ValueParser* _pvpCache;
		DynamicArray<Value*>* _pdaSheetList;
		DynamicArray<Value*>* _pdaTrackedValues;
		DUIXmlParser* _pParserCommon;
		IXmlReader* _pCurrentReader;
		
		IDuiParserCache* _pParserCache;
		IDuiBinaryReader* _pBinaryReader;
		
		int _nCreateDepth;
		
		DynamicArray<int>* _prgLayoutArgs;
		
		
	private:
		float _ScaleRelativePixels(float nRelPix);
		int _ScaleRelativePixels(int nRelPix);
		float _ScalePointsToPixels(float flPoint);
		int _ScalePointsToPixels(int nPoint);

		DUIParseRecorder* _pRecorder;
		DynamicArray<DUIParsePlayer*>* _prgPlayers;
		void SetParseState(DUI_PARSE_STATE eParseState);
		DUI_PARSE_STATE _eParseState;
		ResourceModuleHandles _rmhResourcesModules;
		DWORD _dwThreadId;
		ULONG _cRefThread;
		HWND _rootWindowForTheming;

	public:
		DUIXmlParser& operator=(DUIXmlParser const&);
	};

	class DUIFactory
	{
	public:
		UILIB_API DUIFactory(HWND hwnd);
		UILIB_API ~DUIFactory();
		UILIB_API DUIFactory& operator=(DUIFactory const&);

		UILIB_API HRESULT CreateParser();

		UILIB_API HRESULT LoadFromBuffer(const WCHAR* pszBuf, UINT cchBuf, const WCHAR* pszResid, Element* pParent, DWORD* pdwDeferCookie, Element** ppe);
		UILIB_API HRESULT LoadFromFile(const WCHAR*, const WCHAR*, Element*, unsigned long*, Element* *);
		UILIB_API HRESULT LoadFromResource(HINSTANCE, const WCHAR*, const WCHAR*, Element*, unsigned long*, Element* *, const WCHAR*);

		UILIB_API void SetError(const WCHAR*, ...);

		UILIB_API DUIXmlParser* DetachParser();
		UILIB_API DUIXmlParser* GetParser();

	private:
		UILIB_API static void WINAPI s_XMLParseError(const WCHAR* pszError, const WCHAR* pszToken, int dLine, DUIFactory* pContext);
		UILIB_API void ClearParser();

		int _fError;
		HINSTANCE _hInst;
		DUIXmlParser* _pParser;
		HWND _hwndParent;
	};
}
