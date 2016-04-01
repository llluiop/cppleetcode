#include <iostream>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		ListNode* odd = head;
		ListNode* even = head->next;
		ListNode* evenhead = head->next;

		while (even != nullptr && even->next != nullptr)
		{
			odd->next = even->next;
			even->next = even->next->next;

			odd = odd->next;
			even = even->next;
		}

		odd->next = evenhead;

		return head;
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
	node4->next = node5;
	node5->next = nullptr;

	ListNode* pHead = s.oddEvenList(node1);
	while (pHead != nullptr)
	{
		std::cout << pHead->val << std::endl;
		pHead = pHead->next;
	}

	return getchar();
}