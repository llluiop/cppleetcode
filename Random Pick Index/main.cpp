#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
public:
	Solution(vector<int> nums) {
		nums_ = nums;
	}

	int pick(int target) {
		int ans;
		int cnt = 1;

		for (int i = 0; i < nums_.size(); i++)
		{
			if (nums_[i] == target && (rand() % cnt++) == 0)
			{
				ans = i;
			}
		}

		return ans;
	}

private:
	vector<int> nums_;
};


int main()
{
	Solution s({ 1, 2, 3, 3, 5 });
	cout<<s.pick(3);
	return getchar();
}