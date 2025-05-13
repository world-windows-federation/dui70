#pragma once

namespace DirectUI
{
	class UILIB_API DuiAccessible
		: public IAccessible
		, public IEnumVARIANT
		, public IOleWindow
		, public IAccIdentity
		, public IServiceProvider
	{
	public:
		static HRESULT WINAPI Create(Element* pe, DuiAccessible** ppDA);

		DuiAccessible();

	private:
		DuiAccessible(const DuiAccessible& other) = delete;
		DuiAccessible& operator=(const DuiAccessible& other) = delete;

	public:
		virtual HRESULT Disconnect();

		void Initialize(Element* pe);

		virtual ~DuiAccessible();

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID riid, void** ppvObj) override;
		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknown Interface

		//~ Begin IDispatch Interface
		STDMETHODIMP GetTypeInfoCount(UINT* pctinfo) override;
		STDMETHODIMP GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo) override;
		STDMETHODIMP GetIDsOfNames(REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId) override;
		STDMETHODIMP Invoke(DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr) override;
		//~ End IDispatch Interface

		//~ Begin IAccessible Interface
		STDMETHODIMP get_accParent(IDispatch** ppdispParent) override;
		STDMETHODIMP get_accChildCount(long* pcountChildren) override;
		STDMETHODIMP get_accChild(VARIANT varChild, IDispatch** ppdispChild) override;
		STDMETHODIMP get_accName(VARIANT varChild, BSTR* pszName) override;
		STDMETHODIMP get_accValue(VARIANT varChild, BSTR* pszValue) override;
		STDMETHODIMP get_accDescription(VARIANT varChild, BSTR* pszDescription) override;
		STDMETHODIMP get_accRole(VARIANT varChild, VARIANT* pvarRole) override;
		STDMETHODIMP get_accState(VARIANT varChild, VARIANT* pvarState) override;
		STDMETHODIMP get_accHelp(VARIANT varChild, BSTR* pszHelp) override;
		STDMETHODIMP get_accHelpTopic(BSTR* pszHelpFile, VARIANT varChild, long* pidTopic) override;
		STDMETHODIMP get_accKeyboardShortcut(VARIANT varChild, BSTR* pszKeyboardShortcut) override;
		STDMETHODIMP get_accFocus(VARIANT* pvarChild) override;
		STDMETHODIMP get_accSelection(VARIANT* pvarChildren) override;
		STDMETHODIMP get_accDefaultAction(VARIANT varChild, BSTR* pszDefaultAction) override;
		STDMETHODIMP accSelect(long flagsSelect, VARIANT varChild) override;
		STDMETHODIMP accLocation(long* pxLeft, long* pyTop, long* pcxWidth, long* pcyHeight, VARIANT varChild) override;
		STDMETHODIMP accNavigate(long navDir, VARIANT varStart, VARIANT* pvarEndUpAt) override;
		STDMETHODIMP accHitTest(long xLeft, long yTop, VARIANT* pvarChild) override;
		STDMETHODIMP accDoDefaultAction(VARIANT varChild) override;
		STDMETHODIMP put_accName(VARIANT varChild, BSTR szName) override;
		STDMETHODIMP put_accValue(VARIANT varChild, BSTR szValue) override;
		//~ End IAccessible Interface

		//~ Begin IEnumVARIANT Interface
		STDMETHODIMP Next(ULONG celt, VARIANT* rgVar, ULONG* pCeltFetched) override;
		STDMETHODIMP Skip(ULONG celt) override;
		STDMETHODIMP Reset() override;
		STDMETHODIMP Clone(IEnumVARIANT** ppEnum) override;
		//~ End IEnumVARIANT Interface

		//~ Begin IOleWindow Interface
		STDMETHODIMP GetWindow(HWND* phwnd) override;
		STDMETHODIMP ContextSensitiveHelp(BOOL fEnterMode) override;
		//~ End IOleWindow Interface

		//~ Begin IAccIdentity Interface
		STDMETHODIMP GetIdentityString(DWORD dwIDChild, BYTE** ppIDString, DWORD* pdwIDStringLen) override;
		//~ End IAccIdentity Interface

		//~ Begin IServiceProvider Interface
		STDMETHODIMP QueryService(REFGUID guidService, REFIID riid, void** ppvObject) override;
		//~ End IServiceProvider Interface

		static HRESULT WINAPI AccNavigate(Element* pe, long navDir, Element** ppe);

		static Element* WINAPI GetAccessibleParent(Element* pe);

	protected:
		HRESULT GetDispatchFromElement(Element* pe, IDispatch** ppDispatch);
		HRESULT GetAccName(VARIANT varChild, BOOL fAllowSubstitution, BSTR* pbstrName);
		HRESULT GetAccNameFromContent(BSTR* pbstrName);

		Element* _pe;

	private:
		long _cRefs;
	};

	class UILIB_API HWNDHostAccessible : public DuiAccessible
	{
	public:
		static HRESULT WINAPI Create(Element* pe, IAccessible* pCtrl, DuiAccessible** ppDA);

		HWNDHostAccessible();

	private:
		HWNDHostAccessible(const HWNDHostAccessible& other) = delete;
		HWNDHostAccessible& operator=(const HWNDHostAccessible& other) = delete;

	public:
		HRESULT Disconnect() override;

		HRESULT Initialize(Element* pe, IAccessible* pCtrl);

		~HWNDHostAccessible() override;

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID riid, void** ppvObj) override;
		//~ End IUnknown Interface

		//~ Begin IAccessible Interface
		STDMETHODIMP get_accParent(IDispatch** ppdispParent) override;
		STDMETHODIMP get_accChildCount(long* pcountChildren) override;
		STDMETHODIMP get_accChild(VARIANT varChild, IDispatch** ppdispChild) override;
		STDMETHODIMP get_accName(VARIANT varChild, BSTR* pszName) override;
		STDMETHODIMP get_accValue(VARIANT varChild, BSTR* pszValue) override;
		STDMETHODIMP get_accDescription(VARIANT varChild, BSTR* pszDescription) override;
		STDMETHODIMP get_accRole(VARIANT varChild, VARIANT* pvarRole) override;
		STDMETHODIMP get_accState(VARIANT varChild, VARIANT* pvarState) override;
		STDMETHODIMP get_accHelp(VARIANT varChild, BSTR* pszHelp) override;
		STDMETHODIMP get_accHelpTopic(BSTR* pszHelpFile, VARIANT varChild, long* pidTopic) override;
		STDMETHODIMP get_accKeyboardShortcut(VARIANT varChild, BSTR* pszKeyboardShortcut) override;
		STDMETHODIMP get_accFocus(VARIANT* pvarChild) override;
		STDMETHODIMP get_accSelection(VARIANT* pvarChildren) override;
		STDMETHODIMP get_accDefaultAction(VARIANT varChild, BSTR* pszDefaultAction) override;
		STDMETHODIMP accSelect(long flagsSelect, VARIANT varChild) override;
		STDMETHODIMP accLocation(long* pxLeft, long* pyTop, long* pcxWidth, long* pcyHeight, VARIANT varChild) override;
		STDMETHODIMP accNavigate(long navDir, VARIANT varStart, VARIANT* pvarEndUpAt) override;
		STDMETHODIMP accHitTest(long xLeft, long yTop, VARIANT* pvarChild) override;
		STDMETHODIMP accDoDefaultAction(VARIANT varChild) override;
		STDMETHODIMP put_accName(VARIANT varChild, BSTR szName) override;
		STDMETHODIMP put_accValue(VARIANT varChild, BSTR szValue) override;
		//~ End IAccessible Interface

		//~ Begin IEnumVARIANT Interface
		STDMETHODIMP Next(ULONG celt, VARIANT* rgVar, ULONG* pCeltFetched) override;
		STDMETHODIMP Skip(ULONG celt) override;
		STDMETHODIMP Reset() override;
		STDMETHODIMP Clone(IEnumVARIANT** ppEnum) override;
		//~ End IEnumVARIANT Interface

		//~ Begin IOleWindow Interface
		STDMETHODIMP GetWindow(HWND* phwnd) override;
		STDMETHODIMP ContextSensitiveHelp(BOOL fEnterMode) override;
		//~ End IOleWindow Interface

		//~ Begin IAccIdentity Interface
		STDMETHODIMP GetIdentityString(DWORD dwIDChild, BYTE** ppIDString, DWORD* pdwIDStringLen) override;
		//~ End IAccIdentity Interface

		//~ Begin IServiceProvider Interface
		STDMETHODIMP QueryService(REFGUID guidService, REFIID riid, void** ppvObject) override;
		//~ End IServiceProvider Interface

	protected:
		IAccessible* _pCtrl;

	private:
		IEnumVARIANT* _pEnum;
		IOleWindow* _pOleWindow;
	};

	class UILIB_API HWNDHostClientAccessible : public HWNDHostAccessible
	{
	public:
		static HRESULT WINAPI Create(Element* pe, IAccessible* pCtrl, DuiAccessible** ppDA);

		STDMETHODIMP get_accParent(IDispatch** ppdispParent) override;
		STDMETHODIMP get_accRole(VARIANT varChild, VARIANT* pvarRole) override;
		STDMETHODIMP accNavigate(long navDir, VARIANT varStart, VARIANT* pvarEndUpAt) override;
	};

	class UILIB_API HWNDElementAccessible : public DuiAccessible
	{
	public:
		static HRESULT WINAPI Create(HWNDElement* pe, DuiAccessible** ppDA);
		HWNDElementAccessible();

	private:
		HWNDElementAccessible(const HWNDElementAccessible& other) = delete;
		HWNDElementAccessible& operator=(const HWNDElementAccessible& other) = delete;

	public:
		HRESULT Disconnect() override;
		HRESULT Initialize(HWNDElement* pe);
		
		~HWNDElementAccessible() override;

		STDMETHODIMP get_accParent(IDispatch** ppdispParent) override;

	private:
		IAccessible* _pParent;
	};
}
