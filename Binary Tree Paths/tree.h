#ifndef __TREE_H__
#define __TREE_H__
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> s;

		if (root == nullptr)
		{
			return std::move(s);
		}

		vector<int> path;
		binaryTreePaths_(root, path);

		return pathes_;
	}

private:
	void binaryTreePaths_(TreeNode* root, vector<int>/*&*/ path)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			path.push_back(root->val);
			generatorPath(path);
			return;
		}

		path.push_back(root->val);

		if (root->left)
		{
			binaryTreePaths_(root->left, path);
			//path.pop_back();             //if use reference to path ,you need to pop_back here!!!
		}

		if (root->right)
		{
			binaryTreePaths_(root->right, path);
			//path.pop_back();
		}
	}

	void generatorPath(const vector<int>& path)
	{
		stringstream s;

		
		for (int i = 0; i < path.size(); i++)
		{
			s << path[i];
			if (i != path.size() -1)
			{
				s << "->";
			}
		}

		pathes_.push_back(s.str());
	}

private:
	vector<string> pathes_;
};


#endif