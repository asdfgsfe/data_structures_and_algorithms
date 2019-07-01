void InsertSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  for (int p = 1; p < a.size(); ++p)
  {
    for (int j = p; j > 0 && a[j - 1] > a[j]; --j)
    {
      std::swap(a[j], a[j - 1]);
    }
  }
}
