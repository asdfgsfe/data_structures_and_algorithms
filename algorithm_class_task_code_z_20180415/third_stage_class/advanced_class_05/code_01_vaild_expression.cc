#include <iostream>
#include <string>
#include <stack>

using std::string;
using std::stack;

bool IsVaild(const string& expression)
{
  if (expression.empty())
  {
    return false;
  }
  
  stack<char> st;
  for (int i = 0; i < expression.length(); ++i)
  {
    if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
    {
      st.push(expression[i]);
    }
    if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')')
    {
      char match = expression[i] == '}' ? '{' : (expression[i] == '[' ? ']' : ')';
      if (!st.empty() && st.top() != match)
      {
        return false;
      }
      st.pop();
    }
  }
  return st.empty();
}

int main(void)
{
  string test = "{1+(2+3)+[(1+3)+(4*5)]}";
  std::cout << IsVaild(test) << std::endl;

  return 0;
}
