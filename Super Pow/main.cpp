#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	const int mod = 1337;
	int superPow(int a, vector<int>& b) {
		if (b.empty())
		{
			return 1;
		}

		int last = b.back();
		b.pop_back();

		return powmn(superPow(a, b), 10) * powmn(a, last) % mod;
	}

private:
	int powmn(int a, int b)
	{
		a %= mod;
		int result = 1;

		while (b-- > 0)
		{
			result = (result*a) % mod;
		}

		return result;
	}
};

int main()
{
	Solution s;
	s.superPow(2, vector<int>{1,0});
	return getchar();
}