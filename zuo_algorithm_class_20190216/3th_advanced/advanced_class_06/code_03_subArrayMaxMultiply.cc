#include <iostream>
#include <vector>

using std::vector;

struct ReturnData
{
  double min;
  double max;
  double gMax;
  ReturnData(double i, double a, double g)
    : min(i), max(a), gMax(g)
  {}
};

ReturnData MultiplyProcess(const vector<double>& numbers, int i)
{
  if (i == 0)
  {
    return ReturnData(numbers[0], numbers[0], numbers[0]);
  }
  ReturnData data = MultiplyProcess(numbers, i - 1);
  double max = std::max(data.min * numbers[i], data.max * numbers[i]);
  double min = std::min(data.min * numbers[i], data.max * numbers[i]);
  max = numbers[i] > max ? numbers[i] : max;
  min = numbers[i] < min ? numbers[i] : min;
  return ReturnData(min, max, std::max(max, data.gMax));
}

double SubArrayMaxMultiply(const vector<double>& numbers)
{
  if (numbers.empty())
  {
    return 0.0;
  }
  return MultiplyProcess(numbers, numbers.size() - 1).gMax;
}

int SubArrayMaxMultiply2(const vector<double>& numbers)
{
  if (numbers.empty())
  {
    return 0.0;
  }
  double res = numbers[0];
  double min = numbers[0];
  double max = numbers[0];
  double curMax = 0;
  double curMin = 0;
  for (int i = 1; i < numbers.size(); ++i)
  {
    curMax = std::max(numbers[i], std::max(max * numbers[i], min * numbers[i]));
    curMin = std::min(numbers[i], std::min(max * numbers[i], min * numbers[i]));
    res = std::max(res , curMax);
    max = curMax;
    min = curMin;
  }
  return res;
}


//¾ØÕóÑ¹Ëõ¼¼Êõ
double SubArrayMaxMultiDp2(const vector<double>& numbers)
{
	if (numbers.empty())
	{
		return 0.0;
	}
	double maxMulti = numbers[0];
	double curMin = numbers[0];
	double curMax = numbers[0];
	for (int i = 1; i < numbers.size(); ++i)
	{
		curMin = std::min(numbers[i], std::min(numbers[i] * curMin, numbers[i] * curMax));
		curMax = std::max(numbers[i], std::max(numbers[i] * curMin, numbers[i] * curMax));
		maxMulti = std::max(maxMulti, curMax);
	}
	return maxMulti;
}

int main(void)
{
  vector<double> test = {-2.5, 4, 0, 3, 0.5, 8, -1};
  std::cout << SubArrayMaxMultiply(test) << std::endl;
  std::cout << SubArrayMaxMultiply2(test) << std::endl;

  return 0;
}
