#pragma once

interface ILightDismissProvider;

namespace DirectUI
{
	struct TouchSelectionChangeEvent : Event
	{
		Element* peOldElement;
		Element* peNewElement;
		int iOldIndex;
		int iNewIndex;
	};

	enum POPUPCHANGEEVENTTYPE
	{
		PCE_OPEN = 0,
		PCE_CLOSE = 1,
		PCE_BEFORE_OPEN = 2,
	};

	struct PopupChangeEvent : Event
	{
		POPUPCHANGEEVENTTYPE changeType;
	};

	class TouchSelectItem : public TouchButton
	{
	public:
		UILIB_API static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		UILIB_API IClassInfo* GetClassInfoW() override;

		UILIB_API static HRESULT WINAPI Register();
		UILIB_API static HRESULT WINAPI Create(Element* peParent, DWORD* pdwDeferCookie, Element** ppElement);

		UILIB_API TouchSelectItem();
		TouchSelectItem(const TouchSelectItem&) = default;

		UILIB_API ~TouchSelectItem() override;

		UILIB_API static const PropertyInfo* WINAPI TextContentOverrideProp();
		UILIB_API const WCHAR* GetTextContentOverride(Value** ppv);
		UILIB_API HRESULT SetTextContentOverride(const WCHAR* psz);

		UILIB_API HRESULT GetItemData(IUnknown** ppunkData);
		UILIB_API HRESULT SetItemData(IUnknown* punkData);

	private:
		IUnknown* _pUnkItemData;
	};

	class WrappingList
	{
	};

	class TouchSelectHost
	{
	};

	class TouchSelectPopup
	{
	};

	enum POPUPSCROLLVIEWERTYPE
	{
		PSVT_CAROUSELING = 0,
		PSVT_SCROLLING = 1,
		PSVT_NONSCROLLABLE = 2,
		PSVT_NONE = 3,
	};

	class TouchSelect : public TouchButton
	{
	public:
		UILIB_API static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		UILIB_API IClassInfo* GetClassInfoW() override;

		UILIB_API static HRESULT WINAPI Register();
		UILIB_API static HRESULT WINAPI Create(Element* peParent, DWORD* pdwDeferCookie, Element** ppElement);

		// ReSharper disable once CppHidingFunction
		UILIB_API HRESULT Initialize(Element* peParent, DWORD* pdwDeferCookie);

		UILIB_API TouchSelect();
		UILIB_API ~TouchSelect() override;

		UILIB_API static UID WINAPI SelectionChange();
		UILIB_API static UID WINAPI PopupChange();

		UILIB_API static const PropertyInfo* WINAPI SelectionProp();
		UILIB_API Element* GetSelection();
		UILIB_API HRESULT SetSelection(Element* peNew);

		UILIB_API static const PropertyInfo* WINAPI ItemHeightInPopupProp();
		UILIB_API int GetItemHeightInPopup();
		UILIB_API HRESULT SetItemHeightInPopup(int v);

		UILIB_API static const PropertyInfo* WINAPI PopupBoundsProp();
		UILIB_API const RECT* GetPopupBounds(Value** ppv);
		UILIB_API HRESULT SetPopupBounds(int l, int t, int r, int b);

		UILIB_API static const PropertyInfo* WINAPI AnimatePopupOnDismissProp();
		UILIB_API bool GetAnimatePopupOnDismiss();
		UILIB_API HRESULT SetAnimatePopupOnDismiss(bool v);

		UILIB_API HRESULT AddString(const WCHAR* pszString);
		UILIB_API HRESULT AddString(const WCHAR* pszString, Element** ppeItem);
		UILIB_API HRESULT AddStringWithLabelOverride(const WCHAR* pszString, const WCHAR* pszLabel, Element** ppeItem);
		UILIB_API HRESULT AddElement(Element* pe, const WCHAR* pszTextContent);
		UILIB_API HRESULT RemoveItem(int iIndex);
		UILIB_API HRESULT UpdateElement(int iIndex, Element* pe, const WCHAR* pszTextContent);
		UILIB_API HRESULT UpdateString(int iIndex, const WCHAR* pszString);
		UILIB_API DWORD GetItemCount();
		UILIB_API HRESULT GetItemData(int iIndex, IUnknown** ppunkData);
		UILIB_API HRESULT SetItemData(int iIndex, IUnknown* punkData);
		// ReSharper disable once CppHidingFunction
		UILIB_API void RemoveAll();
		UILIB_API int GetSelectionIndex();
		UILIB_API HRESULT SetSelectionIndex(int iSelection);
		UILIB_API bool IsPopupOpen();
		UILIB_API HRESULT OpenPopup();
		UILIB_API void ClosePopup();

		UILIB_API HRESULT GetElementProviderImpl(InvokeHelper* pih, ElementProvider** ppprv) override;
		UILIB_API void OnHosted(Element* peNewHost) override;
		UILIB_API void OnUnHosted(Element* peOldHost) override;
		UILIB_API void OnEvent(Event* pEvent) override;
		UILIB_API void OnInput(InputEvent* pie) override;
		UILIB_API bool OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		UILIB_API void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		UILIB_API HRESULT Add(Element** ppe, UINT cCount) override;
		UILIB_API HRESULT Insert(Element** ppe, UINT cCount, UINT iInsertIdx) override;

		void FirePopupChangeEvent(Element* peFrom, POPUPCHANGEEVENTTYPE changeType);

	private:
		void _SelfLayoutDoLayout(int cx, int cy) override;
		SIZE _SelfLayoutUpdateDesiredSize(int dConstW, int dConstH, Surface* psrf) override;

		class TouchSelectListener : public CSafeElementListenerCB
		{
		public:
			TouchSelectListener();
			TouchSelectListener(const TouchSelectListener&) = default;
			TouchSelectListener(TouchSelectListener&&) noexcept = default;

			void SetTouchSelect(TouchSelect* peTouchSelect);

			void OnListenedEvent(Element* peFrom, Event* pEvent) override;
			void OnListenerDetach(Element* peFrom) override;

		private:
			TouchSelect* _peTouchSelect;
		};

		TouchSelectListener _touchSelectListener;

		void _OnListenedEvent(Element* peFrom, Event* pEvent);
		void _OnListenerDetach(Element* peFrom);

		static UID WINAPI _AsyncOpen();
		static UID WINAPI _AsyncClose();
		static UID WINAPI _HideAnimationFinished();
		static UID WINAPI _OpenAnimationFinished();

		HRESULT _CreateFaceplate();
		HRESULT _CreateTouchSelectItem(TouchSelectItem** ppeItem);
		HRESULT _ClearTouchSelectItem(TouchSelectItem* peItem);
		HRESULT _SetTouchSelectItem(TouchSelectItem* peItem, Element* pe, const WCHAR* pszTextContent);
		HRESULT _SetTouchSelectItem(TouchSelectItem* peItem, const WCHAR* pszText);
		HRESULT _AddTouchSelectItem(TouchSelectItem* peItem);
		void _UpdateClassPropForItems(Value* pv);
		HRESULT _ClearLabel();
		HRESULT _SetLabel(Element* peSelection);
		HRESULT _SyncLabel(Element* peOldSelection, Element* peNewSelection);
		HRESULT _GetItemFromIndex(int iIndex, TouchSelectItem** ppeItem);
		int _GetItemIndex(Element* peItem);
		Element* _FindNextItem(WCHAR ch);
		static bool s_ContentStartsWithChar(TouchSelectItem* peItem, WCHAR ch);

		enum POPUPFIREEVENTTYPE
		{
			PFE_FIRE_EVENT = 0,
			PFE_DONT_FIRE_EVENT = 1
		};

		HRESULT _OpenPopup(ClickDevice clickdevice);
		void _ClosePopup(POPUPFIREEVENTTYPE fireEventType);
		void _RealClosePopup(POPUPFIREEVENTTYPE fireEventType);
		HRESULT _CreatePopup();
		void _DestroyPopup();
		HRESULT _PostOpenEvent();
		HRESULT _PostCloseEvent();
		HRESULT _PrepareListForPopup();
		HRESULT _RestoreListToFaceplate();
		HRESULT _PrepareCarouselingPopup(const RECT* prcPopupBounds);
		HRESULT _PrepareScrollingPopup(const RECT* prcPopupBounds);
		HRESULT _PrepareNonScrollablePopup(const RECT* _PrepareNonScrollablePopup);
		HRESULT _PreparePopup(ClickDevice);
		HRESULT _GetFaceplateFromScreenRect(RECT* prcFaceplateFromScreen);
		void _GetLabelContentFromFaceplateRect(RECT* prcLabelContentFromFaceplate);
		void _GetSelectionContentFromPopupRect(RECT* prcSelectionContentFromPopup);
		HRESULT _GetAdjustedFaceplateAndSelectionRect(RECT* prcFaceplateInScreen, RECT* prcSelectionInPopup);
		void _SubtractPopupBorderHeight(RECT* prc);
		void _AddPopupBorderHeight(RECT* prc);
		void _OffsetByPopupBorderHeight(RECT* prc);
		HRESULT _IsScrollable(const RECT* prcPopupBounds, bool* pfScrollable);
		HRESULT _PositionNonScrollable(const RECT* prcPopupBounds);
		HRESULT _PositionCarouseling(const RECT* prcPopupBounds, RECT* prcFaceplateInScreen);
		HRESULT _PositionScrolling(const RECT* prcPopupBounds, RECT* prcFaceplateInScreen);
		HRESULT _GetPopupBounds(RECT* prcPopupBounds);
		HRESULT _GetLabelScreenRect(RECT*);
		Element* _GetPopupElement();
		HRESULT _EnableLightDismiss();
		void _DisableLightDismiss();
		static LRESULT CALLBACK _FullScreenWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK _StaticKeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK _KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);
		void _OnIHMShowing(const RECT*, bool);
		void _OnIHMHiding(bool);

		CSafeElementListenerPtr<TouchHWNDElement> _speRoot;
		TouchButton* _peLabel;
		TouchButton* _peArrow;
		WrappingList* _peList;
		TouchSelectHost* _pePopupHost;
		TouchSelectPopup* _pePopup;
		POPUPSCROLLVIEWERTYPE _popupScrollViewerType;
		ILightDismissProvider* _pLightDismiss;
		DWORD _dwLightDismissCookie;
		bool _fOpenPopupAfterIHMAnimate;
		HHOOK _hhookKeyboard;
		HWND _hwndFullScreen;
		bool _fVirtualized;
		bool _fRegisteredForIHMChanges;

		static TouchSelect* s_peActivePopup;
		static const UINT s_cMaxNonScrollable = 9;
	};
}
