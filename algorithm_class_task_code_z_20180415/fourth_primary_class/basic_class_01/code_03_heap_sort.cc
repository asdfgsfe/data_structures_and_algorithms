#include <iostream>
#include <vector>

using std::vector;

void HeapInsert(vector<int>& v, int index)
{
  while (v[index] > v[(index - 1) / 2])
  {
    std::swap(v[index], v[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

void Heapify(vector<int>& v, int index, int size)
{
  int l = 2 * index + 1;
  while (l < size)
  {
    int largest = l + 1 < size && v[l + 1] > v[l] ? l + 1 : l;
    largest = v[largest] > v[index] ? largest : index;
    if (largest == index)
    {
      break;
    }
    std::swap(v[largest], v[index]);
    index = largest;
    l = index * 2 + 1;
  }
}

void HeapSort(vector<int>& v)
{
  if (v.empty() || v.size() == 1)
  {
    return;
  }

  for (int i = 0; i < v.size(); ++i)
  {
    HeapInsert(v, i);
  }
  int size = v.size();
  std::swap(v[0], v[--size]);
  while (size > 0)
  {
    Heapify(v, 0, size);
    std::swap(v[0], v[--size]);
  }
}

void PrintVector(const vector<int>& v)
{
  for (int i : v)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void PercDown(vector<int>& v, int i, int n)
{
  int child;
  int tmp;
  for (tmp = v[i]; (2 * i + 1) < n; i = child)
  {
    child = 2 * i + 1;
    child = child != n-1 && v[child+1] > v[child] ? child + 1 : child;
    if (v[child] <= tmp)
    {
      break;
    }
    v[i] = v[child];
  }
  v[i] = tmp;
}

void HeapSort2(vector<int>& v)
{
  if (v.empty() || v.size() == 1)
  {
    return;
  }
  for (int i = v.size() / 2; i >= 0; --i)
  {
    PercDown(v, i, v.size());
  }
  for (int i = v.size() - 1; i >= 0; --i)
  {
    std::swap(v[0], v[i]);
    PercDown(v, 0, i);
  }
}


int main(void)
{
  vector<int> v = {3, 6, 8, 0, 1, 2};
  HeapSort(v);
  PrintVector(v);

  v = {3, 6, 8, 0, 1, 2};
  HeapSort2(v);
  PrintVector(v);

  return 0;
}
