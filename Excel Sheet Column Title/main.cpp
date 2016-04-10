#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string s = "";

		if (n % 26 == 0)
		{
			return timesof26(n);
		}
		else
		{
			return notimeof26(n);

		}

	}

private:
	string timesof26(int n)
	{
		if (n == 26)
		{
			return string("Z");
		}

		return notimeof26(n/26-1)+"Z";
	}

	string notimeof26(int n)
	{
		string s = "";
		while (n > 0)
		{
			if (n % 26 == 0)
			{
				s = timesof26(n) + s;
				break;
			}
			else
			{
				int div = n % 26;
				char c = ('A' + (div - 1));
				s.insert(0, 1, c);
				n = n / 26;
			}
		}
		return s;
	}
};


int main()
{
	Solution s;
	
	cout << s.convertToTitle(17577);
	return getchar();
}