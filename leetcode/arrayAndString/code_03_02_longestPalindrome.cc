5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成


//这道题目的经典方法是马拉车
//dp 时间复杂度为n*n 和以i为中心向两边扩没有啥区别
//之所以记录dp的方法是为了掌握 判断f(i, f)是否为回文串的快速判断方法
//如果s[i] == s[j] f(i, j) = f(i + 1, j + 1)
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        int longest = 1;
        int start = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < dp.size(); ++i) {
            dp[i][i] = 1;
        }
        for (int j = 1; j < dp.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                if (j - i < 2) {
                    dp[i][j] = s[i] == s[j] ? 1 : 0;
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1] == 1 ? 1 : 0;
                }
                if (dp[i][j] && longest < j - i + 1) {
                    longest = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, longest);
    }
};
