#pragma once

namespace DirectUI
{
	class UILIB_API HWNDElementProvider
		: public ElementProvider
		, public IRawElementProviderFragmentRoot
	{
	public:
		PfnCreateProxy GetProxyCreator() override;

		static HRESULT WINAPI Create(HWNDElement* pe, InvokeHelper* pih, HWNDElementProvider** ppprv);

		HWNDElementProvider();

		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		STDMETHODIMP QueryInterface(REFIID riid, void** ppvObject) override;

		//~ Begin IRawElementProviderFragmentRoot Interface
		STDMETHODIMP ElementProviderFromPoint(double x, double y, IRawElementProviderFragment** ppprv) override;
		STDMETHODIMP GetFocus(IRawElementProviderFragment** ppprv) override;
		//~ End IRawElementProviderFragmentRoot Interface

	protected:
		virtual HRESULT Init(HWNDElement* pe, InvokeHelper* pih);
	};

	class UILIB_API DECLSPEC_NOVTABLE HWNDElementProxy : public ElementProxy
	{
	public:
		static HWNDElementProxy* WINAPI Create(HWNDElement* pe);

		virtual void Init(HWNDElement* pe);

		//~ Begin DirectUI::ElementProxy Interface
		HRESULT DoMethod(MethodId methodId, va_list args) override;
		//~ End DirectUI::ElementProxy Interface

		HWNDElementProxy(const HWNDElementProxy&) = default;

	protected:
		HWNDElementProxy();

		HRESULT ElementFromPoint(double x, double y, IRawElementProviderFragment** ppprv);
		HRESULT GetFocus(IRawElementProviderFragment** ppprv);
	};
}
