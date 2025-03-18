#pragma once

class CSafeElementProxy
{
public:
	ULONG AddRef()
	{
		return InterlockedIncrement(&_cRef);
	}

	ULONG Release()
	{
		ULONG cRef = InterlockedDecrement(&_cRef);
		if (cRef == 0 && this)
		{
			delete this;
		}
		return cRef;
	}

	UILIB_API static HRESULT WINAPI CreateInstance(DirectUI::Element* pe, CSafeElementProxy** ppProxy);
	UILIB_API void Detach();

	UILIB_API static HRESULT CALLBACK s_SyncCallback(HGADGET, void*, EventMsg* pmsg);

protected:
	~CSafeElementProxy()
	{
	}

public:
	CSafeElementProxy(const CSafeElementProxy&) = delete;

protected:
	CSafeElementProxy()
		: _hgSync(nullptr)
		, _cRef(1)
		, _dwUIThreadId(GetCurrentThreadId())
	{
		InitializeSRWLock(&_srwlock);
	}

	UILIB_API HRESULT Initialize(DirectUI::Element*);

private:
	HRESULT _InitDUserContext(HDCONTEXT* phCtx)
	{
		INITGADGET ig;
		ig.cbSize = sizeof(ig);
		ig.nThreadMode = 2;
		ig.nMsgMode = 3;
		ig.nPerfMode = 0;
		ig.hctxShare = nullptr;
		*phCtx = InitGadgets(&ig);
		return *phCtx ? S_OK : E_FAIL;
	}

	void _UnInitDUserContext(HDCONTEXT hCtx)
	{
		DeleteHandle(hCtx);
	}

	CSafeElementPtr<DirectUI::Element> _speAttached;
	HGADGET _hgSync;
	ULONG _cRef;
	DWORD _dwUIThreadId;
	RTL_SRWLOCK _srwlock;
};

template <typename T>
class CElementWithProxy : public T
{
public:
	CElementWithProxy()
		: _hrInit(HRESULT_FROM_WIN32(ERROR_NOT_READY))
		, _pProxy(nullptr)
	{
	}

	CElementWithProxy(const CElementWithProxy&) = default;

	~CElementWithProxy()
	{
		if (_pProxy)
		{
			_pProxy->Detach();
			_pProxy->Release();
		}
	}

protected:
	HRESULT _EnsureInitializedProxy()
	{
		if (_hrInit == HRESULT_FROM_WIN32(ERROR_NOT_READY))
		{
			_hrInit = CSafeElementProxy::CreateInstance(this, &_pProxy);
		}

		return _hrInit;
	}

	CSafeElementProxy* _GetProxy() const
	{
		return _pProxy;
	}

private:
	HRESULT _hrInit;
	CSafeElementProxy* _pProxy;
};
