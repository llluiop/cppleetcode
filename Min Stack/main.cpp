#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
	void push(int x) {
		s_.push(x);

		if (bak_.empty())
		{
			bak_.push(x);
		}
		else
		{
			int temp = bak_.top();
			if (temp > x)
			{
				temp = x;
			}

			bak_.push(temp);
		}
	}

	void pop() {
		s_.pop();
		bak_.pop();
	}

	int top() {
		return s_.top();
	}

	int getMin() {
		return bak_.top();
	}

private:
	stack<int> s_;
	stack<int> bak_;
};


int main()
{
	MinStack s;
	s.push(1);
	return getchar();
}