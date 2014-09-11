#include <assert.h>
#include "Utils.h"

#pragma once

template <class T>
class Collection
{
protected:
	struct Node
	{
		Node() {}
		Node(const T &data) : data(data) {}
		T data;

		virtual ~Node() {}
	};

	int _size;

	virtual Node * allocateNode(const T& data) = 0;
public:
	class Iterator
	{
	protected:
		friend class Collection<T>;
		Node* _p;
	public:
		Iterator(Node* p) : _p(p) {}

		Iterator(const Iterator& other) : _p(other._p) {}

		Iterator& operator=(Iterator other) { 
			Utils::swap(_p, other._p); 
			return *this; 
		}

		bool operator==(const Iterator& other) { return _p == other._p; }
		bool operator!=(const Iterator& other) { return !(_p == other._p); }
		const T& operator*() const { 
			return _p->data; 
		}
	};

	Collection() : _size(0) {}
	
	virtual ~Collection() {}

	const int size()
	{
		return _size;
	}

	/*virtual Iterator begin() = 0;
	virtual Iterator end() = 0;*/
};