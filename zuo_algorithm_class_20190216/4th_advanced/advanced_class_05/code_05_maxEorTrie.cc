//贪心算法可以用堆，排序，trie树解决

struct Node
{
  vector<Node*> nexts;
  Node()
    : nexts(2, nullptr)
  {}
}

struct NumTrie
{
  Node* pRoot;
  NumTrie()
    : pRoot(new Node())
    {}

  void AddNode(int num)
  {
    Node* pNode = pRoot;
    for (int move = 31; move >= 0; --move)
    {
      int path = (num >> move) & 1;
      if (pNode->nexts[path] == nullptr)
      {
        pNode->nexts[path] = new Node;
      }
      pNode = pNode->nexts[path];
    }
  }

  int MaxEor(int num)
  {
    Node* pNode = pRoot;
    int maxEor = 0;
    for (int move = 31; move >= 0; --move)
    {
      int path = (num >> move) & 1;
      int best = move == 31 ? path : (path ^ 1);
      best = pNode->nexts[best] ? best : (best ^ 1);
      maxEor |= (best ^ path) << move;
      pNode = pNode->nexts[best];
    }
    return maxEor;
  }
};

int MaxEor(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  NumTrie nTire;
  nTrie.AddNode(0);
  int curEor = 0;
  int maxEor = 0x80000000;
  for (int number : numbers)
  {
    curEor ^= number;
    maxEor = std::max(maxEor, nTrie.MaxEor(curEor));
    nTrie.AddNode(curEor);
  }
  return maxEor;
}
