#ifndef __NODE_H__
#define __NODE_H__



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};



#endif // !__NODE_H__