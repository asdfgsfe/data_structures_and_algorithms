最大连续1的个数
给定一个二进制数组， 计算其中最大连续 1 的个数。

 

示例：

输入：[1,1,0,1,1,1]
输出：3
解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
 

提示：

输入的数组只包含 0 和 1 。
输入数组的长度是正整数，且不超过 10,000。


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/cd71t/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max=0;
        int cnt=0;
		//求以每个位置结尾的情况下 最长的连续1个数 答案比在其中
        for(int i=0;i<nums.size();i++)
        {
            cnt = nums[i] == 1 ? cnt + 1 : 0;
            max = std::max(max, cnt);
        }
        return max;
    }
};
