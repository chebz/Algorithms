#include "LinkedList.h"

#pragma once

class ReversibleLinkedList : public LinkedList<int>
{
public:
	void reverse()
	{
		if (head->next == tail)
			return;

		//  h -> 1 -> 2 -> 3 -> ... -> t

		Node *prev = nullptr;
		Node *curr = head;
		Node *tmp;

		while (curr != nullptr)
		{
			tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}

		tmp = head;
		head = tail;
		tail = tmp;
	}
};