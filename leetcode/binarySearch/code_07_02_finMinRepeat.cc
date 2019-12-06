class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
        {
            return 0x7fffffff;
        }
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
			//������ lһ��������߰벿�� rһ�������ұ߰벿�� ���Բ�����ô�ж�
            if (nums[m] > nums[r])
            {
                l = m + 1;
            }
            else if (nums[m] < nums[r])
            {
                r = m;//m�п����Ǵ�
            }
            else
            {
                r = r - 1;
            }
        }
        return nums[l];
    }
};