#include <iostream>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}	
};

RandomListNode *copyRandomList(RandomListNode *head) {
	if (!head) return NULL;

	RandomListNode *nhead = NULL;
	RandomListNode *a = head;
	RandomListNode *b = NULL;
	RandomListNode *c = NULL;

	while (a)
	{
		c = new RandomListNode(a->label);
		if (b) b->next = c;
		else nhead = c;
		b = c;
		b->random = a;
		c = a->next;
		a->next = b;
		a = c;
	}

	a = head;

	while (a)
	{
		b->random = a->random ? a->random->next : NULL;
		a->next = b->next->random;
		a = a->next;
	}

	return nhead;
}

void testCopyRandomList()
{
	RandomListNode *head = new RandomListNode(-1);
	copyRandomList(head);
}