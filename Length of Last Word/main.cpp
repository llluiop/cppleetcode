#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s == "")
		{			
			return 0;
		}

		int count = 0;

		int i = s.size() - 1;
		for (; i >= 0; i--)
		{
			if (s[i] != ' ')
				break;
		}

		while (i >= 0 && s[i] != ' ')
		{
			count++;
			--i;
		}

		return count;
	}
};

int main()
{
	Solution s;
	cout << s.lengthOfLastWord(" hello world ");
	return getchar();
}