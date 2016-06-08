#include "node.h"
#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == nullptr)
		{
			return;
		}

		std::queue<TreeLinkNode*> q1;
		std::queue<TreeLinkNode*> q2;

		q1.push(root);
		while (!q1.empty())
		{
			q2.swap(q1);			

			TreeLinkNode* pre = nullptr;
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

				if (pre == nullptr)
				{
					pre = t;
				}
				else
				{
					pre->next = t;
					pre = t;
				}

				q2.pop();
			}
		}

	}
};


int main()
{
	Solution s;

	TreeLinkNode* root = new TreeLinkNode(2);
	TreeLinkNode* left = new TreeLinkNode(4);
	TreeLinkNode* right = new TreeLinkNode(7);

	root->left = left;
	root->right = right;


	s.connect(root);

	return getchar();
}
