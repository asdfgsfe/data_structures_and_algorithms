#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value)
    :val(value), left(nullptr), right(nullptr)
  {}
};


bool IsPost(const vector<int>& arr, int start, int end)
{
  if (start == end)
  {
    return true;
  }

  int lessRight = -1;
  int moreLeft = end;
  for (int i = start; i < end; ++i)
  {
    if (arr[end] > arr[i])
    {
      lessRight = i;
    }
    else 
    {
      moreLeft = moreLeft == end ? i : moreLeft;
    }
  }
  if (lessRight == -1 || moreLeft == end)
  {
    return IsPost(arr, start, end - 1);
  }
  if (moreLeft - 1 != lessRight)
  {
    return false;
  }
  return IsPost(arr, start, lessRight) && IsPost(arr, moreLeft, end - 1);
}

bool IsPostArray(const vector<int>& arr)
{
  if (arr.empty())
  {
    return false;
  }
  return IsPost(arr, 0, arr.size() - 1);
}

TreeNode* PostToBST(const vector<int>& arr, int start, int end)
{
  if (start > end)
  {
    return nullptr;
  }
  
  TreeNode* pRoot = new TreeNode(end);
  int less = -1;
  int more = end;
  for (int i = start; i < end; ++i)
  {
    if (arr[end] > arr[i])
    {
      less = i;
    }
    else
    {
      more = more == end ? i : more;
    }
  }
  pRoot->left = PostToBST(arr, start, less);
  pRoot->right = PostToBST(arr, more, end - 1);
  return pRoot;
}

TreeNode* PostArrayToBST(const vector<int>& arr)
{
  if (arr.empty())
  {
    return nullptr;
  }
  return PostToBST(arr, 0, arr.size());
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

void PrintInOrder(TreeNode* pRoot, int height, const string& to, int len)
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

void PrintTree(TreeNode* pRoot)
{                                
  std::cout << "Binary Tree: ";  
  PrintInOrder(pRoot, 0, "H", 17);
  std::cout << std::endl;        
} 

int main(void)
{
  vector<int> arr = { 2, 1, 3, 6, 5, 7, 4 };
  std::cout << IsPostArray(arr) << std::endl;
  PrintTree(PostArrayToBST(arr));

  return 0;
}

