class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2)
        {
            return nums.size();
        }
        int right = 0;
        int longgest = 1;
        vector<int> ends(nums.size(), 0);
        //ends表示长度为i+1的子序列所能取得的最大值
        ends[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int l = 0;
            int r = right;
            while (l <= r)
            {
                int m = l + (r - l) / 2;
                //找左边最后一个大于我的位置, 我大于你， 说明你们都小于我，我应该向右找这个位置
                if (nums[i] > ends[m])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            ends[l] = nums[i];
            right = std::max(right, l);
            longgest = std::max(longgest, l + 1);
        }
        return longgest;
    }
};

最长上升子序列
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1
 

提示：

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
 

进阶：

你可以设计时间复杂度为 O(n2) 的解决方案吗？
你能将算法的时间复杂度降低到 O(n log(n)) 吗?

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/x29fxj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
