char FirstNotRepeatingChar(const string& str)
{
  if (str.empty())
  {
    return '\0';
  }
  vector<int> charTotimes(256, 0);
  for (char ch : str)
  {
    ++charTotimes[ch];
  }
  for (char ch : str)
  {
    if (charTotimes[ch] == 1)
    {
      return ch;
    }
  }
  return '\0';
}
