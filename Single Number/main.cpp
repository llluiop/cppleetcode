#include <string>
#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		
		int only = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			only = only ^ nums[i];
		}

		return only;
	}
};


int main()
{
	vector<int> v = { 4, 2, 3, 3, 2, 4, 5};
	Solution s;
	s.singleNumber(v);
	return getchar();
}