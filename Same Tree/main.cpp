#include "tree.h"
#include <iostream>
using namespace std;

int main()
{
	TreeNode* p = new TreeNode(1);
	TreeNode* q = new TreeNode(1);

	TreeNode* left = new TreeNode(2);
	p->left = left;

	Solution s;
	if (s.isSameTree(p, q))
	{
		cout << "same tree" << endl;
	}
		
	return getchar();
}