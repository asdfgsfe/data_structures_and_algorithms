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

// ����2��������ȱ���
//�㷨���̣�˼·��ͨ�� DFS �ж�ͼ���Ƿ��л�����
//����һ����־�б� flags�������ж�ÿ���ڵ� i ���γ̣���״̬��
//δ�� DFS ���ʣ�i == 0��
//�ѱ������ڵ�������DFS���ʣ�i == -1��
//�ѱ���ǰ�ڵ�������DFS���ʣ�i == 1��
//�� numCourses ���ڵ�����ִ�� DFS���ж�ÿ���ڵ��� DFS �Ƿ���ڻ��������ڻ�ֱ�ӷ��� False��DFS ���̣�
//��ֹ������
//�� flag[i] == -1��˵����ǰ���ʽڵ��ѱ������ڵ������� DFS ���ʣ��������ظ�������ֱ�ӷ��� True��
//�� flag[i] == 1��˵���ڱ��� DFS �����нڵ� i ���� 2 �η��ʣ��� �γ̰���ͼ�л���ֱ�ӷ��� False��
//����ǰ���ʽڵ� i ��Ӧ flag[i] �� 1��������䱻���� DFS ���ʹ���
//�ݹ���ʵ�ǰ�ڵ� i �������ڽӽڵ� j�������ֻ�ֱ�ӷ��� False��
//��ǰ�ڵ������ڽӽڵ��ѱ���������û�з��ֻ����򽫵�ǰ�ڵ� flag ��Ϊ -1 ������ TrueTrue��
//������ͼ DFS ������δ���ֻ������� True��
//���Ӷȷ�����
//ʱ�临�Ӷ� O(N + M)������һ��ͼ��Ҫ�������нڵ�������ٱߣ�N �� M �ֱ�Ϊ�ڵ��������ٱ�������
//�ռ临�Ӷ� O(N)��Ϊ�����ڽӾ����������ռ䡣

//���ӣ�https://leetcode-cn.com/problems/course-schedule/solution/course-schedule-tuo-bu-pai-xu-bfsdfsliang-chong-fa/