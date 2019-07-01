string LowestString(vector<string>& strs)
{
  if (strs.empty())
  {
    return string();
  }
  std::sort(strs.begin(), strs.end(), [](const string& lhs, const string& rhs) ->bool
      {
        return lhs + rhs < lhs + rhs;
      });
  string tmp;
  for (const string& str : strs)
  {
    tmp += str;
  }
  return tmp;
}
