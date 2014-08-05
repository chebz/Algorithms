#include "LinkedList.h"
#include <iostream>
#include <assert.h>
#include <iomanip>
#pragma once

struct Member
{
	char * name;
	char * email;
	LinkedList<Member*> * friends;

	Member() : name(nullptr), email(nullptr), friends(nullptr)
	{
	}

	Member(const Member& other) : name(other.name), email(other.email), friends(other.friends)
	{
	}

	Member& operator=(Member other)
	{
		name = other.name;
		email = other.email;
		friends = other.friends;
		return *this;
	}

	~Member()
	{
		if (friends)
		{
			for (auto it = friends->begin(); it != friends->end(); ++it)
			{
				delete * it;
			}
			delete friends;
		}
	}
};

template <class T>
class Queue
{
	struct Node
	{
		T data;
		Node * next;

		Node() : next(nullptr)
		{
		}

		Node(const T &data) : data(data), next(nullptr)
		{
		}
	};

	Node *first;
	Node *last;
	int size;
public:
	Queue() : first(nullptr), last(nullptr), size(0)
	{
	}

	~Queue()
	{
		while (size > 0)
		{
			pop();
		}
	}

	void push(const T& data)
	{
		Node * tmp = new Node(data);

		if (size == 0)
		{
			first = tmp;
			last = tmp;
		}
		else
		{
			last->next = tmp;
			last = tmp;
		}
		++size;
	}

	void pop()
	{
		assert(size > 0);

		Node * tmp = first;
		first = first->next;
		delete tmp;
		--size;
	}

	T& front()
	{
		return first->data;
	}

	const int& getSize()
	{
		return size;
	}
};

Member * addFriend(Member * m, char * name, char * email)
{
	Member * f = new Member;
	f->name = name;
	f->email = email;
	f->friends = new LinkedList<Member*>;
	m->friends->add(f);
	return f;
}

void printFriends(Member * m)
{
	Queue<Member*> queue;
	queue.push(m);

	while (queue.getSize() > 0)
	{
		Member * f = queue.front();
		queue.pop();

		if (f->friends)
		{
			for (auto it = f->friends->begin(); it != f->friends->end(); ++it)
			{
				queue.push(*it);
			}
		}

		std::cout << std::setw(20) << f->name << "\t" << f->email << std::endl;
	}
}