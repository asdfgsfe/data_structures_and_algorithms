#include <iostream>
#include <vector>

using std::vector;

//递归条件的判断很繁琐
int MoveProcess(const vector<vector<int>>& matrix, int r, int c)
{
  if (r == matrix.size() - 1 && c == matrix[0].size() - 1)
  {
    return matrix[r][c];
  }
  if (r == matrix.size() - 1)
  {
    return MoveProcess(matrix, r, c + 1) + matrix[r][c];
  }
  if (c == matrix[0].size() - 1)
  {
    return MoveProcess(matrix, r + 1, c) + matrix[r][c];
  }
  return std::min(MoveProcess(matrix, r + 1, c), MoveProcess(matrix, r, c + 1)) + matrix[r][c];
}

int MinPath(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  return MoveProcess(matrix, 0, 0);
}

//dp的填写也很繁琐 考虑多走一格 减掉dp的初始化操作
int MinPathDp(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty())
  {
    return 0;
  }
  vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
  dp[dp.size() - 1][dp[0].size() - 1] = matrix[matrix.size() - 1][matrix[0].size() - 1];
  for (int i = dp[0].size() - 2; i >= 0; --i)
  {
    dp[dp.size() - 1][i] = dp[dp.size() - 1][i + 1] + matrix[matrix.size() - 1][i];
  }
  for (int i = dp.size() - 2; i >= 0; --i)
  {
    dp[i][dp.size() - 1] = dp[i + 1][dp[0].size() - 1] + matrix[i][matrix[0].size() - 1];
  }
  for (int r = dp.size() - 2; r >= 0; --r)
  {
    for (int c = dp[0].size() - 2; c >= 0; --c)
    {
      dp[r][c] = std::min(dp[r + 1][c], dp[r][c + 1]) + matrix[r][c];
    }
  }
  return dp[0][0];
}

void PrintMatrix(const vector<vector<int>>& matrix)
{
  for (const auto& v : matrix)
  {
    for (int number : v)
    {
      std::cout << number << " ";
    }
    std::cout << std::endl;
  }
}


//矩阵压缩
int MinPathDp(const vector<vector<int>>& matrix)
{
	if (matrix.empty() || matrix.front().empty())
	{
		return 0;
	}
	int l = std::max();
	vector<vector<int>> dp(std::min(matrix.size(), matrix.front().size()));
	dp[0] = matrix[0][0];
	for (int i = 1; i < dp.size(); ++i)
	{
		dp[i] = dp[i - 1] + matrix[0][i];
	}
	for (int i = 1; i < std::max(matrix.size(), matrix.front().size()); ++i)
	{
		dp[0] += dp.size() == matrix.size() ? matrix[i][0] : matrix[0][i];
		for (int j = 1; j < std::min(matrix.size(), matrix.front().size()); ++j)
		{
			dp[j] = dp.size() == matrix.size() ? matrix[j][i] : matrix[i][j] + std::min(dp[j - 1], d[j]);
		}
	}
	return dp.back();
}


int main(void)
{
  vector<vector<int>> matrix = { { 1, 3, 5, 9 }, { 8, 1, 3, 4 }, { 5, 0, 6, 1 }, { 8, 8, 4, 0 } };
  std::cout << MinPath(matrix) << std::endl;
  std::cout << MinPathDp(matrix) << std::endl;
  PrintMatrix(matrix);

  return 0;
}
