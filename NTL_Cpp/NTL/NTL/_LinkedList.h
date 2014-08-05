#include <stdlib.h>
#include <memory>
#include <assert.h>

#pragma once

template <typename T>
class LinkedList;

template <typename TNode>
class LinkedListIterator
{
	typedef typename TNode::value_type T;
	friend class LinkedList<T>;
	TNode* p;
public:
	LinkedListIterator(TNode* p) : p(p) {}
	LinkedListIterator(const LinkedListIterator& other) : p(other.p) {}
	LinkedListIterator& operator=(LinkedListIterator other) { std::swap(p, other.p); return *this; }
	LinkedListIterator&  operator++() { p = p->next; return *this; }
	LinkedListIterator&  operator++(int) { p = p->next; return *this; }
	bool operator==(const LinkedListIterator& other) { return p == other.p; }
	bool operator!=(const LinkedListIterator& other) { return !(p == other.p); }
	const T& operator*() const { return p->data; }
	LinkedListIterator& operator+(int i)
	{
		LinkedListIterator iter = *this;
		while (i-- > 0 && iter.p)
		{
			++iter;
		}
		return iter;
	}
};

template <typename T>
class LinkedList
{
protected:
	struct Node
	{
		Node() : next(nullptr) {}
		Node(const T &data) : data(data), next(nullptr) {}
		Node *next;
		T data;
	public:
		typedef T value_type;
	};

	friend class LinkedListIterator<Node>;
	friend class LinkedListIterator<const Node>;

	std::size_t size;
	Node *head;
	Node *tail;

public:
	typedef LinkedListIterator<Node> iterator;
	typedef LinkedListIterator<const Node> const_iterator;

	LinkedList() : size(0), head(new Node), tail(new Node)
	{ 
		head->next = tail; 
	}

	LinkedList(const LinkedList& other) : size(0), head(new Node), tail(new Node)
	{
		head->next = tail;

		const_iterator i = other.begin();
		while (i != other.end())
		{
			add(*i);
			i++;
		}
	}

	LinkedList(LinkedList&& other)
	{
		size = other.size;
		head = other.head;
		tail = other.tail;
		other.size = 0;
	}
	
	LinkedList& operator=(LinkedList other)
	{
		swap(*this, other);
		return *this;
	}

	LinkedList& operator=(LinkedList&& other)
	{
		assert(this != &other);		
		while (head->next != tail)
			remove(begin());
		head = other.head;
		tail = other.tail;
		size = other.size;
		other.size = 0;
		return *this;
	}

	virtual ~LinkedList()
	{
		while (begin() != end())
			remove(begin());
		delete head;
		delete tail;
	}

	friend void swap(LinkedList& first, LinkedList& second)
	{
		std::swap(first.size, second.size);
		std::swap(first.head, second.head);
		std::swap(first.tail, second.tail);
	}

	void add(const T &value)
	{
		Node *first = new Node(value);
		first->next = head->next;
		head->next = first;
		size++;
	}

	void remove(iterator& removeIter)
	{
		Node *last = head;
		iterator i = begin();

		while (i != removeIter)
		{
			last = i.p;
			++i;
		}

		if (i != end())
		{
			last->next = i.p->next;
			size--;
			delete i.p;
		}
	}

	const int getSize() 
	{ 
		return size;
	}

	iterator begin() 
	{
		return iterator(head->next);
	}

	const_iterator begin() const
	{
		return const_iterator(head->next);
	}

	iterator end()
	{
		return iterator(tail);
	}

	const_iterator end() const
	{
		return const_iterator(tail);
	}
};