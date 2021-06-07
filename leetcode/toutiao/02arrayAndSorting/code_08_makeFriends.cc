//【LeetCode-并查集】朋友圈 547已经找不见题目了
/*题目描述#
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

输入：
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出：2
解释：已知学生 0 和学生 1 互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回 2 。

输入：
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出：1
解释：已知学生 0 和学生 1 互为朋友，学生 1 和学生 2 互为朋友，所以学生 0 和学生 2 也是朋友，所以他们三个在一个朋友圈，返回 1 。
说明：

1 <= N <= 200
M[i][i] == 1
M[i][j] == M[j][i] */


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
