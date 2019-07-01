#include <iostream>
#include <vector>

using std::vector;

struct Node
{
  vector<Node*> nexts;
  Node()
    : nexts(vector<Node*>(2, nullptr))
  {}
};

struct NumTrie
{
  Node* pRoot;
  NumTrie()
    : pRoot(new Node())
  {}

  void AddNode(int num)
  {
    Node* pCur = pRoot;
    for (int move = 31; move >= 0; --move)
    {
      int path = (num >> move) & 1;
      pCur->nexts[path] = pCur->nexts[path] ? pCur->nexts[path] : new Node();
      pCur = pCur->nexts[path];
    }
  }

  //选取以i结尾情况下的最大异或和 等价于std::max(numbers[i], numbers[i] ^ dp[i - 1])
  //num == numbers[i] - dp[i - 1]
  int MaxEor(int num)
  {
    Node* pCur = pRoot;
    int maxEor = 0;
    for (int move = 31; move >= 0; --move)
    {
      int path = (num >> move) & 1;
      int best = move == 31 ? path : (path ^ 1); //path取反
      best = pCur->nexts[best] ? best : (best ^ 1);
      maxEor |= (best ^ path) << move;
      pCur = pCur->nexts[best];
    }
    return maxEor;
  }
};

//利用e0 ^ e1 = e2 e2 ^ e1 = e0的性质
int SubArrayMaxEor(const vector<int>& numbers)
{
  if (numbers.empty())
  {
    return 0;
  }
  NumTrie nTrie;
  nTrie.AddNode(0);
  int eor = 0;
  int maxEor = 0x80000000;
  for (int number : numbers)
  {
    eor ^= number;
    // nTrie中保存0~i-1的异或和 其实就是以每个位置结尾的情况下的异或和
    // 0~i ^ 0~j = i~j 异或的性质
    maxEor = std::max(maxEor, nTrie.MaxEor(eor));
    nTrie.AddNode(eor);
  }
  return maxEor;
}

int main(void)
{
  vector<int> numbers = {1, 3, 2, 4, 5};
  std::cout << SubArrayMaxEor(numbers) << std::endl;

  return 0;
}
