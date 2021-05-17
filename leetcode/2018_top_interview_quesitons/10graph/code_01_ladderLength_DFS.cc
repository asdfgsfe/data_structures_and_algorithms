//not ac
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         //dfs + dp + 回溯
        if (beginWord.empty() || endWord.empty() || wordList.empty()) {
            return 0;
        }
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        unordered_map<string, int> path;
        return ladderProcess(beginWord, 0, endWord, visited, path, wordDict);
    }

    int ladderProcess(string& beginWord, int i, const string& endWord, unordered_set<string>& visited, unordered_map<string, int>& path, unordered_set<string>& wordDict) {
        if (beginWord == endWord) {
            return 0;
        }
        if (i == beginWord.size()) {
            return -1;
        }
        int length = 0x7fffffff;
        visited.emplace(beginWord);
        //if (!path.count(beginWord)) {
            for (char c = 'a'; c <= 'z'; ++c) {
                std::swap(beginWord[i], c);
                if (wordDict.count(beginWord)) {
                    length = std::min(length, ladderProcess(beginWord, i + 1, endWord, visited, path, wordDict) + 1);
                }
                std::swap(beginWord[i], c);
            }
        //}
        path[beginWord] = length;
        return length;
    }
};
单词接龙
字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列：

序列中第一个单词是 beginWord 。
序列中最后一个单词是 endWord 。
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典 wordList 中的单词。
给你两个单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0。

 
示例 1：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
输出：5
解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
示例 2：

输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
输出：0
解释：endWord "cog" 不在字典中，所以无法进行转换。
 

提示：

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord、endWord 和 wordList[i] 由小写英文字母组成
beginWord != endWord
wordList 中的所有字符串 互不相同
相关标签
广度优先搜索

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/x2rkbs/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
