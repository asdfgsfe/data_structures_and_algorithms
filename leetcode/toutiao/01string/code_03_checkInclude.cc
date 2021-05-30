class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1 == s2)
        {
            return true;
        }
        if (s1.empty() || s2.empty() || s1.size() > s2.size())
        {
            return false;
        }
        vector<int> charNums1(26, 0);
        vector<int> charNums2(26, 0);
        for (char ch : s1)
        {
            ++charNums1[ch - 'a'];
        }
        for (int i = 0; i < s2.size(); ++i)
        {
            if (i >= s1.size())
            {
                --charNums2[s2[i - s1.size()] - 'a'];//窗口每次移动一个 所以--操作等于出窗口
            }
            ++charNums2[s2[i] - 'a'];
            if (i >= s1.size() - 1 && charNums1 == charNums2)
            {
                return true;
            }
        }
        return false;
    }
};
//滑动窗口模型 窗口大小为s1的长度 在s2中固定窗口找与s1一样的
//
//题目
//567. 字符串的排列
//
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的 子串 。

 

示例 1：

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
示例 2：

输入: s1= "ab" s2 = "eidboaoo"
输出: False
 

提示：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
