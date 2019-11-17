class Solution {
    int dir[5] = {0,-1,0,1,0};
    struct cmp
    {
        bool operator() (const vector<int> &a,const vector<int> &b)
        {
            return a[4] > b[4];
        }
    };
public:
    int minPushBox(vector<vector<char>>& grid) {
        vector<int>s,b,t;
        int n = grid.size(),m=grid[0].size();
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='S')
                {
                    s.push_back(i);
                    s.push_back(j);
                }
                if(grid[i][j]=='B')
                {
                    b.push_back(i);
                    b.push_back(j);
                }
                if(grid[i][j]=='T')
                {
                    t.push_back(i);
                    t.push_back(j);
                }
            }
        priority_queue<vector<int>, vector<vector<int>>, cmp>Q; //这里只能用优先队列
		//vector<int> 里面存的是 renX, renY, boxX, boxY, step
        map<vector<int>,int>ma;
        s.push_back(b[0]);
        s.push_back(b[1]);
        s.push_back(0);
        Q.push(s);
        ma[{s[0],s[1],b[0],b[1]}]=1;
        while(!Q.empty())
        {
            auto cur = Q.top();Q.pop();
            if(cur[2]==t[0]&&cur[3]==t[1])return cur[4];
            for(int i=0;i<4;i++)
            {
                int x = dir[i]+cur[0];
                int y = dir[i+1]+cur[1];
                if(x<0||x>=n||y<0||y>=m)continue;
                if(grid[x][y]=='#')continue;
                if(x==cur[2]&&y==cur[3]) //到达box位置 和人一起走
                {
                    int xx = dir[i]+cur[2];
                    int yy = dir[i+1]+cur[3];
                    if(xx<0||xx>=n||yy<0||yy>=m)continue;
                    if(grid[xx][yy]=='#') continue;
                    if(!ma[{x,y,xx,yy}]) 
                    {
                        ma[{x,y,xx,yy}]=1;
                        Q.push({x,y,xx,yy,cur[4]+1});
                    }
                }
                else if(!ma[{x,y,cur[2],cur[3]}])
                {
                    ma[{x,y,cur[2],cur[3]}] = 1;
                    Q.push({x,y,cur[2],cur[3],cur[4]});
                }
            }
        }
        return -1;
    }
};

//「推箱子」是一款风靡全球的益智小游戏，玩家需要将箱子推到仓库中的目标位置。
//
//游戏地图用大小为 n * m 的网格 grid 表示，其中每个元素可以是墙、地板或者是箱子。
//
//现在你将作为玩家参与游戏，按规则将箱子 'B' 移动到目标位置 'T' ：
//
//玩家用字符 'S' 表示，只要他在地板上，就可以在网格中向上、下、左、右四个方向移动。
//地板用字符 '.' 表示，意味着可以自由行走。
//墙用字符 '#' 表示，意味着障碍物，不能通行。 
//箱子仅有一个，用字符 'B' 表示。相应地，网格上有一个目标位置 'T'。
//玩家需要站在箱子旁边，然后沿着箱子的方向进行移动，此时箱子会被移动到相邻的地板单元格。记作一次「推动」。
//玩家无法越过箱子。
//返回将箱子推到目标位置的最小 推动 次数，如果无法做到，请返回  - 1。
//
//
//
//示例 1：
//
//
//
//输入：grid = [["#", "#", "#", "#", "#", "#"],
//["#", "T", "#", "#", "#", "#"],
//["#", ".", ".", "B", ".", "#"],
//["#", ".", "#", "#", ".", "#"],
//["#", ".", ".", ".", "S", "#"],
//["#", "#", "#", "#", "#", "#"]]
//输出：3
//解释：我们只需要返回推箱子的次数。
//示例 2：
//
//输入：grid = [["#", "#", "#", "#", "#", "#"],
//["#", "T", "#", "#", "#", "#"],
//["#", ".", ".", "B", ".", "#"],
//["#", "#", "#", "#", ".", "#"],
//["#", ".", ".", ".", "S", "#"],
//["#", "#", "#", "#", "#", "#"]]
//输出： - 1
//示例 3：
//
//输入：grid = [["#", "#", "#", "#", "#", "#"],
//["#", "T", ".", ".", "#", "#"],
//["#", ".", "#", "B", ".", "#"],
//["#", ".", ".", ".", ".", "#"],
//["#", ".", ".", ".", "S", "#"],
//["#", "#", "#", "#", "#", "#"]]
//输出：5
//解释：向下、向左、向左、向上再向上。
//示例 4：
//
//输入：grid = [["#", "#", "#", "#", "#", "#", "#"],
//["#", "S", "#", ".", "B", "T", "#"],
//["#", "#", "#", "#", "#", "#", "#"]]
//输出： - 1
//
//
//提示：
//
//1 <= grid.length <= 20
//1 <= grid[i].length <= 20
//grid 仅包含字符 '.', '#', 'S', 'T', 以及 'B'。
//grid 中 'S', 'B' 和 'T' 各只能出现一个。