#include <iostream>
#include <vector>

using std::vector;

bool IsSelfCorssing(const vector<int>& x)
{
  int len = x.size();
  if (len < 4)
  {
    return false;
  }
  if ((len > 3 && x[2] <= x[0] && x[3] >= x[1]) || 
      (len > 4 && 
      (x[3] <= x[1] && x[4] >= x[2])|| 
      (x[3] == x[1] && x[4] + x[0] >= x[2])))
  {
    return true;
  }

  for (int i = 5; i < len; ++i)
  {
    if (x[i-1] <= x[i-3] 
	&& ((x[i] >= x[i-2]) || (x[i] + x[i-4] >= x[2]) && (x[i-1] + x[i-5] >= x[i-3])))
    {
      return true;
    }
  }
  return false;
}

int main(void)
{

  return 0;
}

