#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

bool IsStackPushPopOrder(const vector<int>& pushOrder, const vector<int>& isPopOrder)
{
  if (pushOrder.empty() || isPopOrder.empty() || pushOrder.size() != isPopOrder.size())
  {
    return false;
  }
  stack<int> st;
  int j = 0;
  for (int i = 0; i < pushOrder.size(); ++i)
  {
    while (!st.empty() && j < isPopOrder.size() && st.top() == isPopOrder[j])
    {
      st.pop();
      ++j;
    }
    st.push(pushOrder[i]);
  }
  while (!st.empty() && j < isPopOrder.size())
  {
    if (st.top() != isPopOrder[j])
    {
      break;
    }
    st.pop();
    ++j;
  }
  return st.empty() && j == isPopOrder.size();
}

int main(void)
{
  vector<int> v1 = {1, 2, 3, 4, 5};
  vector<int> v2 = {4, 5, 3, 2, 1};
  vector<int> v3 = {4, 3, 5, 1, 2};
  std::cout << IsStackPushPopOrder(v1, v2) << std::endl;
  std::cout << IsStackPushPopOrder(v1, v3) << std::endl;

  return 0;
}
