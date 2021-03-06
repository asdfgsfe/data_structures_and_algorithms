class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return false;
        }
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp.back() = true;
        for (int i = dp.size() - 2; i >= 0; --i) {
            string sub;
            for (int x = i; x < s.size(); ++x) {
                sub.push_back(s[x]);
                if (dict.count(sub)) {
                    dp[i] = dp[x + 1];
                }
                //注意这种在递归函数中return true的 在dp方法中一定要break
                if (dp[i]) {
                    break;
                }
            }
        }
        return dp[0];
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty()) {
            return false;
        }
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp.back() = true;
        for (int i = dp.size() - 2; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (!dp[i] && wordDictSet.count(s.substr(i, j - i + 1))) {
                    dp[i] = dp[j + 1];
                }
            }
        }
        return dp[0];
    }
};

单词拆分
给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
相关标签
字典树
记忆化搜索
哈希表
字符串
动态规划


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xd7u77/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
