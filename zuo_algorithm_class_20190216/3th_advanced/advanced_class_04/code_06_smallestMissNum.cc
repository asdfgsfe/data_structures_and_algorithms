//o(n)
//如果是负数就丢弃 总是让i位置的值为numbers[i] - 1
//利用i位置去排序 寻找0——n范围内的 如果小于或大于这个范围丢弃
int SmallestMissNum(vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  int l = 0;
  int r = numbers.size();
  while (l < r)
  {
    if (numbers[l] == l + 1) //已经在适当的位置 不需要调整 看下一个位置
    {
      ++l;
    }
    //numbers[l] < l || numbers[l] > r 表示查出范围
    //numbers[numbers[l] - 1] == numbers[l] 表示丢弃重复的值 l位置的值numbers[l] 与 numbers[l] - 1的值相等 重复
    //当前的值和他应该落到的位置的值相等
    else if (numbers[l] < l || numbers[l] > r || numbers[numbers[l] - 1] == numbers[l]) //超出范围丢弃
    {
      numbers[l] = numbers[--r];
    }
    else
    {
      std::swap(numners[l], numners[numbers[l] - 1]); //在范围内 让他落到属于自己位置
    }
  }
  return l + 1;
}
