class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);

		queue<TreeNode*> level;
		int leftmost = root->val;

		bool isleft = true;
		while (!q.empty())
		{
			auto tmp = q.front();
			q.pop();

			if (isleft)
			{
				leftmost = tmp->val;
				isleft = false;
			}

			if (tmp->left) level.push(tmp->left);
			if (tmp->right) level.push(tmp->right);

			if (q.empty())
			{
				q.swap(level);
				isleft = true;
			}
		}
		return leftmost;
	}
};