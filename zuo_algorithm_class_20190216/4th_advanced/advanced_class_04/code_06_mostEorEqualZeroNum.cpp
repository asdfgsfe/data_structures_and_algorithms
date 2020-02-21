//�ݹ� ����һ���޺�Ч�������𣿣���
int MostEor(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	return EorProcess(numbers, 0);
}

int EorProcess(const vector<int>& numbers, int i)
{
	if (i == numbers.size())
	{
		return 0;
	}
	int moreNum = 0;
	for (int s = i; s < numbers.size(); ++s) //����Ӧ��Ҫs = i + 1�������޵ݹ���ȥ
	{
		int curNum = (Eor(numbers, i, s) == 0 ? 0 : 1) + EorProcess(numbers, s);
		moreNum = std::max(moreNum, curNum);
	}
	return moreNum;
}

//�������Ҳ�����Ż��� ֱ���ڵݹ麯�����м�������
int Eor(const vector<int>& numbers, int l, int r)
{
	int eor = 0;
	for (int i = l; i <= r; ++i)
	{
		eor ^= numbers[i];
	}
	return eor;
}

//O(n*n) �����Ż����ڲ��ı��� ͨ��map
int MostEorDp(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	vector<int> dp(numbers.size() + 1, 0);
	vector<int> eors(numbers.size() + 1, 0); //��������Ż���
	int moreNum = 0;
	int curEor = 0;
	for (int i = dp.size() - 2; i >= 0; --i)
	{
		eors[i] = numbers[i] ^ eors[i + 1];
		for (int s = i; s < numbers.size(); ++s)
		{
			curEor = ((eors[i] ^ eors[s]) == 0 ? 1 : 0) + dp[s];
			dp[i] = std::max(dp[i], curEor); //ѡ���ö��ַ��䷽���� ���һ��
		}
	}
	return dp[0];
}

//o(n) ���ۼӺ͵���ĳһ���̶�ֻ��һ���ĵ��� ֻ��������̶�ֵ��0
int MostEorPerfect(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	unordered_map<int, int> eorToIdxs;
	eorToIdxs[0] = -1;
	//dp�д浽ĿǰΪֹ �Ѿ��ֳ�������������� ��i��β����������͵���0���
	vector<int> dp(numbers.size(), 0);
	int moreNum = 0;
	int curEor = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		curEor ^= numbers[i];
		////���eor(0~i) == eor(0~j) ��eor(i~j)һ������0 Ҳ������map���ҵ� �����ҵ�������Ϊ0��һ��������
		auto preIdx = eorToIdxs.find(curEor);
		if (preIdx != eorToIdxs.end())
		{
			dp[i] = preIdx->second == -1 ? 1 : dp[preIdx->second] + 1;
		}
		if (i > 0)
		{
			dp[i] = std::max(dp[i], dp[i - 1]); 
		}
		eorToIdxs[curEor] = i;
		moreNum = std::max(moreNum, dp[i]);
	}
	return moreNum; //�о�dp.back() == moreNum
}
