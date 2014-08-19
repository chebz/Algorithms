#include <vector>
#include <iostream>
#pragma once
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *insert(ListNode *head, ListNode *item)
{
	ListNode *n = head;
	ListNode *p = NULL;

	while (n->val < item->val)
	{
		p = n;
		n = n->next;
	}

	item->next = n;
	if (p != NULL) p->next = item;
	else head = item;
	return head;
}


ListNode *insertionSortList(ListNode *head) {

	if (head == NULL)
		return head;

	ListNode *n = head->next;
	ListNode *p = head;

	while (n != NULL)
	{
		if (n->val < p->val)
		{
			p->next = n->next;
			head = insert(head, n);
			n = p->next;
		}
		else
		{
			p = n;
			n = n->next;
		}
	}

	return head;
}

ListNode *buildList(vector<int> &arr)
{
	ListNode *head = nullptr;
	ListNode *last = nullptr;
	for (int i : arr)
	{
		ListNode *next = new ListNode(i);
		if (!head)
			head = next;
		if (last)
			last->next = next;
		last = next;
	}
	return head;
}


void testInsertListSort()
{
	vector<int> v = { 4, 2, 1, 3 };
	ListNode *head = buildList(v);

	head = insertionSortList(head);
	while (head != nullptr)
	{
		cout << head->val << ", ";
		head = head->next;
	}
	cout << endl;
}