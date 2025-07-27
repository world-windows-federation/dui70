#pragma once

namespace DirectUI
{
	class UILIB_API RangeValueProvider
		: public PatternProvider<RangeValueProvider, IRangeValueProvider, Schema::RangeValue>
		, public IRangeValueProvider
	{
	public:
		RangeValueProvider();

		PfnCreateProxy GetProxyCreator() override;

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID iid, void** ppvObject) override;
		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknown Interface

		//~ Begin IRangeValueProvider Interface
		STDMETHODIMP SetValue(double val) override;
		STDMETHODIMP get_Value(double* pRetVal) override;
		STDMETHODIMP get_IsReadOnly(BOOL* pRetVal) override;
		STDMETHODIMP get_Maximum(double* pRetVal) override;
		STDMETHODIMP get_Minimum(double* pRetVal) override;
		STDMETHODIMP get_LargeChange(double* pRetVal) override;
		STDMETHODIMP get_SmallChange(double* pRetVal) override;
		//~ End IRangeValueProvider Interface
	};

	class UILIB_API RangeValueProxy : public ProviderProxy
	{
	public:
		static RangeValueProxy* WINAPI Create(Element* pe);
		static bool WINAPI IsPatternSupported(Element* pe);

		HRESULT DoMethod(MethodId methodId, va_list args) override;

	protected:
		RangeValueProxy();

	public:
		RangeValueProxy(const RangeValueProxy& other) = default;
		RangeValueProxy(RangeValueProxy&& other) noexcept = default;

	protected:
		void Init(Element* pe) override;
	};

	class UILIB_API ProgressRangeValueProxy : public RangeValueProxy
	{
	public:
		ProgressRangeValueProxy();
		ProgressRangeValueProxy(const ProgressRangeValueProxy& other) = default;
		ProgressRangeValueProxy(ProgressRangeValueProxy&& other) noexcept = default;

		HRESULT DoMethod(MethodId methodId, va_list args) override;

	protected:
		void Init(Element* pe) override;
	};
}
