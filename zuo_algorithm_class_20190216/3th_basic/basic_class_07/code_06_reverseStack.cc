int GetAndPopLastElement(stack<int>& st)
{
  int result = st.top();
  st.pop();
  if (st.empty())
  {
    return result;
  }
  else
  {
    int last = GetAndPopLastElement(st);
    st.push(result);
    return last;
  }
}

void ReverseStack(stack<int>& st)
{
  if (st.empty())
  {
    return;
  }
  int i = GetAndPopLastElement(st);
  ReverseStack(st);
  st.push(i);
}
