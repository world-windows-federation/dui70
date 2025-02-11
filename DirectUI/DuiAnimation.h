#pragma once

namespace DirectUI
{
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
