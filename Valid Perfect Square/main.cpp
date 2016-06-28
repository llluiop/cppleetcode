#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num <= 0)
		{
			return false;
		}

		__int64 i = 1;
		__int64 max = 1;
		while (max < (__int64)num)
		{
			max = i * i;
			i++;
		}

		return max == num;
	}
};

int main()
{
	Solution s;

	s.isPerfectSquare(2147483647);
	return getchar();
}
