整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。
请根据这个假设，如果反转后整数溢出那么就返回 0。

class Solution {
public:
    int reverse(int x) {
        long long num = 0;
        long long n = (long long)x;
        bool minus = n < 0 ? true : false;
        n = n < 0 ? -n : n;
        while (n)
        {
            num = num * 10 + (n % 10);
            n /= 10;
        }
        std::cout << num << std::endl;
        if ((minus && -num < (signed int)0x80000000) || (!minus && num > (signed int)0x7fffffff))
        {
            return 0;
        }
        return minus ? -(int)num : (int)num;
    }
};