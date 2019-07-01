struct Program
{
  int start;
  int end;
  Program(int s, int e)
    : start(s), end(e)
  {}
};

int BestArrange(const vector<Program>& programs, int start)
{
  std::sort(programs.begin(), programs.end(), [](const program& lhs, const program& rhs) ->bool
      {
        return lhs.end < rhs.end;
      });
  int maxNum = 0;
  for (const auto& program : programs)
  {
    if (start <= program.start)
    {
      ++maxNum;
      start = program.end;
    }
  }
  return maxNum;
}

int BestArrange(const vector<Programs>& programs, int start)
{
  if (programs.empty())
  {
    return 0;
  }
  std::make_heap(programs.begin(), programs.end(), [](const program& lhs, const program& rhs) ->bool
      {
        return lhs.end > rhs.end;
      });
  int maxNum = 0;
  for (const auto& program : programs)
  {
    if (start <= program.end)
    {
      ++maxNum;
      start = program.end;
    }
    std::pop_heap(programs.begin(), programs.end(), [](const program& lhs, const auto& program& rhs) ->bool
        {
          return lhs.end > rhs.end;
        });
    programs.pop_back();
  }
}
