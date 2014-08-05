#include <iostream>
#include "Stack.h"
#include "Problem1_Ch3.h"

void StackTest()
{
	std::cout << "Stack Test" << std::endl;
	Stack<int> s;
	for (int i = 0; i < 10; ++i)
		s.push(i);
	while (s.size() > 0)
		std::cout << s.pop() << " ";
	std::cout << std::endl;
}

void Problem1()
{
	std::cout << "Problem 1: ARRAY FOR 3 STACKS" << std::endl;

	TrippleStack<int> s;
	for (int i = 0; i < 100; ++i)
		s.push(i, i % 3);

	for (int i = 0; i < 33; ++i)
		std::cout << "stack1: " << s.pop(0) << ", stack2: " << s.pop(1) << "stack3: " << s.pop(2) << std::endl;
	std::cout << std::endl;
}

int main()
{
	StackTest();
	Problem1();

	int n;
	std::cin >> n;
	return 0;
}