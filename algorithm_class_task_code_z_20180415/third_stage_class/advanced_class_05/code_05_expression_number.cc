#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

struct ReturnData
{
  int trueNums;
  int falseNums;

  ReturnData(int t, int f)
    : trueNums(t), falseNums(f)
  {}
};

bool IsVaild(const string& str)
{
  if ((str.size() & 1) == 0)
  {
    return false;
  }
  for (int i = 0; i < str.size(); i += 2)
  {
    if (str[i] != '0' && str[i] != '1')
    {
      return false;
    }
  }
  for (int i = 1; i < str.size(); i += 2)
  {
    if (str[i] != '&' && str[i] != '|' && str[i] != '^')
    {
      return false;
    }
  }
  return true;
}

ReturnData VaildNumber(const string& str, int l, int r)
{
  if (l == r)
  {
    if (str[l] == '1')
    {
      return ReturnData(1, 0);
    }
    else
    {
      return ReturnData(0, 1);
    }
  } 

  int trueNums = 0;
  int falseNums = 0;
  for (int i = l+1; i < r; i += 2)
  {
    ReturnData leftPartData = VaildNumber(str, l, i - 1);
    ReturnData rightPartData = VaildNumber(str, i + 1, r);
    int a = leftPartData.trueNums;
    int b = leftPartData.falseNums;
    int c = rightPartData.trueNums;
    int d = rightPartData.falseNums;
    if (str[i] == '&')
    {
      trueNums += a * c;
      falseNums += b * c + b * d + d * a;
    }
    else if (str[i] == '|')
    {
      trueNums += a * c + a * d + c * b;
      falseNums += b * d;
    }
    else
    {
      trueNums += a * d + b * c;
      falseNums += a * c + b * d;
    }
  }
  return ReturnData(trueNums, falseNums);
}

int Numbers1(const string& str, bool aim)
{
  if (str.empty())
  {
    return -1;
  }
  if (!IsVaild(str))
  {
    return -1;
  }
  ReturnData data = VaildNumber(str, 0, str.size() - 1);
  return aim ? data.trueNums : data.falseNums;
}

int Numbers2(const string& str, bool aim)
{
  if (str.empty())
  {
    return -1;
  }
  if (str.size() == 1)
  {
    if (str[0] == '1')
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  if (!IsVaild(str))
  {
    return -1;
  }
  //递归函数的返回结果有几个 就有几个dp矩阵 因为dp记录着所有的函数返回值
  vector<vector<int>> trueDp(str.size(), vector<int>(str.size()));
  vector<vector<int>> falseDp(str.size(), vector<int>(str.size()));
  for (int i = 0; i < str.size(); i += 2)
  {
    trueDp[i][i] = str[i] == '1' ? 1 : 0;
    falseDp[i][i] = str[i] == '0' ? 1 : 0;
  }
  //外环填dp的套路过程
  for (int l = str.size() - 3; l >= 0; l -= 2)
  {
    for (int r = l + 2; r < str.size(); r += 2)
    {
      int trueNums = 0;
      int falseNums = 0;
      //真实照搬递归函数的过程
      for (int split = l + 1; split < r; split += 2)
      {
        int a = trueDp[l][split-1];
        int b = falseDp[l][split-1];
        int c = trueDp[split+1][r];
        int d = falseDp[split+1][r];
        if (str[split] == '&')
        {
          trueNums += a * c;
          falseNums += a * d + b * c + b * d;
        }
        else if (str[split] == '|')
        {
          trueNums += a * c + a * d + b * c;
          falseNums += b * d;
        }
        else
        {
          trueNums += a * d + b * c;
          falseNums += a * c + b * d;
        }
      }
      trueDp[l][r] = trueNums;
      falseDp[l][r] = falseNums;
    }
  }
  return aim ? trueDp[0][str.size()-1] : falseDp[0][str.size()-1];
}

int Process(const string& express, int l, int r, bool desired)
{
  if (l == r)
  {
    if (express[l] == '1')
    {
      return desired ? 1 : 0;
    }
    else
    {
      return desired ? 0 : 1;
    }
  }

  int res = 0;
  if (desired)
  {
    for (int i = l + 1; i < r; i += 2)
    {
      switch (express[i])
      {
        case '&':
          res += Process(express, l, i - 1, true) * Process(express, i + 1, r, true);
          break;
        case '|':
          res += Process(express, l, i - 1, true) * Process(express, i + 1, r, false);
          res += Process(express, l, i - 1, true) * Process(express, i + 1, r, true);
          res += Process(express, l, i - 1, false) * Process(express, i + 1, r, true);
          break;
        case '^':
          res += Process(express, l, i - 1, true) * Process(express, i + 1, r, false);
          res += Process(express, l, i - 1, false) * Process(express, i + 1, r, true);
          break;
      }
    }
  }
  else
  {
    for (int i = l + 1; i < r; i += 2)
    {
      switch(express[i])
      {
        case '&':
          res += Process(express, l, i - 1, false) * Process(express, i + 1, r, true);
          res += Process(express, l, i - 1, false) * Process(express, i + 1, r, false);
          res += Process(express, l, i - 1, true) * Process(express, i + 1, r, false);
          break;
        case '|':
          res += Process(express, l, i - 1, false) * Process(express, i + 1, r, false);
          break;
        case '^':
          res += Process(express, l, i - 1, false) * Process(express, i + 1, r, false);
          res += Process(express, l, i - 1, true) * Process(express, i + 1, r, true);
          break;
      }
    }
  }
  return res;
}

//优化过的递归 依据自己期望值去组合
//第一个递归非优化的 选择出全部的 
int Numbers3(const string& express, bool desired)
{
  if (express.empty())
  {
    return -1;
  }
  if (!IsVaild(express))
  {
    return -1;
  }
  return Process(express, 0, express.size()-1, desired);
}

int Numbers4(const string& express, bool desired)
{
  if (express.empty())
  {
    return -1;
  }
  if (!IsVaild(express))
  {
    return -1;
  }

  vector<vector<int>> t(express.size(), vector<int>(express.size()));
  vector<vector<int>> f(express.size(), vector<int>(express.size()));
  t[0][0] = express[0] == '1' ? 1 : 0;
  f[0][0] = express[0] == '0' ? 1 : 0;
  
  //i->r j->l
  for (int i = 2; i < express.size(); i += 2)
  {
    t[i][i] = express[i] == '1' ? 1 : 0;
    f[i][i] = express[i] == '0' ? 1 : 0;
    for (int j = i - 2; j >= 0; j -= 2)
    {
      for (int k = j; k < i; k += 2)
      {
        if (express[k+1] == '&')
        {
          t[j][i] += t[j][k] * t[k+2][i];
          f[j][i] += (f[j][k] + t[j][k]) * f[k+2][i] + f[j][k] * t[k+2][i];
        }
        else if (express[k+1] == '|')
        {
          t[j][i] += (t[j][k] + f[j][k]) * t[k+2][i] + t[j][k] * f[k+2][i];
          f[j][i] += f[j][k] * f[k+2][i];
        }
        else
        {
          t[j][i] += t[j][k] * f[k+2][i] + f[j][k] * t[k+2][i];
          f[j][i] += t[j][k] * t[k+2][i] + f[j][k] * f[k+2][i];
        }
      }
    }
  }
  return desired ? t[0][express.size()-1] : f[0][express.size()-1];
}


int main(void)
{
  string express = "1^0&0|1&1^0&0^1|0|1&1";
  bool desired = true;
  std::cout << Numbers1(express, desired) << std::endl;
  std::cout << Numbers2(express, desired) << std::endl;
  std::cout << Numbers3(express, desired) << std::endl;
  std::cout << Numbers4(express, desired) << std::endl;

  return 0;
}


