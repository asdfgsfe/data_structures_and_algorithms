bool IsOneBorder(const vector<vector<int>>& matrix, int row, int col, int side)
{
  if (row >= matrix.size())
  int r = row;
  int c = col;
  while (s < row + size)
  {
    if (matrix[s][col] != 1)
    {
      return false;
    }
    ++s;
  }
  while (c < col + size)
  {
    if (matrix[s][c] != 1)
    {
      return false;
    }
    ++c;
  }
  while (s > row)
  {
    if (matrix[s][c] != 1)
    {
      return false;
    }
    --s;
  }
  while (c > col)
  {
    if (matrix[s][c] != 1)
    {
      return false;
    }
    --c;
  }
  return true;
}

int CountProcess(const vector<vector<int>>& matrix, int row, int col)
{
  if (row >= matix.size() || col >= matrix[0].size())
  {
    return 0;
  }
  //�������д�r c����������ȫ��1�������� ѡ������
  int oneBorder = std::min(matrix.size() - row, matrix[0].size() - col);
  for (int i = oneBorder; i >= 0; --i)
  {
    if (IsOneBorder(matrix, row, col, i))
    {
      oneBorder = i + 1; //ȷ���´˴���i ����i + 1
      break;
    }
  }
  //�������еĵ�
  return std::max(oneBorder, CountProcess(row + 1, col), CountProcess(row, col + 1))
}

int MaxOneBorderSize1(const vector<vector<int>>& matrix)
{
  if (matrix.empty() || matrix[0].empty() || matrxi.size() != matrix[0].size())
  {
    return 0;
  }
  return CountProcess(matrix, 0, 0);
}

//������������ļ��� ���ڶ�̬�滮
void SetBorder(const vector<vector<int>>& matrix, 
              vector<vector<int>>& right,
              vector<vector<int>>& down)
{
  //right��ʾ���ұ��ж��ٸ�������1
  //down��ʾ�������ж��ٸ�������1
  int rows = matrix.size() - 1;
  int cols = matrix[0].size() - 1;
  if (matrix[rows][cols] == 1)
  {
    right[rows][cols] = 1;
    down[rows][cols] = 1;
  }
  for (int i = rows - 1; i >= 0; --i)
  {
    if (matrix[i][cols] == 1)
    {
      right[i][cols] = 1;
      down[i][cols] = down[i + 1][cols] + 1;
    }
  }
  for (int j = cols; j >= 0; --j)
  {
    down[rows][i] = 1;
    right[rows][i] = right[rows][i + 1] + 1;
  }
  for (int i = rows - 2; i >= 0; --i)
  {
    for (int j = clos - 2; j >= 0; --j)
    {
      if (matrix[i][j] == 1)
      {
        right[i][j] = right[i][j + 1] + 1;
        down[i][j] = down[i + 1][j] + 1;
      }
    }
  }
}

bool HasSizeOfBorder(int size, const vector<vector<int>>& right, const vector<vector<int>>& down)
{
  //rows - size + 1��ʾ�ڱߴ�С�̶�λsize��ʱ�� �õ������������ܵ���λ��
  for (int i = 0; i < right.size() - size + 1; ++i)
  {
    //cols - size + 1��ʾ�õ������������ܵ���λ��
    for (int j = 0; j < right[0].size() - size + 1; ++j)
    {
      if (right[i][j] >= size && down[i][j] >= size && right[i + size - 1][j] >= size && down[i][j + size - 1])
      {
        return true;
      }
    }
  }
  return false;
}

int MaxOneBorderSize2(const vector<vector<int>>& matrix)
{
  if (matrix.empty())
  {
    return 0;
  }
  vector<vector<int>> down(matrix.size(), vector<int>(matrix[0].size()));
  vector<vector<int>> right = down;
  SetBorder(matrix, right, down);
  for (int size = std::min(matrix.size(), matrix[0].size() - 1); i >= 0; --i)
  {
    if(HasSizeOfBorder(i, right, down))
    {
      return i;
    }
  }
  return 0;
}

//O(n*n*n*n) ��̬�滮ʱ�临�Ӷ�
int MaxOneBorderSize3(const vector<vector<int>>& matrix)
{
	if (matrix.empty() || matrix.front().empty())
	{
		return 0;
	}
	int maxSize = 0;
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix.front().size(); ++j)
		{
			for (int bestSize = std::min(matrix.size() - i, matrix.front().size() - j); bestSize > 0; --bestSize)
			{
				if (IsOneBorder(matrix, i, j, bestSize))
				{
					maxSize = std::max(maxSize, bestSize);
				}
			}
		}
	}
	return maxSize;
}