
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

		int val_index = 0;
		int abbr_index = 0;
		

		do 
		{
			auto ret = consume(abbr, abbr_index);

			auto type = get<0>(ret);
			if (type == -1) break;


			if (type == 1)
			{
				val_index += get<1>(ret);
				abbr_index++;
			}
			else
			{
				if (get<1>(ret) != val[val_index])
				{
					return false;
				}
				val_index++;
				abbr_index += get<2>(ret);

			}
		} while (true);

		return val_index == val.size();
	}

	tuple<int, int, int> consume(string val, int index)
	{
		if (index >= val.size())
		{
			return make_tuple(-1, -1, -1);
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
	s.valid("word", "2o1d");
	return getchar();
}

