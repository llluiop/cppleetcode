#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	string decodeString(string s) {
		while (unit(s));
		return s;

	}

	bool unit(string& s)
	{
		int end = s.find(']');
		if (end == string::npos) return false;
		
		int index = end-1;
		string re = "";
		while (s[index] != '[')
		{
			re += s[index--];
		}
		reverse(re.begin(), re.end());

		--index;

		string num;
		while (index >= 0 && s[index] >= '0' && s[index] <= '9')
		{
			num += s[index--];
		}

		reverse(num.begin(), num.end());

		string ret;
		for (int i = 0; i < atoi(num.c_str()); i++)
		{
			ret += re;
		}

		s.erase(index+1, end-index);
		s.insert(index + 1, ret);
		return true;
	}
};

int main()
{
	Solution s;
	cout<<s.decodeString("2[abc]3[cd]ef").c_str();
	return getchar();
}