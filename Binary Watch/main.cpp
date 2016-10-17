#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> v;

		for (int i = 0; i <= min(num, 3); i++)
		{
			if (num - i > 6)
			{
				continue;
			}
			auto time = make_time(get_hour(i), get_minute(num - i));
			for (auto t : time)
			{
				v.push_back(t);
			}

			
		}

		return v;
	}

	vector<string> get_minute(int i)
	{
		switch (i)
		{
		case 0:
			return{ "00" };
		case 1:
			return{ "01", "02", "04", "08", "16", "32" };
		case 2:
			return{ "03", "05", "06", "09", "10", "12", "17", "18", "20", "24", "33", "34", "36", "40", "48" };
		case 3:
			return{ "07", "11", "13", "14", "19", "21", "22", "25", "26", "28", "35", "37", "38", "41", "42", "44", "49", "50", "52", "56" };
		case 4:
			return{ "15", "23", "27", "29", "30", "39", "43", "45", "46", "51", "53", "54", "57", "58" };
		case 5:
			return{ "31", "47", "55", "59" };
		default:
			break;
		}
	}

	vector<string> get_hour(int i)
	{
		switch (i)
		{
		case 0:
			return{ "0" };
		case 1:
			return{ "1", "2", "4", "8" };
		case 2:
			return{ "3", "5", "6", "9", "10" };
		case 3:
			return{ "7", "11" };
		default:
			break;
		}
	}

	vector<string> make_time(vector<string>& hour, vector<string>& minute)
	{
		vector<string> v;
		for (auto h : hour)
		{
			for (auto m : minute)
			{
				v.push_back(h + ":" + m);
			}
		}

		return v;
	}
};


int main()
{
	Solution s;
	s.readBinaryWatch(1);
	return getchar();
}