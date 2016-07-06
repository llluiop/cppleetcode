#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		if (a == 0)
		{
			return b;
		}

		return getSum((a&b) << 1, a^b);
		
	}
};


int main()
{
	Solution s;

	cout << s.getSum(1, 2);
	return getchar();
}