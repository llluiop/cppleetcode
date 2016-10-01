
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
	int Paint(int n, int k) //n: fences, k: colors
	{
		if (n == 1)
		{
			return k;
		}

		int dp1 = k;
		int dp2 = k * k;

		int dp3 = (k - 1)*dp1 + (k - 2)*dp2;
		for (int i = 3; i <= n; i++)
		{
			dp3 = (k - 1)*dp1 + (k - 2)*dp2;
			dp3 = dp2;
			dp2 = dp1;
		}

		return dp3;
	}
};

int main()
{
	Solution s;
	s.Paint(4, 4);
	return getchar();
}

