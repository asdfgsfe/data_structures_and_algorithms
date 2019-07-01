#include <iostream>

int MaxBit(int n)
{
  int count = 1;
  while (n > 10)
  {
    count *= 10;
    n /= 10;
  }
  return count;
}

bool IsPalindromeNumber(int number)
{
  int maxBit = MaxBit(number);
  while (number)
  {
    int r = number % 10;
    int l = number / maxBit;
    if (r != l)
    {
      return false;
    }
    number %= maxBit;
    number /= 10;
    maxBit /= 100;
  }
  return true;
}

bool IsPalindrome(int number)
{
  int help = 1;
  while (number / 10 > 0)
  {
    help *= 10;
  }
  while (number)
  {
    if (number % 10 != number / help)
    {
      return false;
    }
    number = (number % help) / 10;
    help /= 100;
  }
  return true;
}

bool IsPalindromeNumber3(int number)
{
	number = number < 0 ? -number : number;
	vector<char> charToNum = {'0', '1', '2', '3', '4', '5', '6', '7', '8'. '9'};
	string sNum;
	while (number)
	{
		sNum += charToNum[number % 10];
		number /= 10;
	}
	int l = 0;
	int r = sNum.size() - 1;
	while (l < r)
	{
		if (sNum[l] != sNum[r])
		{
			return false;
		}
		++l;
		++r;
	}
	return true;
}

int main(void)
{
  std::cout << IsPalindromeNumber(12321) << std::endl;
  std::cout << IsPalindromeNumber(12331) << std::endl;
  std::cout << IsPalindromeNumber3(12331) << std::endl;
  return 0;
}
