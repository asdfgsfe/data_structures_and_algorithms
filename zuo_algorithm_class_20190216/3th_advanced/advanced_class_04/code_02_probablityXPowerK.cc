double RandomXPowerK(int k)
{
  if (k < 1)
  {
    return 0;
  }
  double res = 0;
  //��k��ѡ�������Ǹ�
  for (int i = 0; i < k; ++i)
  {
    res = std::max(res, Random());
  }
  return res;
}
