class Solution {
public:
    //貌似无法解决重复数字的问题 例如0 2 2找到的数字是3
    int missingNumber(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int miss = nums.size();//这里很重要
        int i = 0;
        while (i < nums.size())
        {
            //可能是缺失的数字 记录下
            if (nums[i] >= nums.size() || nums[i] < 0)
            {
                miss = i++;
            }
            //这一步包含了 i == nums[i]的情况 如果 i == nums[i] 那么下面必然相等
            //重复相等说明丢失了 两个数字 随便找一个就行， 本方法找出来的是最大的那个 一定是最大的那个
            else if (nums[i] == nums[nums[i]])
            {
                ++i;
            }
            else
            {
                std::swap(nums[i], nums[nums[i]]);
            }
        }
        return miss;
    }
};
