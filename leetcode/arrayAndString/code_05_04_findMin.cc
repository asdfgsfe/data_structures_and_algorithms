寻找旋转排序数组中的最小值
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。



作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/array-and-string/c3ki5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//适用于不重复的元素
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.empty() ? 0x80000000 : nums[0];
        }
        if (nums.front() < nums.back()) {
            return nums.front();
        }
        if (nums[nums.size() - 2] > nums[nums.size() - 1]) {
            return nums[nums.size() - 1];
        }
        int l = 1;
        int r = nums.size() - 2;
		//<=
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m - 1] && nums[m] < nums[m + 1]) {
                return nums[m];
            }
			//必须是>r
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return 0x80000000;
    }
};
