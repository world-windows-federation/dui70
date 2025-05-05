#pragma once

namespace DirectUI
{
	class InvokeProvider
		: public PatternProvider<InvokeProvider, IInvokeProvider, Schema::Pattern::Invoke>
		  , public IInvokeProvider
	{
	public:
		InvokeProvider();

		PfnCreateProxy GetProxyCreator() override;

		HRESULT QueryInterface(REFIID riid, void** ppvObj) override;
		ULONG AddRef();
		ULONG Release();

		HRESULT Invoke() override;
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
