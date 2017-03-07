class Solution {
public:
	vector<int> constructRectangle(int area) {
		vector<int> v;
		for (int i = sqrt(area); i >= 0; i--)
		{
			if (area % i == 0)
			{
				v.push_back(area / i);
				v.push_back(i);
				break;
			}
		}
		return v;
	}
};