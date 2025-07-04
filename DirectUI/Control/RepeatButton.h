#pragma once

namespace DirectUI
{
	class UILIB_API RepeatButton : public Button
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
		static HRESULT WINAPI Create(UINT nActive, Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		void OnInput(InputEvent* pie) override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		RepeatButton();
		RepeatButton(const RepeatButton& other) = default;

		HRESULT Initialize(UINT nActive, Element* pParent, DWORD* pdwDeferCookie);

		~RepeatButton() override;

		void SetStopThumbBehavior();

	private:
		static void _RepeatButtonActionCallback(GMA_ACTIONINFO* pmai);

		HACTION _hAction;
		BOOL _fActionDelay;
		BOOL _fStopThumbBehavior;
	};
}
