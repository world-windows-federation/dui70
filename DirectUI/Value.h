#pragma once

enum DynamicScaleValue
{
	DSV_None = 0x0,

	DSV_Int = 0x1,

	DSV_Float = 0x1,

	DSV_Left = 0x1,
	DSV_Top = 0x2,
	DSV_Right = 0x4,
	DSV_Bottom = 0x8,

	DSV_Height = 0x1,
	DSV_Width = 0x2,

	DSV_X = 0x1,
	DSV_Y = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(DynamicScaleValue);

namespace DirectUI
{
	struct ScaledSIZE : SIZE
	{
		DynamicScaleValue dynamicScaleValue;
	};

	struct ScaledInt
	{
		int i;
		DynamicScaleValue dynamicScaleValue;
	};

	struct ScaledFloat
	{
		float fl;
		DynamicScaleValue dynamicScaleValue;
	};

	struct ScaledRECT : RECT
	{
		DynamicScaleValue dynamicScaleValue;
	};

	struct ScaledPOINT : POINT
	{
		DynamicScaleValue dynamicScaleValue;
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
	public:
		Value& operator=(const Value&);

		void AddRef();

		static Value* WINAPI CreateAtom(ATOM atom);
		static Value* WINAPI CreateAtom(const WCHAR* pszValue);
		static Value* WINAPI CreateBool(bool bValue);
		static Value* WINAPI CreateColor(COLORREF cr);
		static Value* WINAPI CreateColor(COLORREF cr0, COLORREF cr1, BYTE dType);
		static Value* WINAPI CreateColor(COLORREF cr0, COLORREF cr1, COLORREF cr2, BYTE dType);
		static Value* WINAPI CreateCursor(HICON hValue);
		static Value* WINAPI CreateCursor(const WCHAR* pszValue);
		static Value* WINAPI CreateDFCFill(UINT uType, UINT uState);
		static Value* WINAPI CreateDTBFill(const WCHAR* pszClassName, int iPartId, int iStateId);
		static Value* WINAPI CreateElementList(DynamicArray<Element*, 0>* peListValue);
		static Value* WINAPI CreateElementRef(Element* pe);
		static Value* WINAPI CreateEncodedString(const WCHAR* pszValue);
		static Value* WINAPI CreateExpression(Expression* pexValue);
		static Value* WINAPI CreateFill(const struct Fill& Fill);

		static Value* WINAPI CreateGraphic(HBITMAP hBitmap, BYTE dBlendMode, UINT dBlendValue, bool bFlip, bool bRTL, bool bPreMultiplied);
		static Value* WINAPI CreateGraphic(HENHMETAFILE hEnhMetaFile, HENHMETAFILE hAltEnhMetaFile);
		static Value* WINAPI CreateGraphic(HICON hIcon, bool bFlip, bool bRTL, bool bShared);
		static Value* WINAPI CreateGraphic(ISharedBitmap* pBitmap, BYTE dBlendMode, UINT dBlendValue);
		static Value* WINAPI CreateGraphic(const WCHAR* pszICO, ScaledSIZE szDesired, HINSTANCE hResLoad, bool bFlip, bool bRTL);
		static Value* WINAPI CreateGraphic(const WCHAR* pszBMP, BYTE dBlendMode, UINT dBlendValue, int cx, int cy, HINSTANCE hResLoad, bool bFlip, bool bRTL);
		static Value* WINAPI CreateGraphic(const WCHAR* pszICO, int cxDesired, int cyDesired, HINSTANCE hResLoad, bool bFlip, bool bRTL);

		static Value* WINAPI CreateInt(int dValue, DynamicScaleValue dsv = DSV_None);
		static Value* WINAPI CreateLayout(class Layout*);
		static Value* WINAPI CreatePoint(int x, int y, DynamicScaleValue dsv = DSV_None);
		static Value* WINAPI CreateRect(int left, int top, int right, int bottom, DynamicScaleValue dsv = DSV_None);
		static Value* WINAPI CreateSize(int cx, int cy, DynamicScaleValue dsv = DSV_None);
		static Value* WINAPI CreateString(const WCHAR* pszValue, HINSTANCE hInstance);
		static Value* WINAPI CreateStyleSheet(StyleSheet* ppsValue);

		bool GetBool();
		struct Cursor* GetCursor();
		Element* GetElement();
		DynamicArray<Element*, 0>* GetElementList();
		Expression* GetExpression();
		const Fill* GetFill();
		struct Graphic* GetGraphic();
		void* GetImage(bool);
		int GetInt();
		Layout* GetLayout();
		const POINT* GetPoint();
		const RECT* GetRect();
		int GetRefCount() const;
		const SIZE* GetSize();
		const WCHAR* GetString();
		StyleSheet* GetStyleSheet();
		int GetType() const;

		ATOM GetAtom();
		static Value* WINAPI GetAtomZero();
		static Value* WINAPI GetBoolFalse();
		static Value* WINAPI GetBoolTrue();
		static Value* WINAPI GetColorTrans();
		static Value* WINAPI GetCursorNull();
		static Value* WINAPI GetElListNull();
		static Value* WINAPI GetElementNull();
		static Value* WINAPI GetExprNull();
		static Value* WINAPI GetIntZero();
		static Value* WINAPI GetLayoutNull();
		static Value* WINAPI GetNull();
		static Value* WINAPI GetPointZero();
		static Value* WINAPI GetRectZero();
		static Value* WINAPI GetSheetNull();
		static Value* WINAPI GetSizeZero();
		static Value* WINAPI GetStringNull();
		static Value* WINAPI GetUnavailable();
		static Value* WINAPI GetUnset();

		bool IsEqual(Value*);
		void Release();
		WCHAR* ToString(WCHAR* psz, UINT c) const;

	private:
		void _ZeroRelease();
		static HRESULT WINAPI StrDupW(const WCHAR* pszIn, WCHAR** pszOut);
	};

	class UILIB_API ValueProvider 
		: public PatternProvider<ValueProvider, IValueProvider, 12>
		, public IValueProvider
	{
	public:
		ValueProvider();

		ProviderProxyCall GetProxyCreator() override;

		//~ Begin IUnknown Interface
		STDMETHODIMP QueryInterface(REFIID riid, void** ppvObject) override;
		STDMETHODIMP_(ULONG) AddRef() override;
		STDMETHODIMP_(ULONG) Release() override;
		//~ End IUnknow Interface

		//~ Begin IValueProvider Interface
		STDMETHODIMP SetValue(LPCWSTR val) override;
		STDMETHODIMP get_Value(BSTR* pRetVal) override;
		STDMETHODIMP get_IsReadOnly(BOOL* pRetVal) override;
		//~ End IValueProvider Interface
	};

	class UILIB_API ValueProxy : IProxy
	{
	public:
		ValueProxy(ValueProxy const&);
		ValueProxy();
		ValueProxy& operator=(ValueProxy const&);
		static ValueProxy* WINAPI Create(Element* pe);
		static bool WINAPI IsPatternSupported(Element* pe);

		HRESULT DoMethod(int, char*) override = 0;

	protected:
		void Init(Element* pe) override = 0;

	private:
		HRESULT GetIsReadOnly(int*);
		HRESULT GetValue(WCHAR* pRetVal);
		HRESULT SetValue(unsigned short const*);
	};
}