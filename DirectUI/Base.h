#pragma once

namespace DirectUI
{
	class UILIB_API ClassInfoBase //: IClassInfo
	{
	public:
		ClassInfoBase(ClassInfoBase const &);
		ClassInfoBase();
		ClassInfoBase & operator=(ClassInfoBase const &);

		//0
		virtual void AddRef();
		//1
		virtual int Release();

		//2
		virtual HRESULT WINAPI CreateInstance(Element*, unsigned long*, Element** ) = 0;

		//3
		virtual const PropertyInfo* EnumPropertyInfo(unsigned int);
		//4
		virtual const PropertyInfo* GetByClassIndex(unsigned int);
		//5
		virtual unsigned int GetPICount() const;
		//6
		virtual unsigned int GetGlobalIndex() const;

		//NULL
		virtual IClassInfo* WINAPI GetBaseClass() = 0;

		//6
		virtual UCString GetName() const;
		//7
		virtual bool IsValidProperty(const PropertyInfo*) const;
		//8
		virtual bool IsSubclassOf(IClassInfo*) const;
		//9
		virtual void Destroy();
		//10
		virtual HINSTANCE GetModule() const;
		//11
		virtual bool IsGlobal() const;

		//12
		virtual void AddChild();
		//13
		virtual void RemoveChild();
		//14
		virtual int GetChildren() const;
		//15
		virtual void AssertPIZeroRef() const;

		virtual ~ClassInfoBase() ;

		static bool WINAPI ClassExist(IClassInfo**, const PropertyInfo* const*, unsigned int, IClassInfo*, HINSTANCE, UCString, bool);
		long Initialize(HINSTANCE, UCString name, bool hasPropertyInfo, const PropertyInfo* const* properties, unsigned int properties_count);
		long Register();
	//private:
		char data[0x10];
	};

	class Viewer;

	class UILIB_API BaseScrollBar
	{
	public:
		BaseScrollBar(BaseScrollBar const&);
		BaseScrollBar();
		BaseScrollBar& operator=(BaseScrollBar const&);
		//0
		virtual Element* GetElement() = 0;
		//1
		virtual int GetPosition() = 0;
		//2
		virtual int GetMaximum() = 0;
		//3
		virtual int GetMinimum() = 0;
		//4
		virtual int GetPage() = 0;
		//5
		virtual int GetLine() = 0;
		//6
		virtual long SetPosition(int) = 0;
		//7
		virtual long SetMaximum(int) = 0;
		//8
		virtual long SetMinimum(int) = 0;
		//9
		virtual long SetPage(int) = 0;
		//10
		virtual long SetLine(int) = 0;
		//11
		virtual bool CanSetFocus() = 0;
		//12
		virtual void LineUp(unsigned int);
		//13
		virtual void LineDown(unsigned int);
		//14
		virtual void PageUp(unsigned int);
		//15
		virtual void PageDown(unsigned int);
		//16
		virtual void End();
		//17
		virtual void Home();

		bool IsPinned();
		bool IsScrollable();
		void OnMaximumChanged(Value*);
		void OnMinimumChanged(Value*);
		void OnPageChanged(Value*);
		bool OnPageChanging(Value*);
		void OnPositionChanged(Value*);
		bool OnPositionChanging(Value*);
		static UID WINAPI Scroll();
		void SetPinned(bool);

	private:
		int GetPageInc();
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

		static const PropertyInfo* XOffsetProp();
		static const PropertyInfo* YOffsetProp();
		static const PropertyInfo* XScrollableProp();
		static const PropertyInfo* YScrollableProp();
		static const PropertyInfo* XBarVisibilityProp();
		static const PropertyInfo* YBarVisibilityProp();
		static const PropertyInfo* PinningProp();

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

		static IClassInfo* GetClassInfoPtr();
		static void SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT Register();

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