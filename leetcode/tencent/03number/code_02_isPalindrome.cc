回文数
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }

        string str;
        while(x) {
            int t = x % 10 + '0';
            x = x / 10;
            str.push_back(t);
        }

        for(int i = 0, j = str.length() - 1; i <= j;i++,j--) {
            if(str[i] != str[j]) {
                return false;
            }
        }

        return true;
        
    }
};

//meth2
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
		int bits = MaxBit(x);
        for (int i = 0; i < (bits / 10) && x > 0; i += 2)
        {
			int l = x % 10;
			int r = x / bits;
			if (l != r)
			{
				return false;
			}
			x /= bits;
			x /= 10;
			bits /= 100;
        }
        return i == (bits / 10);
    }

	int MaxBit(int x)
	{
		int bits = 1;
		while (x >= 10)
		{
			bits *= 10;
			x /= 10;
		}
		return bits;
	}
};

//官方解法
class Solution {
public:
    bool isPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/palindrome-number/solution/hui-wen-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
