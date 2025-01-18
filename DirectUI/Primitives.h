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

	struct PropertyInfo
	{
		UCString name;
		UINT64 unk1;
		struct PropCapability {
			ValueType type : 6;
			UINT other : 26;
			UINT unk;
		} *cap;
		struct { UCString str_value; int int_value; } *enum_value_map;
		Value *(*get_default_value)();
		UINT64 *unk2;
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