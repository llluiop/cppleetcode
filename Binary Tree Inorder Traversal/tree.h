#ifndef __TREE_H__
#define __TREE_H__
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		if (root == nullptr)
		{
			return v;
		}

		inorderTraversalRecursive(root, v);
		return std::move(v);
	}

private:
	void inorderTraversalRecursive(TreeNode* root, vector<int>& nodes)
	{
		if (root->left != nullptr)
		{
			inorderTraversalRecursive(root->left, nodes);
		}

		nodes.push_back(root->val);


		if (root->right != nullptr)
		{
			inorderTraversalRecursive(root->right, nodes);
		}
	}
};


#endif