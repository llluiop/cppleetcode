// Diameter of Binary Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <limits>

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
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == nullptr)
			return 0;

		return max(depth(root->left) + depth(root->right), max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
	}

	int depth(TreeNode* root){
		if (root == nullptr)
			return 0;

		return 1 + max(depth(root->left), depth(root->right));
	}


	int max(int a, int b)
	{
		return a > b ? a : b;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

