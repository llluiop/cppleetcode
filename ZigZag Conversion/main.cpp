#include <string>
#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	string convert(string s, int numRows) {
		if (s == "" || numRows <= 1)
		{
			return s;
		}

		string str = "";
		int lag = (numRows - 1) * 2; //cycle

		for (int i = 0; i < numRows; i++)
		{
			for (int j = i; j < s.length(); j+=lag)
			{
				str += s.at(j);

				if (i > 0 && i < numRows-1)  //not first line and not last line
				{
					if ((j+lag-2*i) < s.length())
					{
						str += s.at(j + lag - 2 * i);
					}
				}
			}
		} 

		return std::move(str);
	}
};


int main()
{
	Solution s;
	s.convert("PAYPALISHIRING", 3);
	return getchar();
}