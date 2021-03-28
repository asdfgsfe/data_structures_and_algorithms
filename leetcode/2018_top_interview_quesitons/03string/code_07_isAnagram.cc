给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

相关标签
排序
哈希表

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xar9lv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


//n*log(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};

//hash  n
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty()) {
            return t.empty();
        }
        if (t.empty()) {
            return s.empty();
        }
        int charNum[26] = {0};
        for (char ch : s) {
            ++charNum[ch - 'a'];
        }
        for (char ch : t) {
            --charNum[ch - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (charNum[i] != 0) {
                return false;
            }
        }
        return true;
    }
};





