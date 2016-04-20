#include <iostream>
#include <vector>
#include <algorithm>    // std::sort
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int rob(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}

		if (!root->left&&!root->right)
			return root->val;


		int max = 0;
		if (root->left != nullptr)
		{
			max += rob(root->left->left);
			max += rob(root->left->right);
		}

		if (root->right != nullptr)
		{
			max += rob(root->right->left);
			max += rob(root->right->right);
		}

		return Max(root->val+max, rob(root->left) + rob(root->right));
	}

private:
	int Max(int a, int b)
	{
		if (a > b)
		{
			return a;
		}
		else
		{
			return b;
		}
	}
};


int main()
{
	TreeNode root(3);
	TreeNode left(4);
	TreeNode right(5);
	root.left = &left;
	root.right = &right;


	TreeNode leftleft(1);
	TreeNode leftright(3);
	left.left = &leftleft;
	left.right = &leftright;

	TreeNode rightleft(3);
	TreeNode rightright(1);
	//right.left = &rightleft;
	right.right = &rightright;

	Solution s;
	cout<<s.rob(&root);


	return getchar();
}