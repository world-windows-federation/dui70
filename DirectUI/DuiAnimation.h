#pragma once

namespace DirectUI
{
	enum PVLANIMATIONDIRECTION
	{
		PANI_DIR_LEFT = 1,
		PANI_DIR_RIGHT = 2,
		PANI_DIR_TOP = 3,
		PANI_DIR_BOTTOM = 4
	};

	enum PVLANIMATIONHINTVALUE
	{
		PANI_HINT_INT = 1,
		PANI_HINT_ELEMENT = 2
	};

	enum PVLANIMATIONSTATE
	{
		PANI_STATE_SELECTDOWN = 1,
		PANI_STATE_SELECTUP = 2,
		PANI_STATE_SELECTREVEAL = 3,
		PANI_STATE_DOWN = 4,
		PANI_STATE_UP = 5,
		PANI_STATE_IN = 6,
		PANI_STATE_OUT = 7,
		PANI_STATE_FULL = 8,
		PANI_STATE_IN_LONG = 9,
		PANI_STATE_OUT_LONG = 10,
		PANI_STATE_OUT_LEAVE_VISIBLE = 11
	};

	struct SafeElementIndexPair
	{
		CSafeElementPtr<Element> spElement;
		UINT uIndex;
		SafeElementIndexPair();
		~SafeElementIndexPair();
	};

	struct ElementGadgetTicketPair
	{
		HGADGET hgad;
		CSafeElementPtr<Element> speTarget;
		DWORD dwTicket;
		ElementGadgetTicketPair();
		~ElementGadgetTicketPair();
	};

	struct PANI_FromToElement
	{
		Element* peFrom;
		Element* peTo;
	};

	struct PANI_FromToInt
	{
		int nFrom;
		int nTo;
	};

	union PANI_FromTo
	{
		PANI_FromToInt nVal;
		PANI_FromToElement pElemVal;
	};

	struct PANI_FromToValue
	{
		PVLANIMATIONHINTVALUE type;
		PANI_FromTo ftv;
	};

	struct POINTFLOAT3D
	{
		float x;
		float y;
		float z;
	};

	struct PVLAnimationZOrder
	{
		bool fUseCustomZOrder;
		DWORD dwZOrder;
	};

	struct PVLAnimationSkew
	{
		bool fInitSkew;
		bool fOriginSkew;
		POINTFLOAT ptflInitSkew;
		POINTFLOAT ptflSkew;
		POINTFLOAT ptflOriginSkew;
	};

	struct PVLAnimationSize
	{
		bool fInitSize;
		SIZE szInit;
		SIZE szDest;
	};

	struct PVLAnimationAlpha
	{
		bool fInitAlpha;
		float flInit;
		float flDest;
	};

	struct PVLAnimationClip
	{
		bool fInitClip;
		POINTFLOAT ptflInitialTopLeft;
		POINTFLOAT ptflInitialBottomRight;
		POINTFLOAT ptflFinalTopLeft;
		POINTFLOAT ptflFinalBottomRight;
	};

	struct ClipRectWithElement : PVLAnimationClip
	{
		CSafeElementPtr<Element> speTarget;
		ClipRectWithElement();
		~ClipRectWithElement();
	};

	struct PVLAnimationRotation
	{
		bool fInitRotation;
		bool fOriginRotation;
		float flInitRotation;
		float flRotation;
		POINTFLOAT ptflOriginRotation;
	};

	struct PVLAnimationRotation3D
	{
		bool fInitRotation3D;
		bool fOriginRotation3D;
		POINTFLOAT3D ptfl3dInitRotation;
		POINTFLOAT3D ptfl3dRotation;
		POINTFLOAT3D ptfl3dOriginRotation;
	};

	struct PVLAnimationTranslation
	{
		bool fInitTranslation;
		POINT ptInit;
		POINT ptDest;
		bool fUseAsOffset;
		bool fChopStart;
		bool fChopStop;
		UINT uiChopIndex;
		LONG lChopStart;
		LONG lChopStop;
	};

	struct PVLAnimationTranslation3D
	{
		bool fInitTranslation3D;
		POINTFLOAT3D ptfl3dInit;
		POINTFLOAT3D ptfl3dDest;
	};

	struct PVLAnimationScale
	{
		bool fInitScale;
		bool fOriginScale;
		POINTFLOAT ptflInit;
		POINTFLOAT ptflScale;
		POINTFLOAT ptflOrigin;
	};

	struct PVLAnimationNotifyEvent : Event
	{
		int iAnimationId;
		bool fTrapped;
		bool fNotifyComplete;
		DWORD dwCookie;
		bool fManualSB;
		int nManualSBID;
		int nInsertionIndex;
		bool fLauncherTriggered;
		PVLAnimationNotifyEvent();
	};

	struct PVLAnimationActionSpaceEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation, PVLAnimationRotation3D
	{
		int nAnimationOptions;
		CSafeElementPtr<Element> speNotify;
		CSafeElementPtr<Element> speLauncherCharm;
		CSafeElementPtr<Element> speLogoBackground;
		CSafeElementPtr<Element> speWash;
		CSafeElementPtr<Element> speLogoPane;
		CSafeElementPtr<Element> speLogoPaneVCrossbar;
		DEVICE_SCALE_FACTOR scaleFactor;
		PVLAnimationActionSpaceEvent();
		~PVLAnimationActionSpaceEvent();
	};

	struct PVLAnimationAddEvent : PVLAnimationNotifyEvent
	{
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelParents;
		DynamicArray<DynamicArray<SafeElementIndexPair*, 0>*, 0>* pdaToAdd;
		int nLayoutPos;
		bool fFilter;
		bool fIgnoreDelay;
		PVLAnimationAddEvent();
		~PVLAnimationAddEvent();
	};

	struct PVLAnimationBadgeUpdateEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speOldBadge;
		CSafeElementPtr<Element> speNewBadge;
		POINT ptOffset;
		PVLAnimationBadgeUpdateEvent();
		~PVLAnimationBadgeUpdateEvent();
	};

	struct PVLAnimationContentTransitionEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelSources;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelDests;
		CSafeElementPtr<Element> speParent;
		POINT ptOffset;
		int nLayoutPos;
		PVLAnimationContentTransitionEvent();
		~PVLAnimationContentTransitionEvent();
	};

	struct PVLAnimationCrossfadeEvent : PVLAnimationNotifyEvent
	{
		CSafeElementPtr<Element> speToFadeOut;
		CSafeElementPtr<Element> speToFadeIn;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelToFadeOut;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelToFadeIn;
		bool fCloneTransforms;
		bool fLayoutAlreadySet;
		bool fDestroy;
		bool fInplace;
		bool fCollection;
		PVLAnimationCrossfadeEvent();
		~PVLAnimationCrossfadeEvent();
	};

	struct PVLAnimationCustomDragDropScalingHintEvent : Event
	{
		bool fDrag;
		POINTFLOAT ptflScaleFactor;
		POINTFLOAT ptflScaleOrigin;
		PVLAnimationCustomDragDropScalingHintEvent();
	};

	struct PVLAnimationCustomReflowHintEvent : Event
	{
		Element* peToMove;
		POINT ptInitial;
		POINT ptDest;
		bool fRowChange;
		bool fColumnChange;
		bool fParentChange;
		bool fUseNewCoordinateSpace;
		bool fUseLinearReflow;
		bool fUseAbsoluteColumnNumbers;
		bool fClipInside;
		PANI_FromToValue ftvRowChange;
		PANI_FromToValue ftvColumnChange;
		PANI_FromToValue ftvParentChange;
		bool fUseNewScalingOrigin;
		POINTFLOAT ptflScalingOrigin;
		int nNumberOfTowersToSkip;
		int nMaxTowerHeight;
		POINT ptExtraPortalingDistance;
		int nStaggerOrder;
		PVLAnimationCustomReflowHintEvent();
	};

	struct PVLAnimationCustomTapHintEvent : Event
	{
		RECT rcTileBounds;
		PVLAnimationCustomTapHintEvent();
	};

	struct PVLAnimationDeleteEvent : PVLAnimationNotifyEvent
	{
		CSafeElementPtr<Element> speToDelete;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelToDelete;
		bool fCollection;
		bool fDestroy;
		bool fFilter;
		PVLAnimationDeleteEvent();
		~PVLAnimationDeleteEvent();
	};

	struct PVLAnimationDragEvent : PVLAnimationNotifyEvent, PVLAnimationScale, PVLAnimationClip
	{
		CSafeElementPtr<Element> speToDrag;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelRemaining;
		CSafeElementPtr<Element> speContent;
		CSafeElementPtr<Element> speAdornment;
		DynamicArray<ClipRectWithElement*, 0>* pTowerClippingRects;
		POINT ptContact;
		bool fUseCustomScale;
		bool fAnimatingTowerClip;
		PVLAnimationDragEvent();
		~PVLAnimationDragEvent();
	};

	struct PVLAnimationDropEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation, PVLAnimationScale, PVLAnimationClip
	{
		CSafeElementPtr<Element> speToDrop;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelRemaining;
		CSafeElementPtr<Element> speContent;
		CSafeElementPtr<Element> speAdornment;
		DynamicArray<ClipRectWithElement*, 0>* pTowerClippingRects;
		CSafeElementPtr<Element> speParent;
		int nIndex;
		int nLayoutPos;
		bool fUseCustomScale;
		bool fAnimatingTowerClip;
		PVLAnimationDropEvent();
		~PVLAnimationDropEvent();
	};

	struct PVLAnimationEntranceEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelToEnter;
		DynamicArray<POINT, 0>* pdaOffsets;
		PVLAnimationEntranceEvent();
		~PVLAnimationEntranceEvent();
	};

	struct PVLAnimationExpandCollapseEvent : PVLAnimationNotifyEvent, PVLAnimationClip
	{
		CSafeElementPtr<Element> speToChange;
		CSafeElementPtr<Element> speAdditional;
		CSafeElementPtr<Element> speContainer;
		bool fExpand;
		int nLayoutPos;
		bool fConsiderAsClip;
		bool fInterruptCollapse;
		PVLAnimationExpandCollapseEvent();
		~PVLAnimationExpandCollapseEvent();
	};

	struct PVLAnimationFadeEvent : PVLAnimationNotifyEvent, PVLAnimationAlpha
	{
		CSafeElementPtr<Element> speToFade;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelToFade;
		bool fCollection;
		bool fLeaveElementsVisible;
		int nOrderNumber;
		PVLAnimationFadeEvent();
		~PVLAnimationFadeEvent();
	};

	struct PVLAnimationLaunchEvent : PVLAnimationNotifyEvent, PVLAnimationScale
	{
		CSafeElementPtr<Element> speToLaunch;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelRemaining;
		PVLAnimationLaunchEvent();
		~PVLAnimationLaunchEvent();
	};

	struct PVLAnimationLauncherEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation, PVLAnimationScale, PVLAnimationZOrder
	{
		bool fLaunch;
		UINT uiVersion;
		CSafeElementPtr<Element> speLauncher;
		CSafeElementPtr<Element> speLauncherContent;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelTowers;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelGroupHeaders;
		CSafeElementPtr<Element> speStartText;
		CSafeElementPtr<Element> speUserTile;
		CSafeElementPtr<Element> speSortDropdown;
		CSafeElementPtr<Element> speSearchBox;
		POINT ptOffsetLauncher;
		POINT ptOffsetTower;
		PVLAnimationLauncherEvent();
		~PVLAnimationLauncherEvent();
	};

	struct PVLAnimationManualStoryboard : PVLAnimationNotifyEvent
	{
		int nCode;
		int nManualStoryboardId;
		CSafeElementPtr<Element> speFinishNotify;
		bool fVerified;
		PVLAnimationManualStoryboard();
		~PVLAnimationManualStoryboard();
	};

	struct PVLAnimationMoveEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speToMove;
		CSafeElementPtr<Element> speParent;
		CSafeElementPtr<Element> speCurrentParent;
		int nIndex;
		bool fTopMost;
		PVLAnimationMoveEvent();
		~PVLAnimationMoveEvent();
	};

	struct PVLAnimationNotifyCompleteEvent : PVLAnimationNotifyEvent
	{
		int iStoryboardId;
		PVLAnimationNotifyEvent* panEvent;
		bool fForceUpdateIfDumped;
		CSafeElementPtr<Element> speNotify;
		PVLAnimationNotifyCompleteEvent();
		~PVLAnimationNotifyCompleteEvent();
	};

	struct PVLAnimationNudgeEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelToNudge;
		DynamicArray<POINT, 0>* pdaOffsets;
		PVLAnimationNudgeEvent();
		~PVLAnimationNudgeEvent();
	};

	struct PVLAnimationParentChangeEvent : PVLAnimationNotifyEvent
	{
		CSafeElementPtr<Element> speReparentTarget;
		CSafeElementPtr<Element> speOldParent;
		CSafeElementPtr<Element> speNewParent;
		PVLAnimationParentChangeEvent();
		~PVLAnimationParentChangeEvent();
	};

	struct PVLAnimationPopEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speToPop;
		CSafeElementPtr<Element> speParent;
		POINT ptOffset;
		bool fLayoutAlreadySet;
		bool fUseCurrentOpacity;
		PVLAnimationPopEvent();
		~PVLAnimationPopEvent();
	};

	struct PVLAnimationReflowEvent : PVLAnimationNotifyEvent, PVLAnimationSize
	{
		CSafeElementPtr<Element> speContainer;
		bool fUseNewSize;
		PVLAnimationReflowEvent();
		~PVLAnimationReflowEvent();
	};

	struct PVLAnimationReflowStyleEvent : Event
	{
		bool fFoundReflowStyle;
		bool fSetReflowStyle;
		int nNewReflowStyle;
		int nCurrentReflowStlye;
		PVLAnimationReflowStyleEvent();
	};

	struct PVLAnimationRepositionEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speToMove;
		bool fReverse;
		int nOrderNumber;
		UINT uiVersion;
		UINT uiState;
		int nReflowStyle;
		CSafeElementPtr<Element> speAttached;
		bool fProcessed;
		DirectUI::ElementGadgetTicketPair* pegtpValidation;
		PVLAnimationRepositionEvent();
		~PVLAnimationRepositionEvent();
	};

	struct PVLAnimationResizeEvent : PVLAnimationNotifyEvent, PVLAnimationSize
	{
		CSafeElementPtr<Element> speToResize;
		bool fReverse;
		PVLAnimationResizeEvent();
		~PVLAnimationResizeEvent();
	};

	struct PVLAnimationRevealHideEvent : PVLAnimationNotifyEvent, PVLAnimationClip
	{
		CSafeElementPtr<Element> speTapped;
		CSafeElementPtr<Element> speOutline;
		CSafeElementPtr<Element> speBackground;
		CSafeElementPtr<Element> speContent;
		RECT rcContentClip;
		bool fReveal;
		PVLAnimationRevealHideEvent();
		~PVLAnimationRevealHideEvent();
	};

	struct PVLAnimationScaleEvent : PVLAnimationNotifyEvent, PVLAnimationScale
	{
		CSafeElementPtr<Element> speToScale;
		int nOrderNumber;
		int nCustomDuration;
		PVLAnimationScaleEvent();
		~PVLAnimationScaleEvent();
	};

	struct PVLAnimationSessionEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation, PVLAnimationScale, PVLAnimationZOrder
	{
		bool fLauncher;
		UINT uiVersion;
		bool fLogin;
		CSafeElementPtr<Element> speLauncher;
		CSafeElementPtr<Element> speLauncherContent;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelTowers;
		DynamicArray<CSafeElementPtr<Element>*, 0>* pspelGroupHeaders;
		CSafeElementPtr<Element> speStartText;
		CSafeElementPtr<Element> speUserTileIcon;
		CSafeElementPtr<Element> speUserTileText;
		POINT ptOffsetLauncher;
		POINT ptOffsetTower;
		POINT ptOffsetStartText;
		POINT ptOffsetUserTileIcon;
		POINT ptOffsetUserTileText;
		POINT ptGroupHeaderOffset;
		CSafeElementPtr<Element> speLoginUserTile;
		CSafeElementPtr<Element> speLoginUserText;
		POINT ptOffsetLogonUI;
		PVLAnimationSessionEvent();
		~PVLAnimationSessionEvent();
	};

	struct PVLAnimationSlideEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speToSlide;
		CSafeElementPtr<Element> speParent;
		UINT uiState;
		UINT uiDir;
		UINT uiVersion;
		bool fLayoutAlreadySet;
		bool fAffected;
		bool fPositionAlreadySet;
		PVLAnimationSlideEvent();
		~PVLAnimationSlideEvent();
	};

	struct PVLAnimationSwipeEvent : PVLAnimationNotifyEvent, PVLAnimationTranslation
	{
		CSafeElementPtr<Element> speToSwipe;
		POINT ptOffset;
		CSafeElementPtr<Element> speCheckmark;
		PVLAnimationSwipeEvent();
		~PVLAnimationSwipeEvent();
	};

	struct PVLAnimationTapEvent : PVLAnimationNotifyEvent, PVLAnimationScale, PVLAnimationRotation3D
	{
		CSafeElementPtr<Element> speToTap;
		UINT uiState;
		UINT uiVersion;
		POINT ptContact;
		bool fSkipScaleTransform;
		PVLAnimationTapEvent();
		~PVLAnimationTapEvent();
	};

	MIDL_INTERFACE("0372C617-AEB1-4BCC-8703-DAD13E0C7D8A")
	IDuiAnimationTriggers : IUnknown
	{
		virtual HRESULT STDMETHODCALLTYPE TriggerDelete(Element* peToDelete, bool fDestroy, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerAdd(Element* peToAdd, Element* peParent, UINT uIndex, int nLayoutPos, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerExpand(Element* peToExpand, Element* peAdditional, int nLayoutPos, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerCollapse(Element* peToCollapse, Element* peAdditional, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerSlide(UINT uiVersion, Element* peToSlide, Element* peParent, UINT uiState, UINT uiDir, POINT ptMove, bool fLayoutAlreadySet, bool fAffected, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerFade(Element* peToFade, UINT uiState, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerTap(Element* peToTap, UINT uiState, POINT ptContact, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerDrag(Element* peToDrag, DynamicArray<Element*, 0>* pelRemaining, UINT uiState, POINT ptContact, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerDrop(Element* peToDrop, DynamicArray<Element*, 0>* pelRemaining, Element* peParent, int nIndex, int nLayoutPos, POINT ptDest, bool fUseCustomScale, POINTFLOAT ptflScaleTo, POINTFLOAT ptflScaleOrigin, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerReveal(Element* peTapped, Element* peOutline, Element* peBackground, Element* peContent, const RECT* prcContentClipFrom, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerHide(Element* peTapped, Element* peOutline, Element* peBackground, Element* peContent, const RECT* prcContentClipTo, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerReflow(Element* peContainer, bool fUseNewSize, SIZE* pszDest, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerResize(Element* peToResize, SIZE szDest, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerReposition(Element* peToMove, POINT ptDest, bool fReverse, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerMove(Element* peToMove, Element* peParent, int nIndex, bool fTopMost, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerContentTransition(DynamicArray<Element*, 0>* pelSources, DynamicArray<Element*, 0>* pelDests, Element* peParent, POINT ptOffset, int nLayoutPos, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerPageTransition(DynamicArray<Element*, 0>* pelSources, DynamicArray<Element*, 0>* pelDests, Element* peParent, POINT ptOffset, int nLayoutPos, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerBadgeUpdate(Element* peOldBadge, Element* peNewBadge, POINT ptOffset, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerPop(Element* peToPop, Element* peParent, UINT uiState, POINT ptDest, POINT ptOffset, bool fLayoutAlreadySet, bool fUseCurrentOpacity, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerCrossfade(Element* peToFadeOut, Element* peToFadeIn, bool fCloneTransforms, bool fLayoutAlreadySet, bool fDestroy, bool fInplace, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerSwipe(Element* peToSwipe, UINT uiState, POINT ptOffset, Element* peCheckmark, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerShowTileNotification(Element* peOutgoing, POINT ptOutgoingDest, Element* peIncoming, POINT ptIncomingDest, UINT uTileNotificationOption, Element* peLogo, Element* peDisplayName, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerPeekTileNotification(Element* peTargetMessage, POINT ptDest, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerDeleteGroup(DynamicArray<Element*, 0>* pelToDelete, bool fDestroy, bool fFilter, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerAddGroup(DynamicArray<Element*, 0>* pelToAdd, Element* peParent, DynamicArray<UINT, 0>* pdaIndices, int nLayoutPos, bool fFilter, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerAddGroupMultiParent(DynamicArray<Element*, 0>* pelParents, DynamicArray<DynamicArray<ElementIndexPair*, 0>*, 0>* pdaToAdd, int nLayoutPos, bool fFilter, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerFadeGroup(DynamicArray<Element*, 0>* pelToFade, UINT uiState, DWORD* pdwCOokie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerEntrance(DynamicArray<Element*, 0>* pelToEnter, DynamicArray<POINT, 0>* pdaOffsets, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerNudge(DynamicArray<Element*, 0>* pelToNudge, DynamicArray<POINT, 0>* pdaOffsets, UINT uiState, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerBeginStoryboard(Element* peTrapElement, int* pnStoryboardId, DWORD* pdwCookie) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerEndStoryboard(Element* peTrapElement, int nStoryboardId) = 0;
		virtual HRESULT STDMETHODCALLTYPE TriggerCancelStoryboard(Element* peTrapElement, int nStoryboardId) = 0;
		virtual HRESULT STDMETHODCALLTYPE AddReposition(int nStoryboardId, Element* peToMove, POINT ptDest, int nOrderNumber, bool fReverse, UINT uiVersion, UINT uiState) = 0;
		virtual HRESULT STDMETHODCALLTYPE AddFade(int nStoryboardId, Element* peToFade, UINT uiState, int nOrderNumber) = 0;
		virtual HRESULT STDMETHODCALLTYPE AddScale(int nStoryboardId, Element* peToScale, POINTFLOAT ptflOrigin, POINTFLOAT ptflScale, int nOrderNumber) = 0;
		virtual HRESULT STDMETHODCALLTYPE AddInputPaneSlide(int nStoryboardId, Element* peToSlide, const POINT* pptInit, const POINT* pptDest, const RECT* prcInputPane, int, int iInputPaneDeltaY) = 0;
	};
}
