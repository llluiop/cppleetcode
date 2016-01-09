#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		return n <= 0 ? false : n == pow(3, round(log(n) / log(3)));
	}
};

int main()
{
	Solution s;
	cout << s.isPowerOfThree(10);
	return getchar();
}