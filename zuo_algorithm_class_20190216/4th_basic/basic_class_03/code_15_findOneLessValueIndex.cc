int FindOneLessValueIndex(const vector<int>& values)
{
	if (values.empty())
	{
		return -1;
	}
	if (values[0] < values[1])
	{
		return 0;
	}
	if (values[values.size() - 2] > values[values.size() - 1])
	{
		return values.size() - 1;
	}
	int l = 1;
	int r = values.size() - 2;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (values[mid] > values[mid - 1])
		{
			r = mid - 1;
		}
		else if (values[mid] > values[mid + 1])
		{
			l = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return l;
}