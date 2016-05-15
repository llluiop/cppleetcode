#ifndef __TREE_H__
#define __TREE_H__

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
	// because our tree is binary search tree and LCA means p and q are in left tree and right tree individually,
	// so just it can be decided which way to go by comparing the value to root.
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		if (p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		return root;
	}

	// if not binary search tree.
	TreeNode* lowestCommonAncestor_General(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || p == nullptr || q == nullptr)
		{
			return nullptr;
		}

		if (isChild(p, q))
		{
			return p;
		}

		if (isChild(q, p))
		{
			return q;
		}

		
		if ((isChild(root->left, p) && isChild(root->right, q)))
		{
			return root;
		}

		if ((isChild(root->right, p) && isChild(root->left, q)))
		{
			return root;
		}

		TreeNode* pTmp = lowestCommonAncestor(root->left, p, q);
		if (pTmp != nullptr)
		{
			return pTmp;
		}

		pTmp = lowestCommonAncestor(root->right, p, q);
		if (pTmp != nullptr)
		{
			return pTmp;
		}

		return nullptr;
	}

private:
	bool isChild(TreeNode* root, TreeNode* p)
	{
		if (root == nullptr || p == nullptr)
		{
			return false;
		}

		if (root == p)
		{
			return true;
		}

		if (root->left == p || root->right == p)
		{
			return true;
		}

		return isChild(root->left, p) || isChild(root->right, p);
	}
};

#endif