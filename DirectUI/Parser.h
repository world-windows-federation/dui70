#pragma once

namespace DirectUI
{
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

	typedef bool (__stdcall*Unknow3Call)(Element*);

	class UILIB_API Schema
	{
	public:
		enum class Pattern
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

		enum class Event
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

		struct RoleMap
		{
			int _accRole;
			bool _fIsContentElement;
			int* _pid;
		};

		struct PropertyInfo
		{
			int* _pPropertyId;
			GUID* _pguid;
		};

		struct PatternMap
		{
			int* _pid;
			HRESULT (*_pfnCreate)(ElementProvider*, IUnknown**);
			bool (*_pfnSupported)(Element*);
		};

		struct EventMap
		{
			int* _pid;
		};

		struct EventInfo
		{
			int* _pEventId;
			GUID* _pguid;
		};

		struct ControlInfo
		{
			int* _pControlTypeId;
			GUID* _pguid;
		};

		struct PatternInfo
		{
			int* _pPatternId;
			GUID* _pguid;
		};


		Schema& operator=(Schema const&);
		static HRESULT WINAPI CreatePatternProvider(Pattern, ElementProvider*, IUnknown* *);
		static Event __stdcall EventFromEventId(int);
		static HRESULT WINAPI Init();
		static int __stdcall LookupAccessibleRole(int, bool*);
		static Pattern __stdcall PatternFromPatternId(int);
		static Unknow3Call __stdcall PfnIsSupportedFromPattern(Pattern);

		static int AcceleratorKeyProperty;
		static int AccessKeyProperty;
		static int AsyncContentLoadedEvent;
		static int AutomationFocusChangedEvent;
		static int AutomationIdProperty;
		static int AutomationPropertyChangedEvent;
		static int BoundingRectangleProperty;
		static int ButtonControlType;
		static int CalendarControlType;
		static int CheckBoxControlType;
		static int ClassNameProperty;
		static int ClickablePointProperty;
		static int ComboBoxControlType;
		static int ControlTypeProperty;
		static int CultureProperty;
		static int CustomControlType;
		static int DataGridControlType;
		static int DataItemControlType;
		static int DockPattern;
		static int DocumentControlType;
		static int EditControlType;
		static int ExpandCollapsePattern;
		static int ExpandCollapse_ExpandCollapseState_Property;
		static int FrameworkId;
		static int GridItemPattern;
		static int GridItem_ColumnSpan_Property;
		static int GridItem_Column_Property;
		static int GridItem_Parent_Property;
		static int GridItem_RowSpan_Property;
		static int GridItem_Row_Property;
		static int GridPattern;
		static int Grid_ColumnCount_Property;
		static int Grid_RowCount_Property;
		static int GroupControlType;
		static int HasKeyboardFocusProperty;
		static int HeaderControlType;
		static int HeaderItemControlType;
		static int HelpTextProperty;
		static int HyperlinkControlType;
		static int ImageControlType;
		static int InvokeInvokedEvent;
		static int InvokePattern;
		static int IsContentElementProperty;
		static int IsControlElementProperty;
		static int IsEnabledProperty;
		static int IsKeyboardFocusableProperty;
		static int IsOffscreen;
		static int IsPasswordProperty;
		static int ItemContainerPattern;
		static int ItemStatusProperty;
		static int ItemTypeProperty;
		static int LabeledByProperty;
		static int LayoutInvalidatedEvent;
		static int ListControlType;
		static int ListItemControlType;
		static int LocalizedControlTypeProperty;
		static int MenuBarControlType;
		static int MenuClosedEvent;
		static int MenuControlType;
		static int MenuItemControlType;
		static int MenuOpenedEvent;
		static int MultipleViewPattern;
		static int NameProperty;
		static int NewNativeWindowHandleProperty;
		static int NullControlType;
		static int Orientation;
		static int PaneControlType;
		static int ProcessIdProperty;
		static int ProgressBarControlType;
		static int RadioButtonControlType;
		static int RangeValuePattern;
		static int RangeValue_IsReadOnly_Property;
		static int RangeValue_LargeChange_Property;
		static int RangeValue_Maximum_Property;
		static int RangeValue_Minimum_Property;
		static int RangeValue_SmallChange_Property;
		static int RangeValue_Value_Property;
		static int RuntimeIdProperty;
		static int ScrollBarControlType;
		static int ScrollItemPattern;
		static int ScrollPattern;
		static int Scroll_HorizontalScrollPercent_Property;
		static int Scroll_HorizontalViewSize_Property;
		static int Scroll_HorizontallyScrollable_Property;
		static int Scroll_VerticalScrollPercent_Property;
		static int Scroll_VerticalViewSize_Property;
		static int Scroll_VerticallyScrollable_Property;
		static int SelectionInvalidatedEvent;
		static int SelectionItemElementAddedToSelectionEvent;
		static int SelectionItemElementRemovedFromSelectionEvent;
		static int SelectionItemElementSelectedEvent;
		static int SelectionItemPattern;
		static int SelectionItem_IsSelected_Property;
		static int SelectionItem_SelectionContainer_Property;
		static int SelectionPattern;
		static int Selection_CanSelectMultiple_Property;
		static int Selection_IsSelectionRequired_Property;
		static int Selection_Selection_Property;
		static int SeparatorControlType;
		static int SliderControlType;
		static int SpinnerControlType;
		static int SplitButtonControlType;
		static int StatusBarControlType;
		static int StructureChangedEvent;
		static int TabControlType;
		static int TabItemControlType;
		static int TableControlType;
		static int TableItemPattern;
		static int TableItem_ColumnHeaderItems_Property;
		static int TableItem_RowHeaderItems_Property;
		static int TablePattern;
		static int Table_ColumnHeaders_Property;
		static int Table_RowHeaders_Property;
		static int Table_RowOrColumnMajor_Property;
		static int TextControlType;
		static int TextPattern;
		static int TextTextSelectionChangedEvent;
		static int ThumbControlType;
		static int TitleBarControlType;
		static int TogglePattern;
		static int Toggle_ToggleState_Property;
		static int ToolBarControlType;
		static int ToolTipClosedEvent;
		static int ToolTipControlType;
		static int ToolTipOpenedEvent;
		static int TransformPattern;
		static int TreeControlType;
		static int TreeItemControlType;
		static HRESULT (__stdcall*UiaHostProviderFromHwnd)(HWND hwnd, IRawElementProviderSimple** ppProvider);
		static int (__stdcall*UiaLookupId)(AutomationIdentifierType type, const GUID* pGuid);
		static HRESULT (__stdcall*UiaRaiseAutomationEvent)(IRawElementProviderSimple* pProvider, EVENTID id);
		static HRESULT (__stdcall*UiaRaiseAutomationPropertyChangedEvent)(IRawElementProviderSimple* pProvider, PROPERTYID id, VARIANT oldValue, VARIANT newValue);
		static HRESULT (__stdcall*UiaRaiseStructureChangedEvent)(IRawElementProviderSimple* pProvider, StructureChangeType structureChangeType, int* pRuntimeId, int cRuntimeIdLen);
		static LRESULT (__stdcall*UiaReturnRawElementProvider)(HWND hwnd, WPARAM wParam, LPARAM lParam, IRawElementProviderSimple* el);
		static int ValuePattern;
		static int Value_IsReadOnly_Property;
		static int Value_Value_Property;
		static int VirtualizedItemPattern;
		static int WindowControlType;
		static int WindowPattern;
		static int WindowWindowClosedEvent;
		static int WindowWindowOpenedEvent;

	private:
		static HRESULT __stdcall LookupControlInfos();
		static HRESULT __stdcall LookupEventInfos();
		static HRESULT __stdcall LookupPatternInfos();
		static HRESULT __stdcall LookupPropertyInfos();
		static HRESULT __stdcall GetProcs();

		static RoleMap const* __ptr32 const _roleMapping;
		static ControlInfo const* __ptr32 const g_controlInfoTable;
		static EventInfo const* __ptr32 const g_eventInfoTable;
		static EventMap const* __ptr32 const g_eventMapping;
		static bool g_fInited;
		static PatternInfo const* __ptr32 const g_patternInfoTable;
		static PatternMap const* __ptr32 const g_patternMapping;
		static const PropertyInfo* __ptr32 const g_propertyInfoTable;
	};

	typedef Value* (WINAPI*GetSheetCallback)(UCString, void*);
	typedef void (WINAPI*ParseErrorCallback)(UCString, UCString, int, void*);
	typedef bool (WINAPI*UnknownAttrCallback)(UCString, void*);

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
			unsigned int cArgs;
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
			DynamicArray<ExprNode, 0>* _pdaNodes;
			DynamicArray<ExprNode, 0>* _pdaNodesT;
			WCHAR* _pszBuf;
			WCHAR _szBuf[260];
		};


		struct ClassicValue
		{
			WCHAR* pszClass;
			int iPart;
			int iState;
			int iProp;
			void* pvParsed;
			ExprNode* pen;
		};
	}

	class UILIB_API DUIXmlParser
	{
	public:
		DUIXmlParser(const DUIXmlParser&);
		DUIXmlParser();
		virtual ~DUIXmlParser();

		DUIXmlParser& operator=(const DUIXmlParser&);

		// Callback defines
		/*
		
		*/
		static HRESULT WINAPI Create(_Inout_ DUIXmlParser** pXmlParser, _In_opt_ GetSheetCallback, _In_opt_ void* sheetParam, _In_opt_ ParseErrorCallback, _In_opt_ void* parseErrorParam);
		HRESULT CreateElement(UCString, Element*, Element*, unsigned long*, Element** out);

		void Destroy();
		void EnableDesignMode();
		GetSheetCallback GetGetSheetCallback();
		HINSTANCE GetHInstance();

		HINSTANCE GetResourceHInstance();
		HRESULT GetSheet(UCString, Value**);
		void* GetSheetContext();

		HRESULT LookupElement(IXmlReader*, UCString, HINSTANCE, IClassInfo**);
		HRESULT LookupElement(LINEINFO, UCString, HINSTANCE, IClassInfo**);

		void SetDefaultHInstance(HINSTANCE);

		void SetGetSheetCallback(GetSheetCallback, void*);
		void SetParseErrorCallback(ParseErrorCallback, void*);
		void SetUnknownAttrCallback(bool (__stdcall*)(UCString, void*), void*);

		HRESULT SetPreprocessedXML(UCString, HINSTANCE, HINSTANCE);
		void SetUnavailableIcon(HICON);

		HRESULT SetXML(UCString szXML, HINSTANCE hModule, HINSTANCE/*0x10000000 作用未知*/);
		
		HRESULT SetXMLFromResource(UINT uID, HINSTANCE hModule, HINSTANCE/*0x10000000 作用未知*/);
		HRESULT SetXMLFromResource(UCString szID, HINSTANCE hModule, HINSTANCE/*0x10000000 作用未知*/);

		HRESULT UpdateSheets(Element*);
		void _DestroyTables();
		HRESULT _InitializeTables();

		// exported for: int, unsigned long, Value*, RECT
		template <typename T>
		struct UILIB_API FunctionDefinition
		{
			typedef HRESULT (DUIXmlParser::*FUNCPARSER)(const ParserTools::ExprNode*, T*, bool*);

			const WCHAR* pszName;
			FUNCPARSER pfnParse;
		};

		struct NUMBER
		{
			int i;
			bool fDynamicScaling;
		};

		union ParsedArg
		{
			NUMBER number;
			WCHAR* psz;
			COLORREF clr;
			HTHEME htheme;
			HMODULE hmod;
			HINSTANCE hinst;
			ParserTools::ExprNode* pen;
		};

	protected:
		HRESULT _EnterOnCurrentThread();
		LINEINFO _GetLineInfo(IXmlReader*);

		HRESULT AddRulesToStyleSheet(IXmlReader*, StyleSheet*, UCString, DynamicArray<XMLParserCond, 0>*, DynamicArray<WCHAR*, 0>*);
		HRESULT CreateLayout(const ParserTools::ExprNode*, long (WINAPI*)(int, int*, Value**));
		HRESULT CreateStyleSheet(IXmlReader*, UCString, StyleSheet**);
		HRESULT CreateXmlReader(IXmlReader**);
		HRESULT CreateXmlReaderFromHGLOBAL(void*, IXmlReader**);
		HRESULT CreateXmlReaderInputWithEncodingName(IStream*, UCString, IUnknown**);
		HRESULT GetParserCommon(DUIXmlParser**);
		HRESULT GetPropValPairInfo(IXmlReader*, IClassInfo*, UCString, UCString, PropertyInfo const**, Value**);
		HRESULT GetPropValPairInfo(LINEINFO, IClassInfo*, UCString, UCString, PropertyInfo const**, Value**);
		HRESULT GetValueParser(ParserTools::ValueParser**);
		static HRESULT WINAPI GetXmlLiteDll(HINSTANCE*);
		HRESULT Initialize();
		HRESULT InitializeParserFromXmlLiteReader(IXmlReader*);
		static bool WINAPI IsThemeClassName(const ParserTools::ExprNode*);
		HRESULT MapPropertyEnumValue(const EnumMap*, UCString, int*);
		HRESULT MapPropertyNameToPropertyInfo(LINEINFO, IClassInfo*, UCString, const PropertyInfo**);
		HRESULT ParseARGBColor(const ParserTools::ExprNode*, unsigned long*);
		HRESULT ParseArgs(const ParserTools::ExprNode*, ParsedArg*, unsigned int, const char*);
		HRESULT ParseAtomValue(const ParserTools::ExprNode*, Value**);
		HRESULT ParseBoolValue(const ParserTools::ExprNode*, Value**);
		HRESULT ParseColor(const ParserTools::ExprNode*, unsigned long*);
		HRESULT ParseDFCFill(const ParserTools::ExprNode*, Value**);
		HRESULT ParseDTBFill(const ParserTools::ExprNode*, Value**);
		HRESULT ParseFillValue(const ParserTools::ExprNode*, Value**);
		HRESULT ParseFunction(UCString, const ParserTools::ExprNode*, ParsedArg*, unsigned int, const char*);
		HRESULT ParseGTCColor(const ParserTools::ExprNode*, unsigned long*);
		HRESULT ParseGTFStr(const ParserTools::ExprNode*, Value**);
		HRESULT ParseGTMarRect(const ParserTools::ExprNode*, LPRECT);
		HRESULT ParseGTMetInt(const ParserTools::ExprNode*, int*);
		HRESULT ParseGradientFill(const ParserTools::ExprNode*, Value**);
		HRESULT ParseGraphicGraphic(const ParserTools::ExprNode*, Value**);
		HRESULT ParseGraphicHelper(bool, const ParserTools::ExprNode*, Value**);
		HRESULT ParseGraphicValue(const ParserTools::ExprNode*, Value**);
		HRESULT ParseIconGraphic(const ParserTools::ExprNode*, Value**);
		HRESULT ParseImageGraphic(const ParserTools::ExprNode*, Value**);
		HRESULT ParseIntValue(const ParserTools::ExprNode*, Value**);
		HRESULT ParseLayoutValue(const ParserTools::ExprNode*);
		HRESULT ParseLibrary(const ParserTools::ExprNode*, HINSTANCE*);
		HRESULT ParseLiteral(const ParserTools::ExprNode*, UCString*);
		HRESULT ParseLiteralColor(UCString, unsigned long*);
		HRESULT ParseLiteralColorInt(UCString, int*);
		HRESULT ParseLiteralNumber(UCString, int*);
		HRESULT ParseMagnitude(UCString, int*);
		HRESULT ParseNumber(const ParserTools::ExprNode*, int*);
		HRESULT ParsePointValue(const ParserTools::ExprNode*, Value**);
		HRESULT ParseQuotedString(const ParserTools::ExprNode*, UCString*);
		HRESULT ParseRGBColor(const ParserTools::ExprNode*, unsigned long*);
		HRESULT ParseRect(const ParserTools::ExprNode*, LPRECT);
		HRESULT ParseRectRect(const ParserTools::ExprNode*, LPRECT);
		HRESULT ParseRectValue(const ParserTools::ExprNode*, Value**);
		HRESULT ParseResStr(const ParserTools::ExprNode*, Value**);
		HRESULT ParseResid(const ParserTools::ExprNode*, UCString*);
		HRESULT ParseSGraphicGraphic(const ParserTools::ExprNode*, Value**);
		HRESULT ParseSGraphicHelper(bool, const ParserTools::ExprNode*, Value**);
		HRESULT ParseSizeValue(const ParserTools::ExprNode*, Value**);
		HRESULT ParseStringValue(const ParserTools::ExprNode*, Value**);
		HRESULT ParseStyleSheets(IXmlReader*);
		HRESULT ParseSysMetricInt(const ParserTools::ExprNode*, int*);
		HRESULT ParseSysMetricStr(const ParserTools::ExprNode*, Value**);
		HRESULT ParseTheme(const ParserTools::ExprNode*, void**);
		static int WINAPI QuerySysMetric(int);
		static UCString WINAPI QuerySysMetricStr(int, WCHAR*, unsigned int);
		void ReturnValueParser(ParserTools::ValueParser*);
		void SendParseError(UCString, UCString, int, int, long);
		void SendParseError(UCString, UCString, IXmlReader*, long);
		void _LeaveOnCurrentThread();

		HRESULT _RecordElementLayout(IXmlReader*, UCString);
		HRESULT _RecordElementStyleSheet(UCString, bool);
		HRESULT _RecordElementTrees(IXmlReader*);
		HRESULT _RecordElementWithChildren(IXmlReader*, bool, WCHAR**);
		HRESULT _RecordInstantiateElement(IXmlReader*, WCHAR**);
		HRESULT _RecordSetElementProperties(IXmlReader*);
		HRESULT _RecordSetValue(IXmlReader*, UCString, UCString);

	private:
		void SetParseState(DUI_PARSE_STATE eParseState);
	};

	class UILIB_API DUIFactory
	{
	public:
		DUIFactory(HWND);
		~DUIFactory();
		DUIFactory& operator=(DUIFactory const&);
		HRESULT CreateParser();
		DUIXmlParser* DetachParser();
		DUIXmlParser* GetParser();
		HRESULT LoadFromBuffer(const WCHAR*, UINT_PTR, const WCHAR*, Element*, unsigned long*, Element* *);
		HRESULT LoadFromFile(const WCHAR*, const WCHAR*, Element*, unsigned long*, Element* *);
		HRESULT LoadFromResource(HINSTANCE, const WCHAR*, const WCHAR*, Element*, unsigned long*, Element* *, const WCHAR*);
		void SetError(const WCHAR*, ...);

	private:
		static void WINAPI s_XMLParseError(const WCHAR*, const WCHAR*, int, void*);
		void ClearParser();
		int _fError;
		HINSTANCE _hInst;
		DUIXmlParser* _pParser;
		HWND _hwndParent;
	};
}
