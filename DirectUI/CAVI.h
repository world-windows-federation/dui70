#pragma once

namespace DirectUI
{
	class UILIB_API CCAVI : public CCBase
	{
	public:
		CCAVI();
		CCAVI(const CCAVI& other) = default;
		CCAVI(CCAVI&& other) noexcept = default;

		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;

		static HRESULT WINAPI Register();

		void Play(HWND hwnd);
		void Stop();

	protected:
		void PostCreate(HWND hwnd) override;

	private:
		void OpenAnimation(HWND hwnd);
	};
}
