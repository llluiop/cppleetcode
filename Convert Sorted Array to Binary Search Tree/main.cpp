#include <iostream>
#include <vector>

using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size()  == 0)
		{
			return nullptr;
		}

		TreeNode* root = new TreeNode(0);
		if (nums.size() == 1)
		{
			root->val = nums[0];

		}
		else
		{
			int mid = nums.size() / 2;
			root->val = nums[mid];
			root->left = sortedArrayToBST(vector<int>(nums.begin(), nums.begin() + mid));
			root->right = sortedArrayToBST(vector<int>(nums.begin() + mid + 1, nums.end()));
		}

		return root;
	}
};


int main()
{
	Solution s;
	TreeNode* p = s.sortedArrayToBST(vector<int>{ 1, 2, 3 });
	return getchar();
}