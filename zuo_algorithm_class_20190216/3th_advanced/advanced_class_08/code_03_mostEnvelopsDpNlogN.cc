//返回具体的信封
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

	//dp o(n * log(n)) 算出以哪个位置结尾的情况下 递增子序列最长
	int length = 0;
	int lenIdx = -1;
	vector<int> ends(envelops.size());
	ends[0] = envelops[0][1];
	for (int i = 1; i < envelops.size(); ++i)
	{
		int l = 0;
		int r = length;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (envelops[i][1] > ends[m])
			{
				l = m + 1;
			}
			else 
			{
				l = m - 1;
			}
		}
		if (l > length)
		{
			length = l;
			lenIdx = i;
		}
		ends[l] = envelops[i][1];
	}

	//依据长度与位置 算出具体的子序列
	assert(length != 0 && lenIdx != -1);
	++length;
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

//左神源码
	public static int maxEnvelopes(int[][] es) {
		if (es == null || es.length == 0 || es[0] == null || es[0].length != 2) {
			return 0;
		}
		Dot[] dots = new Dot[es.length];
		for (int i = 0; i < es.length; i++) {
			dots[i] = new Dot(es[i][0], es[i][1]);
		}
		Arrays.sort(dots, new DotComparator());
		int[] ends = new int[es.length];
		ends[0] = dots[0].h;
		int right = 0;
		int l = 0;
		int r = 0;
		int m = 0;
		for (int i = 1; i < dots.length; i++) {
			l = 0;
			r = right;
			while (l <= r) {
				m = (l + r) / 2;
				if (dots[i].h > ends[m]) {
					l = m + 1;
				} else {
					r = m - 1;
				}
			}
			right = Math.max(right, l);
			ends[l] = dots[i].h;
		}
		return right + 1;
	}