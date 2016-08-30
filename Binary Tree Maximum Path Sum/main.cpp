#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


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
	int maxPathSum(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}

		max_value = INT_MIN;

		maxdown(root);
		return max_value;
	}

	int maxdown(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int left = max(0, maxdown(root->left));
		int right = max(0, maxdown(root->right));

		max_value = max(max_value, left + right + root->val);

		return max(root->val + left, root->val + right);
	}

private:
	int max_value;

};



int main()
{
	TreeNode* root = new TreeNode(3);
	TreeNode* left = new TreeNode(1);
	TreeNode* right = new TreeNode(4);

	root->left = left;
	root->right = right;

	TreeNode* ll = new TreeNode(3);
	left->left = ll;

 	TreeNode* lr = new TreeNode(2);
 	left->right = lr;
// 
// 	TreeNode* rr = new TreeNode(8);
// 	right->right = rr;
// 
// 	TreeNode* rrl = new TreeNode(7);
// 	rr->left = rrl;
// 
// 	TreeNode* rrr = new TreeNode(9);
// 	rr->right = rrr;

	Solution s;
	cout<<s.maxPathSum(root);

	return getchar();
}