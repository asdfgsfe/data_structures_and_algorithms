int ReversePair(vector<int>& numbers)
{
  if (numbers.size() < 2)
  {
    return 0;
  }
  return ReverseProcess(numbers, 0, numbers.size() - 1);
}

int ReverseProcess(vector<int>& numbers, int l, int r)
{
  if (l == r)
  {
    return 0;
  }
  int m = (r + l) / 2;
  return ReverseProcess(numbers, l, m) + ReversePrcesss(numbers, m + 1, r) + Merge(numbersm l, m, r);
}

int Merge(vector<int>& numbers, int l, int m, int r)
{
  vector<int> help(r - l + 1);
  int lS = m;
  int rS = r;
  int reversePair = 0;
  int id = help.size();
  while (lS >= l && rS > m)
  {
    //统计方法有2种  如果左到右遍历 reversePair += (m - lS + 1) 这种不一定正确
    reversePair += numbers[lS] > numbers[rS] ? (rS - m) : 0;
    help[--id] = numbers[lS] > numbers[rS] ? numbers[rS--] : numbers[lS--];
  }
  while (lS >= l)
  {
    help[id--] = numbers[lS--];
  }
  while (rS > m)
  {
    help[id--] = numbers[rS--];
  }
  for (int i = 0; i < help.size(); ++i)
  {
    numbers[l + i] = help[i];
  }
  return reversePair;
}
