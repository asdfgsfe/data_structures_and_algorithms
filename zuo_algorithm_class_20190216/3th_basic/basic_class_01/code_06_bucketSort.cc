//可以做到稳定性
void BucketSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  int min = a[0];
  int max = a[0];
  for (int i = 1; i < a.size(); ++i)
  {
    min = std::min(min, a[i]);
    max = std::max(max, a[i]);
  }
  vector<int> bucket(max - min + 1, 0);
  for (int val : a)
  {
    bucket[val - min]++; 
  }
  int i = 0;
  for (int j = 0; j < bucket.size(); ++j)
  {
    while (bucket[j]-- > 0)
    {
      a[i++] = j + min;
    }
  }
}
