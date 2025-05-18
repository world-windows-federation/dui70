#pragma once

typedef HRESULT (CALLBACK *PFNCREATEDUIPROPERTYSHEETPAGE)(const PROPSHEETPAGE*, HPROPSHEETPAGE*);

namespace DirectUI
{
	class UILIB_API TaskPage
		: public IElementListener
		, IXProviderCP
	{
	public:
		TaskPage();
		TaskPage(const TaskPage& other) = default;

		virtual ~TaskPage();

		HRESULT DUICreatePropertySheetPage(HINSTANCE hInstance);
		operator HPROPSHEETPAGE();
		HWND GetParentHWND();

	protected:
		LRESULT PropSheet_SendMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
		Element* GetElement();
		virtual HRESULT LoadParser(DUIXmlParser** ppParser);

	private:
		HRESULT LoadPage(Element** ppe, Element* pParent, DUIXmlParser** ppParser);

	protected:
		HRESULT LoadPage(HWNDElement* peRoot, HINSTANCE hInstance, Element** ppe, DUIXmlParser** ppParser);
		virtual UINT GetPageRCID();
		virtual const WCHAR* GetPageResID();
		virtual void InitPropSheetPage(PROPSHEETPAGE*);

		// @NOTE: Not sure if these are HRESULT or LRESULT
		virtual LRESULT OnKillActive();
		virtual LRESULT OnQueryCancel();
		virtual LRESULT OnReset();
		virtual LRESULT OnSetActive();
		virtual LRESULT OnWizBack();
		virtual LRESULT OnWizFinish();
		virtual LRESULT OnWizNext();
		virtual Element* OnQueryInitialFocus();
		virtual bool OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet);

		//~ Begin DirectUI::IElementListener Interface
		void OnListenerAttach(Element* peFrom) override;
		void OnListenerDetach(Element* peFrom) override;
		bool OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnListenedInput(Element* peFrom, InputEvent* pInput) override;
		void OnListenedEvent(Element* peFrom, Event* pEvent) override;
		//~ End DirectUI::IElementListener Interface

	private:
		HRESULT CreateDUICP(HWNDElement* peRoot, HWND hwndParent, HWND hwndHost, Element** ppe, DUIXmlParser** ppParser) override;
		HRESULT CreateParserCP(DUIXmlParser** ppParser) override;
		void DestroyCP() override;

		int OnWndMsg(UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet);
		HRESULT LoadComCtl32();
		void FreeComCtl32();

		static void CALLBACK StaticXmlParserError(const WCHAR* pszError, const WCHAR* pszToken, int dLine, void* pContext);
		static LRESULT CALLBACK StaticXHostSubclassProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		HMODULE _hmodComCtl32;
		PFNCREATEDUIPROPERTYSHEETPAGE _pfnCreateDUIPropertySheetPage;
		HPROPSHEETPAGE _hpsp;
		HINSTANCE _hInstance;
		HWND _hwndXElement;
		HWND _hwndXHost;
		Element* _peMarkup;
		IUnknown* _punkPage;
	};
}
