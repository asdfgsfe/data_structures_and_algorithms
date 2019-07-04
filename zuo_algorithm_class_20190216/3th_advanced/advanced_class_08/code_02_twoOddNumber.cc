vector<int> TwoOddNumber(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return vector<int>();
  }
  int e0 = 0;
  for (int number : numbers)
  {
    e0 ^= number;
  }
  int e1 = (~e0 + 1); //取反+1表示左边第一个1
  int e2 = 0;
  for (int number : numbers)
  {
    if (number & e1 == 1)
    {
      e2 ^= number;
    }
  }
  e1 = e2 ^ e0;
  return {e1, e2};
}
