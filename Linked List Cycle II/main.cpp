#include <iostream>
#include <set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// class Solution {
// public:
// 	ListNode *detectCycle(ListNode *head) {
// 		set<ListNode*> s;
// 
// 		ListNode* node = nullptr;
// 		while (head != nullptr)
// 		{
// 			if (s.find(head) != s.end())
// 			{
// 				node = head;
// 				return node;
// 			}
// 			s.insert(head);
// 
// 			head = head->next;
// 		}
// 
// 		return nullptr;
// 	}
// };

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
		{
			return nullptr;
		}

		ListNode* entry = head;

		ListNode* p1 = head;
		ListNode* p2 = head;
		while (p2->next != nullptr && p2->next->next != nullptr)
		{
			p1 = p1->next;
			p2 = p2->next->next;

			if (p1 == p2)
			{
				while (entry != p1)
				{
					entry = entry->next;
					p1 = p1->next;
				}

				return entry;
			}


		}

		return nullptr;
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
	node5->next = node2;

	std::cout << s.detectCycle(node1);


	return getchar();
}