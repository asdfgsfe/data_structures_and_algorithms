//递归 这是一个无后效性问题吗？？？
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
	for (int s = i; s < numbers.size(); ++s) //这里应该要s = i + 1否则无限递归下去
	{
		int curNum = (Eor(numbers, i, s) == 0 ? 0 : 1) + EorProcess(numbers, s);
		moreNum = std::max(moreNum, curNum);
	}
	return moreNum;
}

//这个遍历也可以优化掉 直接在递归函数体中计算异或和
int Eor(const vector<int>& numbers, int l, int r)
{
	int eor = 0;
	for (int i = l; i <= r; ++i)
	{
		eor ^= numbers[i];
	}
	return eor;
}

//O(n*n) 可以优化掉内部的遍历 通过map
int MostEorDp(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	vector<int> dp(numbers.size() + 1, 0);
	vector<int> eors(numbers.size() + 1, 0); //这个可以优化掉
	int moreNum = 0;
	int curEor = 0;
	for (int i = dp.size() - 2; i >= 0; --i)
	{
		eors[i] = numbers[i] ^ eors[i + 1];
		for (int s = i; s < numbers.size(); ++s)
		{
			curEor = ((eors[i] ^ eors[s]) == 0 ? 1 : 0) + dp[s];
			dp[i] = std::max(dp[i], curEor); //选出好多种分配方法中 最长的一种
		}
	}
	return dp[0];
}

//o(n) 和累加和等于某一个固定只是一样的道理 只不过这个固定值是0
int MostEorPerfect(const vector<int>& numbers)
{
	if (numbers.empty())
	{
		return 0;
	}
	unordered_map<int, int> eorToIdxs;
	eorToIdxs[0] = -1;
	//dp中存到目前为止 已经分出来的最长的子数组 以i结尾的情况下异或和等于0的最长
	vector<int> dp(numbers.size(), 0);
	int moreNum = 0;
	int curEor = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		curEor ^= numbers[i];
		////如果eor(0~i) == eor(0~j) 则eor(i~j)一定等于0 也就是在map中找到 就是找到了异或和为0的一段子数组
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
	return moreNum; //感觉dp.back() == moreNum
}
