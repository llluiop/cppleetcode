#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		int sum = 0;
		for (int i = 1; i*i <= n; i++)
		{
			++sum;
		}

		return sum;
	}
};

int main()
{
	Solution s;
	cout<<s.bulbSwitch(99999999);
	return getchar();
}