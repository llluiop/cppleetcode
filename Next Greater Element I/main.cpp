class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> v;

		for (int i = 0; i < findNums.size(); i++)
		{
			int cmp = findNums[i];

			bool exit = false;

			int j = -1;
			for (j = 0; j < nums.size(); j++)
			{
				if (nums[j] == cmp) break;
			}

			for (int k = j + 1; k < nums.size(); k++)
			{
				if (nums[k] > cmp)
				{
					v.push_back(nums[k]);
					exit = true;
					break;
				}
			}

			if (!exit) v.push_back(-1);
		}

		return v;
	}
};