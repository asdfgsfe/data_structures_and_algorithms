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
    vector<string> res;
    int :qa;
    vector<string> generateParenthesis(int n) {
        if(n==0)
            return res;
        end = n;
        dnf(0, 0, "");
        return res;
    }
     void dnf(int r, int l, string has)
     {
         if(l > r || r > end)
         {
             return;
         }
         if(l == end && r == end)
         {
             res.push_back(has);
             return ;
         }
         dnf(r + 1, l, has + '(');
         dnf(r, l + 1, has + ')');
     }
};
