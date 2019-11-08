求众数
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty())
        {
            return 0x7fffffff;
        }
        int times = 1;
        int ret = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (times == 0)
            {
                times = 1;
                ret = nums[i];
            }
            else if (nums[i] == ret)
            {
                ++times;
            }
            else
            {
                --times;
            }
        }
        times = 0;
        for (int num : nums)
        {
            if (num == ret)
            {
                ++times;
            }
        }
        return times >= nums.size() / 2 ? ret : 0x7fffffff;
    }
};


//没有测试
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty())
        {
            return 0x7fffffff;
        }
		while (1)
		{
			int p = Radom(0, nums.size());
			Partition(nums, p);
			if (p == nums.size() / 2)
			{
				break;
			}
		}
		int times = 0;
		for (int num : nums)
		{
		}
	}

	void Partition(vector<int>& nums, int p)
	{
		if (nums.empty() || p < 0 || p >= nums.size())
		{
			return;
		}
		int l = 0;
		int r = nums.size() - 1;
		std::swap(nums[p], nums[r--]);
		while (1)
		{
			while (l < nums.size() && nums[l] < nums.back())
			{
				++l;
			}
			while (r >= && nums[r] > nums.back())
			{
				--r;
			}
			if (l >= r)
			{
				break;
			}
			std::swap(nums[l++], nums[r--]);
		}
		std::swap(nums[p], nums.back());
	}
};