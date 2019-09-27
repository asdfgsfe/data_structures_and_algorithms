//Book p115
int MaxLength(const vector<int>& numbers, int aim)
{
	if (numbers.empty())
	{
		return 0;
	}
	//域处理数组技术
	vector<int> sums(numbers.size());  //记录以每个位置开始的情况下 向右最小的累加和
	sums.back() = numbers.back();
	unordered_map<int, int> ends; //取得这个最小累加和的时候，最右边的位置到了那里
	ends[numbers.size() - 1] = numbers.size() - 1;
	for (int i = numbers.size() - 2; i >= 0; --i)
	{
		if (sums[i + 1] <= 0) //如果下个累加和为负 有利可图加
		{
			sums[i] = numbers[i] + sums[i + 1];
			ends[i] = ends[i + 1];
		}
		else //正数无利可图只有他自己
		{
			sums[i] = numbers[i];
			ends[i] = i;
		}
	}
	int end = 0;
	int sum = 0;
	int longgest = 0;
	//这个地方也是滑动窗口模型 把我能向右累加的最长的一直累加完
	for (int l = 0; l < numbers.size(); ++l)
	{
		while (end < sums.size() && sum + sums[end] <= aim)
		{
			sum += sums[end];
			end = ends[i];
		}
		longgest = std::max(longgest, end - l);
		sum -= end > l ? numbers[l] : 0;
		end = std::max(end, l + 1); //end始终是最右边的位置
	}
	return longgest;
}
