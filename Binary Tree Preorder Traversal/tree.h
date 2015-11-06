#ifndef __TREE_H__
#define __TREE_H__
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		if (root == nullptr)
		{
			return v;
		}

		preorderTraversalIterative(root, v);
		return std::move(v);		
	}

private:
	void preorderTraversalRecursive(TreeNode* root, vector<int>& nodes)
	{
		nodes.push_back(root->val);
		if (root->left != nullptr)
		{
			preorderTraversalRecursive(root->left, nodes);
		}

		if (root->right != nullptr)
		{
			preorderTraversalRecursive(root->right, nodes);
		}
	}

	void preorderTraversalIterative(TreeNode* root, vector<int>& nodes)
	{
		std::stack<TreeNode*> s;


		while (root || !s.empty())
		{
			while (root)
			{
				nodes.push_back(root->val);
				s.push(root);
				root = root->left;
			}

			root = s.top();
			root = root->right;
			s.pop();
		}
	}
};


#endif