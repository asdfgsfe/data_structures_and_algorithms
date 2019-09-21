int SmallSum(vector<int>& numbers)
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
  int p1 = l;
  int p2 = m + 1;
  int res = 0;
  int id = 0;
  while (p1 <= m && p2 <= r)
  {
    //小于仅仅只是针对某一个点 一个点一个点的判断 这个能点够成的小和是多少
    //如果我小于 后半段的某一个点 那么我小于他后面所有的值
    //一个点一个点判断很重要 防止重复判断
    res += numbers[p1] < numbers[p2] ? (r - p2 + 1) * numbers[p1];
    help[id++] = numbers[p1] < numbers[p2] ? numbers[p1++] : numbers[p2++];
  }
  while (p1 <= m)
  {
    help[id++] = numbers[p1++];
  }
  while (p2 <= r)
  {
    help[id++] = numbers[p2++];
  }
  for (int i = 0; i < help.size(); ++i)
  {
    numbers[l + i] = help[i];
  }
  return res;
}


