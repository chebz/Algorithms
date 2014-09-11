#include "Collection.h"

#pragma once
class LinkedListIterator;

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
		LinkedListIterator(const LinkedListIterator& other) : Iterator(other) {}
		
		LinkedListIterator& operator++() {
			_p = static_cast<ListNode*>(_p)->next; 
			return *this; 
		}

		LinkedListIterator operator++(int) {
			LinkedListIterator temp = *this;
			++*this;
			return temp;
		}
	};

	LinkedList() : Collection(), _last(new ListNode()) 
	{
		_first = _last;
	}

	LinkedList(const LinkedList& other) : Collection(), _last(new ListNode())
	{
		for (auto it = other.begin(); it != other.end(); ++it) {
			push_back(*it);
		}
	}

	~LinkedList()
	{
		while (_size > 0)
		{
			ListNode * tmp = _first;
			_first = _first->next;
			delete tmp;
			--_size;
		}
		delete _last;
	}

	void push_back(const T& data)
	{
		ListNode * node = new ListNode();
		_last->data = data;
		_last->next = node;
		if (_size == 0)
			_first = _last;
		_last = node;
		++_size;
	}

	void push_front(const T& data)
	{
		ListNode * node = static_cast<ListNode*>(allocateNode(data));
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

	LinkedListIterator begin() { return LinkedListIterator(_first); }
	LinkedListIterator end() { return LinkedListIterator(_last); }
	LinkedListIterator begin() const { return LinkedListIterator(_first); }
	LinkedListIterator end() const { return LinkedListIterator(_last); }
};