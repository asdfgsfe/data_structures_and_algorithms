给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。

 

示例 1：

输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
示例 2：

输入：s = "a"
输出：[["a"]]
 

提示：

1 <= s.length <= 16
s 仅由小写英文字母组成
相关标签
深度优先搜索
动态规划
回溯算法


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xaxi62/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return vector<vector<string>>();
        }
        vector<string> oneAns;
        vector<vector<string>> allAns;
        processPartition(s, 0, oneAns, allAns);
        return allAns;
    }

    void processPartition(const string& s, int i, vector<string>& oneAns, vector<vector<string>>& allAns) {
        if (i == s.size()) {
            allAns.push_back(oneAns);
            return;
        }
        string part;
        for (int k = i; k < s.size(); ++k) {
            part.push_back(s[k]);
            if (!IsPalindrome(part))  {
                continue;
            }
            oneAns.push_back(part);
            processPartition(s, k + 1, oneAns, allAns);
            oneAns.pop_back();
        }
    }

    bool IsPalindrome(const string& s) {
        int l = 0;
        int r = s.size() - 1;
        while (l <= r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
