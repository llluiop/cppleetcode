
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	Solution(){ sum_ = 0; }
	int sumNumbers(TreeNode* root) {
		if (root == nullptr)
			return sum_;

		countSum(root, 0);

		return sum_;
	}


	void countSum(TreeNode* root, int count)
	{
		count = count * 10 + root->val;
		if (root->left == nullptr && root->right == nullptr)
		{
			sum_ += count;
			return;
		}


		if (root->left != nullptr)
		{
			countSum(root->left, count);
		}

		if (root->right != nullptr)
		{
			countSum(root->right, count);
		}

	}

	
private:
	int sum_;
};



int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(3);

	root->left = left;
	root->right = right;

	Solution s;
	s.sumNumbers(root);
}