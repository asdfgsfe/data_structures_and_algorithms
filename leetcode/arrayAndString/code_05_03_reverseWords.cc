反转字符串中的单词 III
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 

示例：

输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
 

提示：

在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/c8su7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    string reverseWords(string s) {
        if (s.size() < 1) {
            return s;
        }
        int n = 0;
        int p = 0;
		//仅仅只是反转里面的单词
        while (n < s.size()) {
            while (n < s.size() && s[n] != ' ') {
                ++n;
            }
            ReverseWord(s, p, n - 1);
            p = n + 1;
            ++n;
        }
        return s;
    }

    void ReverseWord(string& s, int l, int r) {
        while (l < r) {
            std::swap(s[l++], s[r--]);
        }
    }
};
