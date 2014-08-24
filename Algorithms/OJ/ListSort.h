#include <vector>
#include <iostream>
#pragma once

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}	
};

void FrontBackSplit(ListNode *head, ListNode *&frontRef, ListNode *&backRef)
{
	ListNode *fast;
	ListNode *slow;

	if (head == NULL || head->next == NULL)
	{
		/* length < 2 cases */
		frontRef = head;
		backRef = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;

		/* Advance 'fast' two nodes, and advance 'slow' one node */
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		/* 'slow' is before the midpoint in the list, so split it in two
		at that point. */
		frontRef = head;
		backRef = slow->next;
		slow->next = NULL;
	}
}

ListNode* SortedMerge(ListNode* a, ListNode* b)
{
	ListNode* result = nullptr;
	ListNode* head = nullptr;
	ListNode* prev = nullptr;

	while (a || b)
	{
		if (a && (!b || a->val < b->val))
		{
			result = a;
			a = a->next;
		}
		else
		{
			result = b;
			b = b->next;
		}

		if (head == nullptr)
			head = result;

		if (prev != nullptr)
			prev->next = result;

		prev = result;
	}
	return(head);
}

ListNode *sortList(ListNode *head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode *a, *b;

	FrontBackSplit(head, a, b);
	a = sortList(a);
	b = sortList(b);

	return SortedMerge(a, b);
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


void testListSort()
{
	vector<int> v = { 1, 3, 3, 1, 3, 1, 3, 3, 2, 3, 2, 2, 1, 1, 1, 3, 2, 2, 1, 1, 2, 2, 2, 3, 3, 1, 1, 2, 2, 2, 1, 2, 1, 1, 2, 3, 3, 2, 2, 3, 2, 3, 2, 2, 2, 1, 1, 3, 2, 3, 3, 1, 1, 1, 2, 2, 1, 2, 2, 2, 2, 3, 1, 3, 1, 1, 1, 2, 1, 2, 2, 2, 1, 3, 2, 2, 2, 3, 3, 2, 3, 3, 1, 1, 2, 2, 1, 2, 1, 3, 2, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 2, 3, 3, 3, 1, 1, 3, 2, 1, 1, 2, 1, 3, 3, 2, 2, 1, 3, 1, 3, 1, 3, 2, 2, 3, 2, 3, 2, 2, 1, 2, 3, 1, 3, 1, 2, 3, 3, 2, 3, 3, 3, 1, 1, 2, 3, 1, 2, 3, 2, 1, 1, 2, 3, 1, 1, 3, 1, 2, 2, 3, 2, 1, 3, 1, 2, 1, 3, 2, 1, 1, 2, 2, 2, 1, 3, 1, 3, 2, 3, 3, 1, 1, 3, 1, 2, 1, 2, 3, 1, 2, 1, 1, 3, 1, 3, 3, 1, 1, 1, 2, 2, 1, 3, 1, 2, 2, 3, 2, 1, 3, 2, 1, 3, 2, 2, 3, 3, 2, 2, 1, 3, 2, 2, 2, 2, 2, 3, 2, 2, 3, 1, 3, 2, 1, 3, 2, 1, 2, 3, 3, 3, 1, 2, 2, 3, 1, 1, 2, 2, 3, 2, 1, 1, 1, 1, 1, 3, 2, 2, 2, 1, 3, 2, 1, 2, 3, 2, 1, 1, 2, 1, 3, 3, 1, 3, 1, 2, 2, 1, 2, 3, 2, 3, 3, 1, 2, 3, 2, 2, 3, 3, 2, 1, 3, 2, 2, 2, 3, 3, 3, 1, 1, 2, 1, 1, 2, 3, 3, 3, 1, 3, 2, 2, 1, 2, 2, 1, 2, 3, 1, 3, 2, 2, 3, 3, 3, 1, 2, 3, 2, 1, 3, 1, 1, 2, 2, 1, 1, 1, 2, 2, 3, 1, 3, 1, 2, 3, 3, 3, 2, 2, 3, 1, 1, 1, 3, 2, 1, 1, 3, 1, 2, 3, 3, 3, 2, 1, 2, 3, 2, 3, 2, 1, 3, 2, 2, 2, 2, 1, 1, 3, 1, 1, 1, 3, 2, 2, 2, 1, 2, 3, 2, 3, 2, 2, 1, 2, 3, 2, 1, 1, 3, 1, 3, 3, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 3, 2, 2, 3, 1, 1, 3, 1, 1, 1, 3, 1, 1, 2, 2, 2, 1, 1, 1, 1, 2, 1, 3, 3, 3, 1, 2, 2, 2, 2, 3, 3, 1, 2, 2, 3, 1, 3, 1, 2, 1, 2, 2, 3, 3, 1, 3, 3, 2, 1, 3, 1, 1, 3, 1, 2, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 2, 2, 2, 1, 1, 3, 2, 2, 2, 3, 1, 3, 3, 3, 1, 1, 3, 1, 3, 2, 3, 1, 2, 3, 2, 2, 3, 3, 3, 1, 2, 1, 2, 1, 2, 3, 1, 2, 2, 2, 1, 1, 1, 2, 2, 1, 2, 1, 1, 1, 3, 2, 1, 2, 3, 2, 2, 2, 1, 2, 3, 2, 2, 1, 3, 3, 3, 1, 2, 3, 3, 1, 1, 3, 3, 1, 1, 2, 1, 2, 3, 1, 2, 3, 2, 2, 3, 2, 1, 3, 1, 3, 1, 2, 2, 2, 2, 1, 2, 3, 3, 2, 2, 2, 3, 2, 2, 1, 2, 2, 3, 1, 3, 1, 1, 1, 2, 3, 3, 2, 2, 3, 3, 2, 3, 1, 1, 2, 2, 2, 3, 2, 2, 1, 1, 3, 2, 2, 3, 3, 3, 3, 1, 2, 3, 3, 1, 3, 3, 1, 2, 2, 1, 3, 2, 3, 3, 2, 3, 2, 1, 2, 1, 2, 2 };
	
	ListNode *head = buildList(v);
	
	head = sortList(head);
	cout << v.size();
	while (head != nullptr)
	{
		cout << head->val << ", ";
		head = head->next;
	}
	cout << endl;
}