#pragma once

namespace DirectUI
{
	struct Cond
	{
		const PropertyInfo* ppi;
		LogicalOperators nLogOp;
		Value* pv;
	};

	struct Decl
	{
		const PropertyInfo* ppi;
		Value* pv;
	};

	class UILIB_API StyleSheet
	{
	public:
		static HRESULT WINAPI Create(StyleSheet** ppSheet);

		virtual void Destroy() = 0;
		virtual HRESULT AddRule(const WCHAR* pszSheetResid, IClassInfo* pci, Cond* pConds, Decl* pDecls) = 0;
		virtual void MakeImmutable() = 0;
		virtual Value* GetSheetValue(Element* pe, const PropertyInfo* ppi) = 0;
		virtual void GetSheetDependencies(Element* pe, const PropertyInfo* ppi, DepRecs* pdr, DeferCycle* pdc, HRESULT* phr) = 0;
		virtual void GetSheetScope(Element* pe, DepRecs* pdr, DeferCycle* pdc, HRESULT* phr) = 0;
		virtual const WCHAR* GetSheetResid() = 0;
		virtual HRESULT SetSheetResid(const WCHAR* pszResid) = 0;
		virtual HRESULT SetBaseSheet(Value* pvSheet, UINT sheetId) = 0;
	};
}
