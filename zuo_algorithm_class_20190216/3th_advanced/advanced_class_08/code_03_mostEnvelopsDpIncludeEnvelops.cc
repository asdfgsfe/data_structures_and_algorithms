//���ؾ�����ŷ�
vector<vector<int>> MostEnvelop(const vector<vector<int>>& envelops)
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

	//dp o(n*n) ������ĸ�λ�ý�β������� �����������
	int length = 0;
	int lenIdx = -1;
	vector<int> dp(envelops.size(), 1);
	for (int i = 1; i < dp.size(); ++i)
	{
		for (int s = i - 1; s >= 0; --s)
		{
			dp[i] = std::max(dp[i], dp[s] + 1);
		}
		if (length < dp[i])
		{
			length = dp[i];
			lenIdx = i;
		}
	}

	//���ݳ�����λ�� ��������������
	assert(length != 0 && lenIdx != -1);
	vector<vector<int>> includeEnveLops(length);
	includeEnveLops[length - 1] = envelops[lenIdx];
	int idx = length - 1;
	for (int pre = lenIdx - 1; pre >= 0; --pre)
	{
		if (envelops[pre][1] < envelops[lenIdx][1] && dp[pre] + 1 == dp[lenIdx])
		{
			includeEnvelops[--idx] = envelops[lenIdx];
			lenIdx = pre;
		}
	}
	return includeEnveLops;
}