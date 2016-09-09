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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr)
		{
			return nullptr;
		}


		if (in(p, q))
		{
			return p;
		}

		if (in(q, p))
		{
			return q;
		}

		return lowestCommonAncestor_(root, p, q);
	}

	TreeNode* lowestCommonAncestor_(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		if (in(root->left, p) && in(root->right, q))
		{
			return root;
		}

		if (in(root->left, q) && in(root->right, p))
		{
			return root;
		}

		TreeNode* ret = lowestCommonAncestor_(root->left, p, q);
		if (ret)
		{
			return ret;
		}

		ret = lowestCommonAncestor_(root->right, p, q);
		if (ret)
		{
			return ret;
		}

		return nullptr;
	}


	bool in(TreeNode* root, TreeNode* src)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root == src)
		{
			return true;
		}

		bool b = false;
		if (root->left != nullptr)
		{
			b = in(root->left, src);
		}
		if (root->right != nullptr)
		{
			b |= in(root->right, src);
		}

		return b;
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
	root->right = right;
	left->left = lleft;

	auto r = s.lowestCommonAncestor(root, lleft, right);

}