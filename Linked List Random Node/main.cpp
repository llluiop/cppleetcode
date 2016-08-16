#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <time.h>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	Solution(ListNode* head):count_(0) {
		head_ = head;
		while (head)
		{
			++count_;
			head = head->next;
		}
	}

	int getRandom() {
		int index = rand() % count_;
		auto node = head_;

		while (index > 0)
		{
			node = node->next;
			--index;
		}
		return node->val;
	}

private:
	ListNode* head_;
	int count_;
};



int main()
{
	ListNode* head = new ListNode(2);
	ListNode* l = new ListNode(1);
	ListNode* ll = new ListNode(3);
	ListNode* lll = new ListNode(4);
	ListNode* llll = new ListNode(5);
	ListNode* lllll = new ListNode(6);

	head->next = l;
	l->next = ll;
	ll->next = lll;
	lll->next = llll;
	llll->next = lllll;

	Solution s(head);

	for (int i = 0; i < 1000; i++)
	{
		cout << s.getRandom();
	}

	return getchar();
}