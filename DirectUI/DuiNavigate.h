#pragma once

namespace DirectUI
{
	class DuiNavigate
	{
	public:
		UILIB_API static Element* WINAPI Navigate(Element* peFrom, DynamicArray<Element*>* pelConsider, int nNavDir);
	};
}
