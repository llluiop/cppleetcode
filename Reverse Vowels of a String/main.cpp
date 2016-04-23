#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int low = 0;
		int high = s.length() - 1;
		
		while (low < high)
		{
			while (!isVowels(s[low]))
				low++;

			while (!isVowels(s[high]))
				high--;

			if (low < high)
			{
				char tmp = s[low];
				s[low] = s[high];
				s[high] = tmp;
			}

			++low;
			--high;
		}

		return s;
	}

private:
	inline bool isVowels(char c){
		if (c == 'i' || c == 'o' || c == 'u' || c == 'a' || c == 'e'
			|| c == 'I' || c == 'O' || c == 'U' || c == 'A' || c == 'E')
		{
			return true;
		}

		return false;
	}
};


int main()
{
	Solution s;

	std::cout << s.reverseVowels("leetcode");


	return getchar();
}