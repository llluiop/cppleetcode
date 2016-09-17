/**
* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) { val = x; }
}
/**/


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

class Solution {
public:
	int closestValue(TreeNode* root, double target) {
		if (root == nullptr)
		{
			return -1;
		}

		int ret = root->val;
		double min_diff = INT_MAX;


		while (root != nullptr)
		{
			double diff = abs(root->val - target);

			if (diff < min_diff)
			{
				min_diff = diff;
				ret = root->val;
			}

			if (target < root->val)
			{
				root = root->left;
			}
			else
			{
				root = root->right;
			}
		}

		return ret;
	}
};

int main()
{
	Solution s;
	s.closestValue(nullptr, 0);
	return getchar();
}

