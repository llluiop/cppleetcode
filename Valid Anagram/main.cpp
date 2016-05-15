#include "anagram.h"
#include <iostream>

using namespace std;

int main()
{
	string s = "anagram";
	string t = "nagaram";

	Solution sl;
	sl.isAnagram(s, t);

	return getchar();
}