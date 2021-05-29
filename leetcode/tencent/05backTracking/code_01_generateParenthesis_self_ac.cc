class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n < 1) {
            return {};
        }
        vector<string> ans;
        //回溯 全局只用一个参数
        string par;
        GenProcess(par, 0, 0, ans, n);
        return ans;
    }

    void GenProcess(string& par, int l, int r, vector<string>& ans, int n) {
        if (l == n) {
            //l == n && r == n 表示左右括号数量都已经用完了 一个符合条件的答案
            if (r == n) {
                ans.push_back(par);
            }
            //l== n && r != n表示做括号多于右边括号 不可能是一个正确答案 不记录
            return;
        }
        //尝试在当前位置插入 左括号 右括号 插入的时候 保证右括号的数量总是大于左括号数量 但是都不能超越n
        if (r == n) { //右括号已经到上限 只能插入左括号
            par.push_back(')');
            GenProcess(par, l + 1, r, ans, n);
            par.pop_back();
            return;
        }
        //走到这里 表示左右括号均未到上限 既可以插入左又可以插入右
        if (r == l) { //表示右括号刚好等于左括号 这种情况只能插入右括号 才能组成合法的括号
            par.push_back('(');
            GenProcess(par, l, r + 1, ans, n);
            par.pop_back();
            return;
        }
        //无限制 可以插入左 也可以插入右
        par.push_back(')');
        GenProcess(par, l + 1, r, ans, n);
        par.pop_back();
        par.push_back('(');
        GenProcess(par, l, r + 1, ans, n);
        par.pop_back();
    }
};
