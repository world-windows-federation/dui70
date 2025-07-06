#pragma once

namespace DirectUI
{
	DECLARE_INTERFACE(IDialogElement)
	{
		virtual bool GetButtonClassAcceptsEnterKey() = 0;
		virtual bool GetDefaultButtonTracking() = 0;
		virtual Element* GetRegisteredDefaultButton() = 0;
		virtual bool GetHandleEnterKey() = 0;
		virtual HRESULT SetDefaultButtonTracking(bool v) = 0;
		virtual Element* GetKeyFocusedElement() = 0;
		virtual bool OnChildLostFocus(Element* peFrom) = 0;
		virtual bool OnChildReceivedFocus(Element* peTo) = 0;
		virtual Element* GetDefaultButton() = 0;
	};

	DECLARE_INTERFACE(IElementListener)
	{
		virtual void OnListenerAttach(Element* peFrom) = 0;
		virtual void OnListenerDetach(Element* peFrom) = 0;
		virtual bool OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) = 0;
		virtual void OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) = 0;
		virtual void OnListenedInput(Element* peFrom, InputEvent* pInput) = 0;
		virtual void OnListenedEvent(Element* peFrom, Event* pEvent) = 0;
	};

	DECLARE_INTERFACE(IClassInfo)
	{
		virtual void AddRef() = 0;
		virtual int Release() = 0;
		virtual HRESULT CreateInstance(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement) = 0;
		virtual const PropertyInfo* EnumPropertyInfo(UINT nEnum) = 0;
		virtual const PropertyInfo* GetByClassIndex(UINT iIndex) = 0;
		virtual UINT GetPICount() const = 0;
		virtual UINT GetGlobalIndex() const = 0;
		virtual IClassInfo* GetBaseClass() = 0;
		virtual const WCHAR* GetName() const = 0;
		virtual bool IsValidProperty(const PropertyInfo* ppi) const = 0;
		virtual bool IsSubclassOf(IClassInfo* pci) const = 0;
		virtual void Destroy() = 0;
		virtual HMODULE GetModule() const = 0;
		virtual bool IsGlobal() const = 0;
		virtual void AddChild() = 0;
		virtual void RemoveChild() = 0;
		virtual int GetChildren() const = 0;
		virtual void AssertPIZeroRef() const = 0;
	};

	struct UILIB_API IDataEntry
	{
		virtual ~IDataEntry() = default;

		virtual HRESULT GetProperty(const WCHAR*, WCHAR**, bool*) = 0;
		virtual void* GetActual() = 0;
	};


	class UILIB_API IProvider
	{
	public:
		IProvider(const IProvider&);
		IProvider();
		IProvider& operator=(const IProvider&);

		virtual PfnCreateProxy GetProxyCreator() = 0;
	};
	
	class UILIB_API IXProviderCP
	{
	public:
		IXProviderCP(const IXProviderCP&);
		IXProviderCP();
		IXProviderCP& operator=(const IXProviderCP&);

		virtual long CreateDUICP(class HWNDElement*, HWND, HWND, Element**, class DUIXmlParser**) = 0;
		virtual long CreateParserCP(DUIXmlParser**) = 0;
		virtual void DestroyCP() = 0;
	};

	class UILIB_API IXElementCP
	{
	public:
		IXElementCP(const IXElementCP&);
		IXElementCP();
		IXElementCP& operator=(const IXElementCP&);

		virtual HWND GetNotificationSinkHWND() = 0;
		virtual UINT GetCreationFlags() = 0;
	};

	interface UILIB_API IDataEngine
	{
		virtual ~IDataEngine() = default;
		virtual UINT GetSize() = 0;
		virtual IDataEntry* GetEntry(UINT) = 0;
	};
}

class CSafeElementListenerCB : public DirectUI::IElementListener
{
public:
	void OnListenerAttach(DirectUI::Element* peFrom) override {}
	void OnListenerDetach(DirectUI::Element* peFrom) override {}
	bool OnListenedPropertyChanging(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew) override { return true; }
	void OnListenedPropertyChanged(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew) override {}
	void OnListenedInput(DirectUI::Element* peFrom, DirectUI::InputEvent* pInput) override {}
	void OnListenedEvent(DirectUI::Element* peFrom, DirectUI::Event* pEvent) override {}
};

namespace DuiBehaviorFilters
{
	enum Flags
	{
		None = 0x0,
		Hosted = 0x1,
		UnHosted = 0x2,
		PropertyChanging = 0x4,
		PropertyChanged = 0x8,
		Input = 0x10,
		KeyFocusMoved = 0x20,
		Events = 0x40,
		Layout = 0x80,
		Paint = 0x100,
		GetAdjacent = 0x200,
		DisplayNodeCallback = 0x400,
	};
}

DEFINE_ENUM_FLAG_OPERATORS(DuiBehaviorFilters::Flags);

namespace DirectUI
{
	struct UILIB_API NavReference
	{
		void Init(Element* pe, RECT* prc);

		UINT cbSize;
		Element* pe;
		RECT* prc;
	};
}

DECLARE_INTERFACE_IID_(IDuiBehavior, IUnknown, "70650A6D-8987-4D93-9B1D-ACEB9D92F485")
{
	STDMETHOD(Init)(DirectUI::Value* pvArgs) PURE;
	STDMETHOD(GetCallbackFilters)(DuiBehaviorFilters::Flags* pFilters) PURE;
	STDMETHOD(OnAttach)(DirectUI::Element* pe) PURE;
	STDMETHOD(OnDetach)(DirectUI::Element* pe) PURE;
	STDMETHOD(OnHosted)(DirectUI::Element* peFrom, DirectUI::Element* pe) PURE;
	STDMETHOD(OnUnHosted)(DirectUI::Element* peFrom, DirectUI::Element* peOldHost) PURE;
	STDMETHOD(OnPropertyChanging)(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew, BOOL* pfAllowProcess) PURE;
	STDMETHOD(OnPropertyChanged)(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew) PURE;
	STDMETHOD(OnInput)(DirectUI::Element* peFrom, DirectUI::InputEvent* pInput) PURE;
	STDMETHOD(OnKeyFocusMoved)(DirectUI::Element* peFrom, DirectUI::Element* peOld, DirectUI::Element* peNew) PURE;
	STDMETHOD(OnEvent)(DirectUI::Element* peFrom, DirectUI::Event* pEvent) PURE;
	STDMETHOD(OnDoLayout)(DirectUI::Element* peFrom, int dWidth, int dHeight) PURE;
	STDMETHOD(OnUpdateDesiredSize)(DirectUI::Element* peFrom, int dConstW, int dConstH, DirectUI::Surface* psrf, SIZE* pszDesired) PURE;
	STDMETHOD(OnPaint)(DirectUI::Element* peFrom, HDC hdc, const RECT* prcGadgetPxl, const RECT* prcInvalidPxl) PURE;
	STDMETHOD(OnGetAdjacent)(DirectUI::Element* peFrom, int iNavDir, const DirectUI::NavReference* pnr, DWORD dwFlags, DirectUI::Element** ppeTo) PURE;
	STDMETHOD(OnDisplayNodeCallback)(DirectUI::Element* peFrom, EventMsg* pGMsg) PURE;
};

class IDuiBehaviorImpl : public IDuiBehavior
{
	STDMETHODIMP Init(DirectUI::Value* pvArgs) override;
	STDMETHODIMP OnAttach(DirectUI::Element* pe) override;
	STDMETHODIMP OnDetach(DirectUI::Element* pe) override;
	STDMETHODIMP OnHosted(DirectUI::Element* peFrom, DirectUI::Element* pe) override;
	STDMETHODIMP OnUnHosted(DirectUI::Element* peFrom, DirectUI::Element* peOldHost) override;
	STDMETHODIMP OnPropertyChanging(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew, BOOL* pfAllowProcess) override;
	STDMETHODIMP OnPropertyChanged(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew) override;
	STDMETHODIMP OnInput(DirectUI::Element* peFrom, DirectUI::InputEvent* pInput) override;
	STDMETHODIMP OnKeyFocusMoved(DirectUI::Element* peFrom, DirectUI::Element* peOld, DirectUI::Element* peNew) override;
	STDMETHODIMP OnEvent(DirectUI::Element* peFrom, DirectUI::Event* pEvent) override;
	STDMETHODIMP OnDoLayout(DirectUI::Element* peFrom, int dWidth, int dHeight) override;
	STDMETHODIMP OnUpdateDesiredSize(DirectUI::Element* peFrom, int dConstW, int dConstH, DirectUI::Surface* psrf, SIZE* pszDesired) override;
	STDMETHODIMP OnPaint(DirectUI::Element* peFrom, HDC hdc, const RECT* prcGadgetPxl, const RECT* prcInvalidPxl) override;
	STDMETHODIMP OnGetAdjacent(DirectUI::Element* peFrom, int iNavDir, const DirectUI::NavReference* pnr, DWORD dwFlags, DirectUI::Element** ppeTo) override;
	STDMETHODIMP OnDisplayNodeCallback(DirectUI::Element* peFrom, EventMsg* pGMsg) override;
};

DECLARE_INTERFACE_IID_(ITouchTooltipEventSink, IUnknown, "2D97ED04-C05F-4302-9462-8A9EC79F1464")
{
	STDMETHOD(OnTooltipTimerFired)(DirectUI::TOUCHTOOLTIP_INPUT touchTooltipInput, DirectUI::TOUCHTOOLTIP_TYPE touchTooltipType, DirectUI::TOUCHTOOLTIP_DELAY touchTooltipDelay) PURE;
	STDMETHOD(OnTooltipHidden)() PURE;
};

MIDL_INTERFACE("13450B2E-1819-49A5-B997-800D02CC0980")
ITouchTooltip : IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE SetText(const WCHAR* pszText) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetTextWithMaxLines(const WCHAR* pszText, UINT cLinesMax) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetRichTooltip(DirectUI::Element* pe) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetOptions(DirectUI::TOUCHTOOLTIP_OPTION_FLAGS* ptouchTooltipOptionFlags) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetOptions(DirectUI::TOUCHTOOLTIP_OPTION_FLAGS touchTooltipOptionFlags) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetDirection(DirectUI::TOUCHTOOLTIP_LAYOUT_DIRECTION touchTooltipLayoutDirection) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetProgrammaticOffset(int cRPOffset) = 0;
	virtual HRESULT STDMETHODCALLTYPE StartShowTimer(DirectUI::TOUCHTOOLTIP_INPUT touchTooltipInput, DirectUI::TOUCHTOOLTIP_TYPE touchTooltipType) = 0;
	virtual HRESULT STDMETHODCALLTYPE Show(DirectUI::TOUCHTOOLTIP_INPUT touchTooltipInput, const RECT* prcTool, DirectUI::TOUCHTOOLTIP_PLACEMENT touchTooltipPlacementPreferred) = 0;
	virtual HRESULT STDMETHODCALLTYPE ShowNearTouchPoint(const POINT* pptTouch, DirectUI::TOUCHTOOLTIP_PLACEMENT touchTooltipPlacementPreferred) = 0;
	virtual HRESULT STDMETHODCALLTYPE ShowNearMousePoint(const POINT* pptMouse, DirectUI::TOUCHTOOLTIP_PLACEMENT touchTooltipPlacementPreferred) = 0;
	virtual HRESULT STDMETHODCALLTYPE Hide() = 0;
	virtual HRESULT STDMETHODCALLTYPE IsVisible() = 0;
	virtual HRESULT STDMETHODCALLTYPE Advise(ITouchTooltipEventSink* pEventSink) = 0;
	virtual HRESULT STDMETHODCALLTYPE Unadvise() = 0;
};

DECLARE_INTERFACE_IID_(IDuiBinaryReader, IUnknown, "C1F02EF9-E2EB-47B2-BF2C-EEF7449FC1F6")
{
	STDMETHOD_(HRESULT, GetResource)(UINT index, LPCWSTR* ppszResid) PURE;
	STDMETHOD_(HRESULT, SeekToResource)(LPCWSTR pszResid) PURE;
	STDMETHOD_(HRESULT, PushState)() PURE;
	STDMETHOD_(HRESULT, PopState)() PURE;
};

MIDL_INTERFACE("B97EE329-6B9C-471F-A52A-3F99D814F17A")
IDuiParserCache : IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE Find(ULONG key, DirectUI::IClassInfo** ppClassInfo) = 0;
	virtual HRESULT STDMETHODCALLTYPE Find(ULONG key, DirectUI::Value** ppValue) = 0;
	virtual HRESULT STDMETHODCALLTYPE Store(ULONG key, DirectUI::IClassInfo* pClassInfo) = 0;
	virtual HRESULT STDMETHODCALLTYPE Store(ULONG key, DirectUI::Value* pValue) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateLayout(ULONG key, DirectUI::Value** ppValue) = 0;
	virtual HRESULT STDMETHODCALLTYPE AddLayout(ULONG key, HRESULT (*)(int, int*, DirectUI::Value**), int cargs, int* pargs) = 0; // TODO: Figure out the typedef of this function
	virtual HRESULT STDMETHODCALLTYPE ClearStoredClasses() = 0;
};
