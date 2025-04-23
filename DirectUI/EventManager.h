#pragma once

typedef void (WINAPI *PfnSetState)(VARIANT*);

namespace DirectUI
{
	struct RectangleChange
	{
		Element* _pe;
		RECT _rcOld;
		RECT _rcNew;
		bool _fOffScreenOld;
		bool _fOffScreenNew;
	};

	struct ElementRuntimeId
	{
		bool _fHwndElementSubclass;
		ULONGLONG _id;
	};

	class UILIB_API EventManager
	{
	public:
		static HRESULT WINAPI Init();
		static void WINAPI Close();
		static HRESULT WINAPI AdviseEventAdded(int id, SAFEARRAY* propertyIds);
		static HRESULT WINAPI AdviseEventRemoved(int id, SAFEARRAY* propertyIds);
		static HRESULT WINAPI OnToolTip(Element* pe, DWORD dwFlags);
		static void WINAPI DestroyListener(Element* pe);
		static HRESULT WINAPI PropertyListener(Element* pe, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew);
		static HRESULT WINAPI PropertyChangingListener(Element* pe, const PropertyInfo* ppi, bool* pfHandled);
		static HRESULT WINAPI EventListener(Element* pe, Event* pEvent);
		static HRESULT WINAPI EndDefer(Element* pe);
		static bool WINAPI FWantAnyEvent(Element* pe);
		static HRESULT WINAPI FireStructureChangedEvent(Element* pe, StructureChangeType type);
		static bool WINAPI WantEvent(Schema::Event event);

	private:
		static bool WINAPI WantEvent(Schema::Event e, int propertyId);

	public:
		static bool WINAPI WantPropertyEvent(int propertyId);

	private:
		static HRESULT WINAPI HandleAccChange(Element* pe, IRawElementProviderSimple* pprv, Value* pvOld, Value* pvNew);
		static HRESULT WINAPI HandleAccStateChange(IRawElementProviderSimple* pprv, UINT diff, UINT state, int id, VARIANT* pvarOld, VARIANT* pvarNew, bool fInvertValue);
		static HRESULT WINAPI HandleAccPatternChange(Element* pe, IRawElementProviderSimple* pprv, UINT diff, UINT state, int id, VARIANT* pvarOld, VARIANT* pvarNew, PfnSetState pfn); // @NOTE: Not sure on that typedef
		static HRESULT WINAPI HandleAccDesc(Element* pe, IRawElementProviderSimple* pprv, Value* pvOld, Value* pvNew);
		static HRESULT WINAPI HandleChildrenEvent(Element* pe, Value* pvOld, Value* pvNew);
		static HRESULT WINAPI HandleAccRoleEvent(IRawElementProviderSimple* pprv, Value* pvOld, Value* pvNew);
		static HRESULT WINAPI HandleScrollPos(Element* peScrollBar, IRawElementProviderSimple* pprv, Value* pvOld, Value* pvNew);
		static HRESULT WINAPI HandleBoolProp(Element* pe, bool (*)(Element*), IRawElementProviderSimple* pprv, int id, Value* pvOld, Value* pvNew);
		static HRESULT WINAPI HandleVisibilityChange(Element* pe, UINT diff);
		static HRESULT WINAPI HandleStringProp(IRawElementProviderSimple* pprv, int id, Value* pvOld, Value* pvNew);
		static HRESULT WINAPI HandleRangeValue(Element* pe, IRawElementProviderSimple* pprv, Value* pvOld, Value* pvNew);
		static HRESULT WINAPI HandleToggleValue(Element* pe, IRawElementProviderSimple* pprv, Value* pvOld, Value* pvNew);
		static HRESULT WINAPI GetString(VARIANT* pvar, Value* pv);
		static HRESULT WINAPI GetBool(VARIANT* pvar, Value* pv);
		static HRESULT WINAPI GetInt(VARIANT* pvar, Value* pv);
		static void WINAPI GetToggleState(VARIANT* pvar);
		static void WINAPI GetExpandCollapseState(VARIANT* pvar);
		static HRESULT WINAPI RaiseStructureChangedEvent(Element* pe, StructureChangeType type);
		static HRESULT WINAPI RaiseChildRemovedEvent(const ElementRuntimeId& runtimeId, Element* peParent);
		static HRESULT WINAPI RaiseGeometryEvents();
		static HRESULT WINAPI RaiseStructureEvents();
		static HRESULT WINAPI RaiseVisibilityEvents();
		static HRESULT WINAPI AddRectangleChange(Element* pe, bool fWantRect, bool fWantOffScreen);
		static HRESULT WINAPI RaiseGeometryEventWorker(RectangleChange* prc, bool fWantRect, bool fWantHorizontal, bool fWantVertical, bool fWantOffScreen);
		static HRESULT WINAPI HandleSelectedChange(IRawElementProviderSimple* pPrv, Value* pvNew);

		static UiaArray<int>* g_pArrayPropertyEvent;
		static UINT g_eventRegisteredMap[Schema::EventCount];
		static CRITICAL_SECTION g_cs;
		static bool g_fWantAnyEvent;
		static const int cChangeBulk = 25;
	};
}
