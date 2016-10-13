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
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}

		int ret = 0;
		if (root->left != nullptr)
		{
			sum(root->left, true, ret);
		}

		if (root->right != nullptr)
		{
			sum(root->right, false, ret);
		}

		return ret;
	}
private:
	void sum(TreeNode* root, bool left, int& ret)
	{
		if (root->left == nullptr && root->right == nullptr && left == true)
		{
			ret += root->val;
			return;
		}

		if (root->left != nullptr)
		{
			sum(root->left, true, ret);
		}

		if (root->right != nullptr)
		{
			sum(root->right, false, ret);
		}
	}
};



int main()
{
	Solution s;
	TreeNode* root = new TreeNode(1);
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(3);
	TreeNode* lleft = new TreeNode(4);


	root->left = left;
	left->right = right;
	left->left = lleft;

	s.sumOfLeftLeaves(root);
}