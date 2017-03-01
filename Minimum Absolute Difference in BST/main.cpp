class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		if (root == NULL) return INT_MAX;

		int min_now = INT_MAX;
		if (root->left) min_now = min(min_now, abs(LeftNearest(root)->val - root->val));
		if (root->right) min_now = min(min_now, abs(RightNearest(root)->val - root->val));

		return min(min_now, min(getMinimumDifference(root->left), getMinimumDifference(root->right)));
	}

	TreeNode* LeftNearest(TreeNode* root)
	{
		root = root->left;
		while (root->right)
		{
			root = root->right;
		}

		return root;
	}

	TreeNode* RightNearest(TreeNode* root)
	{
		root = root->right;
		while (root->left)
		{
			root = root->left;
		}

		return root;
	}
};