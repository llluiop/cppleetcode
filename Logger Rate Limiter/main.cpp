
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <unordered_map>
#include <queue>
#include <numeric>
using namespace std;



class MovingAverage {
public:
	MovingAverage(int size) {
		size_ = size;
		sum_ = 0;
	}

	double next(int val) {
		if (q_.size() == size_)
		{
			sum_ -= q_.front();
			q_.pop();
		}

		q_.push(val);
		sum_ += val;

		return sum_ / q_.size();
	}

private:
	int size_;
	queue<int> q_;
	double sum_;
};


int main()
{
	MovingAverage m(1);
	return getchar();
}

