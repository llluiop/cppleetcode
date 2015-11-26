#ifndef __NODE_H__
#define __NODE_H__



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
		{
			return l2;
		}

		if (l2 == nullptr)
		{
			return l1;
		}

		ListNode* head = nullptr;
		ListNode* tmp = head;
		while (l1 != nullptr && l2 != nullptr)
		{
			if (l1->val >= l2->val)
			{
				if (head == nullptr)
				{
					head = l2;
					tmp = head;
				}
				else
				{
					tmp->next = l2;
					tmp = tmp->next;
				}
				l2 = l2->next;
			}
			else
			{
				if (head == nullptr)
				{
					head = l1;
					tmp = head;
				}
				else
				{
					tmp->next = l1;
					tmp = tmp->next;
				}
				l1 = l1->next;
			}


		}

		while (l1 != nullptr)
		{
			tmp->next = l1;
			l1 = l1->next;
			tmp = tmp->next;
		}

		while (l2 != nullptr)
		{
			tmp->next = l2;
			l2 = l2->next;
			tmp = tmp->next;
		}

		return head;
	}
};

#endif // !__NODE_H__