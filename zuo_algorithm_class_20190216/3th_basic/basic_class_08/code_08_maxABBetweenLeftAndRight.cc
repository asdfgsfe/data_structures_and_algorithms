int MaxAB1(const vector<int>& arr)
{
  if (arr.size() < 2)
  {
    return 0x80000000;
  }
  int maxAB = 0x80000000;
  for (int k = 0; k < arr.size() - 1; ++k)
  {
    int leftMax = 0x800000000;
    for (int i = 0; i <= k; ++i)
    {
      leftMax = std::max(leftMax, arr[i]);
    }
    int rightMax = 0x80000000;
    for (int i = k + 1; i < arr.size(); ++i)
    {
      rightMax = std::max(rightMax, arr[i]);
    }
    maxAB = std::max(maxAB, leftMax - rightMax);
  }
  return maxAB;
}

int MaxAB2(const vector<int>& arr)
{
  if (arr.size() < 2)
  {
    return 0x80000000;
  }
  vector<int> leftMaxs(arr.size());
  leftMaxs[0] = arr[0];
  for (int i = 1; i < arr.size(); ++i)
  {
    leftMaxs[i] = std::max(leftMaxs[i - 1], arr[i]);
  }
  vector<int> rightMaxs(arr.size());
  rightMax[arr.size() - 1] = arr[arr.size() - 1];
  for (int i = arr.size() - 2; i >= 0; --i)
  {
    rightMaxs[i] = std::max(rightMaxs[i + 1], arr[i]);
  }
  int maxAB = 0x80000000;
  for (int k = 0; k < arr.size() - 1; ++k)
  {
    maxAB = std::max(maxAB, std::abs(leftMaxs[k] - rightMaxs[k + 1]));
  }
  return maxAB;
}

int MaxAB3(const vector<int>& arr)
{
  if (arr.size() < 2)
  {
    return 0x80000000;
  }
  vector<int> rightMaxs(arr.size());
  rightMax[arr.size() - 1] = arr[arr.size() - 1];
  for (int i = arr.size() - 2; i >= 0; --i)
  {
    rightMaxs[i] = std::max(rightMaxs[i + 1], arr[i]);
  }
  int maxAB = 0x80000000;
  int leftMax = arr[0];
  for (int k = 0; k < arr.size() - 1; ++k)
  {
    maxAB = std::max(maxAB, std::abs(leftMax - rightMaxs[k + 1]));
  }
  return maxAB;
}

int MaxAB4(const vector<int>& arr)
{
  if (arr.size() < 2)
  {
    return 0x80000000;
  }
  int max = arr[0];
  for (int i = 1; i < arr.size(); ++i)
  {
    max = max < arr[i] ? arr[i] : max;
  }
  //从左到右的过程均选择最大值
  //因此每一个选中的值都肯定不比arr[0]小，也不比最后一个值小
  //而左边第一个和右边第一个值无依赖可以很好的分开
  //因为他们一个可以成为一个部分， 因此选择二者中的较小者划分 就是答案
  return max - std::min(arr[0], arr[arr.size() - 1]);
}
