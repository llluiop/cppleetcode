#ifndef __TREE_H__
#define __TREE_H__

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
		{
			return root;
		}

		TreeNode* tmp = root->left;

		root->left = invertTree(root->right);
		root->right = invertTree(tmp);

		return  root;
	}
};

#endif