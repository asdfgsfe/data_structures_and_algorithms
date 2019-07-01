struct ReturnData
{
  int trueNunm;
  int falseNum;
  ReturnData(int t, int f)
    : trueNum(t), falseNum(f)
  {}
  ReturnData() {}
};

int ExpressionNumber(const string& exp, bool desired)
{
  if (exp.empty())
  {
    return 0;
  }
  if (!IsVaild(exp))
  {
    return 0;
  }
  ReturnData data = SelectProcess(exp, 0, exp.size() - 1);
  return desried ? data.trueNum : falseNum;
}

bool IsVaild(const string& exp)
{
  if (exp.size() & 1 == 0)
  {
    return false;
  }
  for (int i = 0; i < exp.size(); ++i)
  {
    if ((i & 1 == 0) && (exp[i] != '0' || exp[i] != '1'))
    {
      return false;
    }
    if ((i & 1 == 1) && (exp[i] != '&' || exp[i] != '|' || exp[i] != '^'))
    {
      return false;
    }
  }
  return true;
}

ReturnData SelectProcess(const string& exp, int l, int r)
{
  if (l == r)
  {
    return exp[l] == '1' ? ReturnData(1, 0) : ReturnData(0, 1);
  }
  int tNum = 0;
  int fNum = 0;
  for (int split = l + 1; split < r; slit += 2)
  {
    ReturnData lData = SelectProcess(exp, l, split - 1);
    ReturnData rData = SelectProcess(exp, split + 1, r);
    int a = lData.trueNum;
    int b = lData.falseNum;
    int c = rData.trueNum;
    int d = rData.falseNum;
    if (exp[split] == '&')
    {
      tNum += a * c;
      fNum += a * d + b * c + b * d;
    }
    if (exp[spit] == ''|)
    {
      tNum += a * c + a * d + c * b;
      fNum += b * d;
    }
    if (exp[split] == '^')
    {
      tNum += a * d + b * c;
      fNum += a * c + b * d;
    }
  }
  return ReturnData(tNum, fNum);
}

int ExpressionNumberDp(const string& exp, int desried)
{
  if (exp.empty())
  {
    return -1;
  }
  if (exp.size() == 1)
  {
    return exp[0] == '1' ? 1 : 0;
  }
  if (!IsVaild(exp))
  {
    return -1;
  }
  vector<vector<int>> tDp(exp.size(), vector<int>(exp.size()));
  vector<vector<int>> fDp = tDp;
  for (int i = 0; i < exp.size(); i += 2)
  {
    tDp[i][i] = exp[i] = '0' ? 0 : 1;
    fDp[i][i] = exp[i] = '0' ? 1 : 0;
  }
  //依赖于他左边位置 下边位置 l <= s <= r
  for (int l = tDp.size() - 3; l >= 0; l -= 2)
  {
    //l + 1 为符号位 l == r位置已经填写
    for (int r = l + 2; r < tDp.size(); r += 2)
    {
      int tNum = 0;
      int fNum = 0;
      for (int s = l + 1; s < r; s += 2)
      {
        int a = tDp[l][s - 1];
        int b = tDp[s + 1][r];
        int c = fDp[l][s - 1];
        int d = fDp[s + 1][r];
        if (exp[s] == '&')
        {
          tNum += a * b;
          fNum += c * b + d * a + d * c;
        }
        if (exp[s] == '|')
        {
          tNum += a * d + a * b + b * c;
          fNum += c * d;
        }
        if (exp[s] == '^')
        {
          tNum += a * d + b * c;
          fNum += a * b + c * d;
        }
      }
      tDp[l][r] = tNum;
      fDp[l][r] = fNum;
    }
  }
  return desired ? tDp[0][tDp.size() - 1] : fDp[0][fDp.size() - 1];
}

int ExpressionNumber2(const string& exp, bool desired)
{
  if (exp.empty())
  {
    return -1;
  }
  if (!IsVaild(exp))
  {
    return -1;
  }
  return SelectProcess2(exp, 0, exp.size() - 1, desired);
}

int SelectProcess2(const string& exp, int l, int r, bool desired)
{
  if (l == r)
  {
    if (desired)
    {
      return exp[l] == '1' ? 1 : 0;
    }
    return exp[l] == '0' ? 1 : 0;  
  }
  int res = 0;
  if (desired)
  {
    for (int s = l + 1; s < r; s += 2)
    {
      switch(exp[s])
      {
        case '&':
          res += SelectProcess2(exp, l, s - 1, true) * SelectProcess2(exp, s + 1, r, true);
          break;
        case '|':
          res += SelectProcess2(exp, l, s - 1, true) * SelectProcess2(exp, s + 1, r, false);
          res += SelectProcess2(exp, l, s - 1, false) * SelectProcess2(exp, s + 1, r, true);
          res += SelectProcess2(exp, l, s - 1, true) * SelectProcess2(exp, s + 1, r, true);
          break;
        case '^':
          res += SelectProcess2(exp, l, s - 1, true) * SelectProcess2(exp, s + 1, r, false);
          res += SelectProcess2(exp, l, s - 1， false) * SelectProcess2(exp, s + 1, r, false);
          break;
      }
    }
  }
  else
  {
    for (int s = l + 1; s < r; s += 2)
    {
      switch(exp[s])
      {
        case '&':
          res += SelectProcess2(exp, l, s - 1, false) * SelectProcess2(exp, s + 1, r, false);
          break;
        case '|':
          res += SelectProcess2(exp, l, s - 1, false) * SelectProcess2(exp, s + 1, r, false);
          res += SelectProcess2(exp, l, s - 1, false) * SelectProcess2(exp, s + 1, r, true);
          res += SelectProcess2(exp, l, s - 1, true) * SelectProcess2(exp, s + 1, r, false);
          break;
        case '^':
          res += SelectProcess2(exp, l, s - 1, false) * SelectProcess2(exp, s + 1, r, false);
          res += SelectProcess2(exp, l, s - 1, true) * SelectProcess2(exp, s + 1, r, true);
      }
    }
  }
  return res;
}

int ExpressionNumberDp2(const string& exp, bool desired)
{
  if (exp.empty())
  {
    return -1;
  }
  if (exp.size() == 1)
  {
    if (desired)
    {
      return exp[0] == '1' ? 1 : 0; 
    }
    return exp[0] == '0' ? 1 : 0;
  }
  if (!IsVaild(exp))
  {
    return -1;
  }
  vector<vector<int>> tDp(exp.size(), vector<int>(exp.size()));
  vector<vector<int>> fDp = tDp;
  tDp[0][0] = exp[0] == '1' ? 1 : 0;
  fDp[0][0] = exp[0] == '0' ? 1 : 0;
  for (int l = 2; l < exp.size(); l += 2)
  {
    tDp[l][l] == exp[l] == '1' ? 1 : 0;
    fDp[l][l] == exp[l] == '0' ? 1 : 0;
    for (int r = l - 2; r >= 0; r -= 2)
    {
      for (int s = l + 1; s < r; s += 2)
      {
        //类似dp1
      }
    }
  }
}
