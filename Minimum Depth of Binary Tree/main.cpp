#include "tree.h"
#include <iostream>

int main()
{
	TreeNode* root = new TreeNode(0);
	TreeNode* left = new TreeNode(0);
	TreeNode* right = new TreeNode(0);
	TreeNode* leftleft = new TreeNode(0);
	TreeNode* leftleftleft = new TreeNode(0);

	root->left = left;
	root->right = right;

	left->left = leftleft;
	leftleft->left = leftleftleft;

	Solution s;
	std::cout<<s.minDepth(root);
	return getchar();
}