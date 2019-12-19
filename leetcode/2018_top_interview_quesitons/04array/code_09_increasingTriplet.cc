class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return false;
        }
        int first = 0x7fffffff;
        int second = 0x7fffffff;
        for (int num : nums)
        {
			//如果我小于第一个 那么把第一个换成我
            if (num <= first) //小于等于很关键
            {
                first = num;
            }
			//到这里说明我大于第一个 如果我小于第二个 把第二个换成我
            else if (num <= second)
            {
                second = num;
            }
            else //我大于第一个 大于第二个 就是答案
            {
                return true;
            }
        }
        return false;
    }
};

//“递增的x元子序列”通用解法：维护子序列数组
//维护一个子序列数组win，该数组长度最长为3。初始化win为[nums[0]]，随后遍历数组。
//遇到比子序列最后一位大的元素，则可以将其加入子序列中
//若比子序列最后一位要小，则需要更新该子序列，使得子序列“尽量小”，例如子序列为[1,4]时，
//此时遇到元素2，那么需要将子序列更新为[1,2]，因为在子序列“尽量小”的情况下才更容易遇到递增元素；
//另一个例子是[4, 5], 遇到元素1,此时需要更新为[1,5]，可以发现这时候子序列并不严格对应最终的递增子序列，
//但是在只需要长度的情况下可以不用考虑子序列的元素情况。

//通用解法
class Solution {
public:
    bool increasingTriplet(vector<int>& nums, int k) {
        if (nums.size() < 3)
        {
            return false;
        }
		vector<int> less(k, 0x7fffffff);
        for (int num : nums)
        {
			for (int j = 0; j < k; ++j)
			{
				if (num <= less[j])
				{
					less[j] = num;
					break;
				}
			}
			if (j == k)
			{
				return true;
			}
        }
        return false;
    }
};