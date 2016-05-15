#include "node.h"
#include <iostream>

using namespace std;

int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* ll1 = new ListNode(4);
	ListNode* lll1 = new ListNode(8);
	ListNode* l2 = new ListNode(2);
	ListNode* ll2 = new ListNode(3);

	l1->next = ll1;
	ll1->next = lll1;

	l2->next = ll2;

	Solution s;
	ListNode* head = s.mergeTwoLists(l1, l2);
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}


	return getchar();
}