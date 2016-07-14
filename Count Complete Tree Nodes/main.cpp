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
	int countNodes(TreeNode* root) {
		return count(root);
	}

private:
	int count(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		
		int l = lheight(root->left);
		int r = rheight(root->right);

		if (l == r)
		{
			return (2 << (l)) - 1;
		}
		else
		{
			return count(root->left) + count(root->right) + 1;
		}
	}

	int count(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		int l = lheight(root->left);
		int r = lheight(root->right);

		if (l > r)
		{
			return count(root->left) + (1 << (r));
		}
		else
		{
			return count(root->right) + (1 << (l));
		}
	}

	int lheight(TreeNode* root)
	{
		int sum = 0;
		while (root)
		{
			root = root->left;
			++sum;
		}

		return sum;
	}

	int rheight(TreeNode* root)
	{
		int sum = 0;
		while (root)
		{
			root = root->right;
			++sum;
		}

		return sum;
	}
};



int main()
{
	Solution s;
	s.countNodes(nullptr);
}