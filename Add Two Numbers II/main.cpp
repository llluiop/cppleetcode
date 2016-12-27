
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <set>
#include <numeric>
using namespace std;

/**/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		ListNode* revL1 = reverseList(l1);
		ListNode* revL2 = reverseList(l2);

		return addList(revL1, revL2);
	}

	ListNode* reverseList(ListNode* l)
	{
		if (l == nullptr || l->next == nullptr)
		{
			return l;
		}

		ListNode* head = reverseList(l->next);
		l->next->next = l;
		l->next = nullptr;

		return head;
	}

	ListNode* addList(ListNode* l1, ListNode* l2)
	{
		int carry = 0;
		ListNode* head = nullptr;
		ListNode* cur = head;
		while (l1 != nullptr && l2 != nullptr)
		{
			int val = l1->val + l2->val + carry;
			
			ListNode* tmp = new ListNode(val % 10);
			if (head == nullptr)
			{
				head = tmp;
			}
			else
			{
				cur->next = tmp;
				cur = cur->next;
			}
			carry = val / 10;
		}

		if (l1 == nullptr && l2 == nullptr)
		{
			if (carry != 0)
			{
				ListNode* tmp = new ListNode(carry);
				cur->next = tmp;
			}
		}
		else
		{
			ListNode* left = (l1 == nullptr ? l2 : l1);
			while (left != nullptr)
			{
				int val = left->val + carry;
				ListNode* tmp = new ListNode(val % 10);
				cur->next = tmp;
				cur = cur->next;

				carry = val / 10;
			}
		}

		return reverseList(head);
	}
	
};

int main()
{
	Solution s;
	ListNode* l11 = new ListNode(7);
	ListNode* l12 = new ListNode(2);
	ListNode* l13 = new ListNode(4);
	ListNode* l14 = new ListNode(3);

	l11->next = l12;
	l12->next = l13;
	l13->next = l14;
	l14->next = nullptr;

	ListNode* l21 = new ListNode(5);
	ListNode* l22 = new ListNode(6);
	ListNode* l23 = new ListNode(4);

	l21->next = l22;
	l22->next = l23;
	l13->next = nullptr;

	s.addTwoNumbers(l11, l21);
	return getchar();
}

