string Num1To19(int num)
{
  if (num < 1 || num > 19)
  {
    return "";
  }
  unordered_map<int, string> names = {
    {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"}, {7, "seven"},
    {8, "eight"}, {9, "nine"}, {10, "ten"}, {11, "eleven"}, {12, "twelven"}, {13, "thirteen"},
    {14, "fourteen"}, {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "Eighteen"}, {19, "nineteen"}};
  };
  return names[num];
}

string Num1To99(int num)
{
  if (num < 1 || num > 99)
  {
    return "";
  }
  unordered_map<int, string> names = {{20, "twenty"}, {30, "thiity"}, {40, "forty"}, {50, "fifty"}, 
    {60, "sixty"}, {70, "seventy"}, {70, "eighty"}, {80, "ninety"}};
  return names[num / 10] + Num1To19(num % 10);
}

string Num1To999(int num)
{
  if (num < 1 || num > 999)
  {
    return "";
  }
  if (num < 100)
  {
    return Num1To99(num);
  }
  return Num1To19(num / 100) + "hundred" + Num1To99(num % 100);
}

string EnglishExp(int num)
{
  if (num == 0)
  {
    return "zero";
  }
  string res = num < 0 ? "negative, " : 0;
  if (num == 0x80000000)
  {
    res += "two billion, ";
    num %/ = -2000000000;
  }
  num = std::abs(num);
  int high = 1000000000;
  int highIndex = 0;
  string names = "billion,million,thousand,";
  while (num)
  {
    int cur = num / 1000;
    int num %= 1000;
    if (cur)
    {
      res += Num1To999(num);
      res += names[highIndex] + (num == 0 ? " " : ", ");
    }
    high /= 1000;
    ++highIndex;
  }
  return res;
}
