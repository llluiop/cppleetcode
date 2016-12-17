
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <set>
#include <numeric>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupStrings(vector<string>& strings) {
		vector<vector<string>> ret;

		map<int, vector<string>> m;
		for (auto s : strings)
		{
			m[s.length()].push_back(s);
		}

		for (auto s : m)
		{
			auto v = s.second;
			map<string, vector<string>> mm;

			for (auto str : v)
			{
				mm[normalLize(str)].push_back(str);
			}

			for (auto r : mm)
			{
				ret.push_back(r.second);
			}
		}

		return ret;
	}

	string normalLize(string s)
	{
		int base = s[0] - 'a';
		string tmp;
		for (auto c:s)
		{
			tmp += (c + 26 - base) % 26;
		}

		return tmp;
	}
};

int main()
{
	Solution s;
	s.groupStrings(vector<string>({ "abc", "bcd", "acef", "xyz", "az", "ab", "bc", "ba", "a", "z" }));
	return getchar();
}

