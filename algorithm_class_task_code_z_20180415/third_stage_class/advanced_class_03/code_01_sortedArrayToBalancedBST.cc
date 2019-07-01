#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

struct BalancedBST
{
  int val;
  BalancedBST* left;
  BalancedBST* right;

  BalancedBST(int value)
    : val(value), left(nullptr), right(nullptr)
  {}
};

BalancedBST* Generate(const vector<int>& arr, int left, int right)
{
  if (left > right)
  {
    return nullptr;
  }
  
  int mid = (left + right) / 2;
  BalancedBST* pRoot = new BalancedBST(arr[mid]);
  pRoot->left = Generate(arr, left, mid - 1);
  pRoot->right = Generate(arr, mid + 1, right);
  return pRoot;
}

BalancedBST* GeneraterTree(const vector<int>& arr)
{
  if (arr.empty())
  {
    return nullptr;
  }

  return Generate(arr, 0, arr.size() - 1);
}

string GetSpace(int num)
{
  string str = " ";
  for (int i = 0; i < num; ++i)
  {
    str += " ";
  }
  return str;
}

void PrintInOrder(BalancedBST* pRoot, int height, const string& to, int len)
{
  if (pRoot == nullptr)
  {
    return;
  }
  PrintInOrder(pRoot->right, height + 1, "v", len);
  string val = to + std::to_string(pRoot->val) + to;
  int lenM = val.length();
  int lenL = (len - lenM) / 2;
  int lenR = len -lenM -lenL;
  val = GetSpace(lenL) + val + GetSpace(lenR);
  std::cout << (GetSpace(height * len) + val) << std::endl;
  PrintInOrder(pRoot->left, height + 1, "^", len);
}

void PrintTree(BalancedBST* pRoot)
{
  std::cout << "Binary Tree: ";
  PrintInOrder(pRoot, 0, "H", 17);
  std::cout << std::endl;
}

int main(void)
{
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  PrintTree(GeneraterTree(arr)); 
  return 0;
}

