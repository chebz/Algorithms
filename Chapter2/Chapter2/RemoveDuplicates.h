#include "LinkedList.h"
#include <map>
#pragma once

template <typename T>
void removeDuplicates(LinkedList<T> &list)
{
	std::map<T, int> elements;
	auto it = list.begin();

	while (it != list.end())
	{
		auto itElements = elements.find(*it);
		if (itElements == elements.end())
		{
			elements[*it] = 1;
			it++;
		}
		else
		{
			auto tmp = it;
			tmp++;
			list.remove(it);
			it = tmp;
		}
	}
}

template <typename T>
void removeDuplicatesNoBuffer(LinkedList<T> &list)
{
	auto it1 = list.begin();

	while (it1 != list.end())
	{
		T current = *it1;

		auto it2 = list.begin();

		while (it2 != it1)
		{
			if (*it1 == *it2)
			{
				auto tmp = it2;
				tmp++;
				list.remove(it2);
				it2 = tmp;
			}
			else
			{
				++it2;
			}
		}

		++it1;
	}
}