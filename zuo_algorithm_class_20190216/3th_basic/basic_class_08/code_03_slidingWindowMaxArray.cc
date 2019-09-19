vector<int> SlidingWindowMaxArray(const vector<int>& arr, int w)
{
  if (arr.empty() || w < 1 || arr.size() < w)
  {
    return vector<int>();
  }
  queue<int> window;
  for (int i = 0; i < w; ++i)
  {
    while (!window.empty() && arr[window.back] <= arr[i])
    {
      window.pop_back();
    }
    window.push_back(i);
  }
  vector<int> maxArray;
  for (int i = w; i < arr.size(); ++i)
  {
    maxArray.push_back(arr[window.front]);
    while (!window.empty() && arr[window.back()] <= arr[i])
    {
      window.push_back(i);
    }
    if (!window.empty() && i - window.front() > w)
    {
      window.pop_front();
    }
    window.push_back(i);
  }
  maxArray.push_back(arr[window.front()]);
  return maxArray;
}

vector<int> SlidingWindowMaxArray2(const vector<int>& arr, int w)
{
  if (arr.empty() || w < 1 || arr.size() < w)
  {
    return vector<int>();
  }
  queue<int> window;
  vector<int> maxValue(arr.size() - w + 1);
  int index = 0;
  for (int i = 0; i < arr.size(); ++i)
  {
    while (!window.empty() && arr[window.back() <= arr[i]])
    {
      window.pop_back();
    }
    if (!window.empty() && i - window.front() >= w) //这里大于还是大于等于 需要测试下
    {
      window.pop_front();
    }
    window.push_back(i);
    if (i >= w - 1)
    {
      maxValue[index++] = arr[window.front()];
    }
  }
  return maxValue;
}
