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

		ListNode* newHead = nullptr;
		ListNode* cur = head;


		while (cur )
		{
			cur = SingleNode(cur);
			if (newHead == nullptr)
			{
				newHead = cur;
				head = newHead;
			}
			else
			{
				newHead->next = cur;
				newHead = cur;
			}

			if (cur == nullptr)
			{
				break;
			}
			cur = cur->next;
		}

		return  head;
	}

	ListNode* SingleNode(ListNode* node)
	{
		if (node == nullptr || node->next == nullptr)
		{
			return node;
		}


		bool dup = false;
		while (node)
		{
			if (node->next == nullptr )
			{
				return  dup != false ? nullptr : node;
			}

			if (node->val == node->next->val)
			{
				dup = true;
			}
			else
			{
				if (!dup)
				{
					return node;
				}

				dup = false;
			}
			node = node->next;
		}


		return nullptr;
	}
};


int main()
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(1);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	ListNode* node6 = new ListNode(5);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = nullptr;

	Solution s;
	ListNode* tmp = s.deleteDuplicates(node1);

	return getchar();
}


