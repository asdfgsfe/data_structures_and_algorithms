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
