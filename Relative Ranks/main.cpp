class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<int> tmp(nums);
		sort(tmp.begin(), tmp.end());

		vector<string> ret;
		for (auto num : nums)
		{
			auto iter = find(tmp.begin(), tmp.end(), num);
			if (tmp.end() - iter == 1) ret.push_back("Gold Medal");
			else if (tmp.end() - iter == 2) ret.push_back("Silver Medal");
			else if (tmp.end() - iter == 3) ret.push_back("Bronze Medal");
			else ret.push_back(to_string(tmp.end() - iter));
		}

		return ret;
	}
};