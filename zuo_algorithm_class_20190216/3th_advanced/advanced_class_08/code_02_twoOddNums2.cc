vector<int> TwoOddNums2(const vector<int>& nums)
{
	if (nums.size() < 3)
	{
		return nums;
	}
	int e0 = 0;
	for (int num : nums)
	{
		e0 ^= num;
	}
	int bit1 = LeftBit1(e0);
	int e1 = 0;
	int e2 = 0;
	for (int num : nums)
	{
		if (num & bit1)
		{
			e1 ^= num;
		}
		else
		{
			e2 ^= num;
		}
	}
	return {e1, e2};
}

int LeftBit1(int num)
{
	int bit = 1;
	for (int move = 0; move < 32; ++move)
	{
		if (num & bit)
		{
			return bit;
		}
	}
	return 0;
}