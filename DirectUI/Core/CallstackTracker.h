#pragma once

/* 15363 */
typedef int (__stdcall *pfnImgHlp_SymFromAddr)(void*, unsigned __int64, unsigned __int64*, SYMBOL_INFO*);
/* 15397 */
typedef int (__stdcall *pfnImgHlp_SymInitialize)(void*, const char*, int);
/* 19129 */
typedef void (CALLBACK *PENUMFRAMESCALLBACK)(const char*, const char*, unsigned int, unsigned int);
/* 20151 */
typedef unsigned __int64 (__stdcall *pfnImgHlp_SymLoadModule64)(void*, void*, const char*, const char*, unsigned __int64, unsigned int);
/* 22689 */
typedef API_VERSION*(__stdcall *pfnImgHlp_ImagehlpApiVersionEx)(API_VERSION*);
/* 22869 */
typedef unsigned int (__stdcall *pfnImgHlp_SymSetOptions)(unsigned int);
/* 22944 */
typedef int (__stdcall *pfnImgHlp_SymGetModuleInfo64)(void*, unsigned __int64, IMAGEHLP_MODULE64*);
/* 23224 */
typedef unsigned __int16 (__stdcall *pfnNtDll_RtlCaptureStackBackTrace)(unsigned int, unsigned int, void**, unsigned int*);

namespace DirectUI
{
	class UILIB_API CallstackTracker
	{
	public:
		CallstackTracker();
		~CallstackTracker();

		int CaptureCallstackFrames();
		int EnumCallstackFrames(PENUMFRAMESCALLBACK pfnEnumFramesCallback);
		int Init();
		void Uninit();

	private:
		static const int INITIALSTACKSKIP;
		static const int STACKDEPTH;

		struct STACK_SYMBOL_INFO
		{
			DWORD_PTR dwOffset;
			char szModule[30];
			char szSymbol[MAX_PATH];
		};

		struct IMGHLPFN_LOAD
		{
			char* pszFnName;
			void** ppvfn;
		};

		UINT _cStackDepth;
		DWORD_PTR _dwEip[32];
		STACK_SYMBOL_INFO _asiSym[32];

		void FillSymbolInfo(STACK_SYMBOL_INFO* psi, DWORD_PTR dwAddr);
		DWORD_PTR GetModuleBase(HANDLE hProcess, DWORD_PTR dwAddr);

		static IMGHLPFN_LOAD s_ImageHlpFuncList[];
		static pfnNtDll_RtlCaptureStackBackTrace s_pfnRtlCaptureStackBackTrace;
		static pfnImgHlp_ImagehlpApiVersionEx s_pfnImagehlpApiVersionEx;
		static pfnImgHlp_SymGetModuleInfo64 s_pfnSymGetModuleInfo64;
		static pfnImgHlp_SymFromAddr s_pfnSymFromAddr;
		static pfnImgHlp_SymInitialize s_pfnSymInitialize;
		static pfnImgHlp_SymLoadModule64 s_pfnSymLoadModule64;
		static pfnImgHlp_SymSetOptions s_pfnSymSetOptions;

		static HINSTANCE s_hinstImageHlp;
		static HINSTANCE s_hinstNtDll;
		static RTL_RUN_ONCE s_initonceInit;
		static HANDLE s_hProcess;

		static BOOL WINAPI DllsLoaded();
		static int CALLBACK InitOnceCallback(RTL_RUN_ONCE*, void*, void**);
		static int WINAPI InitializeDllInfo();
		static BOOL WINAPI IsCorrectImageHlpVersion();
		static int WINAPI InitializeSymbols();
	};
}
