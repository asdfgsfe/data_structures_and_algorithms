//滑动窗口最大值模型 用队列模型记录当前窗口的最大值与最小智
int AllLessNumSubArray(const vector<int>& numbers, int num)
{
  if (numbers.empty())
  {
    return 0;
  }
  deque<int> minNum;
  deque<int> maxNum;
  int i = 0;
  int j = 0;
  int res = 0;
  while (i < numbers.size())
  {
    while (j < numbers.size())
    {
      while (!minNum.empty() && numbers[minNum.front()] >= numbers[j])
      {
        minNum.pop_back()
      }
      minNum.push_back(j);
      while (!maxNum.empty() && numbers[maxNum.front()] <= numbers[j])
      {
        maxNum.pop_back();
      }
      maxNum.push_back(j);
      //如果一个子数组不达标 他扩出来的范围一定不达标 不管他向那个方向扩
      //max - min > num 扩max会变大 min会变小
      if (numbers[maxNum.front()] - numbers[minNum.front()] > num)
      {
        break;
      }
      ++j
    }
    if (minNum.front() == i) //跳出break i要向下移动 i已经无用 所以弹出
    {
      minNum.pop_front();
    }
    if (maxNum.front() == i)
    {
      maxNum.pop_front();
    }
    //一个子数组如果他达标 它内部的子数组一定达标 max - min <= num
    //由于数据缩小max只能减小或者不变 min只能增大或者不变
    res += j - i;
    ++i
  }
  return res;
}
