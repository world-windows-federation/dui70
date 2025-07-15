#pragma once

#include "UIAutomation\SelectionItemProvider.h"

namespace DirectUI
{
	class UILIB_API Navigator : public PushButton
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		
		HRESULT Initialize(Element* pParent, DWORD* pdwDeferCookie);

		Browser* GetBrowser();
		static UID WINAPI ActionInitiated();
		static const PropertyInfo* WINAPI TargetPageProp();
		const WCHAR* GetTargetPage(Value** ppv);
		HRESULT SetTargetPage(const WCHAR* v);
		
		void OnEvent(Event* pev) override;
		
		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

	private:
		void FireNavigationEvent();
	};

	class UILIB_API NavigatorSelectionItemProxy : public SelectionItemProxy
	{
	public:
		NavigatorSelectionItemProxy(NavigatorSelectionItemProxy const &);
		NavigatorSelectionItemProxy(void);
		NavigatorSelectionItemProxy & operator=(NavigatorSelectionItemProxy const &);
		//1
		virtual long DoMethod(int, char *);
	protected:
		//2
		virtual void Init(Element *);

	private:
		long AddToSelection(Browser *);
		long GetIsSelected(Browser *, int *);

	};
}
