//严格单调栈的思想
void SortStack(stack<int>& nums)
{
	if (nums.size() < 2)
	{
		return;
	}
	stack<int> help;
	while (!nums.empty())
	{
		int cur = nums.top();
		nums.pop();
		while (!help.empty() && help.top() <= cur)
		{
			nums.push(help.top());
			help.pop();
		}
		help.push(cur);
	}
	while (!help.empty())
	{
		nums.push(help.top());
		help.pop();
	}
}