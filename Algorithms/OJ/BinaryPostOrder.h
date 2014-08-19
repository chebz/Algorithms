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

vector<int> postorderTraversal(TreeNode *root) {
	vector<int> result;

	if (root == NULL)
		return result;

	stack<TreeNode*> parents;
	parents.push(root);
	TreeNode* n = root;

	while (parents.size() > 0)
	{
		while (n->right != NULL || n->left != NULL)
		{
			if (n->left != NULL) n = n->left;
			else n = n->right;
			parents.push(n);			
		}

		while (parents.size() > 0 && (parents.top()->right == n || parents.top()->right == NULL))
		{
			n = parents.top();
			result.push_back(n->val);
			parents.pop();
		}

		if (parents.size() > 0 && parents.top()->right != NULL)
		{
			n = parents.top()->right;
			parents.push(n);
		}
	}

	return result;
}

void testBinaryPostOrder()
{
	TreeNode *root = new TreeNode(3);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(1);
	root->right->right = new TreeNode(4);

	vector<int> result = postorderTraversal(root);

	for (int i : result)
		cout << i << ",";

}