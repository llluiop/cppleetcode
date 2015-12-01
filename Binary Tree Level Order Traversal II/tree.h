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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> v;

		if (root == nullptr)
		{
			return v;
		}

		queue<TreeNode*> q;
		queue<TreeNode*> q2;
		q.push(root);

		while (!q.empty())
		{
			vector<int> inner;

			q2.swap(q);
			while (!q2.empty())
			{
				TreeNode* node = q2.front();
				inner.push_back(node->val);
				if (node->left != nullptr)
				{
					q.push(node->left);
				}

				if (node->right != nullptr)
				{
					q.push(node->right);
				}

				q2.pop();
			}

			v.push_back(inner);
		}

		reverse(v.begin(), v.end());
		return v;
	}
};
#endif