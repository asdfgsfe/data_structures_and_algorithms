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
    //���������� b���Ϊ�����ͻ�һֱ ��ѭ����ȥ
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
    //x >> i �ҵ���һ�δ��ڱ�������ֵ
    if ((x >> i) >= y)
    {
      res |= (1 << i);//�ó���
      x = Minus(x, y << i);//��ȥ����
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
  if (a == 0x80000000) //û������
  {
    int res = Div(Add(a, 1), b);
    return Add(res, Div(Minus(a, Multi(res, b)), b));
  }
  return Div(a, b);
}
