#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() < 3)
		{
			return 0;
		}

		int ret = 0;

		int size = A.size();
		for (int i = 0; i <= size-3; i++)
		{
			int base = A[i + 1] - A[i];
			for (int j = i+2; j < size; j++)
			{
				if (A[j] - A[j-1] == base)
				{
					ret++;
				}
				else
				{
					break;
				}
			}

		}

		return ret;
	}
};
int main()
{
	Solution s;
	s.numberOfArithmeticSlices(vector<int>{  1, 1 ,1, 1, 1 });
	return getchar();
}