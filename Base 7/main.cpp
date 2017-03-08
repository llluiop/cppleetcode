class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0) return "0";
		bool neg = false;
		if (num < 0)
		{
			num = -num;
			neg = true;
		}

		string ret;
		while (num != 0)
		{
			ret += to_string(num % 7);
			num = num / 7;
		}

		if (neg) ret += "-";

		reverse(ret.begin(), ret.end());
		return ret;
	}
};