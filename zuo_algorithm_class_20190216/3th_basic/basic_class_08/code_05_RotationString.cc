//不是最优解 最优解左神
void Reverse(string& str, int left, int right)
{
  if (str.empty() || left < 0 || right >= str.size() || left >= right)
  {
    return;
  }
  while (left < right)
  {
    std::swap(str[left++], str[right--]);
  }
}

void RotationString(string& str, int k)
{
  if (str.empty() || k < 1)
  {
    return;
  }
  k = k % str.size();
  Reverse(str, 0, str.size() - 1);
  Reverse(str, 0, k - 1);
  Reverse(str, k, str.size() - 1);
}
