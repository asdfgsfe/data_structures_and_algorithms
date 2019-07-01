int Add(int n1, int n2)
{
  int sum = 0;
  int carray = 0;
  do
  {
    sum = n1 ^ n2;
    carray = (n1 & n2) << 1;
    n1 = sum;
    n2 = carray;
  }
  while (n2 != 0);
  return n1;
}
