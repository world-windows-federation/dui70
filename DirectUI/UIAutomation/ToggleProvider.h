#pragma once

namespace DirectUI
{
	class UILIB_API ToggleProvider
		: public PatternProvider<ToggleProvider
			, IToggleProvider
			, Schema::Toggle
		>
		, public IToggleProvider
	{
	public:
		ToggleProvider();

		PfnCreateProxy GetProxyCreator() override;

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID iid, void** ppvObject) override;
		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknown Interface

		//~ Begin IToggleProvider Interface
		STDMETHODIMP Toggle() override;
		STDMETHODIMP get_ToggleState(ToggleState* pRetVal) override;
		//~ End IToggleProvider Interface
	};

	class UILIB_API ToggleProxy : public ProviderProxy
	{
	public:
		static ToggleProxy* WINAPI Create(Element* pe);
		static bool WINAPI IsPatternSupported(Element* pe);
		
		HRESULT DoMethod(MethodId methodId, va_list args) override;

		ToggleProxy();
		ToggleProxy(const ToggleProxy& other) = default;
		ToggleProxy(ToggleProxy&& other) noexcept = default;

	protected:
		void Init(Element* pe) override;

	private:
		HRESULT GetToggleState(ToggleState* pToggleState);
	};
}