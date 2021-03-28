移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:

必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
相关标签
数组
双指针

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xmy9jh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//n * n 既可以保证0左边部分的顺序， 又可以保证0的顺序 而题目要求保证非0的顺序， 所以可以优化到n
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 1) {
            return;
        }
        for (int p = 1; p < nums.size(); ++p) {
            for (int i = p; i >= 1 && nums[i - 1] == 0 && nums[i] != 0; --i) {
                std::swap(nums[i -1], nums[i]);
            }
        }
    }
};

//leetcode n解法。没法保证0的相对顺序
方法一：双指针
思路及解法

使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。

右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。

注意到以下性质：

左指针左边均为非零数；

右指针左边直到左指针处均为零。

因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 1) {
            return;
        }
        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            if (nums[r] != 0) {
                std::swap(nums[l++], nums[r]);
            }
            ++r;
        }
    }
};

//自己想法 双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())
        {
            return;
        }
        int p = 0;
        int n = 0;
        while (n < nums.size())
        {
            while (n < nums.size() && nums[n] == 0)
            {
                ++n;
            }
            if (n == nums.size())
            {
                return;
            }
            while (p < nums.size() && nums[p] != 0 && p < n)
            {
                ++p;
            }
            if (p == nums.size())
            {
                return;
            }
            std::swap(nums[p++], nums[n++]);
        }
    }
};
