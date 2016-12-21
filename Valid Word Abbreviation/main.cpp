
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
	bool valid(string val, string abbr)
	{
		if (val == "" && abbr != "")
		{
			return false;
		}

		int start = 0;
		tuple<bool, int, int> ret;

		do 
		{
			auto ret = consume(abbr, get<1>(ret));
			if (get<0>(ret))
			{
				start += get<1>(ret);
			}
			else
			{
				if (get<1>(ret) == -1)
				{
					break;
				}
				else
				{
					if (get<1>(ret) != val[start])
					{
						return false;
					}
					start++;
				}
			}
		} while (true);

		return start == get<1>(ret);
	}

	tuple<bool, int, int> consume(string val, int index)
	{
		if (index >= val.size())
		{
			return make_tuple(0, -1, -1);
		}

		if (ischaracter(val[index]))
		{
			return make_tuple(0, val[index], 1);
		}

		int ret = 0;
		int count = 0;
		while (index < val.size() && !ischaracter(val[index]))
		{
			ret = ret *10 + toNum(val[index]);
			index++;
			count++;
		}

		return make_tuple(1, ret, count);
	}

	bool ischaracter(char c)
	{
		return c >= 'a' && c <= 'z';
	}

	int toNum(char c)
	{
		return c - '0';
	}
};

int main()
{
	Solution s;
	s.valid("word", "1o1d");
	return getchar();
}

