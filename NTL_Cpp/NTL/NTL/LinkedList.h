#include "Collection.h"

#pragma once

template <class T>
class LinkedList : public Collection<T>
{
protected:
	struct ListNode : public Node
	{
		ListNode() : Node(), next(nullptr) {}
		ListNode(const T &data) : Node(data), next(nullptr) {}
		ListNode * next;
	};

	ListNode * _first;
	ListNode * _last;

	Node * allocateNode(const T& data)
	{
		Node * node = new ListNode(data);
		return node;
	}
public:
	class LinkedListIterator : public Iterator
	{
	public:
		LinkedListIterator(ListNode* p) : Iterator(p) {}
		Iterator&  operator++() { p = static_cast<ListNode*>(p)->next; return *this; }
		Iterator&  operator++(int) { p = static_cast<ListNode*>(p)->next; return *this; }
	};

	LinkedList() : Collection(), _first(nullptr), _last(nullptr) {}

	~LinkedList()
	{
		while (_size > 0)
		{
			ListNode * tmp = _first;
			_first = _first->next;
			delete tmp;
			--_size;
		}
	}

	void push_back(const T& data)
	{
		ListNode * node = new ListNode(data);
		if (_size == 0)
			_first = node;
		else
			_last->next = node;
		_last = node;
		++_size;
	}

	void push_front(const T& data)
	{
		ListNode * node = dynamic_cast<ListNode*>(allocateNode(data));
		if (_size == 0)
			_last = node;
		node->next = _first;
		_first = node;
		++_size;
	}

	T pop_front()
	{
		assert(_size > 0);
		ListNode * tmp = _first;
		T data = tmp->data;
		if (_size == 1)
		{
			_last = nullptr;
			_first = nullptr;
		}
		else
			_first = _first->next;
		delete tmp;
		--_size;
		return data;
	}

	Iterator begin() { return LinkedListIterator(_first); }
	Iterator end() { return LinkedListIterator(_last); }
};