void HeapSort1(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  for (int i = a.size() / 2; i >= 0; --i)
  {
    PercDown(a, i, a.size());
  }
  for (int i = a.size() - 1; i > 0; --i)
  {
    std::swap(a[0], a[i]);
    PercDown(a, 0, i);
  }
}

#define LeftChild(i) (2 * (i)) + 1

void PercDown1(vector<int>& a, int i, int n)
{
  int child;
  int tmp;
  for (tmp = a[i]; LeftChild(i) < n; i = child)
  {
    child = LeftChild(i);
    if (child != n - 1 && a[child] > a[child + 1])
    {
      ++child;
    }
    if (a[child] > a[i])
    {
      a[i] = a[child];
    }
    else
    {
      break;
    }
  }
  a[i] = tmp;
}

void PercDown2(vector<int>& a, int i, int n)
{
  while (LeftChild(i) < n)
  {
    int child = LeftChild(i);
    if (child != n - 1 && a[child] > a[child + 1])
    {
      ++child;
    }
    if (a[child] > a[i])
    {
      std::swap(a[child], a[i]);
    }
    else
    {
      break;
    }
    i = child;
  }
}

void HeapSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  for (int i = 0; i < a.size(); ++i)
  {
    HeapInsert(a, i);
  }
  for (int i = a.size() - 1; i > 0; --i)
  {
    std::swap(a[i], a[0]);
    Heapify(a, 0, i);
  }
}

//仅仅和自己的父亲比较上滤
void HeapInsert(vector<int>& a, int index)
{
  while (a[index] > a[(index - 1) / 2])
  {
    std::swap(a[index], a[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

void Heapify(vector<int>& a, int index, int size)
{
  int left = index * 2 + 1;
  while (left < size)
  {
    int largest = left + 1 < size && a[left + 1] > a[left] ? left + 1 : left;
    largest = a[largest] > a[index] ? largest : index;
    if (index == largest)
    {
      break;
    }
    std::swap(a[largest, index]);
    index = largest;
    left = index * 2 + 1;
  }
}
