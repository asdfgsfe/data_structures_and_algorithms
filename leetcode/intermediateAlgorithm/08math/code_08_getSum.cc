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

两整数之和
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1
相关标签
位运算
数学

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xwaiag/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
