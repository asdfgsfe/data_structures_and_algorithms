void BucketSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  int max = a[0];
  int min = a[0];
  for (int number : a)
  {
    max = number > max ? number : max;
    min = number < min ? number : min;
  }
  vector<int> buckets(max - min + 1, 0);
  for (int number : a)
  {
    buckets[number - min]++;
  }
  int id = 0;
  for (int i = 0; i < buckets.size(); ++i)
  {
    while (buckets[i]--)
    {
      a[id++] = i + min;
    }
  }
}
