#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		size_t size = nums.size();
		if (size <= 1)
		{
			return size;
		}

		int* len = new int[size];
		for (size_t i = 0; i < size; i++)
		{
			len[i] = 1;
		}


		int maxLen = 1;

		for (size_t i = 1; i < size; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				if (nums[j] < nums[i] && len[i] < (len[j] + 1))
				{
					len[i] = len[j] + 1;
					if (len[i] > maxLen)
					{
						maxLen = len[i];
					}
				}
			}


		}
		return maxLen;
	}
};

int main()
{
	Solution s;

	cout << s.lengthOfLIS(vector<int>{10, 9, 2, 5, 3, 7, 101, 18});

	return getchar();
}