int MaxSum(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	int maxSum = 0x80000000;
	int curSum = numbers[0];
	for (int i = 0; i < numbers.size(); ++i)
	{
		curSum = curSum <= 0 ? numbers[i] : curSum + numbers[i];
		maxSum = std::max(maxSum, curSum);
	}
	return maxSum;
}

//����dpҲ��o(n) ���ǿռ临����o(n) ���þ���ѹ�����Խ��ս���ȥ
int MaxSum2(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	int maxSum = 0x80000000;
	vector<int> dp(numbers.size(), 0);
	dp[0] = numbers[0];
	for (int i = 1; i < numbers.size(); ++i)
	{
		
		dp[i] = std::max(numbers[i], dp[i - 1] + numbers[i])
		maxSum = std::max(maxSum, dp[i]);
	}
	return maxSum;
}