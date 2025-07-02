#pragma once

namespace DirectUI
{
	class UILIB_API Viewer : public Element
	{
	public:
		static HRESULT WINAPI Create(Element* peParent, DWORD* pdwDeferCookie, Element** ppElement);

		void OnEvent(Event* pEvent) override;
		void OnInput(InputEvent* pie) override;
		bool OnPropertyChanging(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;
		void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;

		void _SelfLayoutDoLayout(int cx, int cy) override;
		SIZE _SelfLayoutUpdateDesiredSize(int cxConstraint, int cyConstraint, Surface* psrf) override;

		static const PropertyInfo* WINAPI XOffsetProp();
		static const PropertyInfo* WINAPI YOffsetProp();
		static const PropertyInfo* WINAPI XScrollableProp();
		static const PropertyInfo* WINAPI YScrollableProp();

		int GetXOffset();
		int GetYOffset();
		bool GetXScrollable();
		bool GetYScrollable();

		HRESULT SetXOffset(int v);
		HRESULT SetYOffset(int v);
		HRESULT SetXScrollable(bool v);
		HRESULT SetYScrollable(bool v);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		bool EnsureVisible(int x, int y, int cx, int cy) override;

		Viewer();
		Viewer(const Viewer& other) = default;

		HRESULT Initialize(Element* pParent, DWORD* pdwDeferCooke);

		~Viewer() override;

		void SetEnsureVisibleUseLayoutCoordinates(bool fUseLayoutCoordinates);

	private:
		Element* _GetContent();
		bool _InternalEnsureVisible(int x, int y, int cx, int cy);

		bool _fEnsureVisibleUseLayoutCoordinates;
	};
}
