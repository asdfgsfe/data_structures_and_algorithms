#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Dot
{
  int w;
  int h;

  Dot()
  {}

  Dot(int weight, int hight)
    : w(weight), h(hight)
  {}
};

void PrintDot(const vector<Dot>& dots)
{
  std::cout << "Dots: " << std::endl;
  for (int i = 0; i < dots.size(); ++i)
  {
    std::cout << dots[i].w << " " << dots[i].h << std::endl;
  }
}

auto DotComparator = [](Dot arg1, Dot arg2) ->int 
{
  if (arg1.w == arg2.w)
  {
    if (arg1.h == arg2.h)
    {
      return 0;
    }
    else if (arg1.h < arg2.h)
    {
      return -1;
    }
    else
    {
      return 1;
    }
  }
  else if (arg1.w < arg2.w)
  {
    return 1;
  }
  else
  {
    return -1;
  }
};

struct DotComparator2
{
  int operator()(Dot arg1, Dot arg2)
  {
    if (arg1.w == arg2.w)
    {
      if (arg1.h == arg2.h)
      {
        return 0;
      }
      else if (arg1.h < arg2.h)
      {
        return 1;
      }
      else
      {
        return -1;
      }
    }
    else if (arg1.w < arg2.w)
    {
      return -1;
    }
    else
    {
      return 1;
    }
  }

};

int MaxEnvelpoes(const vector<vector<int>>& es)
{
  if (es.empty() || es[0].empty() || es[0].size() != 2)
  {
    return 0;
  }

  vector<Dot> dots(es.size());
  for (int i = 0; i < es.size(); ++i)
  {
    dots[i] = Dot(es[i][0], es[i][1]);
  }
  PrintDot(dots);
  //std::cout << std::endl;
  std::sort(dots.begin(), dots.end(), DotComparator2());
  PrintDot(dots);
  vector<int> ends(es.size());
  ends[0] = dots[0].h;
  int right = 0;
  for (int i = 1; i < dots.size(); ++i)
  {
    int l = 0;
    int r = right;
    while (l <= r)
    {
      int m = (l + r) / 2;
      if (dots[i].h > ends[m])
      {
        l = m + 1;
      }
      else
      {
        r = m - 1;
      }
    }
    right = std::max(right, l);
    ends[l] = dots[i].h;
  }
  return right + 1;
}

int MaxEnvelpoes2(const vector<vector<int>>& es)
{
  if (es.empty() || es[0].empty() || es[0].size() != 2)
  {
    return 0;
  }

  vector<Dot> dots(es.size());
  for (int i = 0; i < es.size(); ++i)
  {
    dots[i] = Dot(es[i][0], es[i][1]);
  }
  sort(dots.begin(), dots.end(), DotComparator);
  PrintDot(dots);
  vector<int> ends(es.size());
  vector<int> dp(es.size());
  int right = 0;
  for (int i = 0; i < dots.size(); ++i)
  {
    int l = 0;
    int r = right;
    while (l <= r)
    {
      int m = (l + r) / 2;
      if (dots[i].h > ends[m])
      {
        l = m + 1;
      }
      else
      {
        r = m - 1;
      }
    }
    right = std::max(right, l);
    ends[l] = dots[i].h;
    dp[i] = right + 1;
  }
  return dp[es.size() - 1];
}

int main(void)
{
  vector<vector<int>> test = { { 4, 3 }, { 1, 2 }, { 5, 7 }, { 5, 3 }, { 1, 1 }, { 4, 9 } };
  std::cout << MaxEnvelpoes(test) << std::endl;
  std::cout << MaxEnvelpoes2(test) << std::endl;
  
  return 0;
}
