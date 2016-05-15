#include <iostream>
#include <vector>

using namespace std;

// (2,5)这个区间，可以是减区间的办法(0,5)-(0,2)，
// 也可是是加区间(2,x,5)， 本题思考的点就在于减区间适用[12/19/2015 liuyu]
class NumArray {
public:
	NumArray(vector<int> &nums) {
		if (nums.size() == 0)
		{
			return;
		}

		sum_.resize(nums.size());

		sum_[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) //note
		{
			sum_[i] = sum_[i - 1] + nums[i];
		}
	}

	int sumRange(int i, int j) {
		if (j < i || i > sum_.size())
		{
			return 0;
		}

		if (i == 0)
		{
			return sum_[j];
		}
		else
		{
			return sum_[j] - sum_[i - 1];
		}
	}

private:
	vector<int> sum_;
};



int main()
{
	vector<int> v = { -2, 0, 3, -5, 2, -1 };
	NumArray arr(v);

	cout<<arr.sumRange(0, 2);
	cout << arr.sumRange(2, 5);
	cout << arr.sumRange(0, 5);
	return getchar();
}