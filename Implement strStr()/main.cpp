#include <string>
#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {
		if (haystack == "" && needle == "")
		{
			return 0;
		}

		if (haystack.length() < needle.length())
		{
			return -1;
		}

		if (needle.length() == 0)
		{
			return 0;
		}

		return kmp(haystack, needle);
	}

private:
	int bruto(string haystack, string needle)
	{
		for (int i = 0; i < haystack.length(); i++)
		{
			int j = 0;
			for (; j < needle.length(); j++)
			{
				if (needle[j] != haystack[i + j])
				{
					break;
				}
			}

			if (j == needle.length())
			{
				return i;
			}
		}

		return -1;
	}

	int kmp(string haystack, string needle)
	{
		vector<int> next = getnext(needle);

		int i = 0;
		int j = 0;

		while (i != haystack.length() && j != needle.length())
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				j = next[j];
			}
		}

		return j == needle.length() ? i - j: -1;
	}

	vector<int> getnext(string needle)
	{
		vector<int> v;
		v.resize(needle.size());

		v[0] = -1;

		int index = 0;
		int match = -1;

		while (index != needle.size() - 1)
		{
			if (match == -1 || needle[match] == needle[index])
			{
				++index;
				++match;
				v[index] = match;
			}
			else
			{
				match = v[match];
			}
		}

		return std::move(v);
		
	}
};


int main()
{
	Solution s;
	s.strStr("hello world nice to met you", "nice");
	return getchar();
}