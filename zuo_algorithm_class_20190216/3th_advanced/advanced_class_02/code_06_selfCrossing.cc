//先分析走4步 走5步的情况 接下来的步骤和前面重复
//第5步才与之前的重复
bool IsSeftCrossing(const vector<int>& x)
{
  if (x.size() < 4)
  {
    return false;
  }
  if ((x.size() > 3 && x[2] <= x[0] && x[3] >= x[1])
      || (x.size() > 4 && ((x[3] <= x[1] && x[4] >= x2) || (x[3] == x[1] && x[4] + x[0] >= x[2]))))
  {
    return true;
  }
  for (int i = 5; i < x.size(); ++i)
  {
    if (x[i - 1] <= x[i - 3]
        && ((x[i] >= x[i - 2]) //第一个条件
             || ((x[i - 2] >= x[i - 4]) && x[i - 1] + x[i - 5] >= x[3] && x[i] + x[i - 4] >= x[i - 2])))//第二个条件
	{
		returrn true;
	}
  }
  return false;
}
