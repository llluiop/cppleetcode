#include "stack.h"
#include <iostream>

using namespace std;

int main()
{

	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	s.pop();

	cout << s.top();
	return getchar();
}