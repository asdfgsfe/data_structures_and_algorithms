#include <stdlib.h>
#include <iostream>
#include <vector>

using std::vector;

vector<int> Paritition(vector<int>& v, int l, int r)
{
  if (v.empty())
  {
    return vector<int>();
  }
  int less = l - 1;
  int more = r;
  while (l < more)
  {
    if (v[l] < v[r])
    {
      std::swap(v[l++], v[++less]);
    }
    else if (v[l] > v[r])
    {
      std::swap(v[l], v[--more]);
    }
    else
    {
      ++l;
    }
  }
  std::swap(v[more], v[r]);
  vector<int> res = {less + 1, more};
  return res;
}

void QSort(vector<int>& v, int l, int r)
{
  if (l < r)
  {
    std::swap(v[l + (int)(::rand() % (r - l + 1))], v[r]);
    vector<int> p = Paritition(v, l, r);
    QSort(v, l, p[0] - 1);
    QSort(v, p[1] + 1, r);
  }
}

void QuickSort(vector<int>& v)
{
  if (v.empty())
  {
    return;
  }
  QSort(v, 0, v.size() - 1);
}

void PrintVector(const vector<int>& v)
{
  for (int i : v)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int Median3(vector<int>& v, int l, int r)
{
  int mid = (l + r) / 2;
  if (v[l] > v[mid])
  {
    std::swap(v[l], v[mid]);
  }
  if (v[mid] > v[r])
  {
    std::swap(v[mid], v[r]);
  }
  if (v[l] > v[mid])
  {
    std::swap(v[l], v[mid]);
  }
  std::swap(v[mid], v[r - 1]);
  return v[r - 1];
}

void InsertSort(vector<int>& v, int l, int r)
{
  if (v.empty() || v.size() == 1)
  {
    return;
  }
  for (int p = l + 1; p <= r; ++p)
  {
    for (int i = p - 1; i >= l && v[i] > v[i+1]; --i)
    {
      std::swap(v[i], v[i+1]);
    }
  }
}

void QSort2(vector<int>& v, int l, int r)
{
  if (l + 3 <= r)
  {
    int pivot = Median3(v, l, r);
    int i = l;
    int j = r - 1;
    while (1)
    {
      while (v[++i] < pivot) {}
      while (v[--j] > pivot) {}
      if (i >= j)
      {
        break;
      }
      std::swap(v[i], v[j]);
    }
    std::swap(v[i], v[r-1]);
    QSort2(v, l, i - 1);
    QSort2(v, i + 1, r);
  }
  else
  {
    InsertSort(v, l, r);
  }
}


void QuickSort2(vector<int>& v)
{
  if (v.empty() || v.size() == 1)
  {
    return;
  }
  QSort2(v, 0, v.size() - 1);
}


int main(void)
{
  vector<int> test = {2, 5, 6, 3, 9, 0, 1, 8};
  QuickSort(test);
  PrintVector(test);

  test = {2, 5, 6, 3, 9, 0, 1, 8};
  QuickSort2(test);
  PrintVector(test);
    
  return 0;
}
