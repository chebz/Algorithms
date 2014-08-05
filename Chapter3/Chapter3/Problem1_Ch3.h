#include "Stack.h"

#pragma once

template <class T>
class TrippleStack : public Collection<T>
{
	struct StackNode : public Node
	{
		StackNode(const int& id) : Node(), previous(nullptr), id(id) {}
		StackNode * previous;
		int id;
	};

	static const unsigned MAX_SIZE = 100;
	StackNode * _buffer[MAX_SIZE];
	Stack<int> _freeNodes;
	StackNode * _top3[3];

	Node * allocateNode(const T& data) { throw 0; }
public:
	TrippleStack() : Collection()
	{
		for (int i = 0; i < MAX_SIZE; ++i)
		{
			_buffer[i] = new StackNode(i);
			_freeNodes.push(i);
		}
		for (int i = 0; i < 3; ++i)
			_top3[i] = nullptr;
	}

	~TrippleStack()
	{
		for (int i = 0; i < MAX_SIZE; ++i)
		{
			delete _buffer[i];
		}
	}

	void push(const T& data, const int& stackId)
	{
		assert(_freeNodes.size() > 0);
		int index = _freeNodes.pop();
		StackNode * n = _buffer[index];
		n->data = data;
		n->previous = _top3[stackId];
		_top3[stackId] = n;
		++_size;
	}

	T pop(const int& stackId)
	{
		assert(_size > 0 && _top3[stackId]);
		StackNode * tmp = _top3[stackId];
		_top3[stackId] = tmp->previous;
		_freeNodes.push(tmp->id);
		--_size;
		return tmp->data;
	}

	virtual T& peek(const int& stackId)
	{
		assert(_size > 0 && _top3[stackId]);
		return _top3[stackId]->data;
	}

	Iterator begin() { throw 0; }
	Iterator end() { throw 0; }
};