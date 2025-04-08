#pragma once

namespace DirectUI
{
	class UILIB_API AutoLock
	{
	public:
		AutoLock(RTL_CRITICAL_SECTION* pacs);
		~AutoLock();

	private:
		RTL_CRITICAL_SECTION* _pacs;
	};
}
