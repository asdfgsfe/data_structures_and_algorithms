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
链接：https://leetcode-cn.com/leetbook/read/array-and-string/c6u02/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//代码简单一点
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        int n = 0;
        int p = 0;
        while (n < nums.size()) {
            if (nums[n] == 0) {
                ++n;
            } else {
                std::swap(nums[p++], nums[n++]);
            }
        }
    }
};


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
			//走完非0数字
			while (n < nums.size() && nums[n] != 0)
			{
				if (p != n)
				{
					std::swap(nums[p], nums[n]);
				}
				++p;
				++n;
			}
		}
	}
};
