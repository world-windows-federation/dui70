#pragma once

namespace DirectUI
{
	class TouchEdit2 : public TouchEditBase, IElementListener
	{
	public:
		UILIB_API static UID WINAPI ClearButtonClicked();
		UILIB_API static UID WINAPI ContextMenuRequested();

		UILIB_API static const PropertyInfo* WINAPI PromptTextProp();
		UILIB_API const WCHAR* GetPromptText(Value** ppv);
		UILIB_API HRESULT SetPromptText(const WCHAR* psz);

		UILIB_API static const PropertyInfo* WINAPI PromptWithCaretProp();
		UILIB_API bool GetPromptWithCaret();
		UILIB_API HRESULT SetPromptWithCaret(bool);

		UILIB_API static const PropertyInfo* WINAPI SuppressClearButtonProp();
		UILIB_API bool GetSuppressClearButton();
		UILIB_API HRESULT SetSuppressClearButton(bool);

		UILIB_API static const PropertyInfo* WINAPI ShowClearButtonMinWidthProp();
		UILIB_API int GetShowClearButtonMinWidth();
		UILIB_API HRESULT SetShowClearButtonMinWidth(int);

		UILIB_API static const PropertyInfo* WINAPI PasswordRevealModeProp();
		UILIB_API TouchEditPasswordRevealMode GetPasswordRevealMode();
		UILIB_API HRESULT SetPasswordRevealMode(TouchEditPasswordRevealMode);

		UILIB_API static const PropertyInfo* WINAPI InnerBorderThicknessProp();
		UILIB_API const RECT* GetInnerBorderThickness(Value** ppv);
		UILIB_API HRESULT SetInnerBorderThickness(int, int, int, int);

		UILIB_API static IClassInfo* WINAPI GetClassInfoPtr();
		void SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		UILIB_API IClassInfo* WINAPI GetClassInfoW() override;
		UILIB_API static HRESULT Register();
		UILIB_API static HRESULT WINAPI Create(Element*, DWORD*, Element**);
		UILIB_API HRESULT Initialize(Element*, unsigned long*);
		TouchEdit2(TouchEdit2*);
		TouchEdit2(TouchEdit2&);
		UILIB_API TouchEdit2();

		UILIB_API void OnHosted(Element*) override;
		UILIB_API void OnInput(InputEvent*) override;
		UILIB_API bool OnPropertyChanging(PropertyInfo*, int, Value*, Value*) override;
		UILIB_API void OnPropertyChanged(PropertyInfo*, int, Value*, Value*) override;
		UILIB_API void OnEvent(Event*) override;

		UILIB_API void Paint(HDC hdc, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) override;
		UILIB_API HRESULT Add(Element**, UINT) override;

		UILIB_API HRESULT GetAccessibleImpl(IAccessible**) override;
		UILIB_API Element* GetUiaFocusDelegate() override;

		UILIB_API HRESULT GetTextDocument(ITextDocument**) override;
		UILIB_API HRESULT GetTextServices(ITextServices**) override;
		UILIB_API HRESULT RefreshContent() override;
		UILIB_API HRESULT FinalizeCurrentIMEComposition() override;
		UILIB_API HRESULT GetTextHost(class ITextHost**);

		UILIB_API HRESULT GetTextSelection(struct ITextSelection**);
		UILIB_API HRESULT PasteText(const WCHAR* pszText);

		UILIB_API HRESULT GetSelection(long*, long*);
		UILIB_API HRESULT SetSelection(long, long);

		UILIB_API HRESULT SetCaretPosition(long);

		UILIB_API InputScope GetInputScope(); // __MIDL___MIDL_itf_inputscope_0000_0000_0001
		UILIB_API HRESULT SetInputScope(InputScope); // __MIDL___MIDL_itf_inputscope_0000_0000_0001

		UILIB_API bool HasSelection();
		UILIB_API HRESULT SelectAll();
		UILIB_API HRESULT SelectNone();
		UILIB_API void DisableSelectionHandlesOnEmptyContent();

	private:
		void OnListenerAttach(Element*) override;
		UILIB_API void OnListenerDetach(Element*) override;

		bool OnListenedPropertyChanging(Element*, PropertyInfo*, int, Value*, Value*);
		UILIB_API void OnListenedPropertyChanged(Element*, PropertyInfo*, int, Value*, Value*);

		void OnListenedInput(Element*, InputEvent*) override;
		void OnListenedEvent(Element*, Event*) override;

		HRESULT _CreateDirectChildren();
		HRESULT _CreateTextElements();
		void _UpdatePrompt();
		void _UpdateButton();
		void _RevealPassword(PasswordReveal);
		bool _IsRevealButtonActive();
		TouchEditInner* _peTouchEditInner;
		PromptText* _pePrompt;
		Element* _peTextContainer;
		TouchButton* _peButton;
		Element* _peExtra;

	public:
		TouchEdit2& operator=(TouchEdit2*);
		TouchEdit2& operator=(TouchEdit2&);
	};
}
