最长连续递增序列 //这里其实是子数组的概念
给定一个未经排序的整数数组，找到最长且连续的的递增序列。

示例 1:

输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
示例 2:

输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。
注意：数组长度不会超过10000。


//递归 以每个位置结尾的最长递增子数组
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int lcs = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            lcs = std::max(lcs, LCSProcess(nums, i));
        }
        return lcs;
    }
    
    int LCSProcess(const vector<int>& nums, int i)
    {
        if (i == 0)
        {
            return 1;
        }
        int lcs = 1;
        if (nums[i] > nums[i - 1])
        {
            lcs += LCSProcess(nums, i - 1);
        }
        return lcs;
    }
};

//dp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }        
        int lcs = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            lcs = std::max(lcs, dp[i]);
        }
        return lcs;
    }
};

//矩阵压缩技术
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }        
        int lcs = 1;
        int pre = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            pre = nums[i] > nums[i - 1] ? pre + 1 : 1;
            lcs = std::max(lcs, pre);
        }
        return lcs;
    }
};
