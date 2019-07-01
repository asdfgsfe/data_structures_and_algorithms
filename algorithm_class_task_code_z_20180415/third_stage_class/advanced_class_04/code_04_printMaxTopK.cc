#include <ctime>
#include<cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct HeapNode
{
  int val;
  int arrNum;
  int index;

  HeapNode(int value, int num, int id)
    : val(value), arrNum(num), index(id)
  {}

  HeapNode& operator=(const HeapNode& other)
  {
    if (&other == this)
    {
      return *this;
    }
    val = other.val;
    arrNum = other.arrNum;
    index = other.index;
    return *this;
  }
};

//makeHeap
void HeapInsert(vector<HeapNode>& heap, int id)
{
  while (id != 0)
  {
    int parent = (id - 1) / 2;
    if (heap[parent].val < heap[id].val)
    {
      std::swap(heap[parent], heap[id]);
      id = parent;
    }
    else
    {
      break;
    }
  }
}

void Heapify(vector<HeapNode>& heap, int id, int heapSize)
{
  int left = id * 2 + 1;
  int right = id * 2 + 2;
  int largest = id;
  while (left < heapSize)
  {
    if (heap[left].val > heap[id].val)
    {
      largest = left;
    }
    if (right < heapSize && heap[right].val > heap[largest].val)
    {
      largest = right;
    }
    if (largest != id)
    {
      std::swap(heap[id], heap[largest]);
    }
    else
    {
      break;
    }

    id = largest;
    left = id * 2 + 1;
    right = id * 2 + 2;
  }
}

void PrintMaxTopK(const vector<vector<int>>& matrix, int topK)
{
  if (matrix.empty())
  {
    return;
  }

  int heapSize = matrix.size();
  vector<HeapNode> heap(heapSize, HeapNode(0, 0, 0));
  for (int i = 0; i < heapSize; ++i)
  {
    int id = matrix[i].size() - 1;
    heap[i] = HeapNode(matrix[i][id], i, id);
    HeapInsert(heap, i);
  }
  std::cout << "topK " << topK << " " << std::endl;
  for (int i = 0; i < topK; ++i)
  {
    if (heapSize == 0)
    {
      break;
    }
    std::cout << heap[0].val << " ";
    if (heap[0].index != 0)
    {
      heap[0].val = matrix[heap[0].arrNum][--heap[0].index];
    }
    else
    {
      std::swap(heap[0], heap[--heapSize]);
    }
    Heapify(heap, 0, heapSize);
  }
}

void PrintMatrix(const vector<vector<int>>& matrix)
{
  for (int i = 0; i < matrix.size(); ++i)
  {
    for (int j = 0; j < matrix[i].size(); ++j)
    {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

vector<vector<int>> GetRandomMatrix(int rows, int cols, int maxValue)
{
  if (cols < 0 || rows < 0)
  {
    return vector<vector<int>>();
  }
  
  vector<vector<int>> matrix;
  ::srand((unsigned)time(NULL));
  int row = ::rand() % rows + 1;
  matrix.resize(row);
  for (int i = 0; i < row; ++i)
  {
    ::srand((unsigned)time(NULL));
    int col = ::rand() * col + 1;
    matrix[i].resize(col);
    for (int j = 0; j < col; ++j)
    {
      ::srand((unsigned)time(NULL));
      matrix[i][j] = rand() * maxValue;
    }
    std::sort(matrix[i].begin(), matrix[i].end());
  }
  return matrix;
}

int main(void)
{
  //vector<vector<int>> matrix = GetRandomMatrix(5, 10, 1000);
  vector<vector<int>>matrix = {{3, 6, 9},{2, 8, 8}, {1, 10, 11}};
  PrintMatrix(matrix);
  std::cout << "====================" << std::endl;
  PrintMaxTopK(matrix, 4);

  return 0;
}

