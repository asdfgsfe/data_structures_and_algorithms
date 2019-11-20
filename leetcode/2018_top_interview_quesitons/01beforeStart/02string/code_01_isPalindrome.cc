验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

//toupper 若参数 c 为小写字母则将该对应的大写字母返回
//isalnum 检查所传的字符是否是字母和数字

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r)
        {
            while(!isalnum(s[l]) && l < r) { ++l; }
            while(!isalnum(s[r]) && l < r) { --r; }
            if(toupper(s[l]) != toupper(s[r])) 
            {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};