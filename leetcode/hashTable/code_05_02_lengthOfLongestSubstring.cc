无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
示例 4:

输入: s = ""
输出: 0
 

提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
相关标签
哈希表
字符串
滑动窗口


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/hash-table/xxnrdi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        //记录某个字符最近一次出现的位置
        vector<int> preIdx(256, -1);
        int pre = -1; //其实是动态规划的矩阵压缩
        int longest = 0;
        //以每个位置结尾的情况下的最长子串 答案比在其中
        for (int i = 0; i < s.size(); ++i) {
            //以当前字符结尾的最长无重复子穿的最前面id为 i - 1的与该字符上次出现的最近距离
            pre = std::max(preIdx[s[i]], pre);
            longest = std::max(longest, i - pre);
            preIdx[s[i]] = i;
        }
        return longest;
    }
};
