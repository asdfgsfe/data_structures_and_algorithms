int SmallSum(vector<int>& numbers)
{
  if (numbers.size() < 2)
  {
    return 0;
  }
  return SumProcess(numbers, 0, numbers.size() - 1);
}

int SumProcess(vector<int>& numbers, int l, int r)
{
  if (l == r)
  {
    return 0;
  }
  int m = (l + r) / 2;
  return SumProcess(numbers, l, m) + SumProcess(numbers, m + 1, r) + Merge(numbers, l, m, r);
}

int Merge(vector<int>& numbers, int l, int m, int r)
{
  vector<int> help(numbers.size());
  int lS = l;
  int rS = m + 1;
  int id = 0;
  int smallSum = 0;
  while (lS <= m && rS <= r)
  {
    smallSum += numbers[lS] < numbers[rS] ? (r - rS + 1) * numbers[lS] : 0;
    help[id++] = numbers[lS] < numbers[rS] ? numbers[lS++] : numbers[rS++];
  }
  while (lS <= m)
  {
    help[id++] = numbers[lS++];
  }
  while (rS <= r)
  {
    help[id++] = numbers[rS++];
  }
  for (int i = 0; i < help.size(); ++i)
  {
    numbers[l + i] = help[i];
  }
  return smallSum;
}
