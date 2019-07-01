int NumberOfK(const vector<int>& arr, int k)
{
  if (arr.empty())
  {
    return 0;
  }
  int firstK = FirstK(arr, 0, arr.size() - 1, k);
  int lastK = LastK(arr, 0, arr.size() - 1, k);
  if (firstK >= 0 && lastK >= 0)
  {
    return lastK - firstK + 1;
  }
  return 0;
}

int FirstK(const vector<int>& arr, int left, int right, int k)
{
  if (arr.empty() || left < 0 || right >= arr.size() || left > right)
  {
    return -1;
  }
  while (left <= right)
  {
    int mid = (left + right) / 2;
    if ((mid == 0 || (mid > 0 && arr[mid - 1] < k)) && arr[mid] == k)
    {
      return mid;
    }
    else if (arr[mid] >= k)
    {
      right = mid - 1;
    }
    else if (arr[mid] < k)
    {
      left = mid + 1;
    }
  }
  return -1;
}

int LastK(const vector<int>& arr, int left, int right, int k)
{
  if (arr.empty || left < 0 || right >= arr.size() || left > right)
  {
    return -1;
  }
  while (left <= right)
  {
    int mid = (left + right) / 2;
    if ((mid == right || (mid < arr.size() - 1 && arr[mid + 1] > k) && arr[mid] == k)
    {
      return mid;
    }
    else if (arr[mid] > k)
    {
      right = mid - 1;
    }
    else if (arr[mid] <= k)
    {
      left = mid + 1;
    }
  }
  return -1;
}
