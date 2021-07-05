删除排序数组中的重复项 II
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x9nivs/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//代码简单一点
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = 0;
        int p = 0;
        while (n < nums.size()) {
            int val = nums[n];
            int times = 0;
            while (n < nums.size() && nums[n] == val) {
                ++times;
                ++n;
            }
            times = times >= 2 ? 2 : 1;
            for (int i = 0; i < times; ++i) {
                nums[p++] = val;
            }
        }
        return p;
    }
};


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
		{
			return 0;
		}
		int p = 0;
		int n = 0;
		while (n < nums.size())
		{
			int times = 1;
			while (n + 1 < nums.size() && nums[n] == nums[n + 1])
			{
				++times;
				++n;
			}
			times = times >= 2 ? 2 : 1;
			if (times == 1)
			{
				nums[p++] = nums[n++];
			}
			else
			{
				nums[p++] = nums[n];
				nums[p++] = nums[n++];
			}
		}
		return p;
	}
};
