string ShortedEnd(const string& str)
{
  if (str.empty())
  {
    return string();
  }
  string mStr = Manacherstring(str);
  vector<int> pArr(mStr.size());
  int r = -1;
  int c = -1;
  int maxContainEnd = 0;
  for (int i = 0; i < mStr.size(); ++i)
  {
    pArr[i] = r > i ? std::min(pArr[2 * c - i], r - i) : 1;
    while (i + pArr[i] < mStr.size() && i - pArr[i] >= 0)
    {
      if (mStr[i + pArr[i]] == mStr[i - pArr[i]])
      {
        ++pArr[i];
      }
      else
      {
        break;
      }
    }
    if (i + pArr[i] > r)
    {
      r = i + pArr[i];
      c = i;
    }
    if (r == mStr.size())
    {
      maxContainEnd = pArr[i];
      break;
    }
  }
  string res;
  for (int i = mStr.size() - 2 * maxContainEnd; i > 0; i -= 2)
  {
    res += mStr[i];
  }
  return res;
}
