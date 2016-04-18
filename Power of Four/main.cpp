#include <iostream>


class Solution {
public:
	bool isPowerOfFour(int num) {
		return num >= 1 && (num&(num - 1)) == 0 && (num - 1) % 3 == 0;
	}
};

int main()
{
	Solution s;

	std::cout<<s.isPowerOfFour(4);


	return getchar();
}