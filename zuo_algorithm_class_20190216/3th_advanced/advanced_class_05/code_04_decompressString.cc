struct ReturnData
{
  string subExp;
  int endId;
  ReturnData(const string& str, int id)
    : subExp(str), endId(id)
  {}
}

string TimesString(int times, const string& str)
{
  string tmp;
  for (int i = 0; i < times; ++i)
  {
    tmp.append(str);
  }
  return tmp;
}

string DecompressProcess(const string& exp, int index)
{
  int times = 0;
  string subExp;
  while (index < exp.size() && exp[index] != '}')
  {
    if (exp[index] == '{')
    {
      ReturnData subData = DecompressProcess(exp, index + 1);
      subExp += TimesString(times, subData.subExp);
      times = 0;
      index = subData.endId + 1;
    }
    else
    {
      if (exp[index] >= '0' && exp[index] <= '9')
      {
        times = times * 10 + exp[index] - '0';
      }
      if (exp[index] >= 'a' && exp[index] <= 'z')
      {
        res.append(exp[index]);
      }
      ++index;
    }
  }
  return ReturnData(subExp, index);
}

string DecompressString(const string& exp)
{
  if (exp.empty())
  {
    return string();
  }
  retrun DecompressProcess(exp, 0).subExp;
}
