#pragma once

namespace DirectUI
{
	class UILIB_API XHost
	{
	public:
		XHost();
		~XHost();

		HRESULT Initialize(IXElementCP* pcp);
		static HRESULT WINAPI Create(IXElementCP* pcp, XHost** ppHost);
		void Destroy();

		HWND GetHWND();
		Element* GetElement();

		void Host(Element* pe);
		void ShowWindow(int iShow);
		void HideWindow();
		void DestroyWindow();

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	private:
		HWND _hWnd;
		Element* _pe;
	};
}
