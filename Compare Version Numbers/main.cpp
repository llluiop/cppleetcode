#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<string> ver1;
		vector<string> ver2;

		string delim = ".";
		split(version1, delim, &ver1);
		split(version2, delim, &ver2);

		int i = 0;
		while (i < ver1.size() && i < ver2.size())
		{
			if (atoi(ver1[i].c_str()) < atoi(ver2[i].c_str()))
			{
				return -1;
			}

			if (atoi(ver1[i].c_str()) > atoi(ver2[i].c_str()))
			{
				return 1;
			}

			++i;
		}
		
		if (i == ver1.size() && i == ver2.size())
		{
			return 0;
		}
		if (i < ver1.size())
		{
			while (i < ver1.size())
			{
				if (atoi(ver1[i].c_str()) != 0)
					return 1;

				i++;
			}
		}

		if (i < ver2.size())
		{
			while (i < ver2.size())
			{
				if (atoi(ver2[i].c_str()) != 0)
					return -1;

				i++;
			}
		}

		return 0;
	}

private:
	//注意：当字符串为空时，也会返回一个空字符串
	void split(std::string& s, std::string& delim, std::vector< std::string >* ret)
	{
		size_t last = 0;
		size_t index = s.find_first_of(delim, last);
		while (index != std::string::npos)
		{
			ret->push_back(s.substr(last, index - last));
			last = index + 1;
			index = s.find_first_of(delim, last);
		}
		if (index - last>0)
		{
			ret->push_back(s.substr(last, index - last));
		}
	}

};


int main()
{
	Solution s;

	


	cout << s.compareVersion("1.2", "1.2.0");

	return getchar();
}