
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <map>
#include <set>
#include <numeric>
using namespace std;

bool canAttendMeetings(vector<pair<int, int>>& intervals) {
	sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b){return a.first < b.second; });
	for (int i = 1; i < intervals.size(); ++i) {
		if (intervals[i].first < intervals[i - 1].second) {
			return false;
		}
	}

	return true;
}

int main()
{

	return getchar();
}

