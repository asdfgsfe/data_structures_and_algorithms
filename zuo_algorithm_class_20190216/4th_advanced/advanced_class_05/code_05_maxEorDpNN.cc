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

//error �������ͺ��ۼӺ� �ۼӺ͵�dp[i - 1]һ��������
//�������Ͳ�һ�� ����Ҫ��ǰ����һֱ�鵽������
//����ĵݹ�
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

//��ȷ�ĵݹ�
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

//o(n*n) ��̬�滮�ķ��� ��ǰ׺����Ϊ���� ������������
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

//o(n*n) ��������ķ��� ����e(0~i) ^ e(0^j) == e(i~j)
int MaxEor(const vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
	vector<int> eors(nums.size(), 0);
	eors[0] = nums[0];
	for (int i = 1; i < nums.size(); ++i)
	{
		eors[i] = eors[i - 1] + nums[i];
	}
	int maxEor = 0x80000000;
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < nums.size(); ++j)
		{
			maxEor = std::max(maxEor, nums[j] ^ nums[i]);
		}
	}
	return maxEor;
}

