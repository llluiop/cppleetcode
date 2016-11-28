
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		map<int, int> m;

		int ret = 0;
		for (int i = 0; i < points.size(); i++)
		{
			for (int j = 0; j < points.size(); j++)
			{
				if (i == j)
				{
					continue;
				}

				m[distance(points[i], points[j])]++;
			}

			for (auto d : m)
			{
				ret += d.second * (d.second - 1);
			}

			m.clear();
		}

		return ret;
	}

	int distance(pair<int, int> i, pair<int, int> j)
	{
		return (i.first - j.first)*(i.first - j.first)
			+ (i.second - j.second)*(i.second - j.second);
	}
};


int main()
{
	Solution s;
	s.numberOfBoomerangs(vector<pair<int, int>>({ { 1, 2 } }));
	return getchar();
}

