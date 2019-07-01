#include <iostream>
#include <vector>

using std::vector;

int s(const vector<int>& cards, int i, int j);

int f(const vector<int>& cards, int i, int j)
{
  if (i == j)
  {
    return cards[i];
  }
  return std::max(cards[i] + s(cards, i + 1, j), cards[j] + s(cards, i, j - 1));
}

int s(const vector<int>& cards, int i, int j)
{
  if (i == j)
  {
    return 0;
  }
  return std::min(cards[i] + f(cards, i + 1, j), cards[j] + f(cards, i, j - 1));
}

int Win1(const vector<int>& cards)
{
  if (cards.empty())
  {
    return 0;
  }
  return std::max(f(cards, 0, cards.size() - 1), s(cards, 0, cards.size() - 1));
}

int Win2(const vector<int>& cards)
{
  if (cards.empty())
  {
    return 0;
  }
  vector<vector<int>> dpf(cards.size(), vector<int>(cards.size(), 0));
  vector<vector<int>> dps(cards.size(), vector<int>(cards.size(), 0));
  for (int j = 0; j < cards.size(); ++j)
  {
    dpf[j][j] = cards[j];
    for (int i = j - 1; i >= 0; --i)
    {
      dpf[i][j] = std::max(cards[i] + dps[i + 1][j], cards[j] + dps[i][j - 1]);
      dps[i][j] = std::min(cards[i] + dpf[i + 1][j], cards[j] + dpf[i][j - 1]);
    }
  }
  return std::max(dpf[0][cards.size() - 1], dps[0][cards.size() - 1]);
}

int main(void)
{
  vector<int> cards = {1, 9, 1};
  std::cout << Win1(cards) << std::endl;
  std::cout << Win2(cards) << std::endl;

  return 0;
}
