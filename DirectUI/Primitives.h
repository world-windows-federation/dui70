#pragma once

typedef DirectUI::Value* (WINAPI *DefaultValueProcT)();

namespace DirectUI
{
	struct Fill
	{
		BYTE dType;

		union
		{
			struct
			{
				COLORREF cr;
				COLORREF cr2;
				COLORREF cr3;
			} ref;

			struct
			{
				UINT uType;
				UINT uState;
			} fillDFC;

			struct
			{
				WCHAR* pszClassName;
				int iPartId;
				int iStateId;
			} fillDTB;
		};
	};

	struct Cursor
	{
		HCURSOR hCursor;
	};

	struct Graphic
	{
		HANDLE hImage;
		HANDLE hAltImage;
		USHORT cx;
		USHORT cy;

		struct
		{
			BYTE dImgType : 3;
			BYTE dMode : 4;
			bool bFlip : 1;
			bool bRTLGraphic : 1;
			bool bFreehImage : 1;
			bool bSharedResource : 1;

			union
			{
				BYTE dAlpha;

				struct
				{
					BYTE r : 8;
					BYTE g : 8;
					BYTE b : 8;
				} rgbTrans;
			};
		} BlendMode;

		HINSTANCE hResLoad;
		const WCHAR* lpszName;
		ScaledSIZE scaledSize;
		float fScaleFactor;
	};


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
		long _cRef;
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

	struct UILIB_API NavReference
	{
		void Init(Element* pe, RECT* prc);

		UINT cbSize;
		Element* pe;
		RECT* prc;
	};
}
