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
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr)
		{
			return false;
		}

		if (isLeaf(root) && root->val == sum)
		{
			return true;
		}

		if (isLeaf(root) && root->val != sum)
		{
			return false;
		}


		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}

private:
	bool isLeaf(TreeNode* node)
	{
		if (node && node->left == nullptr && node->right == nullptr)
		{
			return true;
		}

		return false;
	}
};
#endif