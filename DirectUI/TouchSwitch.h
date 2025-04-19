#pragma once

namespace DirectUI
{
    class TouchSwitch : public Element
    {
    public:
        TouchSwitch();
        TouchSwitch(const TouchSwitch& other) = delete;

        ~TouchSwitch() override;

        UILIB_API static HRESULT WINAPI Register();

        UILIB_API static IClassInfo* WINAPI GetClassInfoPtr();
        static void WINAPI SetClassInfoPtr(IClassInfo* pClass);

    private:
        static IClassInfo* s_pClassInfo;

    public:
        UILIB_API IClassInfo* GetClassInfoW() override;

        UILIB_API static HRESULT WINAPI Create(Element* pParent, DWORD* pdwDeferCookie, Element** ppElement);
        UILIB_API HRESULT Initialize(Element* pParent, DWORD* pdwDeferCookie);

        UILIB_API void SetOnOffText(const WCHAR* OnText, const WCHAR* OffText);
        UILIB_API void SetToggleSwitchText(const WCHAR* TitleText);

        UILIB_API static const PropertyInfo* WINAPI OnTextProp();
        UILIB_API const WCHAR* GetOnText(Value** ppv);
        UILIB_API HRESULT SetOnText(const WCHAR* psz);

        UILIB_API static const PropertyInfo* WINAPI OffTextProp();
        UILIB_API const WCHAR* GetOffText(Value** ppv);
        UILIB_API HRESULT SetOffText(const WCHAR* psz);

        UILIB_API static const PropertyInfo* WINAPI TitleTextProp();
        UILIB_API const WCHAR* GetTitleText(Value** ppv);
        UILIB_API HRESULT SetTitleText(const WCHAR* psz);

        static const PropertyInfo* WINAPI CurrentToggleValueProp();
        int GetCurrentToggleValue();
        HRESULT SetCurrentToggleValue(int v);

        UILIB_API void SetToggleValue(int ToggleValue); // Goes to last overload -> return SetToggleValue(ToggleValue, true, false)
        UILIB_API void SetToggleValue(int ToggleValue, bool RaiseEvent); // Goes to last overload -> return SetToggleValue(ToggleValue, RaiseEvent, false)
        UILIB_API void SetToggleValue(int ToggleValue, bool fRaiseEvent, bool fForce);

        UILIB_API int GetToggleValue();

        void OnEvent(Event* pEvent) override;
        void OnInput(InputEvent* pInput) override;
        void OnPropertyChanged(const PropertyInfo* ppi, int iIndex, Value* pvOld, Value* pvNew) override;

    private:
        void SetElementCustomString(Element* pElement, const WCHAR* pszValue);
        void SyncOnOffText();
        void _SetToggleValue(int ToggleValue);

        Element* _pContentElement;
        RichText* _pTitleElement;
        RichText* _pSignalElement;
        TouchSlider* _pTouchSlider;

        bool _fKeyDown;
    };
}
