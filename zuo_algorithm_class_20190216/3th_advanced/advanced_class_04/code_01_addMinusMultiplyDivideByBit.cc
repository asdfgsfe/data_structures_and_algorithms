int Add1(int a, int b)
{
  int sum = a;
  while (b != 0)
  {
    sum = a ^ b;
    b = (a & b) << 1;
    a = sum;
  }
  return sum;
}

int Add2(int a, int b)
{
  int sum = 0;
  int carray = 0;
  while (b != 0)
  {
    sum = a ^ b;
    carray = (a & b) << 1;
    a = sum;
    b = carray;
  }
  return a;
}

int NgeNum(int n)
{
  return Add1(~n, 1);
}

int Minus(int a, int b)
{
  return Add1(a, NegNum(b));
}

//error
int Multi(int a, int b)
{
    //这里有问题 b如果为负数就会一直 死循环下去
  int res = 0;
  while (b)
  { 
    if (b & 0x01)
    { 
      res = Add(res, a);
    } 
    a <<= 1;
    b >>= 1;
  }
  return res;
}

int Div(int a, int b)
{
  int x = a < 0 ? NegNum(a) : a;
  int y = b < 0 ? NegNum(b) : b;
  int res = 0;
  for (int i = 31; i >= 0; i = Minus(i, 1))
  {
    //x >> i 找到第一次大于被除数的值
    if ((x >> i) >= y)
    {
      res |= (1 << i);//拿出商
      x = Minus(x, y << i);//减去除数
    }
  }
  return (a < 0) ^ (b < 0) ? NegNum(res) : res;
}

int Divide(int a, int b)
{
  if (b == 0)
  {
    return 0x7ffffff;
  }
  if (a == 0x80000000 && b == 0x80000000)
  {
    return 1;
  }
  if (b == 0x80000000)
  {
    return 0;
  }
  if (a == 0x80000000) //没想明白
  {
    int res = Div(Add(a, 1), b);
    return Add(res, Div(Minus(a, Multi(res, b)), b));
  }
  return Div(a, b);
}
