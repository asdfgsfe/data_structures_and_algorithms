struct Program
{
  int start;
  int end;
  Program(int s, int e)
    : start(s), end(e)
  {}
};

int BestArrange(vector<Program>& programs, int firstStart)
{
  if (programs.empty())
  {
    return 0;
  }
  std::sort(programs.begin(), programs.end(), [](const Program& lhs, const Program& rhs) ->bool
      {
        return lhs.end < rhs.end()
      });
  int count = 0;
  for (int i = 0; i < programs.size(); ++i)
  {
    if (firstStart <= programs[i])
    {
      ++count;
      firstStart = programs[i].end;
    }
  }
  return count;
}
