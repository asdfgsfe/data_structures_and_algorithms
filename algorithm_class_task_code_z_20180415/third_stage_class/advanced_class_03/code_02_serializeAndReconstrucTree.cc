#include <iostream>
#include <string>
#include <vector>
#include <queue>

using std::string;
using std::vector;
using std::queue;

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int value)
    : val(value), left(nullptr), right(nullptr)
  {}
};

vector<string> SplitString(const string& str)
{
  if (str.empty())
  {
    return vector<string>();
  }

  vector<string> res;
  int i = 0;
  while (i < str.length())
  {
    int id = str.find('_', i);
    res.push_back(str.substr(i, id - i));
    i = ++id;
  }
  return res;
}

string SerialByPre(TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return "#_";
  }

  string res = std::to_string(pRoot->val) + "_";
  res += SerialByPre(pRoot->left);
  res += SerialByPre(pRoot->right);
  return res;
}

TreeNode* ReconsPreOrder(queue<string>& que)
{
  if (que.empty())
  {
    return nullptr;
  }
  
  string node = que.front();
  que.pop();
  if (node == "#")
  {
    return nullptr;
  }
  TreeNode* pRoot = new TreeNode(std::stoi(node));
  pRoot->left = ReconsPreOrder(que);
  pRoot->right = ReconsPreOrder(que);
  return pRoot;
}

TreeNode* ReconsByPreString(const string& preStr)
{
  if (preStr.empty())
  {
    return nullptr;
  }
  vector<string> nodes = SplitString(preStr);
  queue<string> que;
  for (int i = 0; i < nodes.size(); ++i)
  {
    que.push(std::move(nodes[i]));
  }
  return ReconsPreOrder(que);
}

string SerialByLevel(TreeNode* pRoot)
{
  if (pRoot == nullptr)
  {
    return "#_";
  }

  string res = std::to_string(pRoot->val) + "_";
  queue<TreeNode*> que;
  que.push(pRoot);
  while (!que.empty())
  {
    pRoot = que.front();
    que.pop();
    if (pRoot->left != nullptr)
    {
      res += std::to_string(pRoot->left->val) + "_";
      que.push(pRoot->left);
    }
    else
    {
      res += "#_";
    }
    if (pRoot->right != nullptr)
    {
      res += std::to_string(pRoot->right->val) + "_";
      que.push(pRoot->right);
    }
    else
    {
      res += "#_";
    }
  }
  return res;
}

TreeNode* GenetateNodeByString(const string& str)
{
  if (str.empty() || str == "#")
  {
    return nullptr;
  }
  return new TreeNode(std::stoi(str));
}

TreeNode* ReconByLevelString(const string& str)
{
  if (str.empty())
  {
    return nullptr;
  }
  
  vector<string> nodes = SplitString(str);
  int id = 0;
  TreeNode* pRoot = GenetateNodeByString(nodes[id++]);
  queue<TreeNode*> que;
  if (pRoot != nullptr)
  {
    que.push(pRoot);
  }
  while (!que.empty())
  {
    TreeNode* pNode = que.front();
    que.pop();
    if (id < nodes.size())
    { 
      pNode->left = GenetateNodeByString(nodes[id++]);
      pNode->right = GenetateNodeByString(nodes[id++]);
    }
    if (pNode->left != nullptr)
    {
      que.push(pNode->left);
    }
    if (pNode->right != nullptr)
    {
      que.push(pNode->right);
    }
  }
  return pRoot;
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
  TreeNode* head = nullptr;
  PrintTree(head);

  string pre = SerialByPre(head);
  std::cout << "serialize tree by pre-order: " << pre << std::endl;
  head = ReconsByPreString(pre);
  std::cout << "reconstruct tree by pre-order, " << std::endl;
  PrintTree(head);

  string level = SerialByLevel(head);
  std::cout << "serialize tree by level: " << level << std::endl;
  head = ReconByLevelString(level);
  std::cout << "reconstruct tree by level, "<< std::endl;
  PrintTree(head);

  std::cout << "===================================="<< std::endl;

  head = new TreeNode(1);
  PrintTree(head);

  pre = SerialByPre(head);
  std::cout << "serialize tree by pre-order: " << pre << std::endl;
  head = ReconsByPreString(pre);
  std::cout << "reconstruct tree by pre-order, " << std::endl;
  PrintTree(head);

  level = SerialByLevel(head);
  std::cout << "serialize tree by level: " << level << std::endl;
  head = ReconByLevelString(level);
  std::cout << "reconstruct tree by level, "<< std::endl;
  PrintTree(head);

  std::cout << "===================================="<< std::endl;

  head = new TreeNode(1);
  head->left = new TreeNode(2);
  head->right = new TreeNode(3);
  head->left->left = new TreeNode(4);
  head->right->right = new TreeNode(5);
  PrintTree(head);

  pre = SerialByPre(head);
  std::cout << "serialize tree by pre-order: " << pre << std::endl;
  head = ReconsByPreString(pre);
  std::cout << "reconstruct tree by pre-order, "<< std::endl;
  PrintTree(head);

  level = SerialByLevel(head);
  std::cout << "serialize tree by level: " << level << std::endl;
  head = ReconByLevelString(level);
  std::cout << "reconstruct tree by level, "<< std::endl;
  PrintTree(head);

  std::cout << "===================================="<< std::endl;

  head = new TreeNode(100);
  head->left = new TreeNode(21);
  head->left->left = new TreeNode(37);
  head->right = new TreeNode(-42);
  head->right->left = new TreeNode(0);
  head->right->right = new TreeNode(666);
  PrintTree(head);

  pre = SerialByPre(head);
  std::cout << "serialize tree by pre-order: " << pre <<std::endl;
  head = ReconsByPreString(pre);
  std::cout << "reconstruct tree by pre-order, " << std::endl;
  PrintTree(head);

  level = SerialByLevel(head);
  std::cout << "serialize tree by level: " << level << std::endl;
  head = ReconByLevelString(level);
  std::cout << "reconstruct tree by level, " << std::endl;
  PrintTree(head);

  std::cout << "===================================="<< std::endl;

  return 0;
}

