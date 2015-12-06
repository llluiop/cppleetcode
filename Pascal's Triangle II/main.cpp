#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex){
		if (rowIndex == 0)
		{
			return std::move(vector<int>(1, 1));
		}

		vector<int> v;

		vector<int> vPreRow(1,1);

		for (int i = 1; i <= rowIndex; i++)
		{
			v.clear();
			v.push_back(1);

			if (vPreRow.size() != 1)
			{
				for (int i = 0; i < vPreRow.size() - 1; i++)
				{
					v.push_back(vPreRow.at(i) + vPreRow.at(i + 1));
				}
			}

			v.push_back(1);
			vPreRow = v;
		}

		return std::move(v);
	}
};

int main()
{


	Solution s;
	s.getRow(1);
	return getchar();
}