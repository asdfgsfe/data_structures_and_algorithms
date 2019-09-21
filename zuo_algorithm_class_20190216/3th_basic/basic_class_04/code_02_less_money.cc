//堆的几种操作 适用范围不同
//1.stl中的算法
//2.heapInsert(vector<int>& a, i), 上虑
//2.heapify(vector<int>& a, int i, int n) 下虑 目前看仅仅适用堆排序
//3.percDown(vector<int>& a, int i. int n) 可以代替stl算法 仅仅下滤 能用于建堆的原因是从堆的中间开始下滤
int lessMoney(vector<int>& money)
{
  if (money.empty())
  {
    return -1;
  }
  if (money.size() == 1)
  {
    return money.front();
  }
  std::make_heap(money.begin(), money.end(); std::greater<int>());
  int minMoney = 0;
  while (money.size() != 1)
  {
    int m = money.front();
    std::pop_heap(money.begin(), money.end(), std::greater<int>());
    money.pop_back();
    m += money.front();
    std::pop_heap(money.begin(); money.end(), std::greater<int>());
    money.pop_back();
    money.push_back(m);
    std::push_heap(money.begin(), money.end(), std::greater<int>());
    minMoney += m;
  }
  return minMoney;
}

#define LeftChild(i) ((2 * (i)) + 1)
void PercDwon(vector<int>& money, int i, int n)
{
  while (LeftChild(i) < n;)
  {
    int child = LeftChild(i);
    if (child != n -1 && money[child - 1] > money[child])
    {
      ++child;
    }
    if (money[child] < money[i])
    {
      std::swap(money[child], money[i]);
    }
    else
    {
      break;
    }
    i = child;
  }
}

int lessMoney2(vector<int>& money)
{
  if (money.empty())
  {
    return -1;
  }
  if (money.size() == 1)
  {
    return money.front();
  }
  for (int i = money.size() / 2; i >= 0; --i)
  {
    PercDwon(money, i, money.size());
  }
  int minMoney = 0;
  while (money.size() != 1)
  {
    int m = money.front();
    std::swap(money.front(), money.back());
    money.pop_back();
    PercDown(money, 0, money.size());
    m += money.front();
    std::swap(money.front(), money.back());
    money.pop_back();
    PercDown(money, 0, money.size());
    money.push_back(m);
    //PercDown(money, money.size() - 1, money.size()); PercDown仅仅是下虑操作 而这个地方是插入节点需要上虑
	HeapInsert(money, money.size() - 1, money.size());
    minMoney += m;
  }
  return minMoney;
}
