int MaxGap(const vector<int>& numbers)
{
  if (numbers.size() < 2)
  {
    return 0;
  }
  int max = numbers[0];
  int min = numbers[0];
  for (int number : numbers)
  {
    max = number > max ? number : max;
    min = number < min ? number : min;
  }
  vector<vector<int>> buckets(numbers.size() + 1, vector<int>(3, 0));
  for (int number : numbers)
  {
    int bid = Bucket(number, max, min, numbers.size());
    buckets[bid][1] = buckets[bid][0] == 1 ? std::min(buckets[bid][1], number) : number;
    buckets[bid][2] = buckets[bid][0] == 1 ? std::max(buckets[bid][2], number) : number;
    buckets[bid][0] = 1;
  }
  int lastMax = buckets[0][0];
  int res = 0;
  for (const auto& bucket : buckets)
  {
    if (bucket[0])
    {
      res = std::max(res, bucket[1] - lastMax);
      lastMax = bucket[2];
    }
  }
  return res;
}

int Bucket(int number, int max, int min, int size)
{
  return (int)(number - min) * size / (max - min);
}
