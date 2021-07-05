基本计算器 II
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

整数除法仅保留整数部分。

 

示例 1：

输入：s = "3+2*2"
输出：7
示例 2：

输入：s = " 3/2 "
输出：1
示例 3：

输入：s = " 3+5 / 2 "
输出：5
 

提示：

1 <= s.length <= 3 * 105
s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
s 表示一个 有效表达式
表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
题目数据保证答案是一个 32-bit 整数
相关标签
栈
数学
字符串

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xwsg7t/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
 public:
	int calculate(string s) {
		if (s.empty())
		{
			return 0;
		}
		deque<string> exp;
		int num = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')
			{
				continue;
			}
			if (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
				continue;
			}
			AddNum(exp, num);
			num = 0;
			exp.emplace_back(1, s[i]);
		}
		AddNum(exp, num);
		//DumpStack(exp);
		return GetNum(exp);
	 }

	int GetNum(deque<string>& exp)
	{
		int num = 0;
		bool add = true;
		while (!exp.empty())
		{
			string cur = exp.front();
			exp.pop_front();
			if (cur == "+")
			{
				add = true;
			}
			else if (cur == "-")
			{
				add = false;
			}
			else
			{
				int rhs = ::atoi(cur.data());
				num += add ? rhs : -rhs;
			}
		}
		return num;
	}

	void AddNum(deque<string>& exp, int num)
	{
		if (!exp.empty())
		{
			string symbol = exp.back();
			if (symbol == "*" || symbol == "/")
			{
				exp.pop_back();
				int lhs = ::atoi(exp.back().data());
				exp.pop_back();
				num = symbol == "*" ? (lhs * num) : (lhs / num);
			}
		}
		exp.emplace_back(std::to_string(num));
	 }
 };
