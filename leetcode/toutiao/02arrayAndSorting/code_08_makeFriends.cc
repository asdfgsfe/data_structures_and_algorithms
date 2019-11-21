//并查集的用法
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int res = n;//初始时间每个点就是自己的代表点
        vector<int> root(n);//构造集合
        for (int i = 0; i < n; ++i) 
        {
            root[i] = i;
        }
        for (int i = 0; i < n; ++i) 
        {
            //只考虑右上角的方法
            for (int j = i + 1; j < n; ++j) 
            {
                if (M[i][j] == 0)
                {
                    continue;
                }
                int p1 = getRoot(root, i); //获取i集合所在的father节点
                int p2 = getRoot(root, j); //获取j集合所在的father节点
                if (p1 != p2) 
                {//合并集合
                     --res;
                    root[p2] = p1;
                }
            }   
        }
        return res;
    }
	//查找集合的father 有打平沿途的点
	//root[i]  = cur 表示节点的父节点是cur
    int getRoot(vector<int>& root, int i) 
    {
        int cur = i;
		while (cur != root[cur]) 
        {
            //root[cur] = root[cur]];
            cur = root[cur];
        }
		root[i] = cur;//增加打平沿途的点
        return cur;
    }
};
