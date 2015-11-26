#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <stack>
using namespace std;

class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		s_.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (s_.empty())
		{
			return;
		}

		while (!s_.empty())
		{
			backup_.push(s_.top());
			s_.pop();
		}

		backup_.pop();

		while (!backup_.empty())
		{
			s_.push(backup_.top());
			backup_.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		if (s_.empty())
		{
			return 0;
		}

		while (!s_.empty())
		{
			backup_.push(s_.top());
			s_.pop();
		}

		int tmp = backup_.top();

		while (!backup_.empty())
		{
			s_.push(backup_.top());
			backup_.pop();
		}

		return tmp;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return s_.empty();
	}

private:
	stack<int> s_;
	stack<int> backup_;
};

#endif
