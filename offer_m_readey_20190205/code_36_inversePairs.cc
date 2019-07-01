int InversePairs(vector<int>& arr)
{
  if (arr.size() < 2)
  {
    return 0;
  }
  vector<int> copy(arr.size());
  return Process(arr, copy, 0, arr.size() - 1);
}

int Process(vector<int>& arr, vector<int>& copy, int start, int end)
{
  if (start == end)
  {
    copy[start] = arr[end];
    return 0;
  }
  int len = (end - start) / 2;
  int leftPairs = Process(arr, copy, start, start + len);
  int rightPairs = Process(arr, copy, start + len + 1, end);
  int i = start + len;
  int j = end;
  int curPairs = 0;
  int copyId = end;
  while (i >= start && j >= start + len + 1)
  {
    if (arr[i] > arr[j])
    {
      curPairs += j - start - len;
      copy[copyId--] = arr[i--];
    }
    else
    {
      copy[copyId--] = arr[j--];
    }
  }
  while (i >= start)
  {
    copy[copyId--] = arr[i--];
  }
  while (j >= start -len - 1)
  {
    copy[copyId--] = arr[j--];
  }
  for (int i = start; i <= end; ++i)
  {
    arr[i] = copy[i];
  }
  return leftPairs + rightPairs + curPairs;
}
