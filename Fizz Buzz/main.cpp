#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> v;
		for (int i = 1; i <= n; i++)
		{
			if (i % 3 == 0 && i % 5 == 0)
			{
				v.push_back(string("FizzBuzz"));
			}
			else if (i % 3 == 0)
			{
				v.push_back(string("Fizz"));
			}
			else if (i % 5 == 0)
			{
				v.push_back(string("Buzz"));
			}
			else
			{
				v.push_back(to_string(i));
			}
		}

		return v;
	}
};


int main()
{
	Solution s;
	s.fizzBuzz(15);
	return getchar();
}