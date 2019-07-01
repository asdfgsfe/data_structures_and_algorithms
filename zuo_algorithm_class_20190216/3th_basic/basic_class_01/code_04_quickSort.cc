void QuickSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  QuickProcess(a, 0, a.size() - 1);
}

void SortProcess(vector<int>& a, int left, int right)
{
  if (right - left > 3)
  {
    int pivot = Median3(a, left, right);
    int i = left;
    int j = right - 1;
    while(1)
    {
      while (a[++i] < pivot){}
      while (a[--j] > pivot){}
      if (i < j)
      {
        std::swap(a[i], a[j]);
      }
      else
      {
        break;
      }
    }
    std::swap(a[right - 1], a[i]);
    SortProcess(a, left, i - 1);
    SortProcess(a, i + 1, right);
  }
  else
  {
    InsertSort(a, left, right);
  }
}

int Median3(vector<int>& a, int left, int right)
{
  int center = (left + right) / 2;
  if (a[left] > a[center])
  {
    std::swap(a[left], a[center]);
  }
  if (a[center] < a[right])
  {
    std::swap(a[center], a[right]);
  }
  if (a[left] > a[center])
  {
    std::swap(a[left], a[center]);
  }
  std::swap(a[center], a[right - 1]);
  return a[right - 1];
}

void QuickSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  SortProcess(a, 0, a.size() - 1);
}

void SortProcess(vector<int>& a, int l, int r)
{
  if (l < r)//设计递归函数 一定要记住设计递归的出口
  {
    int pivotId = Random(l, r);
    std::swap(a[pivotId], a[r]);
    vector<int> position = Partition(a, l, r);
    assert(position.size() == 2);
    SortProcess(a, l, position[0] - 1);
    SortProcess(a, position[1] + 1， r);
  }
}

vector<int> Partition(vector<int>& a, int l, int r)
{
  int less = l - 1;
  int more = r;
  while (l < more)
  {
    if (a[l] < a[r])
    {
      std::swap(a[++less], a[l++]);
    }
    else if (a[l] > a[r])
    {
      std::swap(a[l], a[--more]);
    }
    else
    {
      ++l;
    }
  }
  std::swap(a[l], a[r]);//这个地方也容易丢
  return {less + 1, more};
}

