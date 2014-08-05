#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "Utils.h"
#include "RemoveDuplicates.h"
#include "FindNthLastElement.h"
#include "Reverse.h"
#include "BFS1.h"

void RemoveDuplicatesTest()
{
	std::cout << "REMOVE DUPLICATES TEST" << std::endl;

	LinkedList<int> list;

	list.push_back(1);
	list.push_back(1);
	list.push_back(2);
	list.push_back(1);
	list.push_back(3);
	list.push_back(3);
	list.push_back(1);
	list.push_back(1);
	list.push_back(3);
	list.push_back(7);

	std::cout << "Original list\n";
	printList<int>(list);

	removeDuplicates(list);
	std::cout << "list with no duplicates\n";
	printList<int>(list);

	std::cout << std::endl;
}

void RemoveDuplicatesNoBufferTest()
{
	std::cout << "REMOVE DUPLICATES NO BUFFER TEST" << std::endl;
	LinkedList<int> list;

	list.push_back(1);
	list.push_back(1);
	list.push_back(2);
	list.push_back(1);
	list.push_back(3);
	list.push_back(3);
	list.push_back(1);
	list.push_back(1);
	list.push_back(3);
	list.push_back(7);

	std::cout << "Original list\n";
	printList<int>(list);

	removeDuplicatesNoBuffer(list);
	std::cout << "list with no duplicates\n";
	printList<int>(list);

	std::cout << std::endl;
}

void FindNthlastElementTest()
{
	std::cout << "FIND NTH LAST ELEMENT TEST" << std::endl;
	srand(time(NULL));
	LinkedList<int> list;
	for (int i = 0; i < 10; ++i)
		list.push_back(rand() % 100);

	std::cout << "Original list\n";
	printList<int>(list);

	int n = 0;
	int e = lastNthElement(list, n);
	std::cout << n << " element from the end: " << e << std::endl;

	std::cout << std::endl;
}

void ReverseLinkedListTest()
{
	std::cout << "REVERSE LINKED LIST TEST" << std::endl;
	ReversibleLinkedList list;
	for (int i = 0; i < 10; ++i)
		list.push_back(i);

	std::cout << "Original list\n";
	printList<int>(list);

	list.reverse();

	std::cout << "reversed list\n";
	printList<int>(list);

	std::cout << std::endl;
}

void BSF1Test()
{
	std::cout << "BREADTH FIRST TEST" << std::endl;

	Member * m = new Member;
	m->name = "John Doe";
	m->email = "johnDoe0@email.com";
	m->friends = new LinkedList<Member*>;
	Member *f1 = addFriend(m, "Cathy Young", "cathyYoung1@email.com");
	Member *f2 = addFriend(m, "Sam Snicker", "samSnicker1@email.com");
	Member *f3 = addFriend(m, "Bob Dillan", "bobDillan1@email.com");
	Member *f11 = addFriend(f1, "Jeff Lebowsky", "jeffLebowsky2@email.com");
	Member *f12 = addFriend(f1, "Donny", "donny2@email.com");
	Member *f13 = addFriend(f1, "Walter", "walter2@email.com");
	Member *f21 = addFriend(f2, "James Bond", "secretAgent2@email.com");
	Member *f22 = addFriend(f2, "Walter White", "cheapMeth2@email.com");
	Member *f23 = addFriend(f2, "Rambo", "kittenPower2@email.com");
	Member *f31 = addFriend(f3, "Chuck Norris", "youDontMessWithMe2@email.com");
	Member *f32 = addFriend(f3, "Jack Sparrow", "jackSparrow2@email.com");
	Member *f33 = addFriend(f3, "Cpt Krueger", "krueger2@email.com");

	printFriends(m);
	delete m;
	std::cout << std::endl;
}

int main()
{
	RemoveDuplicatesTest();
	RemoveDuplicatesNoBufferTest();
	FindNthlastElementTest();
	ReverseLinkedListTest();
	BSF1Test();

	int n;
	std::cin >> n;
	return 0;
}