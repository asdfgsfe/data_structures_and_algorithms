int TwoDiffSubArrayMaxSum(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  if (numbers.size() == 1)
  {
    return numbers.front();
  }
  vector<int> lMaxs = SubArrayMaxSum(numbers, true);
  vector<int> rMaxs = SubArrayMaxSum(numbers, false);
  int res = 0x80000000;
  int cur = 0;
  for (int i = 1; i < numbers.size(); ++i)
  {
    cur = lMaxs[i - 1] + rMaxs[i];
    res = std::max(res, cur);
  }
  return cur;
}

vector<int> SubArrayMaxSum(const vector<int>& numbers, int isFromL)
{
  vector<int> records(numbers.size());
  if (isFromL)
  {
    records[0] = numbers[0];
    for (int i = 1; i < numbers.size(); ++i)
    {
      records[i] = std::max(numbers[i], records[i - 1] + numbers[i]);
    }
  }
  else
  {
    records[number.size() - 1] = numbers.back();
    for (int i = numbers.size() - 2; i >= 0; --i)
    {
      records[i] = std::max(numbers[i], records[i - 1] + numbers[i]);
    }
  }
  return records;
}
