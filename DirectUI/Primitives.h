#pragma once

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
		HICON hCursor;
	};

	struct Graphic
	{
		HANDLE hImage;
		HANDLE hAltImage;
		USHORT cx;
		USHORT cy;

		struct
		{
			BYTE dImgType: 3;
			BYTE dMode: 4;
			bool bFlip: 1;
			bool bRTLGraphic: 1;
			bool bFreehImage: 1;
			bool bSharedResource: 1;
			
			union
			{
				BYTE dAlpha;
				struct
				{
					BYTE r: 8;
					BYTE g: 8;
					BYTE b: 8;
				} rgbTrans;
			};
		} BlendMode;
		
		HINSTANCE hResLoad;
		const WCHAR* lpszName;
		//ScaledSIZE scaledSize; //TODO: Implement DirectUI::ScaledSIZE
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
		const int *pValidValues;
		const DirectUI::EnumMap* pEnumMaps;
		DirectUI::Value* (*DefaultProc)();
		DirectUI::PropertyInfoData* pData;
	};

	struct DepRecs
	{
		int iDepPos;
		int cDepCnt;
	};

	struct UILIB_API NavReference
	{
	public:
		NavReference() = delete;
		NavReference(const NavReference&) = delete;
		~NavReference() = delete;

		void Init(Element* pe, RECT*);
		NavReference& operator=(NavReference const &);
	};
}