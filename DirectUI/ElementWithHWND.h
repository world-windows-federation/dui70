#pragma once

namespace DirectUI
{
	class UILIB_API ElementWithHWND : public Element
	{
	public:
		ElementWithHWND(const ElementWithHWND &);
		ElementWithHWND();
		ElementWithHWND& operator=(const ElementWithHWND &);

		virtual ~ElementWithHWND();

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static IClassInfo* WINAPI GetClassInfoPtr();
		static HRESULT WINAPI Register();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

		virtual IClassInfo* GetClassInfoW() override;

		virtual HWND GetHWND() = 0;

	private:
		static IClassInfo* s_pClassInfo;
	};
}