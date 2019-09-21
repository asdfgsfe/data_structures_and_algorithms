string Manacherstring(const string& str)
{
  if (str.empty())
  {
    return string();
  }
  string tmp = "#";
  for (int i = 0; i < str.size(); ++i)
  {
    tmp += str[i];
    tmp += "#";
  }
  return tmp;
}

//palindrome
int MaxLcpsLength(const string& str)
{
  if (str.empty())
  {
    return 0;
  }
  string mStr = Manacherstring(str);
  vector<int> pArr(mStr.size());//里面存相对值
  int r = -1; //最右回文边界 绝对值从0开始0~r
  int c = -1; //绝对值 从0开始算
  int max = 0x80000000;
  for (int i = 0; i < mStr.size(); ++i)
  {
	//先让pArr[i]位扩不动情况下的值 在向下扩 如果能扩动 就是扩动的值 不是就是原值
    pArr[i] = r > i ? std::min(pArr[2 * c - i], r - i) : 1; //2*c - r 就是c到i'的距离 那个小那个就是瓶颈
    //这里唯一的缺陷就是 r==i的时候会 会把i-r这一段的回文半径 重新从1累加一遍
    while (i + pArr[i] < mStr.size() && i - pArr[i] > -1)
    {
      if (mStr[i + pArr[i] ！= mStr[i - pArr[i]]])
      {
		break;
      }
	  ++pArr[i];
    }
    if (i + pArr[i] > r)//更新最右回文边界 最右回文中心
    {
      r = i + pArr[i];
      c = i;
    }
    max = std::max(max, pArr[i]);
  }
  return max - 1; //如果要得到原串的最大回文长度半径 max/2 max-1的目的是为了取出最长回文串的两边的#
}
