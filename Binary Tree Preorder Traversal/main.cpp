#include "tree.h"
#include <iostream>
using namespace std;

int main()
{
	TreeNode* root = new TreeNode(0);
	TreeNode* left = new TreeNode(1);
	TreeNode* right = new TreeNode(2);

	TreeNode* lright = new TreeNode(3);
	TreeNode* rleft = new TreeNode(4);
	TreeNode* rright = new TreeNode(5);


	root->left = left;
	left->right = lright;
	root->right = right;
	right->left = rleft;
	right->right = rright;

	Solution s;
	vector<int> v = s.preorderTraversal(root);
	return getchar();
}