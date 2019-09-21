//can stable
void InsertSort1(vector<int>& arr)
{
  if (arr.size() < 2)
  {
    return;
  }
  for (int p = 1; p < arr.size(); ++p)
  {
    for (int i = p; i > 0 && arr[i - 1] > arr[i]; --i)
    {
      std::swap(arr[i - 1], arr[i]);
    }
  }
}

void InsertSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  for (int p = 1; p < a.size(); ++p)
  {
    int tmp = a[p];
    for (int i = p; i > 0 && a[i - 1] > a[i]; --i)
    {
      a[i] = [i - 1];
    }
    a[i] = tmp;
  }
}
