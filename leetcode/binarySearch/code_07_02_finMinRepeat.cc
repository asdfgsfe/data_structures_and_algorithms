//Ѱ����ת���������е���Сֵ II ���ظ�����

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

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.empty() ? 0x80000000 : nums[0];
        }
        if (nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }
        if (nums[nums.size() - 2] > nums[nums.size() - 1]) {
            return nums[nums.size() - 1];
        }
        int l = 1;
        int r = nums.size() - 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                r = m;
			//��������� Ҳ�������ұ� ��r������ƶ�һ�� �����ظ�����
            } else {
                r -= 1;
            }
        }
        return nums[l];
    }
};
