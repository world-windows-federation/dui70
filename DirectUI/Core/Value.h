#pragma once

namespace DirectUI
{
	enum PropertyFlags
	{
		PF_None = 0x0,
		PF_LocalOnly = 0x1,
		PF_Normal = 0x2,
		PF_TriLevel = 0x3,
		PF_Cascade = 0x4,
		PF_Inherit = 0x8,
		PF_ReadOnly = 0x10,
		PF_Cached = 0x20,
		PF_SkipNotify = 0x40,

		PF_TypeBits = 0x3,
	};

	DEFINE_ENUM_FLAG_OPERATORS(PropertyFlags);

	enum PropertyGroups
	{
		PG_None = 0x0,
		PG_AffectsDesiredSize = 0x1,
		PG_AffectsParentDesiredSize = 0x2,
		PG_AffectsLayout = 0x4,
		PG_AffectsParentLayout = 0x8,
		PG_AffectsBounds = 0x10000,
		PG_AffectsDisplay = 0x20000,
		PG_LayoutCompletion = 0x1000000,
		PG_NormalPriMask = 0xFFFF,
		PG_LowPriMask = 0xFF0000,
		PG_NotificationMask = 0xFF000000
	};

	DEFINE_ENUM_FLAG_OPERATORS(PropertyGroups);

	typedef DynamicArray<Value*> ValueList;

	class Layout;

	struct EncodedString
	{
		size_t cbBufferSize;
		WCHAR* pszEncoded;
	};

	enum class ValueType : int
	{
		Unavailable = -2,
		Unset = -1,
		Null = 0,
		Int = 1,
		Bool = 2,
		Element = 3,
		Ellist = 4,
		String = 5,
		Point = 6,
		Size = 7,
		Rect = 8,
		Color = 9,
		Layout = 10,
		Graphic = 11,
		Sheet = 12,
		Expr = 13,
		Atom = 14,
		Cursor = 15,
		Float = 18,
		DblList = 19,
	};

	class UILIB_API Value
	{
		int _dType : 6;
		int _fWeakRef : 1;
		int _cRef : 25;

		static constexpr int c_RefCountBitOffset = 7;
		static constexpr long c_SingleRefCount = 1 << c_RefCountBitOffset;
		static constexpr long c_RefCountMask = ~(c_SingleRefCount - 1);

		union
		{
			int _intVal;
			bool _boolVal;
			Element* _peVal;
			DynamicArray<Element*>* _peListVal;
			EncodedString _encodedStringVal;
			WCHAR* _pszVal;
			POINT _ptVal;
			SIZE _sizeVal;
			RECT _rectVal;
			Fill _fillVal;
			Layout* _plVal;
			Graphic* _pGraphicVal;
			StyleSheet* _ppsVal;
			Expression* _pexVal;
			ATOM _atomVal;
			Cursor _cursorVal;
			ValueList* _pvListVal;
			float _flVal;
			DynamicArray<double>* _pdblListVal;
			ScaledInt _scaledIntVal;
			ScaledFloat _scaledFloatVal;
			ScaledRECT _scaledRectVal;
			ScaledSIZE _scaledSizeVal;
			ScaledPOINT _scaledPointVal;
		};

		void _ZeroRelease();
		static HRESULT StrDupW(const WCHAR* pszIn, WCHAR** pszOut);

	public:
		static Value* WINAPI CreateInt(int dValue, DynamicScaleValue dsv = DSV_None);
		static Value* WINAPI CreateFloat(float flValue, DynamicScaleValue dsv = DSV_None);
		static Value* WINAPI CreateBool(bool bValue);
		static Value* WINAPI CreateElementRef(Element* peValue);
		static Value* WINAPI CreateElementList(DynamicArray<Element*>* peListValue);
		static Value* WINAPI CreateString(const WCHAR* pszValue, HINSTANCE hResLoad);
		static Value* WINAPI CreateEncodedString(const WCHAR* pszValue);
		static Value* WINAPI CreatePoint(int x, int y, DynamicScaleValue dsv = DSV_None);
		static Value* WINAPI CreateSize(int cx, int cy, DynamicScaleValue dsv = DSV_None);
		static Value* WINAPI CreateRect(int left, int top, int right, int bottom, DynamicScaleValue dsv = DSV_None);

		static Value* WINAPI CreateColor(COLORREF cr);
		static Value* WINAPI CreateColor(COLORREF cr0, COLORREF cr1, BYTE dType);
		static Value* WINAPI CreateColor(COLORREF cr0, COLORREF cr1, COLORREF cr2, BYTE dType);

		static Value* WINAPI CreateFill(const Fill& fill);
		static Value* WINAPI CreateDFCFill(UINT uType, UINT uState);
		static Value* WINAPI CreateDTBFill(const WCHAR* pszClassName, int iPartId, int iStateId);

		static Value* WINAPI CreateLayout(Layout* plValue);

		static Value* WINAPI CreateGraphic(ISharedBitmap* pBitmap, BYTE dBlendMode, UINT dBlendValue);
		static Value* WINAPI CreateGraphic(HBITMAP hBitmap, BYTE dBlendMode, UINT dBlendValue, bool bFlip, bool bRTL, bool bPremultiplied);
		static Value* WINAPI CreateGraphic(HICON hIcon, bool bFlip, bool bRTL, bool bShared);
		static Value* WINAPI CreateGraphic(const WCHAR* pszBMP, BYTE dBlendMode, UINT dBlendValue, USHORT cx, USHORT cy, HINSTANCE hResLoad, bool bFlip, bool bRTL);
		static Value* WINAPI CreateGraphic(const WCHAR* pszICO, USHORT cxDesired, USHORT cyDesired, HINSTANCE hResLoad, bool bFlip, bool bRTL);
		static Value* WINAPI CreateGraphic(HENHMETAFILE hEnhMetaFile, HENHMETAFILE hAltEnhMetaFile);
		static Value* WINAPI CreateGraphic(const WCHAR* pszICO, ScaledSIZE szDesired, HINSTANCE hResLoad, bool bFlip, bool bRTL);

	private:
		static Value* WINAPI CreateIconGraphicHelper(HICON hIcon, bool bFlip, bool bRTL, bool bShared);
		static HICON WINAPI ReloadIcon(Graphic* pGraphic, float fScaleFactor);

	public:
		static Value* WINAPI CreateStyleSheet(StyleSheet* ppsValue);
		static Value* WINAPI CreateExpression(Expression* pexValue);

		static Value* WINAPI CreateAtom(const WCHAR* pszValue);
		static Value* WINAPI CreateAtom(ATOM atom);

		static Value* WINAPI CreateCursor(const WCHAR* pszValue);
		static Value* WINAPI CreateCursor(HCURSOR hValue);

		static Value* WINAPI CreateValueList(ValueList* pvListValue);
		static Value* WINAPI CreateValueList(Value* pvValue);


		static Value* WINAPI CreateDoubleList(DynamicArray<double>* pdblListValue);
		static Value* WINAPI CreateDoubleList(const double* rgdbl, int cdbl);

		static Value* WINAPI CreateStringRP(const WCHAR* pszValue, HINSTANCE hResLoad);
		static Value* WINAPI CreateScaledValue(float flScaleFactor, Value* pvIn);
		static Value* WINAPI CreateElementScaledValue(Element* pe, Value* pvIn);

		void AddRef();
		void Release();
		int GetRefCount() const;

		int GetType() const;
		void* GetImage(bool bGetRTL, float fScaleFactor);

		int GetInt();

		ScaledInt* GetScaledInt();
		int GetScaledInt(float flScaleFactor);

		float GetFloat();
		bool GetBool();

		Element* GetElement();
		DynamicArray<Element*>* GetElementList();

		const WCHAR* GetString();
		HRESULT GetEncodedString(WCHAR* pszBuf, size_t cchBuf);
		size_t GetEncodedStringLength();

		const POINT* GetPoint();
		const SIZE* GetSize();
		const RECT* GetRect();
		const Fill* GetFill();

		Layout* GetLayout();
		Graphic* GetGraphic();
		StyleSheet* GetStyleSheet();
		Expression* GetExpression();
		ATOM GetAtom();
		Cursor* GetCursor();
		ValueList* GetValueList();
		DynamicArray<double>* GetDoubleList();
		WCHAR* GetStringDynamicScaling();

		int GetElementScaledInt(Element* pe);

		void GetScaledPoint(float flScaleFactor, POINT* ppt);
		void GetElementScaledPoint(Element* pe, POINT* ppt);

		void GetScaledSize(float flScaleFactor, SIZE* psize);
		void GetElementScaledSize(Element* pe, SIZE* psize);

		void GetScaledRect(float flScaleFactor, RECT* prc);
		void GetElementScaledRect(Element* pe, RECT* prc);

		float GetScaledFloat(float flScaleFactor);
		float GetElementScaledFloat(Element* pe);

		bool IsDynamicScaled();
		bool IsEqual(Value* pv);

		WCHAR* ToString(WCHAR* psz, UINT) const;
		void SetLayoutPointerToNull();

		static Value* WINAPI GetUnavailable();
		static Value* WINAPI GetNull();
		static Value* WINAPI GetUnset();
		static Value* WINAPI GetElementNull();
		static Value* WINAPI GetElListNull();
		static Value* WINAPI GetBoolTrue();
		static Value* WINAPI GetBoolFalse();
		static Value* WINAPI GetStringNull();
		static Value* WINAPI GetPointZero();
		static Value* WINAPI GetSizeZero();
		static Value* WINAPI GetRectZero();
		static Value* WINAPI GetIntZero();
		static Value* WINAPI GetIntMinusOne();
		static Value* WINAPI GetFloatZero();
		static Value* WINAPI GetFloatOne();
		static Value* WINAPI GetLayoutNull();
		static Value* WINAPI GetSheetNull();
		static Value* WINAPI GetExprNull();
		static Value* WINAPI GetAtomZero();
		static Value* WINAPI GetCursorNull();
		static Value* WINAPI GetColorTrans();
		static Value* WINAPI GetDblListEmpty();
		static Value* WINAPI GetStringRPNull();
	};

	struct _StaticValue
	{
		int _dType : 6;
		int _fWeakRef : 1;
		int _cRef : 25;
		int _val0;
		int _val1;
		int _val2;
		int _val3;
		DynamicScaleValue _dynamicScaleValue;
	};

	struct _StaticValuePtr
	{
		int _dType : 6;
		int _fWeakRef : 1;
		int _cRef : 25;
		void* _ptr;
	};

	struct _StaticValueFloat
	{
		int _dType : 6;
		int _fWeakRef : 1;
		int _cRef : 25;
		float _flVal;
		DynamicScaleValue _dynamicScaleValue;
	};

	struct _StaticValueColor
	{
		int _dType : 6;
		int _fWeakRef : 1;
		int _cRef : 25;
		BYTE dType;
		COLORREF cr;
		COLORREF cr2;
		COLORREF cr3;
	};
}
