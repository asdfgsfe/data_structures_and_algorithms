void MergeSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  vector<int> help(a.size());
  MSort(a, help, 0, a.size() - 1);
}

void MSort(vector<int>& a, vector<int>& help, int l, int r)
{
  if (l < r)
  {
    int center = (l + r) / 2;
    MSort(a, help, l, center);
    MSort(a, help, center + 1, r);
    Merge(a, help, l, center, r);
  }
}

void Merge(vector<int>& a, vector<int>& help, int l, int c, int r)
{
  int rStart = c + 1;
  int id = l;
  while (l <= c && rStart <= r)
  {
    if (a[l] < a[rStart])
    {
      help[id++] = a[l++];
    }
    else 
    {
      help[id++] = a[rStart++]
    }
  }
  while (l <= c)
  {
    help[id++] = a[l++];
  }
  while(rStart <= r)
  {
    help[id++] = a[rStart++];
  }
  for (int i = id - 1; id >= l; --id)
  {
    a[id] = help[id];
  }
}

//可以做到稳定 正常时间o(n*log(n)) 空间o(n)
void MergeSort2(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  MSort(a, 0, a.size() - 1);
}

void MSort(vector<int>& a, int l, int r)
{
  if (l < r)
  {
    int mid = l + ((r - l) >> 1);
    MSort(a, l, mid);
    Msort(a, mid + 1, r);
    Merge(a, l, mid, r);
  }
}

void Merge(vector<int>& a, int l, int m, int r)
{
  vector<int> help(r - l + 1);
  int i = 0;
  int p1 = l;
  int p2 = m + 1;
  while (p1 <= m && p2 <= r)
  {
    help[i++] = a[p1] < a[p2] ? a[p1++] : a[p2++];
  }
  while (p1 <= m)
  {
    help[i++] = a[p1++];
  }
  while (p2 <= r)
  {
    help[i++] = a[p2++];
  }
  for (int i = 0; i < help.size(); ++i)
  {
    a[l + i] = help[i];
  }
}
