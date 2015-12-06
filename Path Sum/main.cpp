#include "tree.h"
#include <iostream>

using namespace std;

int main()
{
	TreeNode* root = new TreeNode(0);
	TreeNode* left = new TreeNode(1);
	TreeNode* right = new TreeNode(0);

	root->left = left;
	root->right = right;

	Solution s;
	if (s.hasPathSum(root, 1))
	{
		cout << "true";
	}
	;
	return getchar();
}