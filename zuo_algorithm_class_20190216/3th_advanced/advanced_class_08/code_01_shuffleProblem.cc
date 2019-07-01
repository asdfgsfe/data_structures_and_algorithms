template<typename T>
void Shuffle(vector<T>& cards)
{
  if (!cards.empty() && cards.size() & 1 == 0)
  {
    ShuffleProcess(cards, 0, cards.size() - 1);
  }
}

template<typename T>
void ShuffleProcess(vector<T>& cards, int l, int r)
{
  while (r - l + 1 > 0)
  {
    int lenAndOne = r - l + 1;
    int bloom = 3;
    int k = 1; //k表示这段区间内有多少个触发点
    while (bloom <= lenAndOne / 3)
    {
      bloom *= 3;
      ++k;
    }
    int mid = lenAndOne / 2;
    int part = (bloom - 1) / 2; //bloom一定为奇数 所以bloom-1除以2 和bloom除以2值一样
    Rotate(cards, l + part, mid, mid + part);
    Cycles(cards, l - 1, bloom, k);
    l = l + bloom - 1;
  }
}

template<typename T>
void Rotate(vector<T>& cards, int l, int mid, int r)
{
  //[l,mid)
  Reverse(cards, l, mid);
  Reverse(cards, mid, r);
  Reverse(cards, l ,r)
}

template<typename T>
void Cycles(vector<T>& cards, int base, int bloom, int k)
{
  //base + 1为实际的起始位置
  for (int i = 0, trigger = 1; i < k; ++i, tigger *= 3)
  {
    int next = (2 * trigger) % bloom;
    int cur = next;
    T record = cards[base + next];
    cards[base + next] = cards[base + trigger];
    while (cur != trigger)
    {
      next = (2 * cur) % bloom;
      T tmp = cards[base + next];
      cards[base + next] = records;
      cur = next;
      records = tmp;
    }
  }
}
