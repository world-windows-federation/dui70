#pragma once

namespace DirectUI
{
	class UILIB_API Expression
	{
	public:
		Expression() = delete;
		Expression(const Expression&) = delete;
		~Expression() = delete;

		Expression& operator=(Expression const&);
		void Destroy();
	};
}
