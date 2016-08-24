#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	Solution()
	{
		for (int i = 0; i <= 100; i++)
			for (int j = 0; j <= 100; j++)
			{
				cache[i][j] = -1;
			}
	}
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.size() == 0)
		{
			return 0;
		}

		return path(obstacleGrid, obstacleGrid.size()-1, obstacleGrid[0].size()-1);
	}

	int path(vector<vector<int>>& obstacleGrid, int row, int col)
	{
		if (row < 0 || col < 0)
		{
			return 0;
		}

		if (obstacleGrid[row][col] == 1)
		{
			return 0;
		}

		if (row == 0 && col == 0)
		{
			return 1;
		}

		if (cache[row][col] != -1)
		{
			return cache[row][col];
		}

		int ret = path(obstacleGrid, row - 1, col) + path(obstacleGrid, row, col - 1);
		cache[row][col] = ret;

		return ret;
	}

	int cache[101][101];
};

int main()
{
	Solution s;
	cout<<s.uniquePathsWithObstacles(vector<vector<int>>{{0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }});
	return getchar();
}