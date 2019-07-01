void SelectSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  for (int i = 0; i < a.size(); ++i)
  {
    int minIndex = i;
    for (int j = i + 1; j < a.size(); ++j)
    {
      if (a[j] < a[minIndex])
      {
        minIndex = j;
      }
    }
    std::swap(a[minIndex, a[i]]);
  }
}
