 class Solution {
 public:
	 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		 if (numCourses < 1 || prerequisites.empty() || prerequisites[0].empty())
		 {
			 return true;
		 }
		 int indegrees[numCourses] = { 0 };
		 for (const vector<int>& prerequisite : prerequisites)
		 {
			 ++indegrees[prerequisite[0]];
		 }
		 queue<int> courses;
		 for (int i = 0; i < numCourses; ++i)
		 {
			 if (indegrees[i] == 0)
			 {
				 courses.emplace(i);
			 }
		 }
		 while (!courses.empty())
		 {
			 int pre = courses.front();
			 courses.pop();
			 --numCourses;
			 for (const vector<int>& prerequisite : prerequisites)
			 {
				 if (prerequisite[1] != pre)
				 {
					 continue;
				 }
				 if (--indegrees[prerequisite[0]] == 0)
				 {
					 courses.emplace(prerequisite[0]);
				 }
			 }
		 }
		 return numCourses == 0;
	 }
 };

//解题思路：
//本题可约化为：课程安排图是否是 有向无环图(DAG)。
//即课程间规定了前置条件，但不能构成任何环路，否则课程前置条件将不成立。
//思路是通过 拓扑排序 判断此课程安排图是否是 有向无环图(DAG)。
//拓扑排序是对 DAG 的顶点进行排序，使得对每一条有向边 (u, v)，均有 u（在排序记录中）比 v 先出现。
//亦可理解为对某点 v 而言，只有当 v 的所有源点均出现了，v 才能出现。
//通过课程前置条件列表 prerequisites 可以得到课程安排图的 邻接矩阵 adjacency，以下两种方法都会用到邻接矩阵。
//方法1：入度表（广度优先遍历）
//算法流程：
//统计课程安排图中每个节点的入度，生成 入度表 indegrees。
//借助一个队列 queue，将所有入度为 0 的节点入队。
//当 queue 非空时，依次将队首节点出队，在课程安排图中删除此节点 pre：
//并不是真正从邻接表中删除此节点 pre，而是将此节点对应所有邻接节点 cur 的入度 −1，即 indegrees[cur] -= 1。
//当入度 -1后邻接节点 cur 的入度为 0，说明 cur 所有的前驱节点已经被 “删除”，此时将 cur 入队。
//在每次 pre 出队时，执行 numCourses--；
//若整个课程安排图是有向无环图（即可以安排），则所有节点一定都入队并出队过，即完成拓扑排序。
//换个角度说，若课程安排图中存在环，一定有节点的入度始终不为 0。
//因此，拓扑排序出队次数等于课程个数，返回 numCourses == 0 判断课程是否可以成功安排。
//复杂度分析：
//时间复杂度 O(N + M)，遍历一个图需要访问所有节点和所有临边，N 和 M 分别为节点数量和临边数量；
//空间复杂度 O(N)，为建立邻接矩阵所需额外空间。