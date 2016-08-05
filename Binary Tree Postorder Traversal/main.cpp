#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if (root == nullptr)
		{
			return{};
		}

		vector<int> v;

		stack<TreeNode*> s;

		s.push(root);
		while (!s.empty())
		{
			auto val = s.top();
			v.push_back(val->val);

			s.pop();

			if (val->left)
			{
				s.push(val->left);
			}

			if (val->right)
			{
				s.push(val->right);
			}
		}

		reverse(v.begin(), v.end());
		return v;
	}
};



int main()
{
	TreeNode* root = new TreeNode(3);
	TreeNode* left = new TreeNode(1);
	TreeNode* right = new TreeNode(4);

	root->left = left;
	root->right = right;

	TreeNode* lr = new TreeNode(2);
	left->right = lr;

	TreeNode* rr = new TreeNode(8);
	right->right = rr;

	TreeNode* rrl = new TreeNode(7);
	rr->left = rrl;

	TreeNode* rrr = new TreeNode(9);
	rr->right = rrr;

	Solution s;
	s.postorderTraversal(root);

	return getchar();
}