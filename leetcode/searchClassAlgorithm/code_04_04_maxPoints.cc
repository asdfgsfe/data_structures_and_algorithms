//给出2D平面中的n个坐标点，计算最多有多少个点在一条直线上
//一条直线可以用斜率表示，即如果已知(x1,y1)，(x2,y2)(x1,y1)，(x2,y2)，
//那么斜率为(y2−y1)/(x2−x1)(y2−y1)/(x2−x1) ，
//所以固定一个点，然后遍历其他点，将不同的斜率到个数的映射记录在map中，然后求最大的
//思路是这样，但是由于浮点数计算有误差，导致斜率的计算不是准确的，所以不能直接记录斜率。
//因为斜率是由Δy/ΔxΔy/Δx计算得到的，那么可以采用<Δx,Δy><Δx,Δy>到个数的映射，
//不过需要将Δx，ΔyΔx，Δy化为最简的形式，这样，就可以将<Δx,Δy><Δx,Δy>这个数值对相等看成是斜率相等
//化为最简的方法是找到两个数的最大公约数，使用辗转相除法，计算步骤是
//用第一个数除以第二个数得到余数
//如果余数为0，则第二个数就是最大公约数，返回
//否则，用第二个数除以余数，回到步骤1(即将第二个数作为新的第一个数，将余数作为新的第二个数)
//另外需要注意的一点是坐标点可能存在重合的情况
//代码如下

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
	 //最大公约数
	 int gcd(int a, int b)
	 {
		 return b == 0 ? a : gcd(b, a % b);
	 }
 };