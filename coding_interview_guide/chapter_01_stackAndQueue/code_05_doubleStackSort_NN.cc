//n*n 左神的也是n*n但是少了常数xaing
void SortStack(stack<int>& nums)
{
	if (nums.size() < 2)
	{
		return;
	}
	stack<int> help;
	int size = nums.size();
	int maxNum = 0x80000000;
	for (int i = 0; i < size; ++i)
	{
		while (nums.size() > i)
		{
			int num = nums.top();
			nums.pop();
			help.push(num);
			maxNum = std::max(maxNum, num);
		}
		assert(nums.size() == i);
		nums.push(maxNum);
		while (!help.empty())
		{
			int num = help.top();
			help.pop();
			if (num != maxNum)
			{
				nums.push(num);
			}
		}
		maxNum = 0x80000000;
	}
}