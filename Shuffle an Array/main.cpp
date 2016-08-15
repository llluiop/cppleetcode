#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>


using namespace std;

class Solution {
public:
	Solution(vector<int> nums) {
		v.swap(nums);
		vv = v;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return vv;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		next_permutation(v.begin(), v.end());
		return v;
	}

private:
	vector<int> v;
	vector<int> vv;
};

int main()
{
	Solution s({ 1, 2, 3 });
	return getchar();
}