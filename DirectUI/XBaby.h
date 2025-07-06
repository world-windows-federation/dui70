#pragma once

namespace DirectUI
{
	class XProvider;

	interface IXBaby
	{
		virtual HWNDElement* GetXBabyElement() = 0;
		virtual void CacheParser(DUIXmlParser* pParserNew) = 0;
		virtual HRESULT SetToHost(Element* peToHost) = 0;
		virtual SIZE GetContentDesiredSize(int cxConstraint, int cyConstraint) = 0;
		virtual bool CanSetFocus() = 0;
		virtual HRESULT GetHostedElementID(ATOM* patomID) = 0;
		virtual void ForceThemeChange(WPARAM wParam, LPARAM lParam) = 0;
		virtual bool GetDefaultButtonTracking() = 0;
		virtual HRESULT SetDefaultButtonTracking(bool v) = 0;
		virtual HRESULT SetButtonClassAcceptsEnterKey(bool v) = 0;
		virtual bool ClickDefaultButton() = 0;
		virtual HRESULT SetRegisteredDefaultButton(Element* v) = 0;
		virtual HRESULT SetHandleEnterKey(bool v) = 0;
	};

	class UILIB_API XBaby
		: public DialogElement
		, public IXBaby
	{
	public:
		~XBaby() override;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppe);
		static HRESULT WINAPI Create(IXElementCP* pcp, XProvider* pprov, HWND hwndParent, Element* pParent, DWORD* pdwDeferCookie, Element** ppe);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		Element* GetAdjacent(Element* peFrom, int iNavDir, const NavReference* pnr, DWORD dwFlags) override;
		void OnEvent(Event* pEvent) override;
		void OnThemeChanged(ThemeChangedEvent* pev) override;
		void OnNoChildWithShortcutFound(KeyboardEvent* pke) override;
		bool OnChildLostFocus(Element* peFrom) override;
		bool OnChildReceivedFocus(Element* peTo) override;
		HRESULT CreateStyleParser(DUIXmlParser** ppParser) override;
		void OnWmThemeChanged(WPARAM wParam, LPARAM lParam) override;
		
		virtual Element* GetFocusableElement();
		
		void SetKeyFocus() override;
		HRESULT GetElementProviderImpl(InvokeHelper* pih, ElementProvider** ppprv) override;

		//~ Begin DirectUI::IXBaby Interface
		STDMETHODIMP_(HWNDElement*) GetXBabyElement() override;
		STDMETHODIMP_(void) CacheParser(DUIXmlParser* pParserNew) override;
		STDMETHODIMP SetToHost(Element* peToHost) override;
		STDMETHODIMP_(SIZE) GetContentDesiredSize(int cxConstraint, int cyConstraint) override;
		STDMETHODIMP_(bool) CanSetFocus() override;
		STDMETHODIMP GetHostedElementID(ATOM* patomID) override;
		STDMETHODIMP_(void) ForceThemeChange(WPARAM wParam, LPARAM lParam) override;
		STDMETHODIMP_(bool) GetDefaultButtonTracking() override;
		STDMETHODIMP SetDefaultButtonTracking(bool v) override;
		STDMETHODIMP SetButtonClassAcceptsEnterKey(bool v) override;
		STDMETHODIMP_(bool) ClickDefaultButton();
		STDMETHODIMP SetRegisteredDefaultButton(Element* v) override;
		STDMETHODIMP SetHandleEnterKey(bool v) override;
		//~ End DirectUI::IXBaby Interface

	protected:
		HRESULT Initialize(IXElementCP* pcp, XProvider* pprov, HWND hwndParent, Element* pParent, DWORD* pdwDeferCookie);

		Element* _pe;
		IXElementCP* _pcp;
		XProvider* _pprov;
		DUIXmlParser* _pParserCached;
	};
}
