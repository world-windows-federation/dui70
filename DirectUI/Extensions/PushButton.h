#pragma once


namespace DirectUI
{
	class UILIB_API PushButton : public AutoButton
	{
	public:
		static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);

		static const PropertyInfo* WINAPI EnforceSizeProp();
		bool GetEnforceSize();
		HRESULT SetEnforceSize(bool v);

		static UID WINAPI Hosted();

		SIZE GetContentSize(int cxConstraint, int cyConstraint, Surface* psrf) override;
		void OnHosted(Element* peNewHost) override;
		void OnUnHosted(Element* peOldHost) override;

		static IClassInfo* WINAPI GetClassInfoPtr();
		static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

	private:
		static IClassInfo* s_pClassInfo;

	public:
		IClassInfo* GetClassInfoW() override;
		static HRESULT WINAPI Register();

		enum
		{
			DLU_WIDTH = 50,
			DLU_HEIGHT = 14
		};

	private:
		void FireHostEvent(Element* peTarget, bool fHosted);
	};
}
