
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
	Solution()
	{
		couple_matic_['0'] = '0';
		couple_matic_['1'] = '1';
		couple_matic_['8'] = '8';
		couple_matic_['6'] = '9';
		couple_matic_['9'] = '6';

		single_matic_['0'] = '0';
		single_matic_['1'] = '1';
		single_matic_['8'] = '8';
	}
	vector<string> findStrobogrammatic(int n) {
		vector<string> v;

		string s(n, 0);
		if (n % 2 == 0)
		{
			bulid(v, n, 0, s);
		}
		else
		{
			for (auto m : single_matic_)
			{
				s[n / 2] = m.first;
				bulid(v, n, 0, s);
			}
		}

		
		return v;
	}

	void bulid(vector<string>& ret, int n, int index, string s)
	{
		if (index == n / 2)
		{
			ret.push_back(s);
			return;
		}

		for (auto c : couple_matic_)
		{
			if (index == 0 && c.first == '0')
			{
				continue;
			}
			s[index] = c.first;
			s[n - index - 1] = c.second;
			bulid(ret, n, index + 1, s);
		}
	}

private:
	map<char, char> single_matic_;
	map<char, char> couple_matic_;
};

int main()
{
	Solution s;
	s.findStrobogrammatic(4);
	return getchar();
}

