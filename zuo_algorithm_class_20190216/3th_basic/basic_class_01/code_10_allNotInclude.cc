vector<int> AllNotInclude(const vector<int>& sorted, const vector<int>& unSorted)
{
  if (sorted.empty() || unSorted.empty())
  {
    return vector<int>();
  }
  vector<int> res;
  for (int i = 0; i < unSorted.size(); ++i)
  {
    int l = 0;
    int r = sorted.size() - 1;
    bool isContain = false;
    while (l <= r)
    {
      int mid = l + (r - l) >> 1;
      if (unSorted[i] < sorted[mid])
      {
        r = mid - 1;
      }
      else if (unSorted[i] > sorted[mid])
      {
        l = mid + 1;
      }
      else
      {
        isContain = true;
        break;
      }
    }
    if (!isContain)
    {
      res.push_back(unSorted[i]);
    }
  }
  return res;
}
