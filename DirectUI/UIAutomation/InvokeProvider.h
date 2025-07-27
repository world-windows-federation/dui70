#pragma once

namespace DirectUI
{
	class UILIB_API InvokeProvider
		: public PatternProvider<InvokeProvider, IInvokeProvider, Schema::Invoke>
		, public IInvokeProvider
	{
	public:
		InvokeProvider();

		PfnCreateProxy GetProxyCreator() override;

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID iid, void** ppvObject) override;
		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknown Interface

		//~ Begin IInvokeProvider Interface
		STDMETHODIMP Invoke() override;
		//~ End IInvokeProvider Interface
	};

	class UILIB_API InvokeProxy : public ProviderProxy
	{
	public:
		static InvokeProxy* WINAPI Create(Element* pe);

		InvokeProxy();
		InvokeProxy(const InvokeProxy& other) = default;
		InvokeProxy(InvokeProxy&& other) noexcept = default;

		HRESULT DoMethod(MethodId methodId, va_list args) override;

		static bool WINAPI IsPatternSupported(Element* pe);

	protected:
		void Init(Element* pe) override;
	};
}
