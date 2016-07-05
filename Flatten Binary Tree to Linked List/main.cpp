

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == nullptr)
		{
			return;
		}

		auto l = root->left;
		auto r = root->right;


		flatten(l);
		flatten(r);
		

		root->left = nullptr;
		root->right = l;
		while (root->right)
		{
			root = root->right;
		}

		root->right = r;
	}
	
};


int main()
{
	TreeNode* root1 = new TreeNode(1);
	TreeNode* root2 = new TreeNode(2);
	TreeNode* root3 = new TreeNode(3);
	TreeNode* root4 = new TreeNode(4);
	TreeNode* root5 = new TreeNode(5);
	TreeNode* root6 = new TreeNode(6);

	root1->left = root2;
	//root1->right = root5;

	//root2->left = root3;
	//root2->right = root4;

	//root5->left = root6;

	Solution s;

	s.flatten(root1);
	return getchar();
}