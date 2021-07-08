class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty()) {
            return {};
        }
        string oneAns;
        vector<string> allAns;
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        ProcessWordBreak(s, 0, oneAns, allAns, wordDictSet);
        return allAns;
    }

    void ProcessWordBreak(const string& s, int i, string oneAns, vector<string>& allAns, const unordered_set<string>& wordDictSet) {
        if (i == s.size()) {
            allAns.push_back(std::move(oneAns));
            return;
        }

        string backup = oneAns;
        string word;
        for (int k = i; k < s.size(); ++k) {
            word.push_back(s[k]);
            if (!wordDictSet.count(word)) {
                continue;
            }
            oneAns.append(word);
            if (k + 1 != s.size()) {
                oneAns.push_back(' ');
            }
            ProcessWordBreak(s, k + 1, oneAns, allAns, wordDictSet);
            oneAns = backup;
        }
    }
};
单词拆分 II
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]
示例 2：

输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。
示例 3：

输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]
相关标签
字典树
记忆化搜索
哈希表
字符串
动态规划
回溯


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xdl705/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

