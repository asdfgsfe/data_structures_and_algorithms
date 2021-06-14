class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.empty())
		{
			return -1;
		}
		if (nums.size() < 2 || nums[0] > nums[1])
		{
			return 0;
		}
		if (nums[nums.size() - 2] < nums[nums.size() - 1])
		{
			return nums.size() - 1;
		}
		//�޳��߽� ����Ҫ ��ֹm-1<0��m+1==nums.size()
		int l = 1;
		int r = nums.size() - 2;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			//ע�����ﱣ��ͬ�ź���Ҫ
			if (nums[m] < nums[m - 1])
			{
				r = m - 1;
			}
			else if (nums[m] < nums[m + 1])
			{
				l = m + 1;
			}
			else
			{
				return m;
			}
		}
		return -1;
	}
};
