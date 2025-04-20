#pragma once

namespace DirectUI
{
	class Viewer;

	class UILIB_API BaseScrollBar
	{
	public:
		static UID WINAPI Scroll();

		virtual Element* GetElement() = 0;

		bool OnPositionChanging(Value* pvNew);
		bool OnPageChanging(Value* pvNew);
		void OnPositionChanged(Value* pvNew);
		void OnMinimumChanged(Value* pvNew);
		void OnMaximumChanged(Value* pvNew);
		void OnPageChanged(Value* pvNew);

		virtual int GetPosition() = 0;
		virtual int GetMaximum() = 0;
		virtual int GetMinimum() = 0;
		virtual int GetPage() = 0;
		virtual int GetLine() = 0;

		virtual HRESULT SetPosition(int v) = 0;
		virtual HRESULT SetMaximum(int v) = 0;
		virtual HRESULT SetMinimum(int v) = 0;
		virtual HRESULT SetPage(int v) = 0;
		virtual HRESULT SetLine(int v) = 0;

		virtual bool GetProportional() = 0;

		virtual void LineUp(UINT nCount);
		virtual void LineDown(UINT nCount);
		virtual void PageUp(UINT nCount);
		virtual void PageDown(UINT nCount);
		virtual void Home();
		virtual void End();

		bool IsScrollable();
		bool IsPinned();
		void SetPinned(bool fPinned);
		int GetPageInc();

	private:
		bool _fPinned;
	};

	class UILIB_API BaseScrollViewer
		: public Element
		, public IElementListener
	{
	public:
		BaseScrollViewer();
		BaseScrollViewer(const BaseScrollViewer&) = default;

		~BaseScrollViewer() override;

		// ReSharper disable once CppHiddenFunction
		HRESULT Initialize(Element* pParent, DWORD* pdwDeferCookie);

		void OnEvent(Event* pEvent) override;
		void OnInput(InputEvent* pie) override;
		bool OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		HRESULT Add(Element** ppe, UINT cCount) override;

		//~ Begin DirectUI::IElementListener Interface
		void OnListenerAttach(Element* peFrom) override;
		void OnListenerDetach(Element* peFrom) override;
		bool OnListenedPropertyChanging(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnListenedInput(Element* peFrom, InputEvent* pInput) override;
		void OnListenedEvent(Element* peFrom, Event* pEvent) override;
		//~ End DirectUI::IElementListener Interface

		static const PropertyInfo* WINAPI XOffsetProp();
		static const PropertyInfo* WINAPI YOffsetProp();
		static const PropertyInfo* WINAPI XScrollableProp();
		static const PropertyInfo* WINAPI YScrollableProp();
		static const PropertyInfo* WINAPI XBarVisibilityProp();
		static const PropertyInfo* WINAPI YBarVisibilityProp();
		static const PropertyInfo* WINAPI PinningProp();

		int GetXOffset();
		int GetYOffset();
		bool GetXScrollable();
		bool GetYScrollable();
		int GetXBarVisibility();
		int GetYBarVisibility();
		int GetPinning();
		int GetXScrollHeight();
		int GetYScrollWidth();
		HRESULT SetXOffset(int v);
		HRESULT SetYOffset(int v);
		HRESULT SetXScrollable(bool v);
		HRESULT SetYScrollable(bool v);
		HRESULT SetXBarVisibility(int v);
		HRESULT SetYBarVisibility(int v);
		HRESULT SetPinning(int v);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();

	protected:
		Viewer* _peViewer;
		Element* _peContent;
		int _iLastLayoutPassShown;
		int _cLastLayoutPassShownCount;

		virtual HRESULT CreateScrollBars() = 0;
		virtual HRESULT AddChildren() = 0;
		virtual BaseScrollBar* GetHScroll() = 0;
		virtual BaseScrollBar* GetVScroll() = 0;

		void FireAnimationChangeEvent(bool fStart);

	private:
		int _iMouseWheelDeltaCarryOver;

		void CheckScroll(BaseScrollBar* psb, BOOL fScrollable, int iVisibility, BOOL fPreventLoop);
	};
}