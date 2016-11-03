
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <hash_map>
using namespace std;

//Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	vector<int> findRightInterval(vector<Interval>& intervals) {
		int size = intervals.size();
		if (size == 0)
		{
			return{};
		}

		hash_map<int, int> h;
		for (int i = 0; i < size; i++)
		{
			h[intervals[i].start] = i;
		}
		sort(intervals.begin(), intervals.end(), [&](Interval p1, Interval p2){return p1.start < p2.start; });
		vector<int> ret(size);

		for (int i = 0; i < size; i++)
		{
			auto end = intervals[i].end;

			bool find = false;
			for (int j = i + 1; j < size; j++)
			{
				auto start = intervals[j].start;
				if (start >= end)
				{
					find = true;
					ret[h[intervals[i].start]] = (h[start]);
					break;
				}
			}

			if (find == false)
			{
				ret[h[intervals[i].start]] = -1;
			}
		}

		/*for (int i = 0; i < size; i++)
		{
			auto end = intervals[i].end;
			int min = INT_MAX;
			int min_index = -1;
			for (int j = 0; j < size; j++)
			{
				if (i == j) continue;
				auto start = intervals[j].start;

				if (start > end)
				{
					if (min > start)
					{
						min = start;
						min_index = j;
					}
				}

				if (start == end)
				{
					min_index = j;
					break;
				}
			}

			ret.push_back(min_index);
		}*/

		return ret;
	}
};

int main()
{
	Solution s;
	s.findRightInterval(vector<Interval>{  {3, 4}, { 2, 3 }, { 1, 2 } });
	return getchar();
}

