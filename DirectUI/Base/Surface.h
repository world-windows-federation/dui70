#pragma once

namespace DirectUI
{
	class UILIB_API Surface
	{
	public:
		enum EType
		{
			stDC = 0
		};

		Surface();
		Surface(const Surface& other) = default;

		virtual ~Surface();

		virtual EType GetType() const = 0;
		static EType GetSurfaceType(UINT nSurfaceType);
		static UINT GetSurfaceType(EType type);
	};

	class UILIB_API DCSurface : public Surface
	{
	public:
		DCSurface(HDC hdc);
		DCSurface(const DCSurface& other) = default;

		~DCSurface() override;

		EType GetType() const override;

		HDC GetHDC();

	protected:
		HDC _hdc;
	};
}
