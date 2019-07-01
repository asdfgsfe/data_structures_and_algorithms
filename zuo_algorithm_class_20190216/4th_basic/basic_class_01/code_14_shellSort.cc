void ShellSort(vector<int>& values)
{
	if (values.size() < 2)
	{
		return;
	}
	for (int s = values.size() / 2; s >= 0; s /= 2)
	{
		for (int p = s; p < values.size(); ++p)
		{
			for (int i = p; i >= s && a[i - s] > a[i]; i -= s)
			{
				std::swap(values[i - s], values[i]);
			}
		}
	}
}