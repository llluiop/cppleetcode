#ifndef __NODE_H__
#define __NODE_H__

#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
		{
			return true;
		}

		vector<int> v;
		while (head != nullptr)
		{
			v.push_back(head->val);
			head = head->next;
		}

		vector<int> r(v.rbegin(), v.rend());

		return v == r;
	}
};


#endif // !__NODE_H__
