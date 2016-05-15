#include <iostream>
#include "queue.h"

int main()
{
	Queue s;
	s.push(1);
	s.push(2);
	s.push(3);

	s.pop();
	cout << s.peek();

	return getchar();
}