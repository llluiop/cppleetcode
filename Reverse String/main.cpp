#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		for (size_t i = 0; i < s.length()/2; i++)
		{
			char tmp = s[i];
			s[i] = s[s.length() - i-1];
			s[s.length() - i - 1] = tmp;

		}

		return s;
	}
};


int main()
{
	Solution s;

	std::cout << s.reverseString("12");


	return getchar();
}