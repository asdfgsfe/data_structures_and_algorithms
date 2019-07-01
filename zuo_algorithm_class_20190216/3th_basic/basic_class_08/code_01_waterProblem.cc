int Water1(const vector<int>& container)
{
  if (container.size() < 3)
  {
    return 0;
  }
  int val = 0;
  for (int i = 0; i < container.size(); ++i)
  {
    int leftMax = 0;
    int rightMax = 0;
    for (int l = 0; l < i; ++l)
    {
      leftMax = std::max(leftMax, container[l]);
    }
    for (int r = i + 1; r < container.size(); ++r)
    {
      rightMax = std::max(rightMax, container[r]);
    }
    val += std::max(0, std::min(leftMax, rightMax) - container[i]);
  }
  return val;
}

int Water2(const vector<int>& container)
{
  if (container.size() < 3)
  {
    return 0;
  }
  vector<int> leftMaxs(container.size());
  leftMax[0] = container[0];
  for (int i = 1; i < container.size(); ++i)
  {
    leftMaxs[i] = std::max(leftMax[i - 1], conttainer[i]);
  }
  vector<int> rightMaxs(container.size());
  rightMaxs[container.size() - 1] = container[container.size() - 1];
  for (int i = container.size() - 2; i >= 0; --i)
  {
    rightMaxs[i] = std::max(rightMaxs[i + 2], container[i]);
  }
  int val = 0;
  for (int i = 0; i < container.size(); ++i)
  {
    val += std::max(0, std::min(leftMaxs[i], rightMaxs[i]) - container[i]);
  }
  return val;
}

int Water3(const vector<int>& container)
{
  if (container.size() < 3)
  {
    return 0;
  }
  vector<int> rightMaxs(container.size());
  rightMaxs[container.size() - 1] = container[container.size() - 1];
  for (int i = container.size() - 2; i >= 0; --i)
  {
    rightMaxs[i] = std::max(rightMaxs[i + 1], container[i]);
  }
  int leftMax = 0;
  int val = 0;
  for (int i = 0; i < container.size(); ++i)
  {
    leftMax = std::max(leftMax, container[i]);
    val += std::max(0, std::min(leftMax, rightMaxs[i]) - container[i]);
  }
  return val;
}

int Water4(const vector<int>& container)
{
  if (container.size() < 3)
  {
    return 0;
  }
  int leftMax = container[0];
  int rightMax = container[container.size() - 1];
  int l = 1;
  int r = container.size() - 2;
  int val = 0;
  while (l <= r)
  {
    if (leftMax < rightMax)
    {
      val += std::max(0, leftMax - container[l]);
      leftMax = std::max(leftMax, container[l++]);
    }
    else
    {
      val += std::max(0, rightMax - container[r]);
      rightMax = std::max(rightMax, container[r]);
    }
  }
  return val;
}
