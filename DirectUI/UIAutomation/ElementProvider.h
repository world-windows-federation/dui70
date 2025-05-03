#pragma once

namespace DirectUI
{
	class UILIB_API ElementProvider
		: public RefcountBase
		, public IRawElementProviderSimple2
		, public IRawElementProviderFragment
		, public IRawElementProviderAdviseEvents
	{
	public:
		ElementProvider();
		ElementProvider(const ElementProvider&) = delete;

		~ElementProvider() override;

		virtual PfnCreateProxy GetProxyCreator();
		const Element* GetElementKey();
		virtual const volatile Element* GetElement();
		void TossPatternProvider(Schema::Pattern pattern);
		virtual void TossElement();

		static HRESULT WINAPI Create(Element* pe, InvokeHelper* pih, ElementProvider** ppprv);

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID riid, void** ppvObject) override;
		// ReSharper disable once CppHidingFunction
		STDMETHODIMP_(ULONG) AddRef() override;
		// ReSharper disable once CppHidingFunction
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknown Interface

		//~ Begin IRawElementProviderSimple Interface
		STDMETHODIMP get_ProviderOptions(ProviderOptions* pRetVal) override;
		STDMETHODIMP GetPatternProvider(PATTERNID id, IUnknown** ppunk) override;
		STDMETHODIMP GetPropertyValue(PROPERTYID propertyID, VARIANT* pvar) override;
		STDMETHODIMP get_HostRawElementProvider(IRawElementProviderSimple** ppprv) override;
		//~ End IRawElementProviderSimple Interface

		//~ Begin IRawElementProviderSimple2 Interface
		STDMETHODIMP ShowContextMenu() override;
		//~ End IRawElementProviderSimple2 Interface

		//~ Begin IRawElementProviderFragment Interface
		STDMETHODIMP Navigate(NavigateDirection direction, IRawElementProviderFragment** ppprv) override;
		STDMETHODIMP GetRuntimeId(SAFEARRAY** pparray) override;
		STDMETHODIMP get_BoundingRectangle(UiaRect* prect) override;
		STDMETHODIMP GetEmbeddedFragmentRoots(SAFEARRAY** pRetVal) override;
		STDMETHODIMP SetFocus() override;
		STDMETHODIMP get_FragmentRoot(IRawElementProviderFragmentRoot** ppprv) override;
		//~ End IRawElementProviderFragment Interface

		//~ Begin IRawElementProviderAdviseEvents Interface
		STDMETHODIMP AdviseEventAdded(EVENTID id, SAFEARRAY* propertyIds) override;
		STDMETHODIMP AdviseEventRemoved(EVENTID id, SAFEARRAY* propertyIds) override;
		//~ End IRawElementProviderAdviseEvents Interface

		HRESULT DoInvokeArgs(MethodId methodId, PfnCreateProxy pfnCreate, va_list args);

	protected:
		virtual HRESULT Init(Element* pe, InvokeHelper* pih);
		HRESULT DoInvoke(MethodId methodId, ...);

		Element* _pe;
		InvokeHelper* _pih;
		IUnknown* _patternProviders[Schema::PatternCount];
		CRITICAL_SECTION _cs;
		bool _fDeleteCS;

	private:
		Element* _peKey;
	};
}