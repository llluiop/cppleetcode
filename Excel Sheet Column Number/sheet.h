#ifndef __SHEET_H__
#define __SHEET_H__

#include <string>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int num = 0;
		
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			num *= 26;
			num += (s[i] - 64); //better: s[i]-'A'+1
		}

		return num;
	}
};

#endif