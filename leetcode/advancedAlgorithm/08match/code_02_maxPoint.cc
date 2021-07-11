 //149. 直线上最多的点数

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


