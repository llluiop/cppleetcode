#include "node.h"
#include <iostream>
#include <vector>

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		tree2Vec(root);

		return v_[k-1];
	}


private:
	void tree2Vec(TreeNode* root)
	{
		if (root == nullptr)
		{
			return ;
		}

		if (root->left)
		{
			tree2Vec(root->left);
		}

		v_.push_back(root->val);

		if (root->right)
		{
			tree2Vec(root->right);
		}		
	}

	std::vector<int> v_;
};


int main()
{
	Solution s;

	TreeNode* root = new TreeNode(2);
	TreeNode* left = new TreeNode(4);
	TreeNode* right = new TreeNode(7);

	root->left = nullptr;
	root->right = right;


	std::cout << s.kthSmallest(root, 2);

	return getchar();
}
