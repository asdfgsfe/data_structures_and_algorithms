void ShellSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  for (int s = a.size() / 2; s > 0; s /= 2)
  {
    for (int p = s; p < a.size(); ++p)
    {
      for (int j = p; j >= s && a[j - s] > a[j]; j -= s)
      {
        std::swap(a[j], a[j - s]);
      }
    }
  }
}
