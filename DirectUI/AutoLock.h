#pragma once

namespace DirectUI
{
	class UILIB_API AutoLock
	{
	public:
		AutoLock(CRITICAL_SECTION* pacs);
		~AutoLock();

	private:
		CRITICAL_SECTION* _pacs;
	};
}
