
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;


class Solution {
public:
	int integerReplacement(int n) {
		int min_count =	INT_MAX;
		interger_to_one(n, 0, min_count);
		return min_count;
	}

	void interger_to_one(long long n, int count, int& min_count)
	{
		if (n == 1)
		{
			min_count = min(min_count, count);
			return;
		}
		
		if (n % 2 == 0)
		{
			interger_to_one(n / 2, count+1, min_count);
		}
		else
		{
			interger_to_one(n + 1 , count + 1, min_count);
			interger_to_one(n - 1, count + 1, min_count);
		}
	}
};


int main()
{
	Solution s;
	s.integerReplacement(2147483647);
	return getchar();
}

