������������� //������ʵ��������ĸ���
����һ��δ��������������飬�ҵ���������ĵĵ������С�

ʾ�� 1:

����: [1,3,5,4,7]
���: 3
����: ��������������� [1,3,5], ����Ϊ3��
���� [1,3,5,7] Ҳ�������������, �������������ģ���Ϊ5��7��ԭ�����ﱻ4������ 
ʾ�� 2:

����: [2,2,2,2,2]
���: 1
����: ��������������� [2], ����Ϊ1��
ע�⣺���鳤�Ȳ��ᳬ��10000��


//�ݹ� ��ÿ��λ�ý�β�������������
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int lcs = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            lcs = std::max(lcs, LCSProcess(nums, i));
        }
        return lcs;
    }
    
    int LCSProcess(const vector<int>& nums, int i)
    {
        if (i == 0)
        {
            return 1;
        }
        int lcs = 1;
        if (nums[i] > nums[i - 1])
        {
            lcs += LCSProcess(nums, i - 1);
        }
        return lcs;
    }
};

//dp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }        
        int lcs = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            lcs = std::max(lcs, dp[i]);
        }
        return lcs;
    }
};

//����ѹ������
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }        
        int lcs = 1;
        int pre = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            pre = nums[i] > nums[i - 1] ? pre + 1 : 1;
            lcs = std::max(lcs, pre);
        }
        return lcs;
    }
};
