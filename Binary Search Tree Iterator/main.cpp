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


class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		auto r = root;
		while (r != nullptr)
		{
			v_.push_back(r);
			r = r->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !v_.empty();
	}

	/** @return the next smallest number */
	int next() {
		auto r = v_.back();
		int val = r->val;
		v_.pop_back();


		if (r->right != nullptr)
		{
			r = r->right;
			while (r != nullptr)
			{
				v_.push_back(r);
				r = r->left;
			}
		}

		return val;
	}

	vector<TreeNode*> v_;
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

	BSTIterator s(root);
	while (s.hasNext())
	{
		cout << s.next() << endl;
	}

	return getchar();
}