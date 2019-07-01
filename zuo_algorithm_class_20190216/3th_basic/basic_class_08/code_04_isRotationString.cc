vector<int> NextArray(const string& s)
{
  if (s.empty())
  {
    return vector<int>();
  }
  if (s.size() == 1)
  {
    return vector<int>(1, -1);
  }
  vector<int> nexts(s.size());
  nexts[0] = -1;
  nexts[1] = 0;
  int pos = 2;
  int cn = 0;
  while (pos < next.size())
  {
    if (s[pos - 1] == s[cn])
    {
      nexts[pos++] = ++cn;
    }
    else if (cn > 0)
    {
      cn = nexts[cn];
    }
    else
    {
      nexts[pos++] = 0;
    }
  }
  return nexts;
}

int GetIndexOf(const string& s1, const string& s2)
{
  if (s1.size() < s2.size())
  {
    return -1;
  }
  vector<int> nexts = NextArray(s2);
  int i1 = 0;
  int i2 = 0;
  while (i1 < s1.size() && i2 < s2.size())
  {
    if (s1[i1] == s2[i2])
    {
      ++i1;
      ++i2;
    }
    else if (next[i2] != -1)
    {
      i2 = next[i2];
    }
    else
    {
      ++i1;
    }
  }
  return i2 == s2.size() ? i1 - i2 : -1;
}

bool IsRatationString(const string& s1, const string& s2)
{
  if (s1.empty() || s2.empty() || s1.size() != s2.size())
  {
    return false;
  }
  string tmp = s2 + s2;
  return GetIndexOf(tmp, s1) != -1;
}
