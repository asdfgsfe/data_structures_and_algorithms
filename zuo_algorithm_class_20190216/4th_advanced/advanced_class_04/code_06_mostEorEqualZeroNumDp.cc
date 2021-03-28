int EorEqualZeroSubArrayNum(const vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
	return EorProcess(nums, 0);
}

int EorProcess(const vector<int>& nums, int i)
{
	if (i == nums.empty())
	{
		return 0;
	}
	int cnt = 0;
	int eor = nums[i];
	for (int s = i + 1; s < nums.size(); ++s)
	{
		eor ^= nums[s];
		int nextCnt = EorProcess(nums, s);
		nextCnt = eor == 0 ? nextCnt + 1 : nextCnt;
		cnt = std::max(cnt, nextCnt);
	}
	return cnt;
}

int EorEqualZeroSubArrayNumDp(const vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
	vector<int> dp(nums.size() + 1, 0);
	for (int i = dp.size() - 2; i >= 0; --i)
	{
		int eor = nums[i];
		for (int j = i + 1; j < nums.size(); ++i)
		{
			eor ^= nums[j];
			int cur = eor == 0 ? 1 : 0;
			dp[i] = std::max(dp[i], dp[j] + cur);
		}
	}
	return dp[0];
}

//贪心算法o(n)
int EorEqualZeroSubArrayNumDp(const vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
	unordered_map<int, int> eorToIds;
	eorToIds[0] = -1;
	vector<int> dp(nums.size(), 0); //表示已每个位置结尾的情况下 统计出来的最长值
	int moreNum = 0;
	int eor = 0;
	for (int i = 0; i < nums.size(); ++i)
	{	
		eor ^= nums[i];
		auto preId = eorToIdx.find(eor);
		if (preId != eorToIdx.end())
		{
			dp[i] = preId->second == -1 ? 1 : dp[preId->second] + 1;
		}
		if (i > 0)
		{
			dp[i] = std::max(dp[i], dp[i -1]);
		}
		eorToIds[eor] = i; //类似于贪心算法 存最近的异或和为0的算法
		moreNum = std::max(moreNum, dp[i]);
	}
	return moreNum;
}
