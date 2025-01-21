#pragma once

namespace DirectUI
{
    class TouchScrollViewer : public BaseScrollViewer
    {
    public:
        UID ManipulationStarting();
        UID ManipulationStarted();
        UID ManipulationDelta();
        UID ManipulationCompleted();
        UID SemanticChange();
        UID SnapshotTransformElement();
        UID ReleaseSnapshot();
        UID MapContentVisuals();
        UID SetContactNeeded();
        UID SetContactNotify();
        UID UpdateView();
        UID UpdateContentSize();

        HRESULT Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
        HRESULT Initialize(Element* pParent, DWORD* pdwDeferCookie);

        void OnInput(InputEvent* pInput);
        void OnPropertyChanged(PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew);
        bool IsLayered();

        //bool IsContentElement(Element* ); - doesnt exist?

    protected:
        void OnHosted(Element* peNewHost);
        void OnUnHosted(Element* peOldHost);
        void OnGroupChanged(int fGroups, bool bLowPri);

    public:
        void OnListenedPropertyChanged(Element* peFrom, PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew);
        PropertyInfo* InteractionModeProp();
        PropertyInfo* SnapModeProp();
        PropertyInfo* AllowArrowOutProp();
        PropertyInfo* ScrollPaddingProp();
        PropertyInfo* SnapIntervalXProp();
        PropertyInfo* SnapOffsetXProp();
        PropertyInfo* SnapPointCollectionXProp();
        PropertyInfo* SnapIntervalYProp();
        PropertyInfo* SnapOffsetYProp();
        PropertyInfo* SnapPointCollectionYProp();
        PropertyInfo* ManipulationVerticalAlignmentProp();
        PropertyInfo* ManipulationHorizontalAlignmentProp();
        PropertyInfo* LinkIndicatorsToContentProp();
        PropertyInfo* ZoomMinimumProp();
        PropertyInfo* ZoomMaximumProp();

        int GetInteractionMode();
        HRESULT SetInteractionMode(int v);

        int GetSnapMode();
        HRESULT SetSnapMode(int v);

        bool GetAllowArrowOut();
        HRESULT SetAllowArrowOut(bool v);

        RECT* GetScrollPadding(Value** ppv);
        HRESULT SetScrollPadding(int l, int t, int r, int b);

        float GetZoomMinimum();
        HRESULT SetZoomMinimum(float v);

        float GetZoomMaximum();
        HRESULT SetZoomMaximum(float v);

        float GetSnapIntervalX();
        float GetSnapOffsetX();
        DynamicArray<double, 0>* GetSnapPointCollectionX(Value** ppv);
        float GetSnapIntervalY();
        float GetSnapOffsetY();
        DynamicArray<double, 0>* GetSnapPointCollectionY(Value** ppv);
        bool GetLinkIndicatorsToContent();

        HRESULT SetSnapIntervalX(float v);
        HRESULT SetSnapOffsetX(float v);
        HRESULT SetSnapPointCollectionX(double const* rgdbl , int cdbl);
        HRESULT SetSnapPointCollectionX(DynamicArray<double, 0>* v);
        HRESULT SetSnapIntervalY(float v);
        HRESULT SetSnapOffsetY(float v);
        HRESULT SetSnapPointCollectionY(double const* rgdbl, int cdbl);
        HRESULT SetSnapPointCollectionY(DynamicArray<double, 0>* v);
        HRESULT SetLinkIndicatorsToContent(bool v);
        HRESULT SetContact(UINT uiPointerID, bool fRelease);

        HRESULT ZoomToRect(const RECT* pcrcTarget, bool fAnimate);
        bool CanPerformManualVisualSwap();
        bool IsManualVisualSwapInProgress();
        HRESULT ZoomToRectManualVisualSwap(float left, float top, float right, float bottom, const int* pnHorizontalDelta, float panX, float panY, float scaleDestination, bool fAnimate);
        HRESULT PrepareManualSwapDeferredZoomToRect(const RECT* pcrcTarget, const float* ppanX, const float* ppanY, float* centerXOverride, float* centerYOverride, float scaleDestination);
        HRESULT ExecuteManualSwapDeferredZoomToRect(bool fAnimate);
        HRESULT SetSuppressSetContact(bool fDisable);
        HRESULT ResetManipulations();
        HRESULT ResetInputState();
        HRESULT SetVirtualizeElements(bool fVirtualize);
        void SetDisableOffscreenCaching(bool fDisableOffscreen);
        int GetManipulationVerticalAlignment();
        HRESULT SetManipulationVerticalAlignment(int v);
        int GetManipulationHorizontalAlignment();
        HRESULT SetManipulationHorizontalAlignment(int v);
        HRESULT SetDelegateEventHandler(IUnknown* punk);
        HRESULT GetVScrollbar(Element** ppeScrollbar);
        HRESULT GetHScrollbar(Element** ppeScrollbar);
        void GetInertiaEndpointVisibleRect(RECT* );
        float GetInertiaEndpointZoomLevel(float);
        void GetVisibleRect(RECT*);
        void GetPredictedVisibleRect(RECT*);
        bool GetMouseWithinHorizontalScrollRegion();
        HRESULT SetScrollControlHost(Element*);
        void GetTranslatedTileRects(RECT*, unsigned int*, unsigned int);
        bool IsTileMember(unsigned int, Element*);
        bool IsCrossfadeInProgress();
        HRESULT OverrideZoomThreshold(float, float, int);
        float GetContentCrossfadeOpacity();
        bool IsManipulationConfigured();
        bool IsManipulating();
        bool IsPerformingSemanticZoom();
        TouchScrollViewer();
        ~TouchScrollViewer();
        void ProcessAnimationEvent(struct DirectUI::AnimateScrollEvent*);
        IClassInfo* GetClassInfoPtr();
        void SetClassInfoPtr(IClassInfo*);

    private:
        IClassInfo* s_pClassInfo;

    public:
        IClassInfo* GetClassInfoW();
        HRESULT Register();
        HRESULT OnViewportStatusChanged(struct IDirectManipulationViewport*, enum DIRECTMANIPULATION_STATUS, DIRECTMANIPULATION_STATUS);
        HRESULT OnViewportUpdated(IDirectManipulationViewport*);
        HRESULT OnContentUpdated(IDirectManipulationViewport*, struct IDirectManipulationContent*);
        struct IDirectManipulationManager* GetManipulationManager();
        IDirectManipulationViewport* GetManipulationViewport(bool);
        struct IDirectManipulationCompositor* GetManipulationCompositor();
        HRESULT CreateTile(RECT*, unsigned int*);
        HRESULT RemoveTile(unsigned int);
        void InvalidateVirtualizedContainers();
        bool IsVirtualizedContainerInvalidationPending();
        void SetVirtualizeUsingElementPosition(bool);
        void NewChildElementsAdded();
        void InvalidateChangedChildElements();
        HRESULT OnContentLayoutUpdated();
        HRESULT TelemetrySetDescription(wchar_t*);

    protected:
        HRESULT EnableManipulations(bool);
        HRESULT InitializeManipulationHelper();
        HRESULT InitializeViewport();
        void ReleaseViewport();
        void _ResetManipulations(Element*);
        HRESULT SetMessage(MSG*, bool*);
        void OnEvent(Event*);
        void OnKeyFocusMoved(Element*, Element*);
        void OnMouseFocusMoved(Element*, Element*);

    private:
        bool _SetElementContentVisualTransform(Element*, float, float, float, float, float, float);
        void _MapVisuals(float, float, float, float, bool);

    protected:
        HRESULT CreateScrollBars();
        HRESULT AddChildren();

    public:
        BaseScrollBar* GetHScroll();

    protected:
        TouchScrollBar* GetHScroll();

    public:
        BaseScrollBar* GetVScroll();

    protected:
        TouchScrollBar* GetVScroll();
        void _SetLastInputType(unsigned int);
        unsigned int MessageCallback(tagGMSG*);
        void OnDestroy();
        void _OnManipulationStart();
        void _OnManipulationDelta(float, float, float, float, float);
        void _OnManipulationComplete();
        void _OnRequestManualVisualSwap(float, float, float, float, float);
        void _OnManualVisualSwapComplete();
        class DirectUI::SimpleTimer _timerHide;
        void _OnHideScrollbarTimer();

    private:
        void _SetScrollbarStates(enum DirectUI::ActiveState, bool);
        class CSafeElementPtr<Element> _peSnapshot;
        unsigned long _dwCrossfadeSnapshotCookie;
        bool _fIgnoreActionComplete;
        Element* _pePendingDManipContent;
        bool _fDManipContentSet;
        HRESULT _GoLayered();
        HRESULT _GoUnlayered();
        void _SynchPendingDManipLayer();
        bool _fLayered;
        bool _fContentLayered;
        HRESULT _LayerContent();
        bool _fViewerLayered;
        HRESULT _LayerViewer();
        bool _fVirtualizeElements;
        bool _fDisableOffscreenCaching;
        bool _fLayerAlreadyIgnoringOffsets;
        int _nDraggingMode;
        int _iMouseWheelDeltaCarryOver;
        HRESULT _GetMouseMovedDelta(struct DirectUI::MouseEvent*, POINT&);
        POINT _GetScreenPosition(struct DirectUI::MouseEvent*);
        bool _fSetContactPending;
        bool _fComputingTiles;
        unsigned int _uiTileIndex;
        DynamicArray<DirectUI::TILE*, 0>* _pdaTiles;
        bool _fTileCollectionLayered;
        DynamicArray<CSafeElementPtr<Element>*, 0>* _pspelDeferredReleaseList;
        void _FlipRect(RECT*, RECT*);
        POINT _GetContentOrigin();
        HRESULT _AddTileRect(RECT*, struct DirectUI::TILE**);
        HRESULT _GetTileRect(unsigned int, RECT*);
        HRESULT _RemoveTileRect(unsigned int);
        bool _GadgetExistsInRect(Element*, RECT*);
        bool _ElementExistsInRect(Element*, RECT*);
        void _SetLayeredTiles(bool);
        void _LayerList(DynamicArray<CSafeElementPtr<Element>*, 0>*, bool, DynamicArray<CSafeElementPtr<Element>*, 0>*);
        void _ClearTiles();
        void _RecomputeTiles();
        void _SetupDeferList(DynamicArray<CSafeElementPtr<Element>*, 0>**);
        void _FlushDeferList(DynamicArray<CSafeElementPtr<Element>*, 0>**);
        HRESULT _UpdateTiles();
        HRESULT _UpdateTile(struct DirectUI::TILE*, DynamicArray<CSafeElementPtr<Element>*, 0>*);
        HRESULT _UpdateTileCollectElements_Recursive(Element*, RECT*, DynamicArray<CSafeElementPtr<Element>*, 0>*, bool, int);
        void _UpdateSizes();
        HRESULT _PrepareZoomToRect(float, const float, float, const float, float*, float*, float*, float*, float*, bool, float*, float*, float*, float*);
        HRESULT _ExecuteZoomToRect(float, float, float, float, bool);
        void _FakeDirectManipulationCallbacksToResync();
        HRESULT _GetTransformedContentRect(float*, RECT*);
        void _GetContentRectFromScrollBars(RECT*);
        void _GetSemanticZoomDeltasForDirectManipulation(float*, float*);
        void _RemoveOrRestoreSubpixelMappingOffset(bool);
        void _ShowScrollbars();
        void _RestoreScrollbarsIfNeeded();
        void _HideScrollbarsForSemanticZoom();
        void _DetectKeyboardInput();
        enum DIRECTMANIPULATION_CONFIGURATION _GetManipulationConfiguration(int);
        HRESULT _UpdateManipulationConfiguration(int, int);
        HRESULT _SetSnapPointBehavior(struct IDirectManipulationPrimaryContent*, enum DIRECTMANIPULATION_MOTION_TYPES, float, float);
        HRESULT _SetSnapPointCoordinate(IDirectManipulationPrimaryContent*, DIRECTMANIPULATION_MOTION_TYPES);
        HRESULT _UpdateContentSnapPoints(DIRECTMANIPULATION_MOTION_TYPES, PropertyInfo*);
        HRESULT _UpdateContentSnapPoints(DIRECTMANIPULATION_MOTION_TYPES, PropertyInfo*, PropertyInfo*);
        HRESULT _UpdateContentSnapInterval(DIRECTMANIPULATION_MOTION_TYPES, PropertyInfo*, PropertyInfo*);
        HRESULT _UpdateZoomBoundaries(PropertyInfo*, PropertyInfo*);
        HRESULT _UpdateSnapType(DIRECTMANIPULATION_MOTION_TYPES, enum DIRECTMANIPULATION_SNAPPOINT_TYPE);
        HRESULT _SetManipulationVerticalAlignment(enum DIRECTMANIPULATION_VERTICALALIGNMENT);
        HRESULT _SetManipulationHorizontalAlignment(enum DIRECTMANIPULATION_HORIZONTALALIGNMENT);
        HRESULT _UpdateContentSize();
        HRESULT _UpdateViewportSize();
        void _TranslateSnapPoints();
        void _SetProcessContentSizeUpdates(bool, bool);
        void _GetContentExtent(SIZE*);
        void _GetContentLocation(POINT*);
        void _CleanupSnapshotVisual();
        void _CommitDCompDevice();
        void _TelemetryUpdateViewportDescription();
        HRESULT _ReinsertDManipIntoVisualTree();
        HRESULT _CreateIndicatorContents();
        HRESULT _DeleteIndicatorContents();
        HWND _hwndRoot;
        bool _fActivated;
        bool _fEnabled;
        bool _fInertia;
        bool _fManipulation;
        bool _fListeningToContentChanges;
        bool _fOffsetPropIsChanging;
        unsigned int _nLastInputType;
        SIZE _sizeContentOverride;
        POINT _positionContentOverride;
        int _nOverrideContentSize;
        WCHAR* _pszTelemetryDescription;
        class DirectUI::ManipulationHelper* _pManipulationHelper;
        IDirectManipulationCompositor* _pManipulationCompositor;
        IDirectManipulationViewport* _pManipulationViewport;
        bool _fInitializedForRealContent;
        bool _fChangedChildElements;
        bool _fSuppressSetContact;
        bool _fIsContentSizeInitialized;
        bool _fIsTiling;
        float _c11;
        float _c12;
        float _c21;
        float _c22;
        float _c31;
        float _c32;
        int _nLayerOffsetRTL;
        float _c31SemanticZoomDelta;
        float _c32SemanticZoomDelta;
        int _layerOffsetX;
        int _layerOffsetY;
        float _scaleManualSwap;
        float _rectTargetManualSwap_left;
        float _rectTargetManualSwap_top;
        float _rectTargetManualSwap_right;
        float _rectTargetManualSwap_bottom;
        float _centerXManualSwap;
        float _centerYManualSwap;
        float _panXManualSwap;
        float _panYManualSwap;
        float _subPixelMappingOffsetX;
        float _subPixelMappingOffsetY;
        bool _fCanPerformManualVisualSwap;
        bool _fManualVisualSwapRequested;
        bool _fNeedToRestoreZoomMinimum;
        POINT _ptLastMousePos;
        long _lVertScrollEventDistance;
        long _lHorizScrollEventDistance;
        TouchScrollBar* _peHScroll;
        TouchScrollBar* _peVScroll;
        class DirectUI::SemanticController* _pSemanticController;
        bool _fDeleting;
        bool _fProcessContentSizeUpdates;
        bool _fNeedInitialMouseLocation;
        bool _fContentSizeInvalid;
        bool _fVisualsMapped;
        bool _fAllowSubPixelMapping;
        bool _fCrossfadeInProgress;
        IDuiBehavior* _pContentLayoutBehavior;
        class CSafeElementPtr<Element> _speScrollHost;
        bool _fVirtualizedContainerInvalidationPending;
        bool _fVirtualizeUsingElementPosition;
        UID _InvalidateVirtualizedContainersEvent();
        bool _fIsPerformingSemanticZoom;
        bool _fWasAsMouseBeforeSemanticZoom;

    public:
        void __local_vftable_ctor_closure();
    };
}
