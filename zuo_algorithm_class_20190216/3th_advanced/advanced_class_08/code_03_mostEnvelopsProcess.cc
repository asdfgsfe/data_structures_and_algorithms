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
	int length = 0;
	for (int i = 0; i < envelops.size(); ++i)
	{
		length = std::max(length, LISequences(envelops, i));
	}
	return length;
}

int LISequences(const vector<vector<int>>& envelops, int i)
{
	if (i == 0)
	{
		return 1;
	}
	int length = 1;
	for (int s = i - 1; s >= 0; --s)
	{
		if (envelops[i][1] > envelops[s][1])
		{
			length = std::max(length, LISequences(envelops, s) + 1);
		}
	}
	return length;
}

