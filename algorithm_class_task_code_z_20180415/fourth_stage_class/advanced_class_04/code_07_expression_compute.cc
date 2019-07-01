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
    if (topExp == "*" || topExp == "/")//��ջ������˳�
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

//����2��ֵ 0��ʾ()�б��ʽ��ֵ, 1��ʾ�Լ��㵽���Ǹ�λ��
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
    else if (expression[i] != '(') //�����˷���
    {
      AddNum(pureExp, pre);//�����ּ���ջ��
      string tmp(expression[i++]);//�����ż���ջ��
      pureExp.push(tmp);
      pre = 0;
    }
    else//������������
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
