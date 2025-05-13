#pragma once

namespace DirectUI
{
	class UILIB_API LinkedListNode
	{
	public:
		LinkedListNode* pNext;
		LinkedListNode* pPrev;
	};

	class UILIB_API LinkedList
	{
	public:
		LinkedList();
		~LinkedList();

		void Add(LinkedListNode* pNode);
		void Remove(LinkedListNode* pNode);
		LinkedListNode* RemoveTail();

	private:
		LinkedListNode* pHead;
		LinkedListNode* pTail;
	};
}
