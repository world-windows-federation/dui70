#pragma once

namespace SWF
{
	class Fluster
	{
	};
}

namespace DirectUI
{
	class UILIB_API Movie : public Element
	{
	public:
		Movie();
		Movie(const Movie& other) = default;

		~Movie() override;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element*, DWORD* pdwDeferCookie, Element** ppElement);

		static UID WINAPI AdvanceFrame();

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		static const PropertyInfo* WINAPI PathProp();
		const WCHAR* GetPath(Value** ppv);
		HRESULT SetPath(const WCHAR* v);

		static const PropertyInfo* WINAPI AutoStartProp();
		bool GetAutoStart();
		HRESULT SetAutoStart(bool v);

		static const PropertyInfo* WINAPI AutoStopProp();
		bool GetAutoStop();
		HRESULT SetAutoStop(bool v);

		static const PropertyInfo* WINAPI RepeatProp();
		bool GetRepeat();
		HRESULT SetRepeat(bool v);

		static const PropertyInfo* WINAPI DrawOutlinesProp();
		bool GetDrawOutlines();
		HRESULT SetDrawOutlines(bool v);

		static const PropertyInfo* WINAPI CompositingQualityProp();
		int GetCompositingQuality();
		HRESULT SetCompositingQuality(int v);

		static const PropertyInfo* WINAPI InterpolationModeProp();
		int GetInterpolationMode();
		HRESULT SetInterpolationMode(int v);

		static const PropertyInfo* WINAPI PixelOffsetModeProp();
		int GetPixelOffsetMode();
		HRESULT SetPixelOffsetMode(int v);

		static const PropertyInfo* WINAPI PlayAllFramesModeProp();
		bool GetPlayAllFramesMode();
		HRESULT SetPlayAllFramesMode(bool v);

		static const PropertyInfo* WINAPI SmoothingModeProp();
		int GetSmoothingMode();
		HRESULT SetSmoothingMode(int v);

		void Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) override;
		void OnHosted(Element* peNewRoot) override;
		void OnEvent(Event* pEvent) override;
		void OnDestroy() override;

		static void WINAPI RawActionProc(GMA_ACTIONINFO* pActionInfo);
		void doAction(GMA_ACTIONINFO* pActionInfo);
		HRESULT LoadFromResource(HINSTANCE hinst, int iResourceId);
		HRESULT LoadFromPath(const WCHAR* pszPath);

		void Play();
		void Pause();
		void Resume();
		void Rewind();
		void Forward();

	private:
		void advanceFrameActionStart();
		void advanceFrameActionStop();

		SWF::Fluster* _pFluster;
		HACTION _action_handle;
		UINT _startFrame;
		DWORD _dwStartTick;
		UINT _currentFrame;
		ULONG _cMillisecPerFrame;
	};
}
