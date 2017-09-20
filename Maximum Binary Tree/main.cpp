#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
* Definition for a binary tree node.
* */struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
/**/
class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.size() == 0) return nullptr;


		auto it = max_element(std::begin(nums), std::end(nums));
		int value = *it;
		int pos = it - nums.begin();
		TreeNode* root = new TreeNode(value);

		if (pos > 0)
		{
			vector<int> left(nums.begin(), nums.begin() + pos);
			root->left = constructMaximumBinaryTree(left);

		}
		else
			root->left = nullptr;

		if (pos < nums.size() - 1)
		{
			vector<int> right(nums.begin() + pos + 1, nums.end());
			root->right = constructMaximumBinaryTree(right);
		}
		else
			root->right = nullptr;

		return root;
	}
};


int main()
{
	Solution s;
	s.constructMaximumBinaryTree(vector<int>{3, 2, 1, 6, 0, 5});
	return getchar();
}