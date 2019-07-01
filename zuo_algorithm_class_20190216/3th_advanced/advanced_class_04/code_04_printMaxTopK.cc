struct HeapNode
{
  int val;
  int arrNum;
  int index;
  HeapNode() {}
  HeapNode(int v, int num, int i)
    : val(v), arrNum(num), index(i)
  {}
};
void PrintMaxTopK(const vector<vector<int>>& matrxi, int topK)
{
  if (matrix.empty() || matrix[0].empty() || topK < 1)
  {
    return;
  }
  vector<HeapNode> maxHeap(matrix.size());
  for (int i = 0; i < maxHeap.size(); ++i)
  {
    int index = matrix[i].size() - 1;
    maxHeap[i] = HeapNode(matrix[i][index], i, index);
    HeapInsert(maxHeap, i);
  }
  int heapSize = maxHeap.size();
  for (int i = 0; i < topK; ++i)
  {
    if (heapSize == 0)
    {
      break
    }
    std::cout << maxHeap[0] << " ";
    if (maxHeap[0].index > 0)
    {
      maxHeap[0].val = matrix[maxHeap[0].arrNum][--maxHeap[0].index];
    }
    else
    {
      std::swap(maxHeap[0], maxHeap[--heapSize]);
    }
    Heapify(maxHeap, 0, heapSize);
  }
}

void HeapInsert(vector<HeadNode>& heap, int index)
{
  while (index != 0)
  {
    int parent = (index - 1) / 2;
    if (heap[index].val <= heap[parent].val)
    {
      break;
    }
    std::swap(heap[parent], heap[index]);
    index = parent;
  }
}

void Heapify(vector<HeapNode>& heap, int index, int size)
{
  int l = 2 * index + 1;
  int r = 2 * index + 2;
  int largest = index;
  while (l < size)
  {
    largest = heap[index].val < heap[l] ? l : index;
    largest = r < size && heap[largest] < heap[r] ? r : largest;
    if (largest == index)
    {
      break
    }
    std::swap(heap[index], heap[largest]);
    index = largest;
    l = 2 * index + 1;
    r = 2 * index + 2;
  }
}
