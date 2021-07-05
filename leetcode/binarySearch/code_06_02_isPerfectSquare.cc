有效的完全平方数
给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。

 

示例 1：

输入：num = 16
输出：true
示例 2：

输入：num = 14
输出：false
 

提示：

1 <= num <= 2^31 - 1


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/binary-search/xel3tc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2)
        {
            return true;
        }
        int l = 1;
        int r = num / 2;
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            long long m = mid * mid;
            if (m == (long long)num)
            {
                return true;
            }
            else if (m > (long long)num)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return false;
    }
};
