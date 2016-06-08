#ifndef __NODE_H__
#define __NODE_H__

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


#endif // !__NODE_H__