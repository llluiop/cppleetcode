#ifndef __NODE_H__
#define __NODE_H__



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		while (head && head->val == val)
		{
			head = head->next;
		}

		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode* pHead = head;
		ListNode* pNext = head->next;
		while (pNext != nullptr)
		{
			if (pNext->val == val)
			{
				head->next = pNext->next;
			}
			else
			{
				head = head->next;
			}
			pNext = pNext->next;
		}

		return pHead;

	}
};

#endif // !__NODE_H__
