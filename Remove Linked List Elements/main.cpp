#include "node.h"
#include <iostream>

using namespace std;

int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* ll1 = new ListNode(1);



	l1->next = ll1;




	Solution s;
	ListNode* head = s.removeElements(l1, 1);
	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}


	return getchar();
}