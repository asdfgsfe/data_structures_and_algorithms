void MergeSort(vector<int>& a)
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
    int m = (l + r) / 2;
    SortProcess(a, l, m);
    SortProcess(a, m + 1, r);
    Merge(a, l, m, r)
  }
}

void Merge(vector<int>& a, int l, int m, int r)
{
  vector<int> help(r - l + 1);
  int rS = m + 1;
  int lS = l;
  int id = 0;
  while (lS <= m && rS <= r)
  {
    help[id++] = a[lS] < a[rS] ? a[lS++] : a[rS++];
  }
  while (lS < m)
  {
    help[id++] = a[lS++];
  }
  while (rS < m)
  {
    help[id++] = a[rS++];
  }
  for (int i = 0; i < help.size(); ++i)
  {
    a[l + i] = help[i];
  }
}
