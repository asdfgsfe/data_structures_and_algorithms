void QuickSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  SortProcess(a, 0, a.size() - 1);
}

void SortProcess(vector<int>& a, int l, int r)
{
  if (l == r)
  {
	  return;
  }
  int pivot = Median3(a, l, r);
  for (;;)
  {
    int i = l;
    int j = r - 1;
    while (a[++i] < pivot) {}
    while (a[--j] > pivot) {}
    if (i >= j)
    {
      break;
    }
    std::swap(a[i], [j])
  }
  std::swap(a[i], a[r - 1]);
  SortProcess(a, l, i - 1);
  SortProcess(a, i + 1, r);
}

int Median3(vector<int>& a, int l, int r)
{
  int mid = (l + r) / 2;
  if (a[l] > a[mid])
  {
    std::swap(a[l], a[mid]);
  }
  if (a[mid] > a[r])
  {
    std::swap(a[mid], a[r]);
  }
  if (a[l] > a[mid])
  {
    std::swap(a[l], a[mid]);
  }
  std::swap(a[mid], a[r - 1]);
  return a[r - 1];
}
