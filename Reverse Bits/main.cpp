#include <iostream>
#include <bitset>

using namespace std;
typedef unsigned int uint32_t;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		bitset<32> bit(n);
		for (int i = 0; i < 16; i++)
		{
			if (bit[i] != bit[31-i])
			{
				bit.flip(i);
				bit.flip(31 - i);
			}
		}

		return (uint32_t)bit.to_ullong();
	}
};

int main()
{
	Solution s;
	cout << s.reverseBits(43261596);
	return getchar();
}