#pragma once

namespace DirectUI
{
	class UILIB_API FontCache
	{
	public:
		static HRESULT WINAPI InitProcess();
		static HRESULT WINAPI InitThread();
		static void WINAPI UninitProcess();
		static void WINAPI UninitThread();

		virtual HFONT CheckOutFont(LPCWSTR szFamily, int dSize, int dWeight, int dStyle, int dQuality, int dAngle);
		virtual void CheckInFont();
		virtual HBRUSH AcquireBrush(HBITMAP hbmp, HBRUSH hbrush);
		virtual void ReleaseBrush();
	};
}
