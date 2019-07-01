void RadixSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  int maxBit = MaxBitNum(a);
  for (int i = 0; i < maxBit; ++i)
  {
    queue<int> que[10];
    for (int j = 0; j < a.size(); ++j)
    {
      int num = a[j] / pow(10, i);//向右每次移动1位 10进制的向右移动1位
      que[num % 10].push(a[j]);
    }
    int index = 0;
    for (int k = 0; k < 10; ++k)
    {
      while (!que[k].empty())
      {
        a[index++] = que[k].front();
        que[k].pop();
      }
    }
  }
}

int MaxBitNum(vector<int>& a)
{
  int max = 0x80000000;
  for (int i = 0; i < a.size(); ++i)
  {
    max = std::max(a[i], max);
  }
  int res = 0;
  while (max)
  {
    ++res;
    max /= 10;
  }
  return res;
}
