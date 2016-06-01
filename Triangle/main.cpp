#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.size() == 0)
		{
			return 0;
		}

		/*for (size_t i = 0; i < triangle[0].size(); i++)
		{
			int total = triangle[0][i];
			minimum(triangle, i, 1, total);
		}*/

		vector<int> v(triangle.size(), 0);
		v[0] = triangle[0][0];

		for (size_t i = 1; i < triangle.size(); i++)
		{
			vector<int> tmp = v;
			for (size_t j = 0; j < triangle[i].size(); j++)
			{
				//left
				if (j == 0)
				{
					v[j] += triangle[i][j];
				}

				//right
				else if (j == triangle[i].size()-1)
				{
					v[j] = triangle[i][j] + tmp[j-1];
				}
				else
				{
					//mid
					v[j] = triangle[i][j] + min(tmp[j - 1], tmp[j]);
				}
			}
		}

		return *min_element(v.begin(), v.end());
	}

private:
	/*void minimum(vector<vector<int>>& triangle, int index, int k, int total)
	{
		if (k == triangle.size())
		{
			if (total < min)
			{
				min = total;
			}

			return;
		}

		if (index < triangle[k].size())
		{
			minimum(triangle, index, k + 1, total + triangle[k][index]);
		}

		if ((index+1) < triangle[k].size())
		{			
			minimum(triangle, index+1, k + 1, total + triangle[k][index+1]);
		}
	}*/
};


int main()
{
	Solution s;

	//vector<vector<int>> v = { { 46 }, { 43, 61 }, { 10, -16, 3 }, { -26, 41, 36, -72 }, { -28, -76, -22, 26, 51 }, { 56, -53, 38, 67, 86, -45 },
	//{ 58, 53, 47, -52, -54, -95, 56 }, { -54, -93, 58, 68, 26, -4, -45, 86 }, { 75, 28, 27, 12, 33, 98, 35, 87, 1 }, { -13, 20, 25, -98, -13, 11, -44, -77, -59, -97 }};

	vector<vector<int>> v = { {-1}, {9, -2}, {0, 4, 5}, {7, 4, -4, -5}, {9, 6, 0, 5, 7}, {9, 2, -9, -4, 5, -2}, {-4, -9, -5, -7, -5, -5, -2}, {-9, 5, -6, -4, 4, 1, 6, -4}, {-4, 3, 9, -2, 8, 6, -9, -2, -2} };

	cout<<s.minimumTotal(v);

	return getchar();
}