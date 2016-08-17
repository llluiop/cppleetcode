#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>


using namespace std;


class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> v;
		v.resize(n);

		for (auto& i : v)
		{
			i.resize(n);
		}
		
		int loop = ceil(n / 2.0);

		int count = 1;
		int start = 0;

		while (loop-- > 0)
		{
			//
			for (int i = start; i < n-start; i++)
			{
				v[start][i] = count++;
			}

			//
			for (int i = start + 1; i < (n-start); i++)
			{
				v[i][n-start-1] = count++;
			}

			//
			for (int i = n - start - 1; i > start; i--)
			{
				v[n - start - 1][i-1] = count++;
			}

			//
			for (int i = n - start - 1; i > start+1; i--)
			{
				v[i - 1][start] = count++;
			}
			
			++start;
		}
		

		return v;
	}
};


int main()
{
	Solution s;
	s.generateMatrix(1);

	return getchar();
}