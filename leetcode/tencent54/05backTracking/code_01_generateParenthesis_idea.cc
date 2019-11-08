括号生成
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

class Solution {
public:
 vector<string> generateParenthesis(int n) {
	 if (n < 1)
	 {
		 return {};
	 }

	 string parenthesis("(");
	 vector<string> ans;
	 stack<char> isLegal;
	 isLegal.push('(');
	 GenerateProcess(n * 2, 1, 1, 0, parenthesis, isLegal, ans);
	 return ans;
 }

 void GenerateProcess(int n, int i, int lNum, int rNum, string& parenthesis, stack<char>& isLeal, vector<string>& ans)
 {
	 if (i == n)
	 {
		 if (IsLegal(parenthesis))
		 {
			 ans.emplace_back(parenthesis);
		 }
		 return;
	 }
	 if (lNum == n / 2 && rNum == n / 2)
	 {
		 return;
	 }
	 if (lNum < n / 2)
	 {
		 parenthesis.push_back('(');
		 GenerateProcess(n, i + 1, lNum + 1, rNum, parenthesis, isLeal, ans);
		 parenthesis.pop_back();
	 }
	 if (rNum < n / 2)
	 {
		 parenthesis.push_back(')');
		 GenerateProcess(n, i + 1, lNum, rNum + 1, parenthesis, isLeal, ans);
		 parenthesis.pop_back();
	 }
 }

 bool IsLegal(const string& str)
 {
	 stack<char> chars;
	 for (char ch : str)
	 {
		 if (ch == '(')
		 {
			 chars.push('(');
		 }
		 else
		 {
			 if (!chars.empty() && chars.top() != '(')
			 {
				 return false;
			 }
			 if (!chars.empty())
			 {
				 chars.pop();
			 }
		 }
	 }
	 return chars.empty();
 }
};