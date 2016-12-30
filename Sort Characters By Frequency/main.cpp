
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
	struct t
	{
		char c;
		int num;
		bool operator <(const t& t)
		{
			return this->num < t.num;
		}
	};
	string frequencySort(string s) {
		map<char, int> m;
		for (auto c : s)
		{
			m[c]++;
		}

		vector<t> vv;
		for (auto node : m)
		{
			vv.push_back({ node.first, node.second });
		}

		string ret = "";
		sort(vv.begin(), vv.end());
		for (auto v : vv)
		{
			for (int i = 0; i < v.num; i++)
			{
				ret += v.c;
			}
		}

		reverse(ret.begin(), ret.end());
		return ret;
	}
};


int main()
{
	Solution s;
	s.frequencySort("Aabbaaa");
	return getchar();
}

