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
  if (l < r)
  {
    std::swap(a[l + ::rand() % (r - l + 1)], a[r]);
    vector<int> lessMore = Partition(a, l ,r);
    SortProcess(a, l, lessMore[0] - 1);
    SortProcess(a, lessMore[1] + 1, r)
  }
}

void Partiotion(vector<int>& a, int l, int r)
{
  int less = l - 1;
  int more = r;
  while (l < more)
  {
    if (a[l] < a[r])
    {
      std::swap(a[++less], a[l++]);
    }
    else if (a[l] > a[r])
    {
      std::swap(a[--more], a[l])
    }
    else
    {
      ++l;
    }
  }
  std::swap(a[more], a[r]);
  return {less + 1, more};
}
