字符串中的第一个唯一字符
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

 

示例：

s = "leetcode"
返回 0

s = "loveleetcode"
返回 2
 

提示：你可以假定该字符串只包含小写字母。

相关标签
哈希表
字符串

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xaph0j/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//Note: 对于c语言数组 int a[26] = {-1}; 仅仅只是初始化了第一个位置
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty()) {
            return -1;
        }
        vector<int> charIndex(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            int index = s[i] - 'a';
            charIndex[index] = charIndex[index] == -1 ? i : -2;
        }
        int target = 0x7fffffff;
        for (int i = 0; i < 26; ++i) {
            if (charIndex[i] >= 0) {
                target = std::min(target, charIndex[i]);
            }
        }
        return target == 0x7fffffff ? -1 : target;
    }
};
