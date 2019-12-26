 class Solution {
 public:
	 vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		 if (numCourses < 1)
		 {
			 return {};
		 }
         if (prerequisites.empty() || prerequisites[0].empty())
         {
             vector<int> order;
             for (int i = 0; i < numCourses; ++i)
             {
                 order.emplace_back(i);
             }
             return order;
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
		 vector<int> order;
		 while (!courses.empty())
		 {
			 int pre = courses.front();
			 courses.pop();
			 order.emplace_back(pre);
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
		 return numCourses == 0 ? order : vector<int>();
	 }
 };