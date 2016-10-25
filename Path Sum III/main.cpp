#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
		{
			return 0;
		}

		int count = 0;
		path_sum(root, sum, count);
		return count;
	}

	void path_sum(TreeNode* root, int sum, int& count)
	{
		if (root!= nullptr)
		{
			find_path(root, sum, count);
		}

		if (root->left)
		{
			path_sum(root->left, sum, count);
		}

		if (root->right)
		{
			path_sum(root->right, sum, count);
		}
	}

	void find_path(TreeNode* root, int sum, int& count)
	{
		if (root == nullptr)
		{
			return;
		}

		if (sum == root->val)
		{
			count++;
		}

		if (root->left)
		{
			find_path(root->left, sum - root->val, count);
		}

		if (root->right)
		{
			find_path(root->right, sum - root->val, count);
		}
	}
};

int main()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(3);
	TreeNode* lleft = new TreeNode(1);


	root->left = left;
	root->right = right;
	left->left = lleft;

	s.pathSum(root, 3);
}