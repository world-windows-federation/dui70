#pragma once

namespace DirectUI
{
	typedef ProviderProxy*(CALLBACK *PfnCreateProxy)(Element*);

	class UILIB_API InvokeHelper : public RefcountBase
	{
	public:
		InvokeHelper();

		~InvokeHelper() override;

		int Init(ULONG idThread);
		void Uninit();

		HRESULT DoInvoke(MethodId methodId, ElementProvider* pElementProvider, PfnCreateProxy pfnCreate, va_list args);

		struct InvokeArgs
		{
			InvokeArgs(MethodId methodId, ElementProvider* pElementProvider, PfnCreateProxy pfnCreate, va_list args);

			MethodId _methodId;
			HRESULT _hr;
			PfnCreateProxy _pfnCreate;
			ElementProvider* _pElementProvider;
			va_list _args;
		};

	private:
		static const UINT s_uInvokeHelperMsg;

		static int WINAPI _WndProc(void* pThis, HWND hwnd, UINT nMsg, WPARAM wParam, LPARAM lParam, LRESULT* plRet);
		void OnInvoke(InvokeArgs* pInvokeArgs);

		ULONG _idThread;
		HWND _hwnd;
	};


	class UILIB_API InvokeManager
	{
	public:
		static HRESULT WINAPI GetInvokeHelper(InvokeHelper** ppih);
		static void WINAPI CloseThread();

		static HRESULT WINAPI Init();
		static void WINAPI Close();

	private:
		static InvokeHelper* WINAPI FindInvokeHelper(UINT* idThread); // @NOTE: Last arg is either named this or 'ppih', I couldn't find a clear answer

		static UiaArray<InvokeHelper*>* g_pArrayInvokeHelper;
		static CRITICAL_SECTION g_cs;
	};
}
