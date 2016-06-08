#include "node.h"
#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
	std::vector<int> rightSideView(TreeNode* root) {
		if (root == nullptr)
		{
			return v_;
		}

		std::queue<TreeNode*> q1;
		std::queue<TreeNode*> q2;

		q1.push(root);
		while (!q1.empty())
		{
			q2.swap(q1);
			v_.push_back(q2.back()->val);

			while (!q2.empty())
			{
				auto t = q2.front();
				if (t->left)
				{
					q1.push(t->left);
				}
				if (t->right)
				{
					q1.push(t->right);
				}

				q2.pop();
			}
		}


		return v_;

	}	


private:
	std::vector<int> v_;
};


int main()
{
	Solution s;

	TreeNode* root = new TreeNode(2);
	TreeNode* left = new TreeNode(4);
	TreeNode* right = new TreeNode(7);

	root->left = left;
	root->right = right;


	auto v = s.rightSideView(root);

	return getchar();
}
