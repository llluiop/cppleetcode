#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr)
		{
			return nullptr;
		}

		ListNode* p1 = headA;
		ListNode* p2 = headB;
		while (p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;
			if (p1 == nullptr && p2 != nullptr)
			{
				p1 = headB;
			}


			if (p2 == nullptr && p1 != nullptr)
			{
				p2 = headA;
			}
		}

		return p1;
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

	//s.getIntersectionNode(node1);


	return getchar();
}