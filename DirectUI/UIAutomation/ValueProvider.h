#pragma once

namespace DirectUI
{
	class UILIB_API ValueProvider
		: public PatternProvider<ValueProvider, IValueProvider, Schema::Pattern::Value>
		  , public IValueProvider
	{
	public:
		ValueProvider();

		PfnCreateProxy GetProxyCreator() override;

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID riid, void** ppvObject) override;
		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknow Interface

		//~ Begin IValueProvider Interface
		STDMETHODIMP SetValue(LPCWSTR val) override;
		STDMETHODIMP get_Value(BSTR* pRetVal) override;
		STDMETHODIMP get_IsReadOnly(BOOL* pRetVal) override;
		//~ End IValueProvider Interface
	};

	class UILIB_API ValueProxy : ProviderProxy
	{
	public:
		ValueProxy(ValueProxy const&);
		ValueProxy();
		ValueProxy& operator=(ValueProxy const&);
		static ValueProxy* WINAPI Create(Element* pe);
		static bool WINAPI IsPatternSupported(Element* pe);

		HRESULT DoMethod(int, char*) override = 0;

	protected:
		void Init(Element* pe) override = 0;

	private:
		HRESULT GetIsReadOnly(int*);
		HRESULT GetValue(WCHAR* pRetVal);
		HRESULT SetValue(unsigned short const*);
	};
}
