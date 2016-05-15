#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> v;

		int added = 1;
		for (auto iter = digits.rbegin(); iter != digits.rend(); iter++)
		{
			if (added != 0)
			{
				int root = (*iter + added) % 10;
				added = (*iter + added) / 10;				
				v.push_back(root);
			}
			else
			{
				v.push_back(*iter);
			}


		}

		if (added == 1)
		{
			v.push_back(1);
		}

		std::reverse(v.begin(), v.end());
		return std::move(v);
	}
};


int main()
{
	vector<int> v = { 9, 9 };

	Solution s;
	s.plusOne(v);
	return getchar();
}