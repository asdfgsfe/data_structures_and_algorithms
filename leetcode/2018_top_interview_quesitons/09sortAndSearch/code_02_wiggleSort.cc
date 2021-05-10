324. 摆动排序 II
给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

你可以假设所有输入数组都可以得到满足题目要求的结果。

 

示例 1：

输入：nums = [1,5,1,1,6,4]
输出：[1,6,1,5,1,4]
解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
示例 2：

输入：nums = [1,3,2,2,3,1]
输出：[2,3,1,3,1,2]
 

提示：

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 5000
题目数据保证，对于给定的输入 nums ，总能产生满足题目要求的结果
 

进阶：你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？

class Solution {
public:
    //vector<int> nums{1,3,2,2,3,1};
    void wiggleSort(vector<int>& nums) {
        auto midptr = nums.begin() + nums.size() / 2;
        //仅仅将一个中位数 放到了中间位置 nth_element结束后结果 2 1 1 2 3 3
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;



        // 3-way-partition 
        // 这一步的目的是将所有等于中位数的数字全部放在中间位置
        // 数组中有重复的数字
        //该步骤结束后结果：1 1 2 2 3 3  所有的2全部被当到了中间
        int i = 0, j = 0, k = nums.size() - 1;
        while(j < k){
            if(nums[j] > mid){
                swap(nums[j], nums[k]);
                --k;
            }
            else if(nums[j] < mid){
                swap(nums[j], nums[i]);
                ++i;
                ++j;
            }
            else{
                ++j;
            }
        }

        if(nums.size() % 2) ++midptr;
        vector<int> tmp1(nums.begin(), midptr);
        vector<int> tmp2(midptr, nums.end());
        for(int i = 0; i < tmp1.size(); ++i){
            nums[2 * i] = tmp1[tmp1.size() - 1 - i];
        }
        for(int i = 0; i < tmp2.size(); ++i){
            nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
        }
    }
};

作者：hexcat
链接：mZttps://leetcode-cn.com/problems/wiggle-sort-ii/solution/yi-bu-yi-bu-jiang-shi-jian-fu-za-du-cong-onlognjia/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
