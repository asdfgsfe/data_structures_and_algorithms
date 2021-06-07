// 659 �����������
����һ��������һЩ 0 �� 1�ķǿն�ά���� grid , 
һ�� ���� �����ĸ����� (ˮƽ��ֱ) �� 1 (��������) ���ɵ���ϡ�
����Լ����ά������ĸ���Ե����ˮ��Χ�š�
�ҵ������Ķ�ά���������ĵ��������(���û�е��죬�򷵻����Ϊ0��)

ʾ�� 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0], 1 0 1
 [0,1,0,0,1,1,0,0,1,1,1,0,0], 1 1 1
 [0,0,0,0,0,0,0,0,0,0,1,0,0],     1 ����6
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
�������������������Ӧ���� 6��ע��𰸲�Ӧ����11����Ϊ����ֻ�ܰ���ˮƽ��ֱ���ĸ�����ġ�1����

ʾ�� 2:

[[0,0,0,0,0,0,0,0]]
����������������ľ���, ���� 0��

ע��: �����ľ���grid �ĳ��ȺͿ�ȶ������� 50��


//dfs
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int maxIsland = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    maxIsland = std::max(maxIsland, Infect(grid, i, j));
                }
            }
        }
        return maxIsland;
    }
    
    int Infect(vector<vector<int>>& grid, int r, int c)
    {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 1)
        {
            return 0;
        }
        grid[r][c] = 2;
        return 1 + Infect(grid, r + 1, c) + Infect(grid, r - 1, c) + Infect(grid, r, c + 1) + Infect(grid, r, c - 1);
    }
};
