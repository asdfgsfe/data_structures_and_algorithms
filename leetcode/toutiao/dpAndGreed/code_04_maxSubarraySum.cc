
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ��:

����: [-2,1,-3,4,-1,2,1,-5,4],
���: 6
����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��
����:

������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int sum = 0x80000000;
        int curSum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            curSum += nums[i];
            sum = std::max(sum, curSum);
            curSum = curSum < 0 ? 0 : curSum;
        }
        return sum;
    }
};