#include "LinkedList.h"

#pragma once

template <typename T>
const T &lastNthElement(LinkedList<T> &list, int n)
{
	bool found = false;
	typename LinkedList<T>::iterator it = lastNthElement<T>(list, list.begin(), n, found);
	return *it;	
}

template <typename T>
typename LinkedList<T>::iterator &lastNthElement(LinkedList<T> &list, typename LinkedList<T>::iterator it, int &n, bool &found)
{
	auto it0 = it;

	if (it == list.end())
		return it0;

	typename LinkedList<T>::iterator &it1 = lastNthElement(list, it++, n, found);

	if (found)
		return it1;
	
	if (n == 0)
		found = true;
	else
		n--;

	return it0;
}