#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		if (numbers.size() == 0 || numbers[0] > target)
		{
			return{};
		}

		int start = 0;
		int end = numbers.size() - 1;

		while (start < end)
		{
			if (numbers[start] + numbers[end] == target)
			{
				return{ start+1, end+1 };
			}
			else if (numbers[start] + numbers[end] > target)
			{
				end--;
			}
			else
			{
				start++;
			}
		}

		return{};
	}
};
int main()
{
	Solution s;
	s.twoSum(vector<int>{2, 7, 11, 15}, 18);
	return getchar();
}