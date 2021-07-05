分割回文串
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
字符串
动态规划
回溯

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xdr7yg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return {};
        }
        vector<string> one;
        vector<vector<string>> all;
        PartitionProcess(s, 0, one, all);
        return all;
    }

    void PartitionProcess(const string& s, int i, vector<string>& one, vector<vector<string>>& all) {
        if (i == s.size()) {
            all.emplace_back(one);
            return;
        }
        for (int k = i; k < s.size(); ++k) {
            if (IsParlindrome(s, i, k)) {
                one.emplace_back(s.substr(i, k - i + 1));
                PartitionProcess(s, k + 1, one, all);
                one.pop_back();
            }
        }
    }

    bool IsParlindrome(const string& s, int l, int r) {
        while (l <= r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
