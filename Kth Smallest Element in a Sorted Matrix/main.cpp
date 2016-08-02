#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		if (matrix.size() == 0)
		{
			return 0;
		}

		int row = matrix.size();
		int col = matrix[0].size();

		auto cmp = [&matrix](pair<int, int> p1, pair<int, int> p2){return matrix[p1.first][p1.second] > matrix[p2.first][p2.second]; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp) > q(cmp);

		q.emplace(0, 0);
		for (int i = 1; i < k; i++)
		{
			auto m = q.top();
			q.pop();

			if (m.second + 1 < col)
			{
				q.emplace(m.first, m.second + 1);
			}

			if (m.second == 0 && m.first + 1 < row)
			{
				q.emplace(m.first + 1, m.second);
			}
		}

		return matrix[q.top().first][q.top().second];
	}
};

int main()
{
	Solution s;
	cout<<s.kthSmallest(vector<vector<int>>{ { 1, 5, 9 }, { 10, 11, 13 }, {12, 13, 15} }, 8);
	return getchar();
}