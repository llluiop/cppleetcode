#include <iostream>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
		{
			return false;
		}

		ListNode* p1 = head;
		ListNode* p2 = head->next;
		while (p2 != nullptr && p2->next != nullptr)
		{
			if (p1 == p2)
				return true;

			p1 = p1->next;
			p2 = p2->next->next;
		}

		return false;
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
	node5->next = node1;

	std::cout << s.hasCycle(node1);


	return getchar();
}