//搜索旋转排序数组
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

//perfect 利用部分二分查找的思想 先确定大范围 在确定能确定的小范围
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return -1;
        }
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + ((r - l) >> 1); //这个操作很重要 能节约一半的时间
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] >= nums[l]) //确定大范围 左边区域 =号很重要
            {
                //左边区域的左半段 因为可以确定左边区域的左边半段一定递增 =号很重要
				if (nums[l] <= target && target <= nums[m])
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else //大范围右边区域
            {
				//右边区域的后半段必然递增 这里的=号很重要
				if (nums[m] <= target && target <= nums[r])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};



//low一点的想法 等于两个二分 先找到中间点 在二分
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return -1;
        }
        if (nums.size() == 1)
        {
            return nums[0] == target ? 0 : -1;
        }
        if (nums.front() < nums.back()) //没有逆序
        {
            return BinSearch(nums, 0, nums.size() - 1, target);
        }
        int rIdx = ReverseIdx(nums);//找到中间点
        assert(nums.front() >= nums.back());
        if (target >= nums[0])//左半区
        {
            return BinSearch(nums, 0, rIdx - 1, target);
        }
        return BinSearch(nums, rIdx, nums.size() - 1, target);//右半区
    }
    
    int ReverseIdx(const vector<int>& nums)
    {
        if (nums.empty())
        {
            return -1;
        }
        if (nums.size() == 1)
        {
            return 0;
        }
        int l = 0;
        int r = nums.size() - 1;
        while (nums[l] > nums[r])
        {
            if (r - l == 1)
            {
                return r;
            }
            int m = (l + r) / 2;
            if (nums[m] > nums[l])
            {
                l = m;
            }
            else if (nums[m] < nums[r])
            {
                r = m;
            }
        }
        return l;
    }
    
    int BinSearch(const vector<int>& nums, int l, int r, int target)
    {
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] > target)
            {
                --r;
            }
            else
            {
                ++l;
            }
        }
        return -1;
    }
};
