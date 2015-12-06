#include <iostream>

using namespace std;

class Solution {
public:
	//x is Palindrome, binary format of x may not be Palindrome. --!
	bool isPalindrome(int x) {
		int num = x;
		int reverse = 0;
		while (num > 0)
		{
			reverse = reverse * 10 + num % 10;
			num /= 10;
		}

		return reverse == x;
	}
};

int main()
{

	return getchar();
}