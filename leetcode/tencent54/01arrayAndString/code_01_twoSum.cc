����֮��
����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ��㲻���ظ��������������ͬ����Ԫ�ء�

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return vector<int>();
        }
        unordered_map<int, int> numToIdx;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto idx = numToIdx.find(target - nums[i]);
            if (idx != numToIdx.end())
            {
                return {idx->second, i};
            }
            numToIdx.insert(std::pair<int, int>(nums[i], i));
        }
        return vector<int>();
    }
};