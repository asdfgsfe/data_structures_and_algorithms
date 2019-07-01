vector<int> TwoNumberWithSum(const vector<int>& numbes, int sum)
{
  int small = 0;
  int big = numbers.size() - 1;
  vector<int> result(3, 0);
  while (small < big)
  {
    int curSum = numbers[small] + numbers[big];
    if (curSum == sum)
    {
      result[0] = 1;
      result[1] = numbers[small];
      result[2] = numbers[big];
      return result;
    }
    else if (curSum > sum)
    {
      --big;
    }
    else
    {
      ++small;
    }
  }
  return result;
}

vector<vector<int>> SubArrayWithSum(const vector<int>& numbers, int sum)
{
  int curSum = 0;
  int small = 0;
  int big = 0;
  vector<vector<int>> result;
  while (small < numbers.size() && big < numbers.size())
  {
    curSum += numbers[big];
    if (sumSum < sum)
    {
      ++big;
    }
    else if (curSum > sum)
    {
      curSum -= numbers[small];
      ++small;
    }
    else
    {
      vector<int> subArray(3, 0);
      subArray[0] = 1;
      subArray[1] = small;
      subArray[2] = big;
      result.push_back(subArray);
    }
  }
  return result;
}
