
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <hash_map>
#include <vector>
using namespace std;


 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
/**/
class Solution {
public:
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		if (intervals.size() <= 1)
		{
			return 0;
		}

		sort(intervals.begin(), intervals.end(), [&](Interval v1, Interval v2){return v1.start < v2.start || v1.end < v2.end; });
		int ret = 0;
		bool* moved = new bool[intervals.size()];
		for (int i = 0; i < intervals.size(); i++)
		{
			moved[i] = false;
		}

		int limit = intervals[0].end;
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i].start >= limit)
			{
				limit = intervals[i].end;
			}
			else
			{
				ret++;
			}
		}

		return ret;
	}
};



int main()
{
	Solution s;
	s.eraseOverlapIntervals(vector<Interval>{{1, 2}, { 2, 3 }/*, { 3, 4 }, { 1, 3 }*/});
	return getchar();
}

