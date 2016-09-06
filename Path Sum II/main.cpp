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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
		{
			return{};
		}

		vector<vector<int>> v;

		vector<int> p;
		path(root, sum, p, v);
		return v;
	}

	void path(TreeNode* root, int sum, vector<int> p, vector<vector<int>>& v)
	{
		if (root == nullptr)
		{
			return;
		}


		p.push_back(root->val);

		if (sum == root->val && root->left == nullptr && root->right == nullptr)
		{
			v.push_back(p);
			return;
		}


		if (root->left != nullptr)
		{
			path(root->left, sum - root->val, p, v);
		}

		if (root->right != nullptr)
		{
			path(root->right, sum - root->val, p, v);
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

	s.pathSum(root, 4);
}