#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;
#pragma once

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	struct greater {
		bool operator() (const int& lhs, const int& rhs) const
		{
			return lhs>rhs;
		}
	};

	set<int, greater> paths;
	TreeNode *_root;

	int maxPathSum(TreeNode *root) {
		if (!root)
			return 0;

		if (!_root) _root = root;

		int l = maxPathSum(root->left);
		int r = maxPathSum(root->right);
		int l2r = l + r + root->val;
		int maxBranch = l > r ? l + root->val : r + root->val;
		paths.insert(root->val);
		paths.insert(l2r);
		paths.insert(maxBranch);
		int ret = maxBranch > 0 ? maxBranch : 0;

		return (_root == root) ? *paths.begin() : ret;
	}

	void test() {
		//{9,6,-3,#,#,-6,2,#,#,2,#,-6,-6,-6}
		TreeNode *root = new TreeNode(9);
		root->left = new TreeNode(6);
		root->right = new TreeNode(-3);
		root->right->left = new TreeNode(-6);
		root->right->right = new TreeNode(2);
		root->right->right->left = new TreeNode(2);
		root->right->right->left->left = new TreeNode(-6);
		root->right->right->left->right = new TreeNode(-6);
		root->right->right->left->left->left = new TreeNode(-6);

		int n = maxPathSum(root);
		cout << n << endl;
	}
};