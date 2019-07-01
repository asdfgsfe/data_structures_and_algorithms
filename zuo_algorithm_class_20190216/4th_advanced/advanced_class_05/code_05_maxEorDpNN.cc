int MaxEor(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	int maxEor = 0x80000000;
	EorProcess(numbers, numbers.size() - 1, maxEor);
	return maxEor;
}

//error 区别异或和和累加和 累加和到dp[i - 1]一定是最大的
//但是异或和不一定 所以要向前遍历一直查到到最大的
int EorProcess(const vector<int>& numbers, int i, int maxEor)
{
	if (i == 0)
	{
		return numbers[0];
	}
	int curMaxEor = std::max(numbers[i], numbers[i] ^ EorProcess(numbers, i - 1, maxEor));
	maxEor = std::max(maxEor, curMaxEor);
	return curMaxEor;
}

//正确的递归
int EorProcess2(const vector<int>& numbers, int i, int maxEor)
{
	if (i == 0)
	{
		return numbers[0];
	}
	int curEor = numbers[i] ^ EorProcess2(numbers, i - 1, maxEor);
	for (int s = i - 1; s >= 0; --s)
	{
		maxEor = std::max(maxEor, curEor ^ EorProcess2(numbers, s, maxEor));
	}
	return curEor;
}

//o(n*n)
int MaxEorDp(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	int maxEor = 0;
	int eor = 0;
	vector<int> dp(numbers.size(), 0);
	for (int i = 0; i < numbers.size(); ++i)
	{
		curEor ^= numbers[i];
		for (int s = i - 1; s >= 0; --s)
		{
			maxEor = std::max(maxEor, curEor ^ dp[s]);
		}
		dp[i] = curEor;
	}
	return maxEor;
}
