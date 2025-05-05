#pragma once

namespace DirectUI
{
	class UILIB_API ResourceModuleHandles
	{
	public:
		ResourceModuleHandles();
		~ResourceModuleHandles();

		HRESULT GetHandle(LPCWSTR pszFile, HMODULE* phModule);

	private:
		static long volatile g_cRefCount;
	};
}
