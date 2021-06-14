//题目：寻找重复数

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return 1;
        }
        int i = 0;
        while (i < nums.size()) {
            if (i == nums[i] - 1) {
                ++i;
            } else if (nums[i] == nums[nums[i] - 1]) {
                return nums[i];
            } else {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return nums.size();
    }
};


//才理解这个intersection point。 相交点一定是环上的点，但不一定是入口。
//假设链表从头部到环入口前一个点一共a个点，环上一共b个点，那么每一步龟兔的距离都会加一，
//相交点一定是入口点向后(b-a)个的点。 然后从起点前进a步到达入口，相交点前进a步正好也回到入口。

//这个鸽子原理，我看动图还是看不懂。后来才明白是把坐标和数值之间相互转换，而由于重复数字的存在，
//那么一定会形成环，用快慢指针可以找到环并确定环的起始位置

// 根据题意，容易明白必然存在一个环，难点是如何找到这个环。 看图能看懂，但怎么转换成可实际编码解决的问题是难点。 想了好哈儿，把这个转换成追击问题，一下子就好解决了。 在环形内，一个快，一个慢，同时出发，则必然快的能追上慢的，当追上的那刻，我们就找到了进入这个环的钥匙。
https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode/


//如果能所有的数字会连续出现 这种方法是可以的 但是如果某个数字不会出现 就不能通过
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.size() < 2)
		{
			return 0x7fffffff;
		}
		int n = nums.size();
		int maxVal = 0x80000000;
		long long sum = 0;
		for (int num : nums)
		{
			maxVal = std::max(maxVal, num);
			sum += num;
		}
		std::cout << "maxVal=" << maxVal << " sum=" << sum << " n=" << n << std::endl;
		long long allSum = n * (1 + n) / 2;
		long long diff = (n - maxVal) * (maxVal + 1 +  n) / 2;
		std::cout << "allSum=" << allSum << " diff=" << diff << std::endl;
		sum = allSum - sum;
		int repeat = (diff - sum) / (n - maxVal);
		return repeat;
	}
};
