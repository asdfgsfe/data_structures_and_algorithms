//can stable
void BubbleSort(vector<int>& arr)
{
  if (arr.size() < 2)
  {
    return;
  }
  for (int i = arr.size() - 1; i > 0; --i)
  {
    for (int j = 0; j < i; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}
