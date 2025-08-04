#pragma once

namespace DirectUI
{
    struct TouchSliderUpdatedEvent : Event
    {
        int NewValue;
        bool fTriggeredByKeyboard;
    };

    class TouchSlider : public Element
    {
    public:
        TouchSlider();
        TouchSlider(const TouchSlider& other) = delete;

        ~TouchSlider() override;

        UILIB_API static HRESULT WINAPI Register();

        UILIB_API static IClassInfo* WINAPI GetClassInfoPtr();
        static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

    private:
        static IClassInfo* s_pClassInfo;

    public:
        UILIB_API IClassInfo* GetClassInfoW() override;

        UILIB_API static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
        UILIB_API static HRESULT WINAPI Initialize(Element* pParent, DWORD* pdwDeferCookie);

        void OnInput(InputEvent* pInput) override;
        void OnEvent(Event* pEvent) override;
        void OnHosted(Element* peNewRoot) override;
        void _SelfLayoutDoLayout(int cx, int cy) override;
        SIZE _SelfLayoutUpdateDesiredSize(int dConstW, int dConstH, Surface* psrf) override;
        void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
        void GetImmersiveFocusRectOffsets(RECT* prc) override;

        UILIB_API static const PropertyInfo* WINAPI IsVerticalProp();
        UILIB_API static const PropertyInfo* WINAPI MeteringProp();
        UILIB_API static const PropertyInfo* WINAPI BufferingProp();
        UILIB_API static const PropertyInfo* WINAPI TickCountProp();
        UILIB_API static const PropertyInfo* WINAPI ShowTickProp();
        UILIB_API static const PropertyInfo* WINAPI IsContinuousProp();
        UILIB_API static const PropertyInfo* WINAPI IsShowOnOffFeedbackProp();
        UILIB_API static const PropertyInfo* WINAPI VisualStateProp();
        UILIB_API static const PropertyInfo* WINAPI IsPressedProp();
        UILIB_API static const PropertyInfo* WINAPI ThumbPositionProp();

        UILIB_API bool GetIsVertical();
        UILIB_API int GetMetering();
        UILIB_API int GetBuffering();
        UILIB_API int GetTickCount();
        UILIB_API bool GetShowTick();
        UILIB_API bool GetIsPressed();
        UILIB_API bool GetIsContinuous();
        UILIB_API bool GetIsShowOnOffFeedback();
        UILIB_API int GetVisualState();
        int GetThumbPosition();

        UILIB_API HRESULT SetIsVertical(bool v);
        UILIB_API HRESULT SetMetering(int v);
        UILIB_API HRESULT SetBuffering(int v);
        UILIB_API HRESULT SetTickCount(int v);
        UILIB_API HRESULT SetShowTick(bool v);
        UILIB_API HRESULT SetIsPressed(bool v);
        UILIB_API HRESULT SetIsContinuous(bool v);
        UILIB_API HRESULT SetIsShowOnOffFeedback(bool v);
        HRESULT SetVisualState(int v);
        HRESULT SetThumbPosition(int v);

        UILIB_API void SetRespondToMouseScroll(bool respondToMouseScroll);
        UILIB_API void SetFireContinuousSliderEvent(bool fireContinuousSliderEvent);

        UILIB_API static UID WINAPI SliderUpdated();
        UILIB_API static UID WINAPI MouseOrPointerReleased();

        UILIB_API int GetRangeMin();
        UILIB_API int GetRangeMax();
        UILIB_API int GetStepCount();
        UILIB_API int GetThumbValue();

        UILIB_API void SetRangeMinAndRangeMax(int RangeMin, int RangeMax);
        UILIB_API void SetRangeMin(int RangeMin);
        UILIB_API void SetRangeMax(int RangeMax);
        UILIB_API void SetStepCount(int StepCount);

        UILIB_API void SetThumbValue(int ThumbValue, bool RaiseEvent);
        UILIB_API void SetThumbValue(int ThumbValue, bool RaiseEvent, bool fForce);

        UILIB_API Element* GetTrackElement();
        UILIB_API Button* GetThumbElement();
        UILIB_API Element* GetFillpartElement();

        UILIB_API void RemoveRichDuiTooltip();
        UILIB_API void SetTooltipText(const WCHAR* pszTooltipText);

        UILIB_API int TranslateThumbPositionToThumbValue(int ThumbPosition);
        UILIB_API void FireEventOnMouseOrPointerRelease();
        UILIB_API void SetRespectLanguageDirection(bool fRespectLanguageDirection);
        UILIB_API void EraseFeedback();
        UILIB_API void UseFixedTooltipOffset();
        UILIB_API void ShowTooltipOnRightForLTRBuild();
        UILIB_API void CancelCurrentDrag();

    private:
        int _PPIPositionAdjustments[3][24];

        Element* GetToggle();
        bool IsToggle();
        bool ExceedDragThreshhold(int);
        int HandleMouseClickOrTouch(int x, int y, bool Down, bool Drag);
        void FireSliderUpdatedEvent(bool fTriggeredByKeyboard);
        void FireMouseOrPointerReleasedEvent();
        void SetElementCustomString(Element* pElement, const WCHAR* pszValue);
        void DoIncrement();
        void DoDecrement();
        int SnapThumbValue(int UnsnappedValue); // Unsure
        int GetSnappedThumbPosition(int UnsnappedThumbPosition, float StepSizeInPixels); // Unsure
        int ConvertRawPositionToThumbPosition(int RawPosition);
        int TranslateThumbValueToThumbPosition(int ThumbValue);
        void TranslateThumbValueToFeedbackText(int ThumbValue);
        int SnapThumb(int ThumbPosition);
        void SetThumbValueWithTriggeredByKeyboardFlag(int ThumbValue, bool fRaiseEvent, bool fTriggeredByKeyboard, bool fForce);
        void InternalSetThumbValue(int ThumbValue, bool a3); // TODO: Find the last arg
        HRESULT SetContact(unsigned int, bool);
        HRESULT InitializeDirectManipulation();
        int ExcludeTopPadding(int);
        void ResetDragDelta();
        int GetUserHandedness();

        IDirectManipulationManager* _pManipulationManager;
        IDirectManipulationViewport* _pManipulationViewport;
        ITouchTooltip* _pDuiTooltip;

        int _iRangeMin;
        int _iRangeMax;
        int _iStepCount;
        int _iThumbValue;
        int _iPointerDownPosition;
        int _iSlidableHeight;
        int _iSlidableWidth;
        int _iTrackX;
        int _iTrackY;
        int _iThumbX;
        int _iThumbY;
        int _iPointerX;
        int _iPointerY;
        int _iMouseWheelDeltaCarryOver;

        Button* _pThumb;
        Element* _peTrack;
        Element* _peFillpart;
        Element* _peBuffering;
        Element* _peTrackChild;

        bool _fThumbValueDirty;
        bool _fFireContinuousSliderEvent;
        bool _fDManipInitialized;
        bool _fRespondToMouseScroll;
        bool _fShowTooltip;
        bool _fUseDefaultTooltipText;
        bool _fFireMouseOrPointerReleasedEvent;
        bool _fMouseDown;
        bool _fTouchUpReceivedAfterTouchDown;

        POINT _ptTetherPoint;

        UINT _iPointerEventId;
        UINT _iDragDelta;

        bool _fDragDetected;
        bool _fRespectLanguageDirection;
        bool _fTooltipShowOnRightOnLTR;
        bool _fUseFixedTooltipOffset;
        bool _fTooltipToBeTriggeredByTouch;
        bool _fCancelCurrentDrag;

        int _UserHandedness;

        DynamicArray<Element*>* _pdaTicks;
    };
}
