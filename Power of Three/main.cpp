#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		int tmp = round(log(n) / log(3));
		return n <= 0 ? false : n == pow(3, tmp);
	}
};

int main()
{
	Solution s;
	cout << s.isPowerOfThree(10);
	return getchar();
}