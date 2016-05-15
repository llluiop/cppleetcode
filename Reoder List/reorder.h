#ifndef __REORDER_H__
#define __REORDER_H__

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}

		//reorderListByRecurse(head);  //time exceeded

		ListNode* pList1 = head;
		ListNode* pList2 = split(head);

		pList2 = reverse(pList2);  
		merge(pList1, pList2);
		
	}

private:
	ListNode* split(ListNode* node)
	{
		ListNode* pHead = node;
		
		ListNode* pSlow = pHead;
		ListNode* pFast = pHead;

		while (pFast->next != nullptr && pFast->next->next != nullptr)
		{
			pSlow = pSlow->next;
			pFast = pFast->next->next;
		}

		if (pFast->next != nullptr)
		{
			pSlow = pSlow->next;
			pFast = pFast->next;
		}

		ListNode* pList2Head = pSlow->next;
		pSlow->next = nullptr; //cut the original list

		return pList2Head;

	}

	ListNode* reverse(ListNode* node)
	{
		if (node == nullptr || node->next == nullptr)
		{
			return node;
		}

		ListNode* pHead = node;		
		ListNode* pTmp = pHead->next;

		pHead->next = nullptr;

		while (pTmp != nullptr)
		{
			ListNode* pNext = pTmp->next;
			pTmp->next = pHead;

			pHead = pTmp;
			pTmp = pNext;
		}

		return pHead;

	}

	void merge(ListNode* node1, ListNode* node2)
	{
		while (node1 != nullptr && node2 != nullptr)
		{
			ListNode* pTmp1 = node1->next;
			ListNode* pTmp2 = node2->next;

			node1->next = node2;
			node2->next = pTmp1;

			node1 = pTmp1;
			node2 = pTmp2;
		}
	}

	ListNode* reorderListByRecurse(ListNode* node)
	{
		if (node->next == nullptr || node->next->next == nullptr)
		{
			return node;
		}

		ListNode* pAfterHead = node->next;

		ListNode* pTail = node;
		ListNode* pBeforeTail = pTail;
		while (pTail->next != nullptr)
		{
			pBeforeTail = pTail;
			pTail = pTail->next;			
		}

		pBeforeTail->next = nullptr;

		node->next = pTail;
		pTail->next = reorderListByRecurse(pAfterHead);	

		return node;
	}
};

#endif 
