#include <assert.h>
#include <iostream>
#include <vector>

using std::vector;

static int MedianOfMedians(vector<int>& v, int begin, int end);
static int Select(vector<int>& v, int begin, int end, int i);

void PrintVector(const vector<int>& v)
{
  for (auto i : v)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

vector<int> Partition(vector<int>& v, int begin, int end, int pivotVal)
{
  int small = begin - 1;
  int curr = begin;
  int big = end + 1;
  while (curr < big)
  {
    if (v[curr] < pivotVal)
    {
      std::swap(v[++small], v[curr++]);
    }
    else if (v[curr] > pivotVal)
    {
      std::swap(v[curr], v[--big]);
    }
    else
    {
      ++curr;
    }
  }
  vector<int> pivotRange(2);
  pivotRange[0] = small + 1;
  pivotRange[1] = big - 1;
  return pivotRange;
}

void InsertSort(vector<int>& v, int begin, int end)
{
  for (int p = begin + 1; p <= end; ++p)
  {
    for (int i = p; i > 0 && v[i - 1] > v[i]; --i)
    {
      std::swap(v[i], v[i-1]);
    }
  }
}

int Median(vector<int>& v, int begin, int end)
{
  InsertSort(v, begin, end);
  int sum = begin + end;
  int mid = (sum / 2) + (sum % 2);
  return v[mid];
}

int Select(vector<int>& v, int begin, int end, int i)
{
  if (begin == end)
  {
    return v[begin];
  }
  int pivot = MedianOfMedians(v, begin, end);
  vector<int> pivotRange = Partition(v, begin, end, pivot);
  assert(pivotRange.size() == 2);
  if (i >= pivotRange[0] && i <= pivotRange[1])
  {
    return v[i];
  }
  else if (i <= pivotRange[0])
  {
    return Select(v, begin, pivotRange[0] - 1, i);
  }
  else
  {
    return Select(v, pivotRange[1] + 1, end, i);
  }
}

int MedianOfMedians(vector<int>& v, int begin, int end)
{
  int num = end - begin + 1;
  int offset = (num % 5) == 0 ? 0 : 1;
  vector<int> tmp(num / 5 + offset);
  for (int i = 0; i < tmp.size(); ++i)
  {
    int beginI = begin + i * 5;
    int endI = beginI + 4;
    tmp[i] = Median(v, beginI, std::min(end, endI));
  }
  return Select(tmp, 0, tmp.size() - 1, tmp.size() / 2);
}

int MinKthByBFPRT(const vector<int>& v, int k)
{
  vector<int> copyV = v;
  return Select(copyV, 0, copyV.size() - 1, k - 1);
}

vector<int> MinKNumsByBFPRT(const vector<int>& v, int k)
{
  if (v.empty() || k < 1 || k > v.size())
  {
    return vector<int>();
  }
  int minKth = MinKthByBFPRT(v, k);
  //std::cout << minKth << std::endl;
  vector<int> res(k);
  int pos = 0;
  for (int i = 0; i < v.size() && pos < res.size(); ++i)
  {
    if (v[i] <= minKth)
    {
      res[pos++] = v[i];
    }
  }
  return res;
}

void HeapInsert(vector<int>& heap, int index, int val)
{
  heap[index] = val;
  while (index != 0)
  {
    int parent = (index - 1) / 2;
    if (heap[parent] < heap[index])
    {
      std::swap(heap[parent], heap[index]);
      index = parent;
    }
    else
    {
      break;
    }
  }
}

void Heapify(vector<int>& heap, int index, int heapSize)
{
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  int largest = index;
  while (left < heapSize)
  {
    if (heap[left] > heap[index])
    {
      largest = left;
    }
    if (right < heapSize && heap[right] > heap[largest])
    {
      largest = right;
    }
    if (index != largest)
    {
      std::swap(heap[index], heap[largest]);
    }
    else
    {
      break;
    }
    index = largest;
    left = 2 * index + 1;
    right = 2 * index + 2;
  }
}

vector<int> MinKNumsByHeap(const vector<int>& v, int k)
{
  if (v.empty() || k < 1 || k > v.size())
  {
    return vector<int>();
  }
  vector<int> heap(k);
  for (int i = 0; i < k; ++i)
  {
    HeapInsert(heap, i, v[i]);
  }
  for (int i = k; i < v.size(); ++i)
  {
    if (v[i] < heap[0])
    {
      heap[0] = v[i];
      Heapify(heap, 0, k);
    }
  }
  return heap;
}

int main(void)
{
  vector<int> v = { 6, 9, 1, 3, 1, 2, 2, 5, 6, 1, 3, 5, 9, 7, 2, 5, 6, 1, 9 };
  //sorted : { 1, 1, 1, 1, 2, 2, 2, 3, 3, 5, 5, 5, 6, 6, 6, 7, 9, 9, 9 }
  PrintVector(MinKNumsByBFPRT(v, 10));
  PrintVector(MinKNumsByHeap(v, 10));

  return 0;
}
