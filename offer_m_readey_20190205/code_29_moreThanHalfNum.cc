bool g_InvaildInput = false;
int MoreThanHalfNum1(vector<int>& numbers)
{
  g_InvaildInput = false;
  if (numbers.empty())
  {
    g_InvaildInput = true;
    return 0;
  }
  int start = 0;
  int end = numbers.size() - 1;
  int mind = numbers.size() >> 1;
  int index = RandomPartition(numbers, start, end);
  while (index != mid)
  {
    if (index < mid)
    {
      start = index + 1;
      index = RandomPartition(numbers, start, end);
    }
    else
    {
      end = index - 1;
      index = RandomPartition(numbers, start, end);
    }
  }
  if (!IsRealMoreThanHalfNum(numbers, mid))
  {
    g_InvaildInput = true;
    return 0;
  }
  return numbers[mid];
}

int RandomPartition(vector<int>& numbes, int start, int end)
{
  if (numbers.empty() || start < 0 || end >= numbers.size())
  {
    return -1;
  }
  int index = SelectRadomId(start, end);
  std::swap(numbers[end], numbers[index]);
  int left = start;
  int right = end - 1;
  while (1)
  {
    while (left < end && numbers[left++] < numbers[end]) {}
    while (right > start && numbers[right--] > numbers[end]) {}
    if (left >= right)
    {
      break;
    }
    std::swap(numbers[left], numners[right]);
  }
  return index;
}

int MoreThanHalfNum(const vector<int>& numbers)
{
  g_InvaildInput = false;
  if (numbes.empty())
  {
    g_InvaildInput = true;
    return 0;
  }
  int result = numbers[0];
  int times = 1;
  for (int i = 1; i< numbers.size(); ++i)
  {
    if (times == 0)
    {
      result = numbers[i];
      times = 1;
    }
    if (numbers[i] == result)
    {
      ++times;
    }
    else
    {
      --times;
    }
  }
  if (!IsRealMoreThanHalfNum(numbers))
  {
    g_InvaildInput = true;
    return 0;
  }
  return result;
}
