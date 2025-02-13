#pragma once

namespace DirectUI
{
	MIDL_INTERFACE("1E3D87CB-F434-4838-A004-F14E385E736F")
	IXProvider : IUnknown
	{
		virtual HRESULT STDMETHODCALLTYPE CreateDUI(IXElementCP* pcp, HWND* phwnd) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetParameter(const GUID&, void*) = 0; // @TODO: This might be REFIID or REFGUID
		virtual HRESULT STDMETHODCALLTYPE GetDesiredSize(int cxConstraint, int cyConstraint, SIZE* ps) = 0;
		virtual HRESULT STDMETHODCALLTYPE IsDescendent(Element* pe, bool* pbIsDescendent) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetFocus(Element* pe) = 0;
		virtual HRESULT STDMETHODCALLTYPE Navigate(int iNavDir, bool* pbHandled) = 0;
		virtual HRESULT STDMETHODCALLTYPE CanSetFocus(bool* pfCanSetFocus) = 0;
		virtual int STDMETHODCALLTYPE FindElementWithShortcutAndDoDefaultAction(WCHAR ch, int fSysKey) = 0;
		virtual HRESULT STDMETHODCALLTYPE GetHostedElementID(ATOM* patomID) = 0;
		virtual HRESULT STDMETHODCALLTYPE ForceThemeChange(WPARAM wParam, LPARAM lParam) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetDefaultButtonTracking(bool fEnabled) = 0;
		virtual int STDMETHODCALLTYPE ClickDefaultButton() = 0;
		virtual HRESULT STDMETHODCALLTYPE SetRegisteredDefaultButton(Element* peDefaultButton) = 0;
		virtual HRESULT STDMETHODCALLTYPE SetButtonClassAcceptsEnterKey(bool fEnabled) = 0;
	};

	interface IXBaby;

	// @NOTE: Missing one export which i cant figure out, IDA lists the DirectUI::XProvider::`vftable` as an export for some reason
	class XProvider : public IXProvider
	{
	public:
		//~ Begin IUnknown Interface
		UILIB_API STDMETHODIMP QueryInterface(REFIID iid, void** ppv) override;
		UILIB_API STDMETHODIMP_(ULONG) AddRef() override;
		UILIB_API STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknown Interface

		//~ Begin IXProvider Interface
		UILIB_API STDMETHODIMP CreateDUI(IXElementCP* pcp, HWND* phwnd) override;
		UILIB_API STDMETHODIMP SetParameter(const GUID& , void*) override;
		UILIB_API STDMETHODIMP GetDesiredSize(int cxConstraint, int cyConstraint, SIZE* ps) override;
		UILIB_API STDMETHODIMP IsDescendent(Element* pe, bool* pbHandled) override;
		UILIB_API STDMETHODIMP SetFocus(Element* pe) override;
		UILIB_API STDMETHODIMP Navigate(int iNavDir, bool* pbHandled) override;
		UILIB_API STDMETHODIMP CanSetFocus(bool* pfCanSetFocus) override;
		UILIB_API STDMETHODIMP_(int) FindElementWithShortcutAndDoDefaultAction(WCHAR ch, int fSysKey) override;
		UILIB_API STDMETHODIMP GetHostedElementID(ATOM* patomID) override;
		UILIB_API STDMETHODIMP ForceThemeChange(WPARAM wParam, LPARAM lParam) override;
		UILIB_API STDMETHODIMP SetDefaultButtonTracking(bool fEnabled) override;
		UILIB_API STDMETHODIMP_(int) ClickDefaultButton() override;
		UILIB_API STDMETHODIMP SetRegisteredDefaultButton(Element* peDefaultButton) override;
		UILIB_API STDMETHODIMP SetButtonClassAcceptsEnterKey(bool fEnabled) override;
		//~ End IXProvider Interface
		
		UILIB_API static HRESULT WINAPI Create(Element* pe, IXProviderCP* pprovCP, XProvider** ppxp);
		UILIB_API HRESULT Initialize(Element*, IXProviderCP*);
		
		UILIB_API virtual HRESULT CreateXBaby(IXElementCP* pcp, HWND hwndParent, Element* pParent, DWORD* pdwDeferCookie, IXBaby** ppIXBaby);
		UILIB_API HRESULT CreateParser(DUIXmlParser** ppParser);
		UILIB_API XProvider(const XProvider&);
		UILIB_API XProvider();
		
		UILIB_API virtual ~XProvider();

	protected:
		IXBaby* _peRoot;
		UILIB_API Element* GetRoot();
		UILIB_API void SetHandleEnterKey(bool);
		int _cRef;
		Element* _pe;
		IXProviderCP* _pprovCP;

	public:
		UILIB_API XProvider& operator=(XProvider const&);
	};
}
