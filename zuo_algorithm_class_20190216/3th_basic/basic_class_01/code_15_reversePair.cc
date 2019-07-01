int ReversePair(vector<int>& numbers)
{
  if (numbers.size() < 2)
  {
    return 0;
  }
  return MergeSort(numbers, 0, numbers.size() - 1);
}

int MergeSort(vector<int>& numbers, int l, int r)
{
  if (l == r)
  {
    return 0;
  }
  int mid = l + (r - l) >> 1;
  return MergeSort(numbers, l, mid) + MergeSort(numbers, mid + 1, r) + Merge(numbers, l, mid, r);
}

int Merge(vector<int>& numbers, int l, int m, int r)
{
  array<int, r - l + 1> help;
  int p1 = m;
  int p2 = r;
  int count = 0;
  int id = 0;
  while (p1 >= 0 && p2 >= 0)
  {
    if (numbers[p1] > numbers[p2])
    {
      count += p2 - mid;
      help[id++] = numbers[p2--];
    }
    else
    {
      help[id++] = numbers[p1--];
    }
  }
  while (p1 >= 0)
  {
    help[id++] = numbers[p1--];
  }
  while (p2 >= 0)
  {
    help[id++] = numbers[p2--]
  }
  for (int i = 0; i < help.size(); ++i)
  {
    numbers[r - i] = help[i];
  }
  return count;
}
