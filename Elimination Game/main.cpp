
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <set>
#include <numeric>
using namespace std;

class Solution {
public:
	int lastRemaining(int n) {


		return last(n, true);
	}

	int last(int n, bool left2right)
	{
		if (n <= 1)
		{
			return 1;
		}

		if (left2right)
		{
			return 2 * last(n / 2, false);
		}
		else
		{
			return 2 * last(n / 2, true) - 1 + n % 2;
		}
	}
};


int main()
{
	Solution s;
	s.lastRemaining(10);
	return getchar();
}

