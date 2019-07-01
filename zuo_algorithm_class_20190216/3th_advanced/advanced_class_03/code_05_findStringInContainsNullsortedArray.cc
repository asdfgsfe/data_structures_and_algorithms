int GetIndexOfSortedArray(const vector<int>& strs, const string& str)
{
  if (strs.empty())
  {
    return -1;
  }
  int l = 0;
  int r = strs.size() - 1;
  int res = -1;
  while (l <= r)
  {
    int mid = (l + r) / 2;
    if (strs[mid] != "null" && strs[mid] == str)
    {
      res = mid;
      r = mid - 1;
    }
    else if (strs[mid] != "null")
    {
      if (strs[mid] > str)
      {
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    else
    {
      int i = mid;
      while (strs[i] == "null" && --i >= l) {}
      if (i < l || strs[i] < str)//当前位置的值小于要找的值向右移动
      {
        l = mid + 1; 
      }
      else
      {
        res = strs[i] == str ? i : res;
        r = i - 1;
      }
    }
  }
  return res;
}
