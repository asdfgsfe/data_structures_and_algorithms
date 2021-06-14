移除元素
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x9p1iv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = 0;
        int p = 0;
        while (n < nums.size()) {
            while (n < nums.size() && nums[n] == val) {
                ++n;
            }
            if (n == nums.size()) {
                break;
            }
            nums[p++] = nums[n++];
        }
        return p;
    }
};
