#include "tree.h"
#include <iostream>

using namespace std;

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(3);
	TreeNode* leftRight = new TreeNode(4);

	root->left = left;
	root->right = right;
	left->right = leftRight;

	Solution s;
	TreeNode* node = s.lowestCommonAncestor(root, leftRight, right);
	if (node != nullptr)
	{
		cout << node->val;
	}

	return getchar();
}