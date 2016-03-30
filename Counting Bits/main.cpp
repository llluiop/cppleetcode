#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> v = { 0 };

		int index = 0;
		for (int i = 1; i <= num; i++)
		{
			if (poweroftwo(i))
			{
				index = 0;
			}

			v.push_back(v[index++] + 1);
		}

		return std::move(v);
	}

private:
	bool poweroftwo(int num)
	{
		int countone = 0;
		while (num > 0)
		{
			if (num & 1 == 1)
			{
				++countone;
			}

			if (countone > 1)
			{
				return false;
			}

			num = num >> 1;
		}

		return countone == 1;
	}
};



int main()
{
	Solution s;
	//vector<int> v = ;
	for (int i : s.countBits(2))
	{
		cout << i << " ";
	}
	return getchar();
}