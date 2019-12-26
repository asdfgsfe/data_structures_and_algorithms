 class Solution {
 public:
	 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		 if (numCourses < 1 || prerequisites.empty() || prerequisites[0].empty())
		 {
			 return true;
		 }
		 vector<vector<int>> adjacency(numCourses, vector<int>(numCourses, 0));
		 for (const vector<int>& prerequisite : prerequisites)
		 {
			 adjacency[prerequisite[1]][prerequisite[0]] = 1;
		 }
		 vector<int> visited(numCourses, 0);
		 for (int i = 0; i < adjacency.size(); ++i)
		 {
			 if (!FinishProcess(adjacency, visited, i))
			 {
				 return false;
			 }
		 }
		 return true;
	 }

	 bool FinishProcess(const vector<vector<int>>& adjacency, vector<int>& visited, int i)
	 {
         assert(i >= 0 && i < visited.size());
		 if (visited[i] == 1)
		 {
			 return false;
		 }
		 if (visited[i] == -1)
		 {
			 return true;
		 }
		 visited[i] == 1;
		 for (int j = 0; j < adjacency[0].size(); ++j)
		 {
			 if (adjacency[i][j] == 1 && !FinishProcess(adjacency, visited, j))
			 {
				 return false;
			 }
		 }
		 visited[i] = -1;
		 return true;
	 }
 };

// 方法2：深度优先遍历
//算法流程（思路是通过 DFS 判断图中是否有环）：
//借助一个标志列表 flags，用于判断每个节点 i （课程）的状态：
//未被 DFS 访问：i == 0；
//已被其他节点启动的DFS访问：i == -1；
//已被当前节点启动的DFS访问：i == 1。
//对 numCourses 个节点依次执行 DFS，判断每个节点起步 DFS 是否存在环，若存在环直接返回 False。DFS 流程；
//终止条件：
//当 flag[i] == -1，说明当前访问节点已被其他节点启动的 DFS 访问，无需再重复搜索，直接返回 True。
//当 flag[i] == 1，说明在本轮 DFS 搜索中节点 i 被第 2 次访问，即 课程安排图有环，直接返回 False。
//将当前访问节点 i 对应 flag[i] 置 1，即标记其被本轮 DFS 访问过；
//递归访问当前节点 i 的所有邻接节点 j，当发现环直接返回 False；
//当前节点所有邻接节点已被遍历，并没有发现环，则将当前节点 flag 置为 -1 并返回 TrueTrue。
//若整个图 DFS 结束并未发现环，返回 True。
//复杂度分析：
//时间复杂度 O(N + M)：遍历一个图需要访问所有节点和所有临边，N 和 M 分别为节点数量和临边数量；
//空间复杂度 O(N)，为建立邻接矩阵所需额外空间。

//链接：https://leetcode-cn.com/problems/course-schedule/solution/course-schedule-tuo-bu-pai-xu-bfsdfsliang-chong-fa/