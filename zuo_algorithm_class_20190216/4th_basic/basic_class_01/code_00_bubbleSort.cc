void BubbleSort(vector<int>& numbers)
{
  if (numbers.size() < 2)
  {
    return;
  }
  for (int i = numbers.size() - 1; i > 0; --i)
  {
    for (int j = 0; j < i; ++j)
    {
      if (numbers[j] > numbers[j + 1])
      {
        std::swap(numbers[j], numbers[j + 1]);
      }
    }
  }
}
