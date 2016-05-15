#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		sort(nums.begin(), nums.end());

		auto iter = find(nums.begin(), nums.end(), val);
		if (iter != nums.end())
		{
			auto iterLast = iter;
			while (iterLast != nums.end() && *iterLast == val)
			{
				++iterLast;
			}

			nums.erase(iter, iterLast);
		}

		return nums.size();
	}
};

int main()
{
	Solution s;

	vector<int> num = { 1, 6, 8, 7, 4, 1, 2, 3, 6, 45, 4 };
	cout << s.removeElement(num, 45);
	return getchar();
}