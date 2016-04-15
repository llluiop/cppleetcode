#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode* pTmp = head->next;

		ListNode* pPre = nullptr;
		while (head != nullptr && head->next != nullptr)
		{
			if (pPre != nullptr)
			{
				pPre->next = head->next;
			}

			ListNode* pNode = head->next->next;
			head->next->next = head;
			head->next = pNode;

			pPre = head;
			head = head->next;
		}

		return pTmp;
	}
};

int main()
{
	Solution s;

	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = nullptr;
	node5->next = nullptr;

	s.swapPairs(node1);


	return getchar();
}