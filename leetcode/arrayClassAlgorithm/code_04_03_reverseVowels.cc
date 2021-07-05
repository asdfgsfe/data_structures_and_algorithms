345. 反转字符串中的元音字母
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

 

示例 1：

输入："hello"
输出："holle"
示例 2：

输入："leetcode"
输出："leotcede"

class Solution {
public:
	string reverseVowels(string s) {
		if (s.empty())
		{
			return s;
		}
		static const unordered_set<char> yuanYin{ 'a', 'u', 'o', 'i', 'e', 'A', 'U', 'O', 'I', 'E'};
		int l = 0;
		int r = s.size() - 1;
		while (1)
		{
			while (l < s.size() && !yuanYin.count(s[l]))
			{
				++l;
			}
			while (r >= 0 && !yuanYin.count(s[r]))
			{
				--r;
			}
			if (l >= r)
			{
				break;
			}
			std::swap(s[l++], s[r--]);
		}
		return s;
	}
};
