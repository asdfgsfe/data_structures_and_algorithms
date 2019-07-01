array<int, 2> NetherlandsFlag(vector<int>& flags, int l, int r, int p)
{
  if (flags.size() < 2)
  {
    return array<int, 2>();
  }
  return Partition(flags, l, r, p);
}

array<int, 2> Partition(vector<int>& flags, int l, int r, int p)
{
  int less = l - 1;
  int more = r + 1;
  while (l < more)
  {
    if (a[l] < p)
    {
      std::swap(a[l++], a[++less]);
    }
    else if (a[l] > p)
    {
      std::swap(a[l], a[--more]);
    }
    else
    {
      ++l;
    }
  }
  return {less + 1, more - 1};
}
