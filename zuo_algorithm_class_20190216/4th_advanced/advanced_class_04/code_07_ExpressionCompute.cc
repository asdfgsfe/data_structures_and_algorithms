int ComputeNum(stack<string>& pureExp)
{
  while (pureExp.size() != 1)
  {
    int pre = pureExp.top();
    pureExp.pop();
    string symbol = pureExp.top();
    pureExp.pop();
    int next = pureExp.top();
    pureExp.pop();
    pre = symbol == "+" ? (pre + next) : (next - pre);
    pureExp.push(pre);
  }
  return pureExp.top();
}

//可以优化为这种
int GetNum(stack<string>& compute)
{
	int num = 0;
	bool isAdd = true;
	while (!compute.empty())
	{
		string cur = compute.top();
		compute.pop();
		if (cur == '+')
		{
			isAdd = true;
		}
		else if (cur == '-')
		{
			isAdd = false;
		}
		else
		{
			int curNum = ::atoi(cur);
			num += isAdd ?  curNum : -curNum;
		}
	}
	return num;
}


void AddNum(stack<string>& pureExp, int num)
{
  if (!pureExp.empty())
  {
    string topExp = pureExp.top();
    if (topExp == '*' || topExp == '/')
    {
      pureExp.pop();
      int cur = ::atoi(pureExp.top());
      pureExp.pop();
      num = topExp == '*' ? (cur * num) : (cur / num);
    }
  }
  pureExp.push(std::to_string(num));
}

vector<int> ComputeProcess(const string& exp, int i)
{
  stack<string> pureExp;
  int pre = 0;
  while (i < exp.size() && exp[i] != ')')
  {
    if (exp[i] >= '0' && exp[i] <= '9')
    {
      pre = pre * 10 + exp[i++] - '0';
    }
    else if (exp[i] != '(')
    {
      AddNum(pureExp, pre);
      pureExp.push(string(exp[i++]));
      pre = 0; //这里非常容易丢
    }
    else
    {
      vector<int> bra = ComputeProcess(exp, i + 1);
      assert(bra.size() == 2);
      pre = bra[0];
      i = bra[1] + 1;
    }
  }
  AddNum(pureNum, pre);//这里也容易丢
  return {ComputeNum(pureNum), i};
}

int ExpCompute(const string& exp)
{
  if (exp.empty())
  {
    return 0x80000000;
  }
  return ComputeProcess(exp, 0).front();
}
