double RandomXPowerK(int k)
{
  if (k < 1)
  {
    return 0;
  }
  double res = 0;
  //跑k次选择最大的那个
  for (int i = 0; i < k; ++i)
  {
    res = std::max(res, Random());
  }
  return res;
}
