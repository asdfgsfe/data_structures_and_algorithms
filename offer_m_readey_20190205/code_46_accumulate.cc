class Temp
{
public:
  Temp()
  {
    ++n;
    sum += n;
  }

  static void Reset()
  {
    n = 0;
    sum = 0;
  }

  static unsigned int Sum () const
  {
    return sum;
  }

private:
  static unsigned int sum;
  static unsigned int n; 
};

unsigned int Temp::sum = 0;
unsigned int Temp::n = 0;

unsigned int Accumulate(unsigned int n)
{
  Temp::Reset();
  Temp* pTemp= new Temp[n];
  delete []pTemp;
  pTemp = nullptr;
  return Temp::Sum();
}

class A;
A* arr[2];

class A
{
public:
  virtual unsigned int Sum(unsigned int n) const
  {
    return 0;
  }
  virtual ~A(){}
};

class B : public A
{
public:
  virtual unsigned int Sum(unsigned int n) const
  {
    return arr[!!n]->Sum(n - 1) + n;
  }
};

unsigned int Accumulate2(unsigned int n)
{
  A a;
  B b;
  arr[0] = &a;
  arr[1] = &b;
  return arr[1]->Sum(n);
}

unsigned int Func1(unsigned int n)
{
  return 0;
}

unsigned int Func2(unsigned int n)
{
  return funcs[!!n](n -1) + n;
}

typedef unsigned int (*Func)(unsigned int);
static funcs[2] = {Func1, Func2};

unsigned int Accumulate3(unsigned int n)
{
  return funcs[1](n);
}
