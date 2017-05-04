// Binary Tree Tilt.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>

/**
* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int findTilt(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int left_sum = sum(root->left);
		int right_sum = sum(root->right);

		return abs(left_sum - right_sum) + findTilt(root->left) + findTilt(root->right);

	}

	int sum(TreeNode* root){
		if (root == nullptr)
			return 0;

		return root->val + sum(root->left) + sum(root->right);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	return 0;
}

