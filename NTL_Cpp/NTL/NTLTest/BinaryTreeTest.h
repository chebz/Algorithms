#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
#pragma once

class TestHarness {
public:

	static int comparisonInt(int a, int b)
	{
		if (a < b)
			return -1;
		if (a > b)
			return 1;
		return 0;
	}

	void test() {
		BinarySearchTree<int> tree(&TestHarness::comparisonInt);
		tree.insert(5);
		tree.insert(3);
		tree.insert(4);
		tree.insert(1);
		tree.insert(11);
		tree.insert(21);

		int * n = tree.search(1);
		cout << *n << endl;
		n = tree.search(11);
		cout << *n << endl;

		/*auto itPre = tree.beginPreOrder();
		while (itPre != tree.endPreOrder()) {
			int n = *itPre;
			itPre++;
			cout << n << ",";
		}
		cout << endl;

		auto itPost = tree.beginPostOrder();
		while (itPost != tree.endPostOrder()) {
			int n = *itPost;
			itPost++;
			cout << n << ",";
		}
		cout << endl;

		auto itIn = tree.beginInOrder();
		while (itIn != tree.endInOrder()) {
			int n = *itIn;
			itIn++;
			cout << n << ",";
		}
		cout << endl;*/

		cout << "Levelorder traversal:\n";
		auto itLev = tree.begin(TreeTraversal::Levelorder);
		while (itLev != tree.end()) {
			int n = *itLev;
			itLev++;
			cout << n << ",";
		}
		cout << endl;

		cout << "Preorder traversal:\n";
		auto itPre = tree.begin(TreeTraversal::Preorder);
		while (itPre != tree.end()) {
			int n = *itPre;
			itPre++;
			cout << n << ",";
		}
		cout << endl;

		cout << "Inorder traversal:\n";
		auto itIn = tree.begin(TreeTraversal::Inorder);
		while (itIn != tree.end()) {
			int n = *itIn;
			itIn++;
			cout << n << ",";
		}
		cout << endl;

		cout << "Postorder traversal:\n";
		auto itPost = tree.begin(TreeTraversal::Postorder);
		while (itPost != tree.end()) {
			int n = *itPost;
			itPost++;
			cout << n << ",";
		}
		cout << endl;

		tree.deleteNode(3);
	}
};