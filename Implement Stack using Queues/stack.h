#ifndef __STACK_H__
#define	__STACK_H__		

#include <queue>
using namespace std;

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		q1.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		while (!q1.empty())
		{
			if ( q1.size() != 1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			else
			{
				q1.pop();
			}
		}

		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
	}

	// Get the top element.
	int top() {
		int top_ = 0;

		while (!q1.empty())
		{
			if (1 == q1.size())
			{
				top_ = q1.front();
			}

			q2.push(q1.front());
			q1.pop();
		}

		while (!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}

		return top_;
	}

	// Return whether the stack is empty.
	bool empty() {
		return q1.empty();
	}

private:
	queue<int> q1;
	queue<int> q2;
};

#endif