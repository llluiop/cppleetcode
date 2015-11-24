#include "node.h"
#include <iostream>
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode* pTmp = reverseList(head->next);

		head->next->next = head; 
		head->next = nullptr;

		return  pTmp;
	}
};


int main()
{

	return getchar();
}