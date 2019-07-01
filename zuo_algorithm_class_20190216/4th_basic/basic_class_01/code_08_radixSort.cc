void RadixSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  int maxBit = MaxBit(a);
  for (int i = 0; i < maxBit; ++i)
  {
    queue<int> buckets[10];
    for (int number : a)
    {
      int num = number / pow(10, i);
      buckets[num % 10].push(number);
    }
    int id = 0;
    for (int k = 0; k < 10; ++k)
    {
      while (!buckets[k].empty())
      {
        a[id++] = buckets[k].front();
        buckets[k].pop()
      }
    }
  }
}

int MaxBit(vector<int>& a)
{
  int max = a[0];
  for (int number : a)
  {
    max = number > max ? number : max;
  }
  int bit = 0;
  for (max)
  {
    ++bit;
    max /= 10;
  }
  return bit;
}
