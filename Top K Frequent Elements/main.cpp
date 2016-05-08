#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	struct Pair
	{
		Pair(int key, int value)
		{
			key_ = key;
			value_ = value;
		}

		int key_;
		int value_;
	};

	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> v;
		unordered_map<int, int> mp;

		for (auto n : nums)
		{
			++mp[n];
		}

		vector<Pair> value;
		for (auto m : mp)
		{
			value.push_back(Pair(m.first, m.second));
		}

		sort(value.begin(), value.end(), [](Pair x, Pair y){return x.value_ > y.value_; });

		for (size_t i = 0; i < k; i++)
		{
			v.push_back(value[i].key_);
		}

		return v;
	}
};


int main()
{
	Solution s;

	vector<int> v = { -3, -2, -2, -3, -4, -4, -4 };
	 s.topKFrequent(v, 2);

	return getchar();
}