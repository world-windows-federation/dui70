#pragma once

namespace DirectUI
{
	inline void* HAlloc(SIZE_T cbBlockSize)
	{
		return HeapAlloc(GetProcessHeap(), 0, cbBlockSize);
	}

	inline void* HReAlloc(void* p, SIZE_T s)
	{
		return HeapReAlloc(GetProcessHeap(), 0, p, s);
	}

	inline void HFree(void* pv)
	{
		HeapFree(GetProcessHeap(), 0, pv);
	}

	template <typename T>
	T* HNewAndZero()
	{
		T* p = (T*)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(T));
		if (p)
			new (p) T();
		return p;
	}

	template <typename T>
	T* HNew()
	{
		return HNewAndZero<T>();
	}

	template <typename T>
	void HDelete(T* p)
	{
		p->~T();
		HFree(p);
	}
}
