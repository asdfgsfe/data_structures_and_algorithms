class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) {
            return "";
        }
        if (numerator == 0) {
            return "0";
        }
        string ret;
        bool minus = (numerator > 0) ^ (denominator > 0);
        if (minus) {
            ret.push_back('-');
        }
        long long num = numerator < 0 ? std::labs(numerator) : numerator;
        long long den = denominator < 0 ? std::labs(denominator) : denominator;
        ret += std::to_string(num / den);
        num %= den;
        if (num == 0) {
            return ret;
        }
        ret.push_back('.');
        unordered_map<int, int> visited;
        visited[numerator] = ret.size();
        num *= 10;
        while (1) {
            if (num < den) {
                ret.push_back('0');
                num *= 10;
                continue;
            }
            ret.push_back((num / den) + '0');
            num %= den;
            if (num == 0) {
                return ret;
            }
            if (visited.count(num)) {
                int pre = visited[num];
                string tmp(ret.begin(), ret.begin() + pre);
                tmp.push_back('(');
                tmp += ret.substr(pre);
                tmp.push_back(')');
                return tmp;
            }
            visited[num] = ret.size();
            num *= 10;
        }
        return "";
    }
};


分数到小数
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。

如果存在多个答案，只需返回 任意一个 。

对于所有给定的输入，保证 答案字符串的长度小于 104 。

 

示例 1：

输入：numerator = 1, denominator = 2
输出："0.5"
示例 2：

输入：numerator = 2, denominator = 1
输出："2"
示例 3：

输入：numerator = 2, denominator = 3
输出："0.(6)"
示例 4：

输入：numerator = 4, denominator = 333
输出："0.(012)"
示例 5：

输入：numerator = 1, denominator = 5
输出："0.2"
 

提示：

-231 <= numerator, denominator <= 231 - 1
denominator != 0
相关标签
哈希表
数学
字符串

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xwm8ne/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
