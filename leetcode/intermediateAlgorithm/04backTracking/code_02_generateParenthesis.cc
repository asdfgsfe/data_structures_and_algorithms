括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]
 

提示：

1 <= n <= 8
相关标签
字符串
动态规划
回溯


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xv33m7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n < 1) {
            return {};
        }
        vector<string> ans;
        string par;
        GenProcess(par, 0, 0, ans, n);
        return ans;
    }

    void GenProcess(string& par, int l, int r, vector<string>& ans, int n) {
        if (l == n && r == n) {
            ans.push_back(par);
            return;
        }
        if (r == n) {
            par.push_back(')');
            GenProcess(par, l + 1, r, ans, n);
            par.pop_back();
            return;
        }
        if (r == l) {
            par.push_back('(');
            GenProcess(par, l, r + 1, ans, n);
            par.pop_back();
            return;
        }
        par.push_back(')');
        GenProcess(par, l + 1, r, ans, n);
        par.pop_back();
        par.push_back('(');
        GenProcess(par, l, r + 1, ans, n);
        par.pop_back();
    }
};
