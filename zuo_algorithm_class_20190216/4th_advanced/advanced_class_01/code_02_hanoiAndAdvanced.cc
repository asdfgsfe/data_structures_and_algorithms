int HanoiAdvanced(const vector<int>& steps)
{
	if (steps.empty())
	{
		return 0;
	}
	return MoveProcess(steps, steps.size() - 1, 1, 2, 3);
}

int MoveProcess(const vector<int>& steps, int i, int from, int mid, int to)
{
	if (i < 0)
	{
		return 0;
	}
	if (steps[i] == mid)
	{
		return -1;
	}
	if (steps[i] == from)
	{
		return MoveProcess(steps, i - 1, from, to, mid);
	}
	in res = MoveProcess(steps, i - 1, mid, to, from);
	return res == -1 ? -1 : (1 << i) + res;
}

int HanoiAdvanced2(const vector<int>& steps)
{
	if (steps.empty())
	{
		return 0;
	}
	int form = 1;
	int mid = 2;
	int to = 3;
	int i = steps.size() - 1;
	int step = 0;
	while (i >= 0)
	{
		if (steps[i] == mid)
		{
			return -1;
		}
		if (steps[i] == from)
		{
			std::swap(to, mid);
		}
		else
		{
			std::swap(mid, from);
			res += (1 << i);
		}
		--i;
	}
	return res;
}