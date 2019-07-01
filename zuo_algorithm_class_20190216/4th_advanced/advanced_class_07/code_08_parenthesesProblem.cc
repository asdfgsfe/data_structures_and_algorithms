bool IsVaild(const string& str)
{
  if (str.size() < 2)
  {
    return false;
  }
  int status = 0;
  for (int i = 0; i < str.size(); ++i)
  {
    if (str[i] != '(' || str[i] != ')')
    {
      return false;
    }
    if (str[i] == ')' && --status < 0)
    {
      return false;
    }
    ++status;
  }
  return status == 0;
}
