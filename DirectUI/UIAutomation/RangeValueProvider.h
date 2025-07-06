#pragma once

namespace DirectUI
{
	class UILIB_API RangeValueProvider
		: public PatternProvider<RangeValueProvider, IRangeValueProvider, Schema::Pattern::RangeValue>
		, public IRangeValueProvider
	{
	public:
		RangeValueProvider(void);
		virtual ~RangeValueProvider(void);

		virtual unsigned long __stdcall AddRef(void);
		virtual PfnCreateProxy GetProxyCreator(void);
		virtual long __stdcall QueryInterface(GUID const &, void * *);
		virtual unsigned long __stdcall Release(void);
		virtual long __stdcall SetValue(double);
		virtual long __stdcall get_IsReadOnly(int *);
		virtual long __stdcall get_LargeChange(double *);
		virtual long __stdcall get_Maximum(double *);
		virtual long __stdcall get_Minimum(double *);
		virtual long __stdcall get_SmallChange(double *);
		virtual long __stdcall get_Value(double *);
	};

	class UILIB_API RangeValueProxy : public ProviderProxy
	{
	public:
		RangeValueProxy(RangeValueProxy const &);
		RangeValueProxy & operator=(RangeValueProxy const &);

		static RangeValueProxy * __stdcall Create(Element *);
		static bool __stdcall IsPatternSupported(Element *);
		
		virtual long DoMethod(int, char *);
	protected:
		RangeValueProxy(void);

		virtual void Init(Element *);

	};

	class UILIB_API ProgressRangeValueProxy : public RangeValueProxy
	{
	public:
		ProgressRangeValueProxy(ProgressRangeValueProxy const&);
		ProgressRangeValueProxy(void);
		ProgressRangeValueProxy& operator=(ProgressRangeValueProxy const&);

		virtual long DoMethod(int, char*);

	protected:
		virtual void Init(Element*);
	};
}