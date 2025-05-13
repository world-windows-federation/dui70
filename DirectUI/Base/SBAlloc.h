#pragma once

namespace DirectUI
{
	struct UILIB_API ISBLeak
	{
		virtual void OnAlloc(void*) = 0;
		virtual void OnFree(void*) = 0;
		virtual void OnLeakedAlloc(void*) = 0;
	};
}
