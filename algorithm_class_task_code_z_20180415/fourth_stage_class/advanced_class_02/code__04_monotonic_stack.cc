#include <iostream>
#include<vector>
#include <stack>

using std::vector;
using std::stack;

struct ReturnData
{
  int leftMaxId;
  int rightMaxId;
  int id;
  ReturnData(int l, int r, int i)
    : leftMaxId(l), rightMaxId(r), id(i)
  {}
};

vector<ReturnData> LeftRightMaxId(const vector<int>& v)
{
  if (v.empty() || v.size() == 1)
  {
    return vector<ReturnData>();
  }
  stack<stack<int>> mst;
  vector<ReturnData> res;
  for (int i = 0; i < v.size(); ++i)
  {
    while (!mst.empty() && !mst.top().empty() && v[mst.top().top()] < v[i])
    {
      stack<int> tmp = mst.top();
      mst.pop();
      while (!tmp.empty())
      {
        if (!mst.empty())
        {
          res.emplace_back(ReturnData(mst.top().top(), i, tmp.top()));
        }
        else
        {
          res.emplace_back(ReturnData(-1, i, tmp.top()));
        }
        tmp.pop();
      }
    }
    if (!mst.empty() && !mst.top().empty() && v[mst.top().top()] == v[i])
    {
      mst.top().push(i);
    }
    else
    {
      stack<int> s;
      s.push(i);
      mst.push(s);
    }
  }
  while (!mst.empty())
  {
    stack<int> tmp = mst.top();
    mst.pop();
    while (!tmp.empty())
    {
      if (!mst.empty())
      {
        res.emplace_back(ReturnData(mst.top().top(), -1, tmp.top()));
      }
      else
      {
        res.emplace_back(ReturnData(-1, -1, tmp.top()));
      }
      tmp.pop();
    }
  }

  return res;
}

void DumpReturnData(const vector<ReturnData>& datas)
{
  std::cout << "Dump:" << std::endl;
  for (auto data : datas)
  {
    std::cout << data.leftMaxId << " " << data.rightMaxId << " ->" << data.id << std::endl;
  }
}

int main(void)
{
  vector<int> v = {5, 4, 3, 5, 5, 6};
  vector<ReturnData> res = LeftRightMaxId(v);
  DumpReturnData(res);

  return 0;
}
