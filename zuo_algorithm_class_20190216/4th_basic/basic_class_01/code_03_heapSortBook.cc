void HeapSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  for (int i = a.size() / 2; i >= 0; --i)
  {
    PercDown(a, i, a.size());
  }
  for (int i = a.size(); i > 0; --i)
  {
    std::swap(a[0], a[i]);
    PercDown(a, 0, i);
  }
}

#define LeftChild(i) ((2 * (i)) + 1)
void PercDown(vector<int>& a, int i, int n)
{
  int tmp;
  for (tmp = a[i]; LeftChild(i) < n; i = child)
  {
    int child = LeftChild(i);
    if (child != n - 1 && a[child + 1] > a[child])
    {
      ++child;
    }
    if (a[child] > a[i])
    {
      a[i] = a[child];
    }
    else
    {
      break;
    }
  }
  a[i] = tmp;
}

void PercDown2(vector<int>& a, int i, int n)
{
  while (LeftChild(i) < n)
  {
    int child = LeftChild(i);
    if (child != n - 1 && a[child + 1] > a[child])
    {
      ++child;
    }
    if (a[i] > a[child])
    {
      break;
    }
    std::swap(a[i], a[child]);
    i = child;
  }
}

