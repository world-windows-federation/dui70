#pragma once

namespace DirectUI
{
	class UILIB_API GridProvider
		: public PatternProvider<GridProvider, IGridProvider, Schema::Grid>
		, public IGridProvider
	{
	public:
		GridProvider();

		PfnCreateProxy GetProxyCreator() override;

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID iid, void** ppvObject) override;
		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknown Interface

		//~ Begin IGridProvider Interface
		STDMETHODIMP GetItem(int row, int column, IRawElementProviderSimple** pRetVal) override;
		STDMETHODIMP get_RowCount(int* pRetVal) override;
		STDMETHODIMP get_ColumnCount(int* pRetVal) override;
		//~ End IGridProvider Interface
	};

	class UILIB_API GridProxy : public ProviderProxy
	{
	public:
		static GridProxy* WINAPI Create(Element* pe);

		GridProxy();
		GridProxy(const GridProxy& other) = default;
		GridProxy(GridProxy&& other) noexcept = default;

		HRESULT DoMethod(MethodId methodId, va_list args) override;
		static bool WINAPI IsPatternSupported(Element* pe);

	protected:
		void Init(Element* pe) override;

	private:
		HRESULT GetItem(UINT row, UINT column, IRawElementProviderSimple** ppprv);
		HRESULT GetRowCount(int* pcRow);
		HRESULT GetColumnCount(int* pcColumn);
	};
}
