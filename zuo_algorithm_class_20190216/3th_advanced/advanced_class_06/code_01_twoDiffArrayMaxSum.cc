//o(n) 域处理数组的思想 
int TwoDiffSubArrayMaxSum(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  if (numbers.size() == 1)
  {
    return numbers.front();
  }
  vector<int> lMaxs = SubArrayMaxSum(numbers, true);
  vector<int> rMaxs = SubArrayMaxSum(numbers, false);
  int res = 0x80000000;
  int cur = 0;
  for (int i = 1; i < numbers.size(); ++i)
  {
    cur = lMaxs[i - 1] + rMaxs[i];
    res = std::max(res, cur);
  }
  return res;
}

//计算以每个位置结尾的情况下 最大累加和 存起来
vector<int> SubArrayMaxSum(const vector<int>& numbers, int isFromL)
{
  vector<int> records(numbers.size());
  if (isFromL)
  {
    records[0] = numbers[0];
    for (int i = 1; i < numbers.size(); ++i)
    {
      records[i] = std::max(numbers[i], records[i - 1] + numbers[i]);
    }
  }
  else
  {
    records[number.size() - 1] = numbers.back();
    for (int i = numbers.size() - 2; i >= 0; --i)
    {
      records[i] = std::max(numbers[i], records[i - 1] + numbers[i]);
    }
  }
  return records;
}


//o(n*n) 不好的解法 第二种方法
int TwoDiffSubArrayMaxSum(const vector<int>& nums)
{
	if (nums.empty())
	{
		return 0;
	}
	int sum = 0;
	for (int i = 1; i < nums.size(); ++i)
	{
		sum = std::max(sum, SubArrayNums(nums, 0, i - 1) + SubArrayNums(nums, i, nums.size() - 1));
	}
	return sum;
}

int SubArrayNums(const vector<int>& nums, int l, int r)
{
	int sum = 0x80000000;
	int cur = 0;
	for (int i = l; i <= r; ++i)
	{
		cur += nums[l];
		sum = std::max(cur, sum);
		cur = cur < 0 ? 0 : cur;
	}
	return sum;
}
