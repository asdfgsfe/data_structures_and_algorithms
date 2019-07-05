int MostEnvelop(const vector<vector<int>>& envelops)
{
	if (envelops.empty() || envelopes[0].size() != 2)
	{
		return 0;
	}
	std::sort(envelops.begin(), envelops.end(), 
		[](const auto& lhs, const auto& rhs)
		{
			if (lhs[0] != rhs[0])
			{
				return lhs[0] < rhs[0];
			}
			return lhs[1] > rhs[1];
		});

	//dp o(n*n)
	int length = 0;
	vector<int> dp(envelops.size(), 1);
	for (int i = 1; i < dp.size(); ++i)
	{
		for (int s = i - 1; s >= 0; --s)
		{
			dp[i] = std::max(dp[i], dp[s] + 1);
		}
		length = std::max(length, dp[i]);
	}

	return length;
}