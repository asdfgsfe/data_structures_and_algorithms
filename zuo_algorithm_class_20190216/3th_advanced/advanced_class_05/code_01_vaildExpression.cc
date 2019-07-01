bool IsVaildExpression(const string& exp)
{
  if (exp.empty())
  {
    return true;
  }
  stack<char> matched;
  for (char ch : exp)
  {
    if (ch == '(' || ch == '{' || ch == '[')
    {
      matched.push(ch);
    }
    if (ch == ')' || ch == '}' || ch == ']')
    {
      char match = ch == ')' ? '(' : (ch == '}' ? '{' : ']');
      if (!matched.empty() && match != matched.top())
      {
        return false;
      }
      matched.pop();
    }
  }
  return matched.empty();
}
