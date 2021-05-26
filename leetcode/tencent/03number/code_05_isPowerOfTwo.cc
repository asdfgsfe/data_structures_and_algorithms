2的幂
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1)
        {
            return true;
        }
        if (n < 1 || (n & 0x01) == 1)
        {
            return false;
        }
        while (n > 1)
        {
            if (n % 2 != 0)
            {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};



//官方解法 o(1)
//一个数 n 是 2 的幂，当且仅当 n 是正整数，并且 n 的二进制表示中仅包含 1 个 1。
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/power-of-two/solution/2de-mi-by-leetcode-solution-rny3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
