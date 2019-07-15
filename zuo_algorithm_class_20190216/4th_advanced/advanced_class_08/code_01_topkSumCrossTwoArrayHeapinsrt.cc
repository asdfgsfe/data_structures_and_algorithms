struct Node
{
  int val;
  int row;
  int col;
  Node() {}
  Node(int v, int r, int c)
    : val(v), row(r), col(c)
  {}
};

template<typename T>
class Heap
{
public:
  Heap(int size)
    : data_(vector<T>(size)), size_(0)
  {}
  
  void Insert(const T& node)
  {
    int index = size_;
    assert(index >= 0);
    data_[index] = node;
    while (index > 0)
    {
      int parent = (index - 1) / 2;
      if (data_[parent].val <= data_[index].val)
      {
        break;
      } 
      std::swap(data_[index], data_[parent]);
      index = parent;
    }
  }

  void Heapify(int index)
  {
    int larggest = index;
    int left = index * 2 + 1;
    int right = left + 1;
    while (left < size_)
    {
      larggest = data_[index] < data_[left] ? left : larggest;
      larggest = right < size && data_[larggest] < data_[right] ? right : larggest;
      if (larggest == index)
      {
        break;
      }
      std::swap(data_[index], data_[larggest]);
      index = larggest;
      left = index * 2 + 1;
      right = left + 1;
    }
  }
  void Pop()
  {
    std::swap(data_[0], data_[--size_]);
    Heapify(0);
  }

  T Top() const
  {
    assert(size_ > 0);
    return data_[0];
  }
private:
int size_;
vector<T> data_;
};

void HeapInsert(vector<Node>& nodes, int index, const Node& node)
{
  assert(index >= 0);
  nodes[index] = node;
  while (index > 0)
  {
    int parent = (index - 1) / 2;
    if (nodes[parent].val <= nodes[index].val)
    {
      break;
    }
    std::swap(nodes[index], nodes[parent]);
    index = parent;
  }
}

void Heapify(vector<Node>& nodes, int index, int size)
{
  int larggest = index;
  int left = index * 2 + 1;
  int right = left + 1;
  while (left < size)
  {
    larggest = nodes[index] < nodes[left] ? left : larggest;
    larggest = right < size && nodes[larggest] < nodes[right] ? right : larggest;
    if (larggest == index)
    {
      break;
    }
    std::swap(nodes[index], nodes[larggest]);
    index = larggest;
    left = index * 2 + 1;
    right = left + 1;
  }
}

void HeapPop(vector<int>& nodes, int size)
{
  std::swap(nodes[0], nodes[--size]);
  Heapify(nodes, 0, size);
}

vector<int> TopKSum(const vector<int>& a1, const vector<int>& a2, int k)
{
  if ((a1.empty() && a2.empty()) || k < 1)
  {
    return vector<int>();
  }
  k = std::min(k, (int)(a1.size() * a2.size()));
  vector<Node> nodes(k);
  int heapSize = 0;
  HeapInsert(nodes, heapSize++, Node(a1.back() + a2.back(), a1.size() - 1, a2.size() - 2));
  set<string> position; //这个地方可以利用二维数组visited思想去判断 必须去重复 相同的位置可能累加多次
  vector<int> topK(k);
  for (int i = 0; i < k ++i)
  {
    assert(headSize >= 0);
    topK[i] = nodes[0].val;
    int headR = nodes[0].row;
    int headC = nodes[0].col;
    HeapPop(nodes, heapSize);
    int r = headR - 1;
    int c = headC;
    string curPos = std::to_string(r) + "_" + std::to_string(c);
    if (headR > 0 && position.find(curPos) == position.end())
    {
      HeapInsert(nodes, heapSize++, Node(a1[r] + a2[c], r, c));
      position.insert(curPos);
    }
    r = headR;
    c = headC - 1;
    curPos = std::to_string(r) + "_" + std::to_string(c);
    if (headC > 0 && position.find(curPos) == position.end())
    {
      HeapInsert(nodes, heapSize++, Node(a1[r] + a2[c], l, r));
      position.insert(curPos);
    }
  }
  return topK;
}
