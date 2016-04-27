#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:
	int totalNQueens(int n) {
		int total = 0;

		vector<int> board( n, INT_MIN );
		solve(board, 0, n, total);

		return total;
	};

private:
	void solve(vector<int>& board, int k, int n, int& total)
	{
		if (k == n)
		{
			total++;
		}
		for (size_t i = 0; i < n; i++)
		{
			if (placeable(board, i, k))
			{
				board[k] = i;
				solve(board, k + 1, n, total);
			}
		}
	}


	bool placeable(const vector<int>& board, int i, int k)
	{
		for (int index = 0; index < k; index++)
		{
			if (board[index] == i)
			{
				return false;
			}

			if (abs(k - index) == abs(i - board[index]))
			{
				return false;
			}
		}


		return true;
	}
};

int main()
{
	Solution s;

	auto v = s.totalNQueens(4);

	return getchar();
}