#include <iostream>
#include <vector>
#include <algorithm>
#include <hash_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if (strs.size() == 0)
		{
			return{};
		}

		hash_map<string, vector<string>> hashValue;
		vector<vector<string>> ret;
		for (auto s : strs)
		{
			auto key = s;
			sort(key.begin(), key.end());
			hashValue[key].push_back(s);
		}

		for (auto s : hashValue)
		{
			ret.push_back(s.second);
		}
		return ret;
	}
};


int main()
{
	Solution s;

	s.groupAnagrams(vector<string>{"eat", "tea", "tan", "ate", "nat", "bat"});
	return getchar();
}