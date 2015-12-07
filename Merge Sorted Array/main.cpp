#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index1 = m-1;
		int index2 = n-1;

		int indexEnd = m + n - 1;
		while (index1 >= 0 && index2 >= 0)
		{
			if (nums1.at(index1) >= nums2.at(index2))
			{
				nums1.at(indexEnd) = nums1.at(index1);
				index1--;
			}
			else
			{
				nums1.at(indexEnd) = nums2.at(index2);
				index2--;
			}

			indexEnd--;
		}

		while (index2 >= 0)
		{
			nums1.at(indexEnd) = nums2.at(index2);
			index2--;
			indexEnd--;
		}
	}
};

int main()
{
	vector<int> v1 = { 1, 1, 1 };
	v1.resize(6);
	vector<int> v2 = { 2, 2, 2 };

	Solution s;
	s.merge(v1, 3, v2, 3);
	return getchar();
}