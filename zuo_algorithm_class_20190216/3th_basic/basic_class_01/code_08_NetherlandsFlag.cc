array<int, 2> NetherlandFlag(vector<int>& flags, int l, int r, int p)
{
  if (flags.size() < 2)
  {
    return;
  }
  Partition(flags, l, r, p);
}

array<int> Partition(vector<int>& flags, int l, int r, int p)
{
  int less = l - 1;
  int more = r + 1;
  while (l < more)
  {
    if (flags[l] < p)
    {
      std::swap(flags[l++], flags[++less]);
    }
    else if (flags[l] > p)
    {
      std::swap(flags[l], flags[--more]);
    }
    else
    {
      ++l;
    }
  }
  return {less + 1, more - 1};
}
