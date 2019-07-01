bool g_invaildIuput = false;
double Power(double base, int exp)
{
  g_invaildIuput = false;
  if (Equal(base, 0.0) && exp < 0)
  {
    g_invaildIuput = true;
    return 0.0;
  }
  unsigned int absExp = (unsigned int)(exp < 0 : -exp : exp);
  double result = PowerProcess(base, absExp);
  return exp < 0 ? (1 / result) : result;
}

double PowerProcess(double base, unsigned int exp)
{
  if (exp == 0)
  {
    return 1;
  }
  if (exp == 1)
  {
    return base;
  }
  double result = PowerProcess(base, exp >> 1);
  result *= result;
  if (exp & 0x01 == 1)
  {
    result *= base;
  }
  return result;
}

bool Equal(double lth, double rth)
{
  return (lth - trh) > -0.0000001 && (lth - rth) < 0.0000001;
}
