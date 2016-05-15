#ifndef __TREE_H__
#define __TREE_H__
#include <math.h>
#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}

		return isSame(root->left, root->right);

// 		if (root->left == nullptr && root->right != nullptr)
// 		{
// 			return false;
// 		}
// 
// 		if (root->left != nullptr && root->right == nullptr)
// 		{
// 			return false;
// 		}
// 
// 		if (root->left == nullptr && root->right == nullptr)
// 		{
// 			return true;
// 		}
//equals to :
// 		if (!root->left || !root->right)
// 		{
// 			return root->left == root->right;
// 		}
	}

	bool isSymmetricIteratively(TreeNode* root) {
		if (root == nullptr)
		{
			return true;
		}

		std::queue<TreeNode*> q;
		q.push(root->left);
		q.push(root->right);

		while (!q.empty())
		{
			TreeNode* p1 = q.front();
			q.pop();

			TreeNode* p2 = q.front();
			q.pop();

			if (p1 == nullptr && p2 == nullptr)
			{
				continue;;
			}

			if (p1 == nullptr || p2 == nullptr)
			{
				return false;
			}

			if (p1->val != p2->val)
			{
				return false;
			}

			if (p1->left == nullptr && p2->right != nullptr)
			{
				return false;
			}

			if (p1->right == nullptr && p2->left != nullptr)
			{
				return false;
			}

			q.push(p1->left);
			q.push(p2->right);
			q.push(p1->right);
			q.push(p2->left);
		}

		return true;
	}

private:
	bool isSame(TreeNode* p1, TreeNode* p2)
	{
		if (!p1 || !p2)
		{
			return p1 == p2;
		}
		else
		{
			return (p1->val == p2->val) && isSame(p1->left, p2->right) && isSame(p1->right, p2->left); //very nice, mirror in recursively
		}
	}
};
#endif