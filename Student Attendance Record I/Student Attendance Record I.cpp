// Student Attendance Record I.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
	bool checkRecord(string s) {
		bool absent = false;
		int late = 0;

		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == 'A')
			{
				if (absent == true)
				{
					return false;
				}

				absent = true;
			}
			else if (s[i] == 'L')
			{
				if (i == 0 || s[i-1] != 'L') late = 1;
				else if (s[i - 1] == 'L') late++;

				if (late > 2) return false;
			}

		}

		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

