#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		return generate(1, n);
	}


	vector<TreeNode*> generate(int left, int right)
	{
		if (left > right)
		{
			return{};
		}
		vector<TreeNode*> res;
		for (int i = left; i <= right; i++)
		{		
			vector<TreeNode*> l = generate(left, i - 1);
			vector<TreeNode*> r = generate(i + 1, right);

			if (l.size() == 0 && r.size() == 0)
			{
				TreeNode* t = new TreeNode(i);
				res.push_back(t);
			}

			else if (l.size() == 0)
			{
				for (auto rr : r)
				{
					TreeNode* t = new TreeNode(i);
					t->left = nullptr;
					t->right = rr;

					res.push_back(t);
				}
			}

			else if (r.size() == 0)
			{
				for (auto ll : l)
				{
					TreeNode* t = new TreeNode(i);
					t->left = ll;
					t->right = nullptr;

					res.push_back(t);
				}
			}

			else
			{
				for (auto ll : l)
				{
					for (auto rr : r)
					{
						TreeNode* t = new TreeNode(i);
						t->left = ll;
						t->right = rr;

						res.push_back(t);
					}
				}
			}
		}

		return res;
	}
};


int main()
{
	Solution s;
	s.generateTrees(3);
	return getchar();
}