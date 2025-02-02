#pragma once

// TODO: ITouchTooltipEventSink
// TODO: CIHMCallback
// TODO: CSafeElementListenerPtr

namespace DirectUI
{
    enum IHMState
    {
        IHMState_AnimatingToShow = 0,
        IHMState_Shown = 1,
        IHMState_AnimatingToHide = 2,
        IHMState_Hidden = 3
    };

    enum TouchHWNDElementFlags
    {
        THEF_None = 0,
        THEF_AllowBackgroundTooltip = 1,
        THEF_TreatRightButtonAsLeft = 2,
        THEF_ConstrainTooltipToWorkspace = 4,
        THEF_NoAutoFocusRectVisibility = 8,
        THEF_DisableTooltips = 16
    };

    class UILIB_API TouchHWNDElement : HWNDElement
    {
    public:
        static HRESULT WINAPI Create(HWND hwndParent, bool fDblBuffer, UINT nCreate, Element* peParent, DWORD* pdwDeferCookie, Element** ppe);
        static UID TooltipTimerStarting();
        static UID TextTooltipShowing();
        static UID RichTooltipShowing();
        static UID ForwardingWindowMessage();
        static UID ProcessingKeyboardNavigation();
        static UID ScaleChanged();
        static UID MonitorPowerSettingsChange();
        static UID IHMNotify();

        static const PropertyInfo* FlagsProp();
        TouchHWNDElementFlags GetFlags();
        HRESULT SetFlags(TouchHWNDElementFlags v, TouchHWNDElementFlags vmask);

        static const PropertyInfo* WindowAccessGradientColorProp();
        Value* GetWindowAccessGradientColor();
        HRESULT SetWindowAccessGradientColor(Value* v);
        static const PropertyInfo* TooltipMaximumLineCountProp();
        int GetTooltipMaximumLineCount();
        HRESULT SetTooltipMaximumLineCount(int v);
        static const PropertyInfo* LightDismissIHMProp();
        bool GetLightDismissIHM();
        HRESULT SetLightDismissIHM(bool v);
        HRESULT Initialize(HWND hwndParent, bool fDblBuffer, UINT nCreate, Element* peParent, DWORD* pdwDeferCookie);

        virtual UINT MessageCallback(GMSG* pGMsg);
        virtual void OnInput(InputEvent* pInput);
        virtual void OnEvent(Event* pEvent);
        virtual void OnKeyFocusMoved(Element* peFrom, Element* peTo);
        virtual void OnPropertyChanged(const PropertyInfo*, int iIndex, Value* pvOld, Value* pvNew);

        virtual LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
        virtual bool IsMSAAEnabled();
        virtual void OnDestroy();
        //void UpdateTooltip(Element*);
        //void ActivateTooltip(Element*, unsigned long);
        //void RemoveTooltip(Element*);

        HRESULT StartRichTooltipTimer(enum TOUCHTOOLTIP_INPUT touchTooltipInput);
        HRESULT ShowRichTooltip(TOUCHTOOLTIP_INPUT touchTooltipInput, enum TOUCHTOOLTIP_OPTION_FLAGS touchTooltipOptions, Element* peTooltipContents);

        HRESULT HideTouchTooltip();
        HRESULT RegisterForMonitorPowerChanges();
        HRESULT UnregisterForMonitorPowerChanges();
        bool ShouldUsePerMonitorScaling();
        void UsePerMonitorScaling(HMONITOR hMon);
        HRESULT RegisterForIHMChanges();
        void UnregisterForIHMChanges();
        HRESULT GetIHMRect(RECT* prc);
        IHMState GetIHMState();
        HRESULT DismissIHMAsync();
        void RegisterForAnimationStatusChanges();
        void UnregisterForAnimationStatusChanges();
        bool IsRegisteredForAnimationStatusChanges();

        IClassInfo* GetClassInfoPtr(); // Cant find this...
        void SetClassInfoPtr(IClassInfo*); // or this...

    private:
        IClassInfo* s_pClassInfo;

    public:
        IClassInfo* GetClassInfoW() override;
        static HRESULT WINAPI Register();
        TouchHWNDElement();
        ~TouchHWNDElement();

    protected:
        virtual void _OnUIStateChanged(WCHAR wUIStateOld, WCHAR wUIStateNew);
        void _ClearTooltipState();
        void _DestroyTooltip();

    private:
        static bool WINAPI _IsElementContentTruncated(RichText* pe);
        UID _DismissIHM(); // Cant find
        void _OnIHMNotify(IHMState ihmstate);
        HRESULT _EnsureTooltip();

        Element* _TargetElementFromEventInfo(Element* peTarget, const POINT* ppt);

        void _SetActiveTooltipElement(Element* pe, TOUCHTOOLTIP_INPUT touchTooltipInput);
        void _OnTooltipTimerFired(TOUCHTOOLTIP_INPUT touchTooltipInput, enum TOUCHTOOLTIP_TYPE touchTooltipType, enum TOUCHTOOLTIP_DELAY touchTooltipDelay); // Last argument name is guessed based on the other names
        HRESULT _ShowTooltipForElement(TOUCHTOOLTIP_INPUT touchTooltipInput, Element* pe);
        DEVICE_SCALE_FACTOR _UpdateImmersiveScaleFactor();
        void _UpdateChildrenForAcceleratorDisplayChange(Element* pe);
        bool _ShouldUseImmersivePerWindowScaling();
        void _HideFocusRect();
        void _FireScaleChangeEvent();
        void _UpdateImmersiveScaleFactorAndMaybeFireScaleChangeEvent();
        void _OnListenerDetach(Element* pe);
        class CSafeElementListenerPtr<Element> _speWithTooltip;
        struct ITouchTooltip* _pTooltip;
        POINT _ptLastMousePosition;
        UINT _nLastPointerID;
        POINT _ptLastPointerPosition;
        bool _fProcessingKeyboardNavigationEvent;
        DWORD _dwScaleChangeCookie;
        HMONITOR _hMonitorForScaling;
        HWND _hwndScaleChange;
        enum TOUCHTOOLTIP_CREATE_FLAGS _touchTooltipCreateFlags;
        UINT _cMonitorRegistrations;
        void* _hPower;
        UINT _cIHMRegistrations;
        class DirectUI::CIHMCallback* _pIHMCallback;
        UINT _cAnimationStatusRegistrations;
        bool _fDismissIHMOnEvent;
        bool _fDismissIHMEventPosted;
        bool _fLightDismissIHMUnregisterIHMChanges;

        class TooltipEventSink : public CSafeElementListenerCB, public ITouchTooltipEventSink
        {
        public:
            static HRESULT WINAPI s_CreateInstance(TouchHWNDElement* peTouchHWNDElement, REFIID riid, void** ppv);

            //~ Begin ITouchTooltipEventSink Interface
            virtual HRESULT STDMETHODCALLTYPE OnTooltipTimerFired(TOUCHTOOLTIP_INPUT touchTooltipInput, TOUCHTOOLTIP_TYPE touchTooltipType, TOUCHTOOLTIP_DELAY touchTooltipDelay);
            virtual HRESULT STDMETHODCALLTYPE OnTooltipHidden();
            //~ End ITouchTooltipEventSink Interface

            //~ Begin IElementListener Interface
            STDMETHODIMP_(void)OnListenerDetach(Element* peFrom) override;
            //~ End IElementListener Interface

        protected:
            _GUID* s_rgpIID[0];
            ~TooltipEventSink();
            HRESULT SetTouchHWNDElement(TouchHWNDElement*); // Cant find this

        private:
            class CSafeElementListenerPtr<TouchHWNDElement> _speTouchHWNDElement;

        public:
            TooltipEventSink();
        };

        class ElementWithTooltipListener : public CSafeElementListenerCB
        {
        public:
            void SetTouchHWNDElement(TouchHWNDElement*);
            STDMETHODIMP_(void) OnListenerDetach(Element*) override;

        private:
            TouchHWNDElement* _peTouchHWNDElement;

        public:
            ElementWithTooltipListener(ElementWithTooltipListener*);
            ElementWithTooltipListener(ElementWithTooltipListener&);
            ElementWithTooltipListener();
            ElementWithTooltipListener& operator=(ElementWithTooltipListener*);
            ElementWithTooltipListener& operator=(ElementWithTooltipListener&);
        };

        ElementWithTooltipListener elementWithTooltipListener;
    };
}
