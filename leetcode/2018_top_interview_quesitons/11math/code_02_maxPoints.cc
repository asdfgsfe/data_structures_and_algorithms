 class Solution {

 public:
	 int maxPoints(vector<vector<int>>& points) {
		 if (points.size() < 3)
		 {
			 return points.size();
		 }
		 int maxCnt = 1;
		 for (int i = 0; i < points.size(); ++i)
		 {
			 map<pair<int, int>, int> tanToCnts;
			 int cnt = 0;
			 int same = 0;
			 for (int j = i + 1; j < points.size(); ++j)
			 {
				 int xDiff = points[j][0] - points[i][0];
				 int yDiff = points[j][1] - points[i][1];
				 if (xDiff == 0.0 && yDiff == 0.0)
				 {
					 ++same;
					 continue;
				 }
				 int g = gcd(xDiff, yDiff);
				 xDiff /= g;
				 yDiff /= g;
				 cnt = std::max(cnt, ++tanToCnts[std::make_pair(xDiff, yDiff)]);
			 }
			 maxCnt = std::max(maxCnt, cnt + same + 1);
		 }
		 return maxCnt;
	 }
 private:
	 int gcd(int a, int b)
	 {
		 return b == 0 ? a : gcd(b, a % b);
	 }
 };

 直线上最多的点数
给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

示例 1:

输入: [[1,1],[2,2],[3,3]]
输出: 3
解释:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
示例 2:

输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出: 4
解释:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
相关标签
哈希表
数学


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/x2n2g1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
