int MinNumberInRotatedArray(const vector<int>& arr)
{
  if (arr.empty())
  {
    return 0;
  }
  int left = 0;
  int right = arr.size() - 1;
  int mid = left;
  while (arr[left] >= arr[right])
  {
    if (right - left == 1)
    {
      mid = right;
      break;
    }
    mid = (left + right) / 2;
    if (arr[left] == arr[mid] && arr[mid] == arr[right])
    {
      for (int i = left; i <= right; ++i)
      {
        mid = arr[i] < arr[mid] ? i : mid;
        break;
      }
    }
    if (arr[mid] >= arr[left])
    {
      left = mid;
    }
    else if (arr[mid] <= arr[right])
    {
      right = mid;
    }
  }
  return arr[mid];
}
