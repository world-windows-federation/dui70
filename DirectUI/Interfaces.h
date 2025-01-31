#pragma once

namespace DirectUI
{
	class Value;
	struct PropertyInfo;

	struct DECLSPEC_NOVTABLE IElementListener
	{
		//0
		virtual void OnListenerAttach(Element* peFrom) = 0;
		//1
		virtual void OnListenerDetach(Element* peFrom) = 0;
		//2 returns false to cancel
		virtual bool OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) = 0;
		//3
		virtual void OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) = 0;
		//4
		virtual void OnListenedInput(Element* peFrom, InputEvent* pInput) = 0;
		//5
		virtual void OnListenedEvent(Element* peFrom, Event* pEvent) = 0;
	};

	struct UILIB_API IClassInfo
	{
		IClassInfo& operator=(const IClassInfo&) = delete;

		virtual void AddRef() = 0;
		virtual int Release() = 0;
		virtual HRESULT CreateInstance(Element*, ULONG*, Element**) = 0;
		virtual const PropertyInfo* EnumPropertyInfo(UINT) = 0;
		virtual const PropertyInfo* GetByClassIndex(UINT) = 0;
		virtual unsigned int GetPICount() const = 0;
		virtual unsigned int GetGlobalIndex() const = 0;
		virtual IClassInfo* GetBaseClass() = 0;
		virtual UCString GetName() const = 0;
		virtual bool IsValidProperty(PropertyInfo const*) const = 0;
		virtual bool IsSubclassOf(IClassInfo*) const = 0;
		virtual void Destroy() = 0;
		virtual HINSTANCE GetModule() const = 0;
		virtual bool IsGlobal() const = 0;
		virtual void AddChild() = 0;
		virtual void RemoveChild() = 0;
		virtual int GetChildren() const = 0;
		virtual void AssertPIZeroRef() const = 0;

		//virtual ~IClassInfo();
	};

	struct UILIB_API IDataEntry
	{
	public:
		IDataEntry(const IDataEntry&);
		IDataEntry();
		virtual ~IDataEntry();

		virtual HRESULT GetProperty(const WCHAR*, WCHAR**, bool*) = 0;
		virtual void* GetActual() = 0;

		IDataEntry& operator=(const IDataEntry&);
	};

	class DECLSPEC_NOVTABLE IProxy
	{
	public:
		virtual long DoMethod(int, char*) = 0;

	protected:
		virtual void Init(Element*) = 0;
	};

	class UILIB_API Proxy
	{
	public:
		Proxy(const Proxy&);
		Proxy();
		virtual ~Proxy();
		Proxy& operator=(const Proxy&);

		static long __stdcall SyncCallback(HGADGET__*, void*, EventMsg*);

	protected:
		void Invoke(unsigned int, void*);
		virtual void OnInvoke(unsigned int, void*);
	};

	class UILIB_API ProviderProxy : public IProxy
	{
	public:
		ProviderProxy(const ProviderProxy&);
		ProviderProxy& operator=(const ProviderProxy&);

	protected:
		ProviderProxy();
		virtual void Init(Element*);
	};

	typedef ProviderProxy* (__stdcall*ProviderProxyCall)(Element*);

	class UILIB_API IProvider
	{
	public:
		IProvider(const IProvider&);
		IProvider();
		IProvider& operator=(const IProvider&);

		virtual ProviderProxyCall GetProxyCreator() = 0;
	};

	class UILIB_API RefcountBase
	{
	public:
		RefcountBase();
		RefcountBase(const RefcountBase&) = delete;
		RefcountBase& operator=(const RefcountBase&) = delete;

		virtual ~RefcountBase();

		long AddRef();
		long Release();
	};


	template <class X, class Y, int i>
	class PatternProvider
		: public RefcountBase
		  , public IProvider
		//, public Y
	{
	public:
		PatternProvider();
		PatternProvider(const PatternProvider&) = delete;
		PatternProvider& operator=(const PatternProvider&) = delete;
		virtual ~PatternProvider();

		static long WINAPI Create(class ElementProvider*, IUnknown**);
		virtual void Init(ElementProvider*);
		//IProvider
		virtual ProviderProxyCall GetProxyCreator();

	protected:
		long DoInvoke(int, ...);

	private:
	};


	struct UILIB_API ISBLeak
	{
	public:
		ISBLeak(const ISBLeak&);
		ISBLeak();
		ISBLeak& operator=(const ISBLeak&);

		virtual void T1() = 0;
		virtual void T2() = 0;
		virtual void T3() = 0;
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
	};

	struct UILIB_API IDataEngine
	{
	public:
		IDataEngine(const IDataEngine&);
		IDataEngine();
		IDataEngine& operator=(const IDataEngine&);

		virtual ~IDataEngine();

		virtual UINT GetSize() = 0;
		virtual IDataEntry* GetEntry(UINT) = 0;
	};

	class UILIB_API StyleSheet
	{
	public:
		StyleSheet(const StyleSheet&);
		StyleSheet();
		StyleSheet& operator=(const StyleSheet&);

		static long __stdcall Create(StyleSheet**);

		virtual void T1() = 0;
		virtual void T2() = 0;
		virtual void T3() = 0;
		virtual void T4() = 0;
		virtual void T5() = 0;
		virtual void T6() = 0;
		virtual void T7() = 0;
		virtual void T8() = 0;
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
	struct NavReference;
}

MIDL_INTERFACE("70650a6d-8987-4d93-9b1d-aceb9d92f485")
IDuiBehavior : IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE Init(DirectUI::Value*) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCallbackFilters(DuiBehaviorFilters::Flags*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnAttach(DirectUI::Element*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnDetach(DirectUI::Element*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnHosted(DirectUI::Element*, DirectUI::Element*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnUnHosted(DirectUI::Element*, DirectUI::Element*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnPropertyChanging(DirectUI::Element*, const DirectUI::PropertyInfo*, int, DirectUI::Value*, DirectUI::Value*, int*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnPropertyChanged(DirectUI::Element*, const DirectUI::PropertyInfo*, int, DirectUI::Value*, DirectUI::Value*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnInput(DirectUI::Element*, DirectUI::InputEvent*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnKeyFocusMoved(DirectUI::Element*, DirectUI::Element*, DirectUI::Element*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnEvent(DirectUI::Element*, DirectUI::Event*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnDoLayout(DirectUI::Element*, int, int) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnUpdateDesiredSize(DirectUI::Element*, int, int, DirectUI::Surface*, tagSIZE*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnPaint(DirectUI::Element*, HDC, const RECT*, const RECT*) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnGetAdjacent(DirectUI::Element*, int, const DirectUI::NavReference*, DWORD, DirectUI::Element**) = 0;
	virtual HRESULT STDMETHODCALLTYPE OnDisplayNodeCallback(DirectUI::Element*, EventMsg*) = 0;
};
