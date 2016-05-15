#ifndef __NODE_H__
#define __NODE_H__



struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		node->next = node->next->next;
	}
};


#endif // !__NODE_H__
