
最长连续序列
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
1
2
3
分析
由于O(n)时间复杂度的限制，我们就不能采取先排序后遍历的思路。

针对O(n)时间复杂度的实现思路：遍历nums[]数组，利用Map存储元素nums[i]的值以及其所在连续序列的长度，
此时基本只有两种情况：

数组中出现过元素nums[i]-1或nums[i]+1，意味着当前元素可以归入左或右序列，
那么此时假如左右序列的长度分别为left、right，那么显然加入nums[i]后，
这整段序列的长度为 1+left+right，而由于这一整段序列中，只可能在左右两端扩展，所以只需要更新左右两端的value值即可。
数组中未出现过元素nums[i]-1或nums[i]+1，意味着当前元素所在的连续序列就是自身（只有自己一个元素）。
但是！！总是有坑在等着我们跳：nums数组存在重复数字。

假设nums[]数组为[2,4,3,3]，按照上面的逻辑，map（key->value）中2->1，4->1，
当遇到3时，因为左右两端都存在，因此会直接更新2->2，4->2，再次遇到3，2->3，4->3，
于是我们需要判断是否已经处理过3这个重复数字，方法就是每次处理的数字nums[i]，也在map中更新它的值，
并且在遍历的时候先判断nums[i].value是不是0，如果不是0，那么意味着前面我们处理过了，直接跳过就好。
--------------------- 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        unordered_map<long long, long long> numToLens;
        int longgest = 0;
        for (int num : nums)
        {
            if (numToLens[num] != 0)//这个数字已经添加过 不用在添加
            {
                continue;
            }
            int left = numToLens[num - 1];
            int right = numToLens[num + 1];
            int len = 1 + left + right;
            numToLens[num] = len;
            if (left != 0)
            {
                numToLens[num - left] = len;
            }
            if (right != 0)
            {
                numToLens[num + right] = len;
            }
            longgest = std::max(longgest, len);
        }
        return longgest;
    }
};