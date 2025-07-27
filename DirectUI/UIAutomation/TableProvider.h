#pragma once

namespace DirectUI
{
	class UILIB_API TableProvider
		: public PatternProvider<TableProvider
			, ITableProvider
			, Schema::Table
		>
		, public ITableProvider
	{
	public:
		TableProvider();

		PfnCreateProxy GetProxyCreator() override;

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID iid, void** ppvObject) override;
		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknown Interface

		//~ Begin ITableProvider Interface
		STDMETHODIMP GetRowHeaders(SAFEARRAY** pRetVal) override;
		STDMETHODIMP GetColumnHeaders(SAFEARRAY** pRetVal) override;
		STDMETHODIMP get_RowOrColumnMajor(RowOrColumnMajor* pRetVal) override;
		//~ End ITableProvider Interface
	};

	class UILIB_API TableProxy : public ProviderProxy
	{
	public:
		static TableProxy* WINAPI Create(Element* pe);
		static bool WINAPI IsPatternSupported(Element* pe);

		TableProxy();
		TableProxy(const TableProxy& other) = default;
		TableProxy(TableProxy&& other) noexcept = default;

		HRESULT DoMethod(MethodId methodId, va_list args) override;

	protected:
		void Init(Element* pe) override;
	};
}