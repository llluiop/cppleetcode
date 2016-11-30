
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <map>
#include <bitset>
using namespace std;

struct Node
{
	int val;
	Node* left;
	Node* right;

	Node(int val)
	{
		this->val = val;
		left = right = nullptr;
	}
};

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		auto root = BuildTrieTree(nums);

		int maxXor = INT_MIN;
		for (auto n : nums)
		{
			maxXor = max(maxXor, MaxXor(n, root));
		}

		return maxXor;
	}

	Node* BuildTrieTree(vector<int>& nums)
	{
		Node* root = new Node(0);
		for (auto n : nums)
		{
			Node* cur = root;

			bitset<32> set(n);
			for (int i = 30; i >= 0; i--)
			{
				Node* tmp = new Node(set[i]);
				if (tmp->val == 0)
				{
					if (cur->left == nullptr){ 
						cur->left = tmp; cur = tmp;
					}
					else cur = cur->left;
					
				}
				else if (tmp->val == 1)
				{
					if (cur->right == nullptr) {
						cur->right = tmp; cur = tmp;
					}
					else cur = cur->right;
				}
			}
		}

		return root;
	}

	int MaxXor(int n, Node* root)
	{
		bitset<32> set(n);

		int xor = 0;
		for (int i = 30; i >= 0; i--)
		{
			int bit = set[i];

			if (bit == 0)
			{
				if (root->right != nullptr)
				{
					root = root->right;
					xor += (1 - bit) << i;
				}
				else
				{
					root = root->left;
					xor += (bit) << i;
				}
			}
			else
			{
				if (root->left != nullptr)
				{
					root = root->left;
					xor += (1 - bit) << i;
				}
				else
				{
					root = root->right;
					xor += (bit) << i;
				}
			}
		}
		return xor ^ n;
	}
};


int main()
{
	Solution s;
	s.findMaximumXOR(vector<int>({ 3, 10, 5, 25, 2, 8 }));
	return getchar();
}

