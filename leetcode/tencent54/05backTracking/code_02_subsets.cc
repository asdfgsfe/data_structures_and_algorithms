�Ӽ�
����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:

����: nums = [1,2,3]
���:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty())
        {
            return {{}};
        }
        vector<vector<int>> subsequences;
        vector<int> oneSequence;
        SequenceProcess(nums, 0, oneSequence, subsequences);
        return subsequences;
    }
    
    void SequenceProcess(const vector<int>& nums, int i, vector<int>& oneSequence, vector<vector<int>>& subsequences)
    {
        if (i == nums.size())
        {
            subsequences.emplace_back(oneSequence);
            return;
        }
        SequenceProcess(nums, i + 1, oneSequence, subsequences);
        oneSequence.emplace_back(nums[i]);
        SequenceProcess(nums, i + 1, oneSequence, subsequences);
        oneSequence.pop_back();
    }
};