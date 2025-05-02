#pragma once

namespace DirectUI
{
	class UILIB_API RefcountBase
	{
	public:
		RefcountBase();

	private:
		RefcountBase(const RefcountBase&) = delete;
		RefcountBase& operator=(const RefcountBase&) = delete;

	public:
		virtual ~RefcountBase();

		long AddRef();
		long Release();

	private:
		long _refCount;
	};
}
