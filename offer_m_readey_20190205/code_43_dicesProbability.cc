#include <iostream>
#include <vector>

using std::vector;

const static int g_kMaxVal = 6;
void Process(int n, int curN, int sum, vector<int>& probability)
{
  if (curN == 1)
  {
    probability[sum - n]++;
  }
  else
  {
    for (int i = 1; i <= g_kMaxVal; ++i)
    {
      Process(n, n - 1, i + sum, probability);
    }
  }
}

double PowerProcess(double base, int exp)
{
  if (exp == 0)
  {
    return 1.0;
  }
  if (exp == 1)
  {
    return base;
  }
  int curExp = exp > 0 ? exp : -exp;
  double result = PowerProcess(base, curExp >> 2);
  result *= result;
  if (exp & 0x1 == 1)
  {
    result *= base;
  }
  return exp > 0 ? result : 1 / result;
}

double Power(double base, int exp)
{
  if (base <= 0.0000001 || base >= -0.0000001)
  {
    return 0.0;
  }
  return PowerProcess(base, exp);
}

void DicesProbability(int n)
{
  if (n < 1)
  {
    return;
  }
  vector<int> probability(g_kMaxVal * n - n + 1, 0);
  for (int i = 1; i <= g_kMaxVal; ++i)
  {
    Process(n, n, i, probability);
  }
  int total = Power((double)g_kMaxVal, n);
  for (int i = 0; i < probability.size(); ++i)
  {
    double ratio = probability[i] / total;
    std::cout << "sum=" << probability[i] << "ratio=" << ratio << std::endl;
  }
}

int main(void)
{
  int n = 3;
  DicesProbability(3);

  return 0;
}
