#pragma once

namespace DirectUI
{
	class UILIB_API DECLSPEC_NOVTABLE DialogElementCore
	{
	public:
		void Initialize(IDialogElement* pIDialogElement, IElementListener* pIParentListener);
		Element* GetDefaultButton();
		bool ClickDefaultButton();
		void OnRegisteredDefaultButtonChanged(Value* pvOld, Value* pvNew);
		void OnDefaultButtonTrackingChanged(Value* pvNew);
		void OnKeyFocusMoved(Element* peFrom, Element* peTo);
		void UpdateChildFocus(Element* peFrom, Element* peTo);
		bool OnChildLostFocus(Element* peFrom);
		bool OnChildReceivedFocus(Element* peTo);
		void OnGetDlgCode(MSG* pmsg, LRESULT* plResult);
		void OnInput(InputEvent* pie);
		void OnListenerDetach(Element* pe);
		void OnDestroy();

	protected:
		void SetRegisteredDefaultButtonSelectedState(bool fSelected);
		static bool IsButtonEnabledAndVisible(Element* pe);

		IDialogElement* _pIDialogElement;
		IElementListener* _pIParentListener;
		Element* _peFocusedButton;
	};

	class UILIB_API DialogElement
		: public HWNDElement
		, public IElementListener
		, public IDialogElement
	{
	public:
		DialogElement();
		DialogElement(const DialogElement& other) = default;
		DialogElement(DialogElement&& other) noexcept = default;

		static HRESULT WINAPI Create(HWND hwndParent, bool fDblBuffer, UINT nCreate, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		Element* GetDefaultButton() override;
		bool ClickDefaultButton();

		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnKeyFocusMoved(Element* peFrom, Element* peTo) override;
		void OnInput(InputEvent* pie) override;
		void OnGetDlgCode(MSG* pmsg, LRESULT* plResult) override;
		void OnDestroy() override;
		bool OnChildLostFocus(Element* peFrom) override;
		bool OnChildReceivedFocus(Element* peTo) override;

		static const PropertyInfo* WINAPI DefaultButtonTrackingProp();
		static const PropertyInfo* WINAPI RegisteredDefaultButtonProp();
		static const PropertyInfo* WINAPI HandleEnterKeyProp();
		static const PropertyInfo* WINAPI ButtonClassAcceptsEnterKeyProp();

		bool GetDefaultButtonTracking() override;
		Element* GetRegisteredDefaultButton() override;
		bool GetHandleEnterKey() override;
		bool GetButtonClassAcceptsEnterKey() override;
		HRESULT SetDefaultButtonTracking(bool v) override;

		HRESULT SetRegisteredDefaultButton(Element* v);
		HRESULT SetHandleEnterKey(bool v);
		HRESULT SetButtonClassAcceptsEnterKey(bool v);

		Element* GetKeyFocusedElement();

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		//~ Begin DirectUI::IElementListener Interface
		void OnListenerAttach(Element* peFrom) override;
		void OnListenerDetach(Element* peFrom) override;
		bool OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnListenedInput(Element* peFrom, InputEvent* pInput) override;
		void OnListenedEvent(Element* peFrom, Event* pEvent) override;
		//~ End DirectUI::IElementListener Interface

	private:
		DialogElementCore _dlgElementCore;
	};
}
