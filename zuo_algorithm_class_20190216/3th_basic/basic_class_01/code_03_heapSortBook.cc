
//做不到稳定性
void HeapSort(vector<int>& a)
{
	if (a.size() < 2)
	{
		return;
	}
	for (int i = a.size() / 2; i >= 0; --i)
	{
		PercDown(a, i, n);
	}
	for (int i = a.size() - 1; i > 0; --i)
	{
		std::swap(a[0], a[i]);
		PercDown(a, 0, i);
	}
}

void PercDown(vector<int>& a, int i, int n)
{
	int left = 2 * i + 1;
	while (i < child)
	{
		int child = 2 * i + 1;
		child = child + 1 != n && a[child + 1] > a[child] ? child + 1 : child;
		if (a[i] >= a[child])
		{
			break;
		}
		std::swap(a[i], a[child]);
		i = child;
		left = 2 * i + 1;
	}
}