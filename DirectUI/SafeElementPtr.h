#pragma once

template <typename T>
class CSafeElementPtrBase : protected DirectUI::IElementListener
{
public:
    operator T*() const { return _pe; }
    T* operator->() const { return _pe; }
    bool operator!() const { return !_pe; }
    bool operator!=(T* pe) const { return _pe != pe; }
    bool operator==(T* pe) const { return _pe == pe; }

    CSafeElementPtrBase(const CSafeElementPtrBase& other) = delete;

protected:
    CSafeElementPtrBase()
        : _pe(nullptr)
    {
    }

    CSafeElementPtrBase(int)
    {
        // Function body unknown
    }

    HRESULT _Assign(T* pe)
    {
        HRESULT hr = E_INVALIDARG;
        if (pe)
        {
            _pe = pe;
            hr = pe->AddListener(this);
            if (FAILED(hr))
            {
                _pe = nullptr;
            }
        }

        return hr;
    }

    void OnListenerAttach(DirectUI::Element* peFrom) override {}
    void OnListenerDetach(DirectUI::Element* peFrom) override { if (_pe) _pe = nullptr; }
    bool OnListenedPropertyChanging(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew) override { return true; }
    void OnListenedPropertyChanged(DirectUI::Element* peFrom, const DirectUI::PropertyInfo* ppi, int iIndex, DirectUI::Value* pvOld, DirectUI::Value* pvNew) override {}
    void OnListenedInput(DirectUI::Element* peFrom, DirectUI::InputEvent* pInput) override {}
    void OnListenedEvent(DirectUI::Element* peFrom, DirectUI::Event* pEvent) override {}

    T* _pe;

private:
    T** operator&() = delete;
};

template <typename T>
class CSafeElementPtr : public CSafeElementPtrBase<T>
{
    CSafeElementPtr(T* pe)
    {
        this->_Assign(pe); // Function body assumed
    }

    CSafeElementPtr(const CSafeElementPtr&) = delete;

public:
    CSafeElementPtr()
    {
    }

    CSafeElementPtr(int)
    {
        // Function body unknown
    }

    ~CSafeElementPtr()
    {
        Unassign();
    }

    HRESULT Assign(T* pe)
    {
        Unassign();
        return this->_Assign(pe);
    }

    void Unassign()
    {
        if (this->_pe)
        {
            this->_pe->RemoveListener(this);
            this->_pe = nullptr;
        }
    }

    void DestroyAndUnassign()
    {
        if (this->_pe)
        {
            this->_pe->Destroy(true);
        }
        Unassign();
    }

    CSafeElementPtr* AddressOfClass()
    {
        return this;
    }
};
