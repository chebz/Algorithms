#include <stdlib.h>
#include <string>
#include <vector>
#include "LinkedList.h"
#pragma once

template <typename T>
struct KVP
{
	KVP() {}
	KVP(const std::string &key, const T &data) : data(data), key(key) {}
	const std::string key;
	T data;
};

template <typename T>
class Hashtable
{
	typedef KVP<T> kvp;
	typedef LinkedList<kvp> list;

	std::vector<list> table;
	std::size_t size;

	unsigned int computeHash(const std::string &key)
	{
		unsigned int index = 0;
		for (auto c : key)
			index += (int)c;
		index %= size;
		return index;
	}

public:

	Hashtable(int size) : size(size), table(size) {}
	Hashtable(const Hashtable& other) : size(other.size) 
	{
		table = other.table;

	}
	Hashtable(Hashtable&& other) : table(other.table), size(other.size)
	{
		other.table = nullptr;
		other.size = 0;
	}
	Hashtable& operator=(Hashtable other)
	{
		swap(*this, other);
		return *this;
	}
	Hashtable& operator=(Hashtable&& other)
	{
		assert(this != &other);
		delete(table);
		size = other.size;
		table = other.table;
		other.size = 0;
		other.table = nullptr;
		return *this;
	}
	virtual ~Hashtable() 
	{ 
	}

	friend void swap(Hashtable& first, Hashtable& second)
	{
		std::swap(first.size, second.size);
		std::swap(first.table, second.table);
	}

	void insert(const std::string &key, const T &data)
	{
		int index = computeHash(key);
		table[index].add(kvp(key, data));
	}

	T* find(const std::string &key)
	{
		int index = computeHash(key);
		for (auto it = begin(table[index]); it != end(table[index]); ++it)
		{
			if (it->key == key)
				return &(*it);
		}
		return nullptr;
	}

	void erase(const std::string &key);

	const int getSize()
	{
		return size;
	}
};
