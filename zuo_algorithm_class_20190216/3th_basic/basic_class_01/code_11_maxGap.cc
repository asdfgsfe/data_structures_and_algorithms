int MaxGap(vector<int>& numbers)
{
  if (numbers.size() < 2)
  {
    return 0;
  }
  //bucket[id][0] == isEmpty 1±íÊ¾·Ç¿Õ
  //bucket[id][1] == min
  //bucket[bid][2] == max
  vector<vector<int>> bucket(numbers.size() + 1, vector<int>(3, 0));
  int max = numbers[0];
  int min = numbers[0];
  for (int number : numbers)
  {
    max = std::max(max, number);
    min = std::min(min, number);
  }
  if (max == min)
  {
    return 0;
  }
  for (int number : numbers)
  {
    int bid = Bucket(number, min, max, number.size());
    bucket[bid][1] = bucket[bid][0] == 1 ? std::min(number, bucket[bid][1]) : number;
    bucket[bid][2] = bucket[bid][0] == 1 ? std::max(number, bucket[bid][2]) : number;
    bucket[bid][0] = 1;
  }
  int lastMax = bucket[0][2];
  int res = 0;
  for (int i = 1; i < bucket.size(); ++i)
  {
    if (bucket[i][0])
    {
      res = std::max(res, bucket[i][1] - lastMax);
      lastMax = bucket[i][2];
    }
  }
  return res;
}

int Bucket(int num, long min, long max, long size)
{
  return (int)((num - min) * size / (max - min));
}
