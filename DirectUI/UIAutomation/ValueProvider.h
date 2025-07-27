#pragma once

namespace DirectUI
{
	class UILIB_API ValueProvider
		: public PatternProvider<ValueProvider
			, IValueProvider
			, Schema::Pattern::Value
		>
		, public IValueProvider
	{
	public:
		ValueProvider();

		PfnCreateProxy GetProxyCreator() override;

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID iid, void** ppvObject) override;
		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknow Interface

		//~ Begin IValueProvider Interface
		STDMETHODIMP SetValue(LPCWSTR val) override;
		STDMETHODIMP get_Value(BSTR* pRetVal) override;
		STDMETHODIMP get_IsReadOnly(BOOL* pRetVal) override;
		//~ End IValueProvider Interface
	};

	class UILIB_API ValueProxy : public ProviderProxy
	{
	public:
		static ValueProxy* WINAPI Create(Element* pe);

		ValueProxy();
		ValueProxy(const ValueProxy& other) = default;
		ValueProxy(ValueProxy&& other) noexcept = default;

		HRESULT DoMethod(MethodId methodId, va_list args) override;
		static bool WINAPI IsPatternSupported(Element* pe);

	protected:
		void Init(Element* pe) override;

	private:
		HRESULT SetValue(const WCHAR* val);
		HRESULT GetValue(BSTR* pRetVal);
		HRESULT GetIsReadOnly(BOOL* pRetVal);
	};
}
