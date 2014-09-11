#include "Collection.h"
#include "Stack.h"
#pragma once

enum TreeTraversal { Preorder, Inorder, Postorder, Levelorder };

template <class T>
class BinarySearchTree : public Collection<T>
{
protected:
	struct BNode : public Node
	{
		BNode() : Node(), left(nullptr), right(nullptr), parent(nullptr) {}
		BNode(const T &data) : Node(data), parent(nullptr), left(nullptr), right(nullptr) {}
		BNode * parent;
		BNode * left;
		BNode * right;

		bool hasBothChildren() {
			return (left && right);
		}

		bool hasAnyChildren() {
			return (left || right);
		}
	};

	BNode * _root;
	BNode * _end;

	Node * allocateNode(const T& data)
	{
		Node * node = new BNode(data);
		return node;
	}

	int(*_comparison)(T, T);

	void insert(BNode * node, BNode * &root) {
		if (!root) { root = node; return; }
		node->parent = root;
		if (_comparison(node->data, root->data) < 1) insert(node, root->left);
		else insert(node, root->right);
	}

	BNode * search(const T& data, BNode * root) {
		if (!root) return nullptr;
		if (_comparison(data, root->data) == 0) return root;
		if (_comparison(data, root->data) < 0) return search(data, root->left);
		return search(data, root->right);
	}

	BNode * findMin(BNode * root) {
		if (!root->left) return root;
		return findMin(root->left);
	}

	void deleteNode(BNode * node) {
		if (node->hasBothChildren()) {
			BNode * min = findMin(node->right);
			node->data = min->data;
			deleteNode(min);
		}
		else if(!node->left && !node->right) {
			if (node->parent) {
				if (node->parent->left == node) node->parent->left = nullptr;
				else node->parent->right = nullptr;
			}
			else _root = nullptr;
			delete node;
		}
		else {
			BNode * child = node->left ? node->left : node->right;
			node->data = child->data;
			deleteNode(child);
		}		
	}

	static BNode* moveToLeaf(BNode* root) {
		while (root->hasAnyChildren()) {
			root = root->left ? root->left : root->right;
		}
		return root;
	}

	static BNode* moveToLeafLeft(BNode* root) {
		while (root->left) {
			root = root->left;
		}
		return root;
	}

	static BNode* moveToNextBranch(BNode* leaf) {
		while (leaf->parent) {
			if (leaf->parent->right && leaf->parent->right != leaf)
				return leaf->parent->right;
			leaf = leaf->parent;
		}
		return leaf;
	}

	static BNode* moveToRoot(BNode* leaf) {
		while (leaf->parent) {
			if (leaf->parent->right != leaf)
				return leaf->parent;
			leaf = leaf->parent;
		}
		return leaf;
	}

	static bool moveRight(BNode* &leaf) {
		int level = 0;

		while (leaf->parent) {
			if (leaf->parent->right && leaf->parent->right != leaf) {
				leaf = leaf->parent->right;
				while (leaf->hasAnyChildren() && level > 0) {
					leaf = leaf->left ? leaf->left : leaf->right;
					level--;
				}
				if (level == 0)
					return true;
			}

			leaf = leaf->parent;
			level++;
		}
		return false;
	}

public:

	class BinaryTreeIterator : public Iterator
	{
		TreeTraversal _t;
		BNode *child;

		BNode *preOrderNext(BNode * n) {
			if (n->hasAnyChildren())
				n = n->left ? n->left : n->right;
			else
				n = moveToNextBranch(n);
			return n;
		}

		BNode *inOrderNext(BNode * n) {
			if (n->right)
				n = moveToLeafLeft(n->right);
			else
				n = moveToRoot(n);
			return n;
		}

		BNode *postOrderNext(BNode * n) {
			if (n->parent->right && n->parent->right != n)
				n = moveToLeaf(n->parent->right);
			else
				n = n->parent;
			return n;
		}

		BNode *levelOrderNext(BNode * n) {
			if (!child) {
				child = n->left ? n->left : n->right;
			}

			if (!moveRight(n)) {
				if (child) {
					n = child;
					child = nullptr;
				}
			}
			return n;
		}

	public:
		BinaryTreeIterator(BNode* p, TreeTraversal t) : Iterator(p), _t(t) {
			if (t == TreeTraversal::Postorder) 
				_p = moveToLeaf(p);
			else if (t == TreeTraversal::Inorder)
				_p = moveToLeafLeft(p);
		}

		BinaryTreeIterator(const BinaryTreeIterator& other) : Iterator(other), _t(other._t) {}
				
		BinaryTreeIterator&  operator++() {
			BNode * n = static_cast<BNode*>(_p);
			switch (_t) {
			case TreeTraversal::Preorder:
				_p = preOrderNext(n);
				break;
			case TreeTraversal::Inorder:
				_p = inOrderNext(n);
				break;
			case TreeTraversal::Postorder:
				_p = postOrderNext(n);
				break;
			case TreeTraversal::Levelorder:
				_p = levelOrderNext(n);
				break;
			}
			return *this;
		}

		BinaryTreeIterator operator++(int) {
			BinaryTreeIterator temp = *this;
			++*this;
			return temp;
		}
	};

	BinarySearchTree(int(*comparison)(T, T)) : Collection(), 
		_root(nullptr), _comparison(comparison), _end(new BNode()) {}

	void insert(const T& data) {
		BNode * node = static_cast<BNode*>(allocateNode(data)); //can use static_cast here, as valid downcast is guranteed
		insert(node, _root);
		if (_size == 0) _root->parent = _end;
		++_size;
	}

	T * search(const T& data) {
		BNode * node = search(data, _root);
		if (node) return &node->data;
		return nullptr;
	}

	void deleteNode(const T& data) {
		BNode * node = search(data, _root);
		if (node) deleteNode(node);
	}

	BinaryTreeIterator begin(TreeTraversal t) { return BinaryTreeIterator(_root, t); }
	BinaryTreeIterator end() { return BinaryTreeIterator(_end, TreeTraversal::Preorder); }
};