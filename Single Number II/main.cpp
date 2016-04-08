#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;

		for (int i = 0; i < 32; i++)
		{
			int cut = 0;
			int mask = (1 << i);

			for (auto num : nums)
			{
				cut += bool(num & mask);
			}

			if (cut % 3)
			{
				result |= mask;
			}
		}

		return result;

	}
};
int main()
{
	Solution s;

	vector<int> num = { -19, -46, -19, -46, -9, -9, -19, 17, 17, 17, -13, -13, -9, -13, -46, -28 };
	cout << s.singleNumber(num);
	return getchar();
}