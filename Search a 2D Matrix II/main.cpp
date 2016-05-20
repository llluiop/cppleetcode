#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
		{
			return false;
		}

		int m = matrix.size();
		int n = matrix[0].size();;

		int row = 0;
		int col = n-1;

		while ( row < m && col >= 0)
		{
			if (matrix[row][col] == target)
				return true;
			else if (matrix[row][col] > target)
			{
				col--;
			}
			else
			{
				row++;
			}
		}


		return false;
	}
};

int main()
{
	Solution s;

	vector<vector<int>> v{ { 1, 2 }, { 3, 4 } };
	cout << s.searchMatrix(v, 1);
	return getchar();
}