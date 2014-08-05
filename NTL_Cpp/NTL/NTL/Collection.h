#include <assert.h>
#include "Utils.h"

#pragma once

template <typename T>
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
		Node* p;
	public:
		Iterator(Node* p) : p(p) {}
		Iterator(const Iterator& other) : p(other.p) {}
		Iterator& operator=(Iterator other) { Utils::swap(p, other.p); return *this; }
		virtual Iterator&  operator++() = 0;
		virtual Iterator&  operator++(int) = 0;
		bool operator==(const Iterator& other) { return p == other.p; }
		bool operator!=(const Iterator& other) { return !(p == other.p); }
		const T& operator*() const { return p->data; }
		Iterator& operator+(int i)
		{
			Iterator iter = *this;
			while (i-- > 0 && iter.p)
				++iter;
			return iter;
		}
	};

	Collection() : _size(0) {}
	
	virtual ~Collection() {}

	const int size()
	{
		return _size;
	}

	virtual Iterator begin() = 0;
	virtual Iterator end() = 0;
};