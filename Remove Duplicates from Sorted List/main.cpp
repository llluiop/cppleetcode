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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
		{
			return head;
		}

		ListNode* cur = head;
		ListNode* next = head->next;

		while (next != nullptr)
		{
			if (cur->val == next->val)
			{
				cur->next = next->next;
				next = cur->next;
			}
			else
			{
				cur = next;
				next = next->next;
			}
		}

		/*		
		ListNode* cur = head;
		while (cur->next != nullptr)
		{
			if (cur->val == cur->next->val)
			{
				*cur = *cur->next;
			}
			else
			{
				cur = cur->next;
			}
		}
		*/

		return  head;
	}
};


