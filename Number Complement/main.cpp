
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;


/*class Solution {
public:
	int findComplement(int num) {
		int ret = 0;

		bool start = false;
		for (int i = 0; i < 32; i++)
		{
			int tmp = (num << i);
			int curbit = (tmp & 0x80000000);
			if (curbit == 0x80000000)
			{
				start = true;
			}

			if (start)
				ret = (ret << 1 | (curbit == 0x80000000 ? 0 : 1));
			
		}
		return start ? ret : 1;
	}
};*/


class Solution {
public:
	int findComplement(int num) {
		int mask = ~0;
		while (num & mask) mask <<= 1;
		return ~mask & ~num;
	}
};


int main()
{
	int x = 0x50000000;
	int y = (x << 1);
	Solution s;
	s.findComplement(5);
	return getchar();
}

