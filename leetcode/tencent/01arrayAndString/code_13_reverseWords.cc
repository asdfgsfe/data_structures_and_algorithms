反转字符串中的单词 III
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty())
        {
            return string();
        }
        int pre = 0;
        int next = 0;
        while (next < s.size())
        {
            while (next < s.size() && s[next] != ' ')
            {
                ++next;
            }
            ReverseWord(s, pre, next - 1);
            pre = next + 1;
            ++next;
        }
        ReverseWord(s, pre, next - 1);
        return s;
    }
    
    void ReverseWord(string& str, int l, int r)
    {
        while (l < r)
        {
            std::swap(str[l++], str[r--]);
        }
    }
};


//稍微优化一点
class Solution {
public:
    string reverseWords(string s) {
        if (s.size() < 2) {
            return std::move(s);
        }
        int n = 0;
        int p = 0;
        while (p < s.size()) {
            while (p < s.size() && s[p] != ' ') {
                ++p;
            }
            reverseStr(s, n, p - 1);
            n = ++p;
        }
        return std::move(s);
    }

    void reverseStr(string& s, int l, int r) {
        while (l < r) {
            std::swap(s[l++], s[r--]);
        }
    }
};
