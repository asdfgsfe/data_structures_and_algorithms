vector<int> MaxInWindows(const vector<int>& numbers, int k)
{
  if (numners.empty() || k < 1)
  {
    return vector<int>();
  }
  deque<int> window;
  for (int i = 0; i < k; ++i)
  {
    while (!window.empty() && numbers[window.back()] <= numbers[i])
    {
      window.pop_back();
    }
    window.push_back(i);
  }
  vector<int> max;
  for (int i = k; i < numbers.size(); ++i)
  {
    max.push_back(numbers[window.front()]);
    while (!window.empty() && numbers[window.back()] <= numbers[i])
    {
      window.pop_back();
    }
    if (!window.empty() && i - window.front() >= k)
    {
      window.pop_front();
    }
    window.push_back(i);
  }
  assert(!window.empty());
  max.push_back(numbers[window.front()]);
  return max;
}
