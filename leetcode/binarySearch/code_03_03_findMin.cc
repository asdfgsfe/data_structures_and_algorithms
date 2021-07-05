class Solution {
public:
	int findMin(vector<int>& nums) {
		if (nums.empty())
		{
			return -1;
		}
		if (nums.size() < 2 || nums.front() < nums.back())
		{
			return nums[0];
		}
		if (nums[nums.size() - 2] > nums[nums.size() - 1])
		{
			return nums.back();
		}
		//���������޳��߽�ļ���
		int l = 1;
		int r = nums.size() - 2;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] < nums[m - 1])
			{
				return nums[m];
			}
			else
			{
				//����һ���� ����r �����Ǵ���l ��Ϊl�п�����Ŀ���
				//ֻ�д���������� ����֪��m�����ұ�
				if (nums[m] > nums[r])
				{
					l = m + 1;
				}
				else
				{
					r = m - 1;
				}
			}
		}
		return -1;
	}
};

//��������һ��
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.empty() ? 0x80000000 : nums[0];
        }
        if (nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }
        if (nums[nums.size() - 1] < nums[nums.size() - 2]) {
            return nums.back();
        }

        int l = 1;
        int r = nums.size() - 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m - 1] && nums[m] < nums[m + 1]) {
                return nums[m];
            }
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return 0x80000000;
    }
};
