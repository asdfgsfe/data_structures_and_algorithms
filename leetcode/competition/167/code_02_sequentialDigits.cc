class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> nums;
		int lBits = Bits(low);
		int rBits =Bits(high);
		for (int l = lBits; l <= rBits; ++l)
		{
			for (int i = 1; i <= 9; ++i)
			{
				int num = 0;
				int index = i;
				bool end = false;
				for (int j = l; j > 0; --j)
				{
					if (index > 9)
					{
						end = true;
						break;
					}
					num = num * 10 + index++;
				}
				if (!end && num >= low && num <= high)
				{
					nums.emplace_back(num);
				}
				num = 0;
			}
		}
		return nums;
	}

	int Bits(int num)
	{
		int bit = 0;
		while (num)
		{
			++bit;
			num /= 10;
		}
		return bit;
	}
};