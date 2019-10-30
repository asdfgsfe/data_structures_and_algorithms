最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"


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