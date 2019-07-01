//n/10去掉的是最后以为 结果是前几位
//n%10去掉的是前几位 结果是最后以为
bool IsPaildromeNumber(int number)
{
  if (number < 0)
  {
    return false;
  }
  int help = 1;
  while (n / help > 10)
  {
    help *= 10;
  }
  while (n)
  {
    //n/help第一位 n%10最后一位
    if (n / help != n % 10)
    {
      return false;
    }
    n = (n % help) / 10;
    help /= 100;
  }
  return true;
}
