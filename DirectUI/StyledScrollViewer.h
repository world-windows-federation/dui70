#pragma once

namespace DirectUI
{
	class UILIB_API StyledScrollViewer : public BaseScrollViewer
	{
	public:
		StyledScrollViewer();
		StyledScrollViewer(const StyledScrollViewer& other) = default;
		~StyledScrollViewer() override;

		static HRESULT WINAPI Create(Element* peParent, DWORD* pdwDeferCookie, Element** ppElement);

		void OnListenedPropertyChanged(Element* peFrom, const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private :
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

	protected:
		HRESULT CreateScrollBars() override;
		HRESULT AddChildren() override;
		BaseScrollBar* GetHScroll() override;
		BaseScrollBar* GetVScroll() override;

	private :
		ScrollBar* _peHScroll;
		ScrollBar* _peVScroll;
	};
}
