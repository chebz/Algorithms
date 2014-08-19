#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root) {
	vector<int> result;
	if (root == NULL)
		return result;

	stack<TreeNode*> parents;
	TreeNode *n = root;
	parents.push(n);

	while (parents.size() > 0)
	{
		result.push_back(n->val);

		if (n->left != NULL) n = n->left;
		else if (n->right != NULL) n = n->right;
		else
		{
			while (parents.size() > 0 && (parents.top()->right == n || parents.top()->right == NULL))
			{
				n = parents.top();
				parents.pop();
			}
			if (parents.size() > 0 && parents.top()->right != NULL)
			{
				n = parents.top()->right;
			}
			continue;
		}
		parents.push(n);
	}

	return result;
}

void testBinaryPretOrder()
{
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->left->left = new TreeNode(4);
	root->right = new TreeNode(5);
	vector<int> result = preorderTraversal(root);

	for (int i : result)
		cout << i << ",";

}