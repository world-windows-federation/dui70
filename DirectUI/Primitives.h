#pragma once

typedef DirectUI::Value* (WINAPI *DefaultValueProcT)();

namespace DirectUI
{
	struct EnumMap
	{
		const WCHAR* pszEnum;
		int nEnum;
	};

	struct PropertyInfoData
	{
		Value* _pvDefault;
		int _iIndex;
		int _iGlobalIndex;
		IClassInfo* _pciOwner;
		LONG _cRef;
	};

	struct PropertyInfo
	{
		const WCHAR* pszName;
		int fFlags;
		int fGroups;
		const int* pValidValues;
		const EnumMap* pEnumMaps;
		DefaultValueProcT DefaultProc;
		PropertyInfoData* pData;
	};

	struct DepRecs
	{
		int iDepPos;
		int cDepCnt;
	};
}
