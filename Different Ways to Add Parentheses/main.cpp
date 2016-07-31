#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> v;
		
		int size = input.size();
		if (size == 0)
		{
			return v;
		}

		for (int i = 0; i < size; i++)
		{
			auto c = input[i];
			if (c != '+' && c != '-' && c != '*')
			{
				continue;
			}

			auto v1 = diffWaysToCompute(input.substr(0, i));
			auto v2 = diffWaysToCompute(input.substr(i + 1));

			for (auto i : v1)
			{
				for (auto j : v2)
				{
					if (c == '+')
					{
						v.push_back(j + i);
					}
					if (c == '-')
					{
						v.push_back(i - j);
					}
					if (c == '*')
					{
						v.push_back(j * i);
					}
				}
			}
		}

		return v.empty() ? vector<int>{stoi(input)} : v;
	}
};

int main()
{
	Solution s;
	s.diffWaysToCompute("2-1-1");
	return getchar();
}