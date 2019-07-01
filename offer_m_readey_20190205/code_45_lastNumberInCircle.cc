int LastNumberInCircle(int n, int m)
{
  if (n < 1 || m < 1)
  {
    return -1;
  }
  list<int> circle;
  for (int i = 0; i < n; ++i)
  {
    circle.push_back(i);
  }
  list<int> curr = circle.begin();
  while (circle.size() > 1)
  {
    for (int i = 0; i < m; ++i)
    {
      ++curr;
      if (curr == circle.end())
      {
        curr = circle.begin();
      }
    }
    curr = circle.erase(curr);
    if (curr == circle.end())
    {
      curr = curr.begin();
    }
  }
  return circle.front()
}

int LastNumberInCircle2(int n)
{
  if (n < 1 || m < 1)
  {
    return -1;
  }
  int last = 0;
  for (int i = 2; i <= n; ++i)
  {
    last = (last + m) % i;
  }
  return last;
}

int LastNumberInCircle3(int n)
{
  if (n < 1 || m < 1)
  {
    return -1;
  }
  if (n == 1)
  {
    return 0;
  }
  return (LastNumberInCircle(n - 1, m) + m) % n;
}
