字符串解码
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

 

示例 1：

输入：s = "3[a]2[bc]"
输出："aaabcbc"
示例 2：

输入：s = "3[a2[c]]"
输出："accaccacc"
示例 3：

输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"
示例 4：

输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"
相关标签
栈
递归
字符串

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/queue-stack/gdwjv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
struct ReturnData {
    string sub;
    int i;

    ReturnData(const string& s, int index) : sub(s), i(index) {}
};
public:
    string decodeString(string s) {
        if (s.empty()) {
            return "";
        }
        return DecodeProcess(s, 0).sub;
    }

    ReturnData DecodeProcess(const string& s, int i) {
        int n = 0;
		//这里直接定义sub 有队列的功能
        string sub;
        while (i < s.size() && s[i] != ']') {
            if (s[i] >= '0' && s[i] <= '9') {
                n = n * 10 + (s[i++] - '0');
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                sub.push_back(s[i++]);
            } else {
                ReturnData next = DecodeProcess(s, i + 1);
                for (int j = 0; j < n; ++j) {
                    sub += next.sub;
                }
				//注意这里n=0和i的迭代 很容易错
                n = 0;
                i = next.i + 1;
            }
        }
        return ReturnData(sub, i);
    }
};
