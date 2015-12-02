#include "tree.h"


int main()
{
	TreeNode* root = new TreeNode(0);
	TreeNode* left = new TreeNode(0);
	TreeNode* right = new TreeNode(0);

	root->left = left;
	root->right = right;
	
	Solution s;
	s.levelOrderBottom(root);
	return getchar();
}