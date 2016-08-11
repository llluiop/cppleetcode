#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return head;
		}

		auto cur = head->next;

		while (cur != nullptr)
		{
			auto tmp = head;
			while (cur->val > tmp->val)
			{
				tmp = tmp->next;
			}

			int pre = cur->val;
			int nextVal = tmp->val;

			while (cur != tmp)
			{
				nextVal = tmp->val;
				tmp->val = pre;
				pre = nextVal;
				tmp = tmp->next;
			}

			tmp->val = nextVal;
			cur = cur->next;
		}

		return head;
	}
};

int main()
{
	Solution s;
	ListNode* head = new ListNode(1);
	ListNode* l = new ListNode(3);
	ListNode* ll = new ListNode(5);
	ListNode* lll = new ListNode(2);

	head->next = l;
	l->next = ll;
	ll->next = lll;

	s.insertionSortList(head);

	return getchar();
}