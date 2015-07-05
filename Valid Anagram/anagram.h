#ifndef __ANAGRAM_H__
#define __ANAGRAM_H__
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length())
		{
			return false;
		}

		// you can use a array instead, int array[26], making it runs fast [11/19/2015 liuyu]
		map<int, int> m1;
		map<int, int> m2;

		for (int i = 0; i < s.length(); i++)
		{
			m1[s.at(i)]++;
			m2[t.at(i)]++;
		}

		if (m1 == m2)
			return true;
		else
			return false;
	}
};

#endif