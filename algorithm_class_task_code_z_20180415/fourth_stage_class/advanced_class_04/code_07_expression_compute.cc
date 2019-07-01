#include <assert.h>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using std::string;
using std::stack;
using std::vector;

int GetNum(stack<string>& pureExp)
{
  int res = 0;
  while (!pureExp.empty())
  {
    string cur = pureExp.top();
    pureExp.pop();
    bool isAdd = true;
    if (cur == "+")
    {
      isAdd = true;
    }
    else if (cur == "-")
    {
      isAdd = false;
    }
    else
    {
      int num = ::atoi(cur.c_str());
      res -= isAdd ? num : (-num);
    }
  }
  return res;
}

void AddNum(stack<string>& pureExp, int num)
{
  if (!pureExp.empty())
  {
    string topExp = pureExp.top();
    if (topExp == "*" || topExp == "/")//在栈中先算乘除
    {
      pureExp.pop();
      int cur = ::atoi(pureExp.top().c_str());
      pureExp.pop();
      cur = topExp == "*" ? (cur * num) : (cur / num);
      pureExp.push(std::to_string(cur));
    }
  }
  pureExp.push(std::to_string(num));
}

//返回2个值 0表示()中表达式的值, 1表示自己算到了那个位置
vector<int> Value(string& expression, int i)
{
  stack<string> pureExp;
  int pre = 0;
  vector<int> bre(2, 0);
  while (i < expression.size() && expression[i] != ')')
  {
    if (expression[i] >= '0' && expression[i] <= '9')
    {
      pre = pre * 10 + expression[i++] - '0';
    }
    else if (expression[i] != '(') //遇到了符号
    {
      AddNum(pureExp, pre);//将数字加入栈中
      string tmp(expression[i++]);//将符号加入栈中
      pureExp.push(tmp);
      pre = 0;
    }
    else//遇到了左括号
    {
      bre = Value(expression, i+1);
      assert(bre.size() == 2);
      pre = bre[0];
      i = bre[1] + 1;
    }
  }
  AddNum(pureExp, pre);
  return {GetNum(pureExp), i};
}

int ExpressionCompute(string& expression)
{
  if (expression.empty())
  {
    return 0;
  }
  return Value(expression, 0)[0];
}

int main(void)
{
  string exp = "48 * ((70 -65) - 43) + 8 * 1";
  std::cout << ExpressionCompute(exp) << std::endl;;


  return 0;
}
