
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <hash_map>
#include <vector>
using namespace std;

class Solution {
public:
	int findMinArrowShots(vector<pair<int, int>>& points) {
		if (points.size() == 0)
		{
			return 0;
		}

		sort(points.begin(), points.end());
		int count = 1;
		int limit = points[0].second;

		for (int i = 1; i < points.size(); i++)
		{
			if (limit >= points[i].first)
			{
				limit = min(limit, points[i].second);
			}
			else
			{
				count++;
				limit = points[i].second;
			}
		}

		return count;
	}
};
int main()
{
	Solution s;
	s.findMinArrowShots(vector<pair<int,int>>({  {10, 16}, { 2, 8 }, { 1, 6 }, {7, 12} }));
	return getchar();
}

