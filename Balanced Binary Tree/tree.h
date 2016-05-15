#ifndef __TREE_H__
#define __TREE_H__
#include <math.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}

		int lh = maxDepth(root->left);
		int rh = maxDepth(root->right);

		if (abs(lh - rh) > 1)
		{
			return false;
		}

		return isBalanced(root->left) && isBalanced(root->right);		
	}

public:
	int maxDepth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}

private:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
};
#endif