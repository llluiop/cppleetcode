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


		while (row < m )
		{
			if (matrix[row][n - 1] >= target)
			{
				return find(matrix[row].begin(), matrix[row].end(), target) != matrix[row].end();
			}
			row++;
		}


		return false;
	}
};

int main()
{
	Solution s;

	vector<vector<int>> v{ { 1, 2 }, { 3, 4 } };
	cout << s.searchMatrix(v, 5);
	return getchar();
}