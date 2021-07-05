课程表
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

 

示例 1：

输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
示例 2：

输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
输出：false
解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 

提示：

1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
prerequisites[i] 中的所有课程对 互不相同
相关标签
深度优先搜索
广度优先搜索
图
拓扑排序

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xd54x2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses < 1 || prerequisites.empty()) {
            return true;
        }
        vector<int> courses(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            ++courses[prerequisites[i][0]];
        }
        queue<int> paths;
        for (int i = 0; i < courses.size(); ++i) {
            if (courses[i] == 0) {
                paths.emplace(i);
            }
        }
        while (!paths.empty()) {
            int c = paths.front();
            paths.pop();
            --numCourses;
            for (vector<int>& pre : prerequisites) {
                if (pre[1] == c && --courses[pre[0]] == 0) {
                    paths.emplace(pre[0]);
                }
            }
        }
        return numCourses == 0;
    }
};
