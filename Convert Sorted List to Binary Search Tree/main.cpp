#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head)
	{
		return sortedListToBST(head, NULL);
	}

private:
	TreeNode *sortedListToBST(ListNode *head, ListNode *tail)
	{
		if (head == tail)
			return NULL;
		if (head->next == tail)    // 
		{
			TreeNode *root = new TreeNode(head->val);
			return root;
		}
		ListNode *mid = head, *temp = head;
		while (temp != tail && temp->next != tail)    // 寻找中间节点
		{
			mid = mid->next;
			temp = temp->next->next;
		}
		TreeNode *root = new TreeNode(mid->val);
		root->left = sortedListToBST(head, mid);
		root->right = sortedListToBST(mid->next, tail);
		return root;
	}
};



int main()
{
	Solution s;
	ListNode* root = new ListNode(1);
	ListNode* left = new ListNode(2);
	ListNode* right = new ListNode(3);
	ListNode* lleft = new ListNode(4);


	root->next = left;
	left->next = right;
	right->next = lleft;

	s.sortedListToBST(root);
}