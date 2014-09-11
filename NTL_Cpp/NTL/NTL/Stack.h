#include <assert.h>
#include "LinkedList.h"

#pragma once

template <class T>
class Stack : protected LinkedList<T>
{
public:
	Stack() : LinkedList() {}
	Stack(const Stack& other) : LinkedList(other) {}

	virtual void push(const T& data)
	{
		LinkedList::push_front(data);
	}

	virtual T pop()
	{
		return LinkedList::pop_front();
	}

	virtual T& peek()
	{
		assert(_size > 0);
		return _first->data;
	}

	const int size() { return LinkedList::size(); }
};