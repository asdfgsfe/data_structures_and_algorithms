bool IsContinousCards(vector<int>& cards)
{
  if (cards.size() != 5)
  {
    return false;
  }
  std::sort(cards.begin(), cards.end());
  int gap = 0;
  int zeroNum = 0;
  while (zeroNum < cards.size())
  {
    if (cards[zeroNum] != 0)
    {
      break;
    }
    ++zeroNum;
  }
  for (int i = zeroNum + 1; i < cards.size(); ++i)
  {
    if (cards[i] - cards[i - 1] == 0)
    {
      return false;
    }
    gap += cards[i] - cards[i - 1] - 1;
  }
  return zeroNum >= gap;
}
