// Next Greater.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int longestStrChain(vector<string>& words) {
		sort(words.begin(), words.end(), [](string s1, string s2) {return s1.size() < s2.size(); });
		unordered_map<string, int> dp;
		int res = 0;
		for (string w : words) {
			int best = 0;
			for (int i = 0; i < w.length(); i++) {
				string word = w.substr(0, i) + w.substr(i + 1);
				best = max(best, dp[word] + 1);
			}
			dp[w] = best;
			res = max(res, best);
		}
		return res;
	}


};

int main()
{
	Solution s;
	cout<<s.longestStrChain({ "a","b","ba","bca","bda","bdca" });
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
