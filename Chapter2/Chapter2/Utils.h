#include "LinkedList.h"
#include <iostream>

#pragma once

template <typename T>
void printList(LinkedList<T> &list)
{
	auto it = list.begin();

	while (it != list.end())
	{
		std::cout << *it;
		it++;
		if (it != list.end())
			std::cout << ", ";
		else
			std::cout << std::endl;
	}	
}
