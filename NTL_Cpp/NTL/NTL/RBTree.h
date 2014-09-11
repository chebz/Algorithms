#include "Collection.h"

#pragma once

template <class T>
class RBTree : public Collection<T>
{
protected:
	struct RBNode : public Node
	{
		RBNode() : Node(), next(nullptr) {}
		RBNode(const T &data) : Node(data), parent(nullptr), left(nullptr), right(nullptr), r(true) {}
		RBNode * parent;
		RBNode * left;
		RBNode * right;
		bool r; //true = red, false = black
	};

	RBNode * _root;

	void rotate_left(RBNode * x) {
		RBNode * y = x->right;
		x->right = y->left;
		if (y->left) y->left->parent = x;
		y->parent = x->parent;
		if (!x->parent) _root = y;
		else {
			if (x == x->parent->left) x->parent->left = y;
			else x->parent->right = y;			
		}
		y->left = x;
		x->parent = y;
	}

	void rotate_right(RBNode * y) {
		RBNode * x = y->left;
		y->left = x->right;
		if (x->right) x->right->parent = y;
		x->parent = y->parent;
		if (!y->parent) _root = x;
		else {
			if (y == y->parent->left) y->parent->left = x;
			else y->parent->right = x;
		}
		x->right = y;
		y->parent = x;
	}

public:
	RBTree() : Collection(), _root(nullptr) {}

};