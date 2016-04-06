#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version)
{
	return version > 0;
}

class Solution {
public:
	int firstBadVersion(int n) {
		int low = 1;
		int high = n;
		int mid = 0;;
		int count = 0;
		//while ((high - low) != 1)
		//{
		//	count++;
		//	mid = low + (high - low) / 2;

		//	if (isBadVersion(mid))
		//	{
		//		high = mid;
		//	}
		//	else
		//	{
		//		low = mid;
		//	}
		//}

		while ((high - low) > 1)
		{
			count++;
			mid = low + (high - low) / 2;

			if (isBadVersion(mid))
			{
				high = mid;
			}
			else
			{
				low = mid;
			}
		}
		cout << count;
		return high;
	}
};


int main()
{
	Solution s;
	cout << s.firstBadVersion(1);
	return getchar();
}