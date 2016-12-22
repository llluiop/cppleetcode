
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <set>
#include <numeric>
using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<int>> findLeaves(TreeNode* root) {
		vector<vector<int>> res;
		while (root) {
			vector<int> leaves;
			root = remove(root, leaves);
			res.push_back(leaves);
		}
		return res;
	}
	TreeNode* remove(TreeNode *node, vector<int> &leaves) {
		if (!node) return NULL;
		if (!node->left && !node->right) {
			leaves.push_back(node->val);
			return NULL;
		}
		node->left = remove(node->left, leaves);
		node->right = remove(node->right, leaves);
		return node;
	}
};

int main()
{
	TreeNode* root = new TreeNode(0);
	TreeNode* left = new TreeNode(1);
	TreeNode* right = new TreeNode(2);
	TreeNode* leftleft = new TreeNode(3);
	TreeNode* leftleftleft = new TreeNode(4);

	root->left = left;
	root->right = right;

	left->left = leftleft;
	leftleft->left = leftleftleft;

	Solution s;
	s.RemoveLeaves(root);
	return getchar();
}

