bool g_vaildInput = false;
int SubArrayMaxSum(const vector<int>& numbers)
{
  g_vaildInput = false;
  if (numbers.empty)
  {
    g_vaildInput = true;
    return 0;
  }
  int maxSum = numbers[0];
  int curSum = numbers[0];
  for (int i = 1; i < numbers.size(); ++i)
  {
    if (curSum <= 0)
    {
      curSum = numbers[0]; 
    }
    else
    {
      curSum += numbers[0];
    }
    maxSum = curSum > maxSum ? curSum : maxSum;
  }
  return maxSum;
}