������Ӵ�
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��

ʾ�� 1��

����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч�𰸡�
ʾ�� 2��

����: "cbbd"
���: "bb"


class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())
		{
			return string();
		}
		string str = ManacherString(s);
		int r = -1;
		int c = -1;
		int longgest = 1;
		int pos = 0;
		vector<int> radius(str.size());
		for (int i = 0; i < str.size(); ++i)
		{
			radius[i] = r > i ? std::min(radius[2 * c - i], r - i) : 1;
			while (i + radius[i] < str.size() && i - radius[i] >= 0)
			{
				if (str[i + radius[i]] != str[i - radius[i]])
				{
					break;
				}
				++radius[i];
			}
			if (i + radius[i] > r)
			{
				r = radius[i] + i;
				c = i;
			}
			if (radius[i] > longgest)
			{
				longgest = radius[i];
				pos = i;
			}
		}
		string palindrome;
		for (int i = pos - longgest + 1; i < pos + longgest; ++i)
		{
			if (str[i] != '#')
			{
				palindrome += str[i];
			}
		}
		return palindrome;
	}

	string ManacherString(const string& s)
	{
		string str("#");
		for (char ch : s)
		{
			str += ch + string("#");
		}
		return str;
	}
};