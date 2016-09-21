#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		int n = A.size();
		int ret = 0;
		int sum = 0;
		int f = 0;

		for (int i = 0; i < n; i++)
		{
			sum += A[i];
			f += i * A[i];
		}

		ret = f;
		for (int i = 1; i < n; i++)
		{
			f = f + sum - n * A[n - i];
			ret = max(ret, f);
		}

		return ret;
	}
};

int main()
{
	Solution s;
	s.maxRotateFunction(vector<int>{4});
	return getchar();
}