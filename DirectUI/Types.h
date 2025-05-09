#pragma once

typedef class UID (WINAPI *UIDPROC)();

class UID
{
public:
	// user defined ctor
	// to enable correct return by outptr sematics
	// https://learn.microsoft.com/en-us/cpp/build/x64-calling-convention?view=msvc-170#return-values
	UID() : _address(nullptr)
	{
	}

	UID(const BYTE* address) : _address(address)
	{
	}

	UID(UIDPROC proc) : _address(proc()._address)
	{
	}

	const BYTE* _address;
};

inline bool operator==(const UID& lhs, const UID& rhs)
{
	return lhs._address == rhs._address;
}

inline bool operator==(const UID& lhs, const UIDPROC& rhs)
{
	return lhs._address == rhs()._address;
}

//forward declares
namespace DirectUI
{
	template <typename T, typename U>
	struct _IsSame
	{
		static constexpr bool Value = false;
	};

	template <typename T>
	struct _IsSame<T, T>
	{
		static constexpr bool Value = true;
	};

	static_assert(_IsSame<wchar_t, unsigned short>::Value,
		"Please disable \"Treat WChar_t As Built in Type\" in the project settings. "
		"Disabling this is required as dui70.dll is compiled with this setting disabled, "
		"otherwise linking to dui70.dll functions using WCHAR will fail.");


	typedef class ProviderProxy* (CALLBACK *PfnCreateProxy)(class Element*);
	typedef int MethodId;


	struct ThemeChangedEvent
	{

	};

	class ElementProvider;
	class InvokeHelper;
	class Value;
	struct PropertyInfo;
}
