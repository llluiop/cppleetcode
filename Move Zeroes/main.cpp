#include "array.h"
#include <iostream>

using namespace std;

int main()
{
	vector<int> v = { 1, 0, 2, 0, 3, 0 };
	Solution s;
	s.moveZeroes(v);

	for (auto x : v)
	{
		cout << x << " ";
	}

	return getchar();
}