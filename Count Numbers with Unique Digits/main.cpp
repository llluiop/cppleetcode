#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n <= 0)
			return 1;

		int sum = 10;
		for (int i = 1; i < n; i++)
		{
			int digroot = 9;
			for (int j = 0; j < i; j++)
			{
				digroot *= (9 - j);
			}
			sum += digroot;
		}

		return sum;
	}
};

int main()
{
	Solution s;

	cout << s.countNumbersWithUniqueDigits(15);

	return getchar();
}