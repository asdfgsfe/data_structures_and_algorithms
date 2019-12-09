class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		if (nums.empty())
		{
			return 0;
		}
		int cnt = 0;
		SumWaysProcess(nums, 0, S, cnt);
		return cnt;
	}

	void SumWaysProcess(const vector<int>& nums, int i, int sum, int& cnt)
	{
		if (i == nums.size())
		{
			cnt = sum == 0 ? cnt + 1 : cnt;
			return;
		}
		SumWaysProcess(nums, i + 1, sum - nums[i],cnt)
		SumWaysProcess(nums, i + 1, sum + nums[i],cnt);
	}
};


class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		if (nums.empty())
		{
			return 0;
		}
		return SumWaysProcess(nums, 0, S);
	}

	//���յݹ����������ս���ķ��� ֻ�е���������++1 �����Ƿ��صĹ����м�1
	int SumWaysProcess(const vector<int>& nums, int i, int sum)
	{
		if (i == nums.size())
		{
			return sum == 0 ? 1 : 0;
		}
		return SumWaysProcess(nums, i + 1, sum - nums[i],cnt)
				+ SumWaysProcess(nums, i + 1, sum + nums[i],cnt);
	}
};