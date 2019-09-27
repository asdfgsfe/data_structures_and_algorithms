#include <iostream>
#include <vector>

using std::vector;

//fa先选 选完后一个后fb选 fa希望fa选择后他还能拿到最大的
//fb后选 fb希望他选完后 fa在选只能拿到最小的
int fb(const vector<int>& cards, int l, int r);
int fa(const vector<int>& cards, int l, int r)
{
  if (l == r)
  {
    return cards[l];
  }
  //a先手 a可以选左边 也可以选右边 a先选完左边b选 a先右边b选 a去尝试的选 最终那种值大选那种
  return std::max(cards[l] + fb(cards, l + 1, r), cards[r] + fb(cards, l, r - 1));
}

int fb(const vector<int>& cards, int l, int r)
{
  if (l == r)
  {
    return 0;
  }
  return std::min(fa(cards, l + 1, r), fa(cards, l, r - 1));
}

int WinCards(const vector<int>& cards)
{
  if (cards.size() < 2)
  {
    return cards.empty() ? 0 : cards[0];
  }
  return std::max(fa(cards, 0, cards.size() - 1), fb(cards, 0, cards.size() - 1)); //选择全局最大的 也就是谁赢
}

int WinCardsDp(const vector<int>& cards)
{
  if (cards.size() < 2)
  {
    return cards.empty() ? 0 : cards[0];
  }
  vector<vector<int>> dpa(cards.size(), vector<int>(cards.size(), 0));
  vector<vector<int>> dpb(cards.size(), vector<int>(cards.size(), 0));
  for (int r = 0; r < cards.size(); ++r)
  {
    dpa[r][r] = cards[r];
    for (int l = r - 1; l >= 0; --l)
    {
      dpa[l][r] = std::max(cards[l] + dpb[l + 1][r], cards[r] + dpb[l][r - 1]);
      dpb[l][r] = std::min(dpa[l + 1][r], dpa[l][r - 1]);
    }
  }
  return std::max(dpa[0][cards.size() - 1], dpb[0][cards.size() - 1]);
}

int main(void)
{
  vector<int> cards = {1, 2, 100, 4};
  std::cout << WinCards(cards) << std::endl;
  std::cout << WinCardsDp(cards) << std::endl;

  return 0;
}
