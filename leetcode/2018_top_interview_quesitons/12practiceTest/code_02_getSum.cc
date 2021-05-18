class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            auto c = ((unsigned int)a & b) << 1; // 防止 AddressSanitizer 对有符号左移的溢出保护处理
            a = a ^ b;
            b = c;
        }
        return a;
    }
};

371. 两整数之和
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1
通过次数49,425提交次数85,505
