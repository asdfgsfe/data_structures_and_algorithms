class Solution {
public:
    //ò���޷�����ظ����ֵ����� ����0 2 2�ҵ���������3
    int missingNumber(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int miss = nums.size();//�������Ҫ
        int i = 0;
        while (i < nums.size())
        {
            //������ȱʧ������ ��¼��
            if (nums[i] >= nums.size() || nums[i] < 0)
            {
                miss = i++;
            }
            //��һ�������� i == nums[i]����� ��� i == nums[i] ��ô�����Ȼ���
            //�ظ����˵����ʧ�� �������� �����һ�����У� �������ҳ������������Ǹ� һ���������Ǹ�
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
