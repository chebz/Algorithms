#include <iostream>
using namespace std;

class LRUCache{
	struct Node {
		int key;
		int value;
		Node *next;
		Node *previous;

		Node(int key, int value) : key(key), value(value), next(NULL), previous(NULL)
		{
		}
	};

	int capacity;
	int size;
	Node *first = NULL;
	Node *last = NULL;

	Node *moveFront(int key)
	{
		Node *n = first;

		while (n)
		{
			if (n->key == key)
			{
				if (n->previous != NULL)
				{
					n->previous->next = n->next;
					if (n->next != NULL) n->next->previous = n->previous;
					if (n->previous->next == NULL) last = n->previous;
					n->next = first;
					first->previous = n;
					first = n;
					n->previous = NULL;
				}
				return n;
			}
			n = n->next;
		}

		return NULL;
	}

public:
	LRUCache(int capacity) : capacity(capacity), size(0) {
	}

	~LRUCache()
	{
		while (first != NULL)
		{
			Node *tmp = first;
			first = first->next;
			delete tmp;
		}
		last = NULL;
	}

	int get(int key) {
		Node *n = moveFront(key);
		if (n != NULL) return n->value;
		return -1;
	}

	void set(int key, int value) {
		Node *n = moveFront(key);
		if (n == NULL)
		{
			if (size == capacity)
			{
				Node *tmp = last;
				last = last->previous;				
				if (last == NULL) first = NULL;
				else last->next = NULL;
				delete tmp;
				size--;
			}
			n = new Node(key, value);
			n->next = first;
			if (first) first->previous = n;
			first = n;
			if (last == NULL) last = n;
			size++;
		}
		else
		{
			n->value = value;
		}
	}
};

void testLRU()
{
	//10,[set(10,13),set(3,17),set(6,11),set(10,5),set(9,10),get(13),set(2,19),get(2),get(3),set(5,25),get(8),set(9,22),set(5,5),set(1,30),get(11),set(9,12),get(7),get(5),get(8),get(9),set(4,30),set(9,3),get(9),get(10),get(10),set(6,14),set(3,1),get(3),set(10,11),get(8),set(2,14),get(1),get(5),get(4),set(11,4),set(12,24),set(5,18),get(13),set(7,23),get(8),get(12),set(3,27),set(2,12),get(5),set(2,9),set(13,4),set(8,18),set(1,7),get(6),set(9,29),set(8,21),get(5),set(6,30),set(1,12),get(10),set(4,15),set(7,22),set(11,26),set(8,17),set(9,29),get(5),set(3,4),set(11,30),get(12),set(4,29),get(3),get(9),get(6),set(3,4),get(1),get(10),set(3,29),set(10,28),set(1,20),set(11,13),get(3),set(3,12),set(3,8),set(10,9),set(3,26),get(8),get(7),get(5),set(13,17),set(2,27),set(11,15),get(12),set(9,19),set(2,15),set(3,16),get(1),set(12,17),set(9,1),set(6,19),get(4),get(5),get(5),set(8,1),set(11,7),set(5,2),set(9,28),get(1),set(2,2),set(7,4),set(4,22),set(7,24),set(9,26),set(13,28),set(11,26)]

	LRUCache lru(10);
	lru.set(10, 13); 
	lru.set(3, 17); 
	lru.set(6, 11); 
	lru.set(10, 5); 
	lru.set(9, 10); 
	cout << lru.get(13) << ",";
	lru.set(2, 19); 
	cout << lru.get(2) << ",";
	cout << lru.get(3) << ",";
	lru.set(5, 25); 
	cout << lru.get(8) << ",";
	lru.set(9, 22); 
	lru.set(5, 5); 
	lru.set(1, 30); 
	cout << lru.get(11) << ",";
	lru.set(9, 12); 
	cout << lru.get(7) << ",";
	cout << lru.get(5) << ",";
	cout << lru.get(8) << ",";
	cout << lru.get(9) << ",";
	lru.set(4, 30); 
	lru.set(9, 3); 
	cout << lru.get(9) << ",";
	cout << lru.get(10) << ",";
	cout << lru.get(10) << ",";
	lru.set(6, 14); 
	lru.set(3, 1); 
	cout << lru.get(3) << ",";
	lru.set(10, 11); 
	cout << lru.get(8) << ",";
	lru.set(2, 14); 
	cout << lru.get(1) << ",";
	cout << lru.get(5) << ",";
	cout << lru.get(4) << ",";
	lru.set(11, 4); 
	lru.set(12, 24); 
	lru.set(5, 18); 
	cout << lru.get(13) << ",";
	lru.set(7, 23); 
	cout << lru.get(8) << ",";
	cout << lru.get(12) << ",";
	lru.set(3, 27); 
	lru.set(2, 12); 
	cout << lru.get(5) << ",";
	lru.set(2, 9); 
	lru.set(13, 4); 
	lru.set(8, 18); 
	lru.set(1, 7); 
	cout << lru.get(6) << ",";
	lru.set(9, 29); 
	lru.set(8, 21); 
	cout << lru.get(5) << ",";
	lru.set(6, 30); 
	lru.set(1, 12); 
	cout << lru.get(10) << ",";
	lru.set(4, 15); 
	lru.set(7, 22); 
	lru.set(11, 26); 
	lru.set(8, 17); 
	lru.set(9, 29); 
	cout << lru.get(5) << ",";
	lru.set(3, 4); 
	lru.set(11, 30); 
	cout << lru.get(12) << ",";
	lru.set(4, 29); 
	cout << lru.get(3) << ",";
	cout << lru.get(9) << ",";
	cout << lru.get(6) << ",";
	lru.set(3, 4); 
	cout << lru.get(1) << ",";
	cout << lru.get(10) << ",";
	lru.set(3, 29); 
	lru.set(10, 28); 
	lru.set(1, 20); 
	lru.set(11, 13); 
	cout << lru.get(3) << ",";
	lru.set(3, 12); 
	lru.set(3, 8); 
	lru.set(10, 9); 
	lru.set(3, 26); 
	cout << lru.get(8) << ",";
	cout << lru.get(7) << ",";
	cout << lru.get(5) << ",";
	lru.set(13, 17); 
	lru.set(2, 27); 
	lru.set(11, 15); 
	cout << lru.get(12) << ",";
	lru.set(9, 19); 
	lru.set(2, 15); 
	lru.set(3, 16); 
	cout << lru.get(1) << ",";
	lru.set(12, 17); 
	lru.set(9, 1); 
	lru.set(6, 19); 
	cout << lru.get(4) << ",";
	cout << lru.get(5) << ",";
	cout << lru.get(5) << ",";
	lru.set(8, 1); 
	lru.set(11, 7); 
	lru.set(5, 2); 
	lru.set(9, 28); 
	cout << lru.get(1) << "\n";
	lru.set(2, 2); 
	lru.set(7, 4); 
	lru.set(4, 22); 
	lru.set(7, 24); 
	lru.set(9, 26); 
	lru.set(13, 28); 
	lru.set(11, 26);
	
	cout << "done\n";
}