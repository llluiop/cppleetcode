#ifndef __TREE_H__
#define __TREE_H__
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}

		if (root->left == nullptr && root->right == nullptr)
		{
			return 1 ;
		}

		if (root->left != nullptr && root->right != nullptr)
		{
			return 1 + min(minDepth(root->left), minDepth(root->right));;
		}


		//!
		if (root->left == nullptr)
			return minDepth(root->right) + 1;

		if (root->right == nullptr)
			return minDepth(root->left) + 1;
	}

private:
	int min(int a, int b)
	{
		return a > b ? b : a;
	}
};
#endif