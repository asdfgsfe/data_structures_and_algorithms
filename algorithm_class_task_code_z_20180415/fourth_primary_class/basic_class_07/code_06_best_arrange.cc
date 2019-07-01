#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Program
{
  int start;
  int end;

  Program(int s, int e)
    : start(s), end(e)
  {}
};

int BestArrange(vector<Program>& programs, int start)
{
  if (programs.empty())
  {
    return 0;
  }
  std::sort(programs.begin(), programs.end(), 
      [&](const Program& p1, const Program& p2) ->bool {return p1.end < p2.end;});
  int result = 0;
  for (const auto& program : programs)
  {
    if (start <= program.start)
    {
      ++result;
      start = program.end;
    }
  }
  return result;
}

int BestArrange2(vector<Program>& programs, int start)
{
  if (programs.empty())
  {
    return 0;
  }
  auto comparator = [&](const Program& p1, const Program& p2) ->bool {return p1.end > p2.end;};
  make_heap(programs.begin(), programs.end(), comparator);
  int result = 0;
  for (int i = 0; i < programs.size(); ++i)
  {
    if (start <= programs.front().start)
    {
      ++result;
      start = programs.front().end;
      pop_heap(programs.begin(), programs.end(), comparator);
    }
  }
  return result;
}

int main(void)
{

  return 0;
}

