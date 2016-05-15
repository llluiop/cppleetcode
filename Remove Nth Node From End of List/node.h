#ifndef __NODE_H__
#define __NODE_H__



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr)
			return nullptr;


		ListNode* pHead = head;
		ListNode* pEnd = head;

		while (n >= 0)
		{
			if (pEnd == nullptr)
				return pHead->next;

			pEnd = pEnd->next;
			--n;
		}

		while (pEnd)
		{
			pEnd = pEnd->next;
			pHead = pHead->next;
		}

		pHead->next = pHead->next->next;


		return head;
	}
};

#endif // !__NODE_H__