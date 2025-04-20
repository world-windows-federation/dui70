#pragma once

namespace DirectUI
{
	class UILIB_API ScrollBar
		: public Element
		, public BaseScrollBar
	{
	public:
		static HRESULT WINAPI Create(bool, Element*, DWORD*, Element**);
		static HRESULT WINAPI Create(Element*, DWORD*, Element**);

		void OnEvent(Event* pEvent) override;
		bool OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void _SelfLayoutDoLayout(int cx, int cy) override;
		SIZE _SelfLayoutUpdateDesiredSize(int cxConstraint, int cyConstraint, Surface* psrf) override;

		static const PropertyInfo* WINAPI PositionProp();
		static const PropertyInfo* WINAPI MinimumProp();
		static const PropertyInfo* WINAPI MaximumProp();
		static const PropertyInfo* WINAPI PageProp();
		static const PropertyInfo* WINAPI LineProp();
		static const PropertyInfo* WINAPI VerticalProp();
		static const PropertyInfo* WINAPI ProportionalProp();
		static const PropertyInfo* WINAPI OrderProp();

		Element* GetElement() override;
		int GetPosition() override;
		int GetMaximum() override;
		int GetMinimum() override;
		int GetPage() override;
		int GetLine() override;

		HRESULT SetPosition(int v) override;
		HRESULT SetMaximum(int v) override;
		HRESULT SetMinimum(int v) override;
		HRESULT SetPage(int v) override;
		HRESULT SetLine(int v) override;

		bool GetProportional() override;
		int GetOrder();
		bool GetVertical();

		HRESULT SetOrder(int v);
		HRESULT SetProportional(bool v);
		HRESULT SetVertical(bool v);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		ScrollBar();
		ScrollBar(const ScrollBar&) = default;

		// ReSharper disable once CppHiddenFunction
		HRESULT Initialize(bool fBuildSubTree, Element* pParent, DWORD* pdwDeferCookie);

		~ScrollBar() override;

	protected:
		Element* _peParts[5];

		virtual HRESULT CreateButtons();

	private:
		int _posTop;
		int _cTrack;
	};

	class UILIB_API ScrollBarRangeValueProxy : public RangeValueProxy
	{
	public:
		ScrollBarRangeValueProxy();
		ScrollBarRangeValueProxy(const ScrollBarRangeValueProxy&) = default;
		ScrollBarRangeValueProxy(ScrollBarRangeValueProxy&&) noexcept = default;

		HRESULT DoMethod(MethodId methodId, va_list args) override;

	protected:
		void Init(Element* pe) override;
	};
}
