#pragma once

namespace DirectUI
{
	class UILIB_API Progress : public Element
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		void Paint(HDC hDC, const RECT* prcBounds, const RECT* prcInvalid, RECT* prcSkipBorder, RECT* prcSkipContent) override;
		SIZE GetContentSize(int dConstW, int dConstH, Surface* psrf) override;

		static const PropertyInfo* WINAPI PositionProp();
		static const PropertyInfo* WINAPI MinimumProp();
		static const PropertyInfo* WINAPI MaximumProp();
		int GetPosition();
		int GetMaximum();
		int GetMinimum();
		HRESULT SetPosition(int v);
		HRESULT SetMaximum(int v);
		HRESULT SetMinimum(int v);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		Progress();
		Progress(const Progress& other) = default;

		HRESULT Initialize(Element* pParent, DWORD* pdwDeferCookie);
	};
}
