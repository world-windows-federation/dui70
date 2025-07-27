#pragma once

namespace DirectUI
{
	class UILIB_API ExpandCollapseProvider
		: public PatternProvider<ExpandCollapseProvider
			, IExpandCollapseProvider
			, Schema::ExpandCollapse
		>
		, public IExpandCollapseProvider
	{
	public:
		ExpandCollapseProvider();

		PfnCreateProxy GetProxyCreator() override;

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID iid, void** ppvObject) override;
		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknown Interface

		//~ Begin IExpandCollapseProvider Interface
		STDMETHODIMP Expand() override;
		STDMETHODIMP Collapse() override;
		STDMETHODIMP get_ExpandCollapseState(ExpandCollapseState* pRetVal) override;
		//~ End IExpandCollapseProvider Interface
	};

	class UILIB_API ExpandCollapseProxy : public ProviderProxy
	{
	public:
		static ExpandCollapseProxy* Create(Element* pe);
		static bool IsPatternSupported(Element* pe);

		ExpandCollapseProxy();
		ExpandCollapseProxy(const ExpandCollapseProxy& other) = default;
		ExpandCollapseProxy(ExpandCollapseProxy&& other) noexcept = default;

		HRESULT DoMethod(MethodId methodId, va_list args) override;

	protected:
		void Init(Element* pe) override;
	};
}
