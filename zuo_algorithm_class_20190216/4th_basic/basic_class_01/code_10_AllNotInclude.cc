vector<int> AllNotInclude(const vector<int>& sorted, const vector<int>& unsorted)
{
  if (sorted.empty() || unsorted.empty())
  {
    return vector<int>();
  }
  for (int numbers : unsorted)
  {
    int l = 0;
    int r = sorted.size() - 1;
    bool isContain = false;
    while (l <= r)
    {
      int m = (l + r) / 2;
      if (sorted[m] == numbers)
      {
        isContain = true;
        break;
      }
      else if (sorted[m] < numbers)
      {
        l = m + 1;
      }
      else
      {
        r = m - 1;
      }
    }
    if (!isContain)
    {
      res.push_back(numbers);
    }
  }
  return res;
}
