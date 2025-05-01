#pragma once


namespace DirectUI
{
	class ModernProgressRing : public CElementWithProxy<Element>
	{
	public:
		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		ModernProgressRing();
		ModernProgressRing(const ModernProgressRing& other) = default;

		~ModernProgressRing() override;

		static const PropertyInfo* WINAPI ActivityOccuringProp();
		static const PropertyInfo* WINAPI AddLayeredRefProp();

		bool IsActivityOccuring();
		HRESULT SetActivityOccuring(bool v);

		bool IsAddLayeredRef();
		HRESULT SetAddLayeredRef(bool v);

		static HRESULT WINAPI Register();
		static HRESULT Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		HRESULT Initialize(UINT, Element*, DWORD*);

	protected:
		void OnDestroy() override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnHosted(Element* peNewRoot) override;
		void OnUnHosted(Element* peOldRoot) override;

		void Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) override;

		enum FUNCMODE
		{
			FUNCMODE_CIRCULAR_IN = 0,
			FUNCMODE_CIRCULAR_OUT = 1,
			FUNCMODE_STAY = 2
		};

		struct ANIMATIONTIMELINE
		{
			FUNCMODE mode;
			DWORD dwLowerTimePoint;
			DWORD dwUpperTimePoint;
			DWORD dwLowerPos;
			DWORD dwUpperPos;
		};

		struct RING_DESIGN_VALUES
		{
			int nMaxApplicableCanvasSize;
			float flBallSize;
			float flCircleRadius;
			DWORD dwBallTimeSpace;
			DWORD dwBallSpaceAngle;
			DWORD dwBallNum;
		};

		struct VERTEX
		{
			float x;
			float y;
		};

	private:
		void _TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);
		void _Start();
		void _Stop();
		void _AddLayeredRef();
		void _UpdateTimerState();

		static void s_GetAngleEndpoint(float flAngle, float flRadius, float* pflX, float* pflY);
		static float s_ComputeCircularFunc(float t, FUNCMODE mode);
		static ULONG s_PowerNotifyCallback(void* pvContext, ULONG ulType, void* pvSetting);

		DWORD _dwBallTimeSpace;
		VERTEX _rgCenter[6];
		ULONG_PTR _timerID;
		HWND _hwndTimer;
		HPOWERNOTIFY _hPowerNotify;
		MONITOR_DISPLAY_STATE _monitorDisplayState;
		LARGE_INTEGER _liFrequency;
		LARGE_INTEGER _rgStartTime[6];
		LONGLONG _llLastPaintDuration;
		ULONG _rgStartTickCount[6];
		bool _fSetRingInfoEvents;
		bool _fAddedLayeredRef;
		bool _fAnimationFinished;
		bool _fAnimationRunning;
		static const RING_DESIGN_VALUES c_rgRingDesignValues[];
		static const ANIMATIONTIMELINE c_rgAnimationCurves[];
	};
}
