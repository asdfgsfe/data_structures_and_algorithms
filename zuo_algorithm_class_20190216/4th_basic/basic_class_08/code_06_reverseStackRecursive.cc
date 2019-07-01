#include <iostream>
#include <stack>

using std::stack;

int LastAndPop(stack<int>& values)
{
  assert(!values.empty());
  int result = values.top();
  values.pop();
  if (values.empty())
  {
    return result;
  }
  int last = LastAndPop(values);
  values.push(result);
  return last;
}

void ReverseProcess(stack<int>& values)
{
  if (values.empty())
  {
    return;
  }
  int last = LastAndPop(values);
  ReverseProcess(values);
  values.push(last);
}


int main(void)
{
  stack<int> values;
  for (int i = 1; i <= 3; ++i)
  {
    values.push(i);
  }
  ReverseProcess(values);
  while (!values.empty())
  {
    std::cout << values.top() << " ";
    values.pop();
  }
  std::cout << std::endl;

  return 0;
}
