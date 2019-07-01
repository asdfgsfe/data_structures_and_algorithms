#include <assert.h>
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
    : pRoot(new Node)
  {}

  void AddNode(int num)
  {
    Node* pCur = pRoot;
    for (int move = 31; move >= 0; --move)
    {
      int path = ((num >> move) & 1);
      assert(pCur);
      pCur->nexts[path] = pCur->nexts[path] == nullptr ? new Node() : pCur->nexts[path];
      pCur = pCur->nexts[path];
    }
  }

  int MaxXor(int num)
  {
    int res = 0;
    Node* pCur = pRoot;
    for (int move = 31; move >= 0; --move)
    {
      int path = ((num >> move) & 1);
      int best = move == 31 ? path : (path ^ 1);
      assert(pCur);
      best = pCur->nexts[best] == nullptr ? (best ^ 1) : best;
      res |= (path ^ best) << move;
      pCur = pCur->nexts[best];
    }
    return res;
  }
};

int MaxXorSubArray1(const vector<int>& arr)
{
  if (arr.empty())
  {
    return 0;
  }
  int eor = 0;
  int max = 0x80000000;
  NumTrie nTrie;
  nTrie.AddNode(0);
  for (int num : arr)
  {
    eor ^= num;
    max = std::max(max, nTrie.MaxXor(num));
    nTrie.AddNode(eor);
  }
  return max;
}

int MaxXorSubArray2(const vector<int>& arr)
{
  if (arr.empty())
  {
    return 0;
  }
  int eor = 0;
  int max = 0x80000000;
  vector<int> eors(arr.size(), 0);
  for (int i = 0; i < arr.size(); ++i)
  {
    eor ^= arr[i];
    max = std::max(max, eor);
    for (int start = 1; start <= i; ++start)
    {
      int curEor = eor ^ eors[start - 1];
      max = std::max(max, curEor);
    }
    eors[i] = eor;
  }
  return max;
}

int MaxXorSubArray3(const vector<int>& arr)
{
  if (arr.empty())
  {
    return 0;
  }
  int max = 0x80000000;
  for (int i = 0; i < arr.size(); ++i)
  {
    for (int start = 0; start < i; ++start)
    {
      int eor = 0;
      for (int k = start; k < i; ++k)
      {
        eor ^= arr[k];
      }
      max = std::max(eor, max);
    }
  }
  return max;
}

int main(void)
{
  vector<int> v = {1, 3, 2, 4, 5};
  std::cout << MaxXorSubArray1(v) << std::endl;
  std::cout << MaxXorSubArray2(v) << std::endl;
  std::cout << MaxXorSubArray3(v) << std::endl;

  return 0;
}
