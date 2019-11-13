//给定两个二进制字符串，返回他们的和（用二进制表示）。
//
//输入为非空字符串且只包含数字 1 和 0。
//
//示例 1 :
//
//输入: a = "11", b = "1"
//	输出 : "100"
//	示例 2 :
//
//	输入 : a = "1010", b = "1011"
//	输出 : "10101"

class Solution {
public:
	string addBinary(string a, string b) {
		if (a.empty())
		{
			return b;
		}
		if (b.empty())
		{
			return a;
		}
		string& l = a.size() > b.size() ? a : b;
		string& s = a.size() > b.size() ? b : a;
		string sum = "0" + l;
		int i = sum.size() - 1;
		int j = s.size() - 1;
		int rest = 0;
		while (j >= 0)
		{
			int cur = (sum[i] - '0') + (s[j--] - '0') + rest;
			sum[i--] = (cur % 2) + '0';
			rest = cur >= 2 ? 1 : 0;
		}
		while (rest == 1)
		{
			int cur = (sum[i] - '0') + rest;
			sum[i--] = (cur % 2) + '0';
			rest = cur >= 2 ? 1 : 0;
		}
		return sum[0] == '1' ? sum : sum.substr(1, sum.size() - 1);
	}
};