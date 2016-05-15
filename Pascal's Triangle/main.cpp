#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> v;

		if (numRows != 0)
		{
			v.push_back(vector<int>(1, 1));
			for (int i = 1; i < numRows; i++)
			{
				vector<int>& vPreRow = v.at(i - 1);

				vector<int> vRow;
				vRow.push_back(1);

				if (vPreRow.size() != 1)
				{
					for (int i = 0; i < vPreRow.size() - 1; i++)
					{
						vRow.push_back(vPreRow.at(i) + vPreRow.at(i+1));
					}
				}

				vRow.push_back(1);

				v.push_back(vRow);
			}
		}

		return std::move(v);
	}
};

int main()
{


	Solution s;
	s.generate(5);
	return getchar();
}