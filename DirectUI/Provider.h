#pragma once

namespace DirectUI
{
	class UILIB_API XResourceProvider : public IXProviderCP
	{
	public:
		//~ Begin DirectUI::IXProviderCP Interface
		HRESULT CreateDUICP(HWNDElement* peHWNDElement, HWND hwndParent, HWND hwndHost, Element** ppe, DUIXmlParser** ppParser) override;
		HRESULT CreateParserCP(DUIXmlParser** ppParser) override;
		void DestroyCP() override;
		//~ End DirectUI::IXProviderCP Interface

		static HRESULT WINAPI Create(XResourceProvider** pprprov);
		static HRESULT WINAPI Create(HINSTANCE hRes, const WCHAR* pszResource, const WCHAR* pszResID, const WCHAR* pszFile, XResourceProvider** pprprov);

		HRESULT Initialize(HINSTANCE hRes, const WCHAR* pszResource, const WCHAR* pszResid, const WCHAR* pszFile);

	private:
		HINSTANCE _hInstance;
		WCHAR* _pszResource;
		WCHAR _szResource[MAX_PATH];
		WCHAR _szResid[MAX_PATH];
		WCHAR _szFile[MAX_PATH];
	};
}
