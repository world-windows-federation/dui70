#pragma once

namespace DirectUI
{
	class UILIB_API GridItemProvider
		: public PatternProvider<GridItemProvider, IGridItemProvider, Schema::GridItem>
		, public IGridItemProvider
	{
	public:
		GridItemProvider();

		PfnCreateProxy GetProxyCreator() override;

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID iid, void** ppvObject) override;
		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknown Interface

		//~ Begin IGridItemProvider Interface
		STDMETHODIMP get_Row(int* pRetVal) override;
		STDMETHODIMP get_Column(int* pRetVal) override;
		STDMETHODIMP get_RowSpan(int* pRetVal) override;
		STDMETHODIMP get_ColumnSpan(int* pRetVal) override;
		STDMETHODIMP get_ContainingGrid(IRawElementProviderSimple** pRetVal) override;
		//~ End IGridItemProvider Interface
	};

	class UILIB_API GridItemProxy : public ProviderProxy
	{
	public:
		static GridItemProxy* WINAPI Create(Element* pe);

		GridItemProxy();
		GridItemProxy(const GridItemProxy& other) = default;
		GridItemProxy(GridItemProxy&& other) noexcept = default;

		HRESULT DoMethod(MethodId methodId, va_list args) override;
		static bool WINAPI IsPatternSupported(Element* pe);

	protected:
		void Init(Element* pe) override;

	private:
		HRESULT GetContainingGrid(IRawElementProviderSimple** ppprv);
		HRESULT GetColumn(int* piColumn);
		HRESULT GetRow(int* piRow);
	};
}
