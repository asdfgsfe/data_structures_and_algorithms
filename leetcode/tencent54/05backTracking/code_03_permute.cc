ȫ����
����һ��û���ظ����ֵ����У����������п��ܵ�ȫ���С�

ʾ��:

����: [1,2,3]
���:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty())
        {
            return {{}};
        }
        vector<vector<int>> permutetions;
        PermuteProcess(nums, 0, permutetions);
        return permutetions;
    }
    
    void PermuteProcess(vector<int>& nums, int i, vector<vector<int>>& permutetions)
    {
        if (i == nums.size())
        {
            permutetions.emplace_back(nums);
            return;
        }
        for (int s = i; s < nums.size(); ++s)
        {
            std::swap(nums[s], nums[i]);
            PermuteProcess(nums, i + 1, permutetions);
            std::swap(nums[s], nums[i]);
        }
    }
};