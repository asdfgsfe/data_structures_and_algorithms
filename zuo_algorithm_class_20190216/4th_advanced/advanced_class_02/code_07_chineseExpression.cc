//个
string Num1To9(int num)
{
  if (num < 1 || num > 9)
  {
    return "";
  }
  unordered_map<int, string> names = {
    {1, "一"}, {2, "二"}, {3, "三"}, {4, "四"}, {5, "五"}, {6, "六"}, {7, "七"}, {8, "八"}, {9, "九"}};
  return names[num];
}

//十
string Num1To99(int num, bool hasBai)
{
  if (num < 1 || num > 99)
  {
    return "";
  }
  if (num < 10)
  {
    return Num1To9(num);
  }
  int shi = num / 10;
  int rest = num % 10;
  if (shi == 1 && !hasBai)
  {
    return "十" + Num1To9(rest);
  }
  return Num1To9(shi) + "十" + Num1To9(rest);
}

//百
string Num1To999(int num)
{
  if (num < 1 || num > 999)
  {
    return "";
  }
  if (num < 100)
  {
    return Num1To99(num, false);
  }
  string res = Num1To9(num / 100) + "百";
  int rest = num % 100;
  if (rest == 0)
  {
    return res;
  }
  if (rest < 10)
  {
    return res + "零" + Num1To9(rest);
  }
  return res + Num1To99(rest, true);
}

//千
string Num1To9999(int num)
{
  if (num < 1 || num > 9999)
  {
    return "";
  }
  if (num < 1000)
  {
    return Num1To999(num);
  }
  int qian = num / 1000;
  int rest = num % 1000;
  string res = Num1To9(qian) + "千";
  if (rest == 0)
  {
    return res;
  }
  if (rest < 100)
  {
    return res + "零" + Num1To99(rest, false);
  }
  return res + Num1To999(rest);
}

//千万
string Num1To99999999(int num)
{
  if (num < 1 || num > 99999999)
  {
    return "";
  }
  int wan = num / 10000;
  int rest = num % 10000;
  if (wan == 0)
  {
    return Num1To9999(rest);
  }
  //万也分 个十百千
  string res = Num1To9999(wan) + "万";
  if (rest == 0)
  {
    return res;
  }
  if (rest < 1000)
  {
    return res + "零" + Num1To999(rest);
  }
  return res + Num1To9999(rest);
}


// xx亿xx千万xx百万xx十万xx万xx千xx百xx十
//亿
int ChineseExp(int num)
{
  if (num == 0)
  {
    return "零";
  }
  string res = num < 0 ? "负" : "";
  num = std::abs(num);
  int yi = num / 100000000;	//取最高位
  int rest = num % 100000000;	//取除去最高位的值
  if (yi == 0)
  {
    return res + Num1To99999999(rest);//千万
  }
  res += Num1To9999(yi) + "亿";//亿最多到千
  if (rest == 0)
  {
    return res;
  }
  if (rest < 10000000) //小于1千万 千万位为0
  {
    return res + "零" + Num1To99999999(rest);
  }
  return res + Num1To99999999(rest);
}
