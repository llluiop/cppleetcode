#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;


class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		while (n > m)
		{
			n = n&(n - 1);
		}
		return n;
	}
};


int main()
{
	Solution s;
	s.rangeBitwiseAnd(1, 2);

	return getchar();
}