//分析过程
//那么至少应该是个二维的dp数组，其中dp[i][j]表示在子数组[i, j]范围内所能得到的最高的分数，
//那么最后我们返回dp[0][n-1]就是要求的结果。
//那么对于dp[i][j]我们想，如果我们移除boxes[i]这个数字，那么总得分应该是1 + dp[i+1][j]，
//但是通过分析题目中的例子，能够获得高积分的trick是，移除某个或某几个数字后，
//如果能使得原本不连续的相同数字变的连续是坠好的，因为同时移除的数字越多，那么所得的积分就越高。
//那么假如在[i, j]中间有个位置m，使得boxes[i]和boxes[m]相等，那么我们就不应该只是移除boxes[i]这个数字，
//而是还应该考虑直接移除[i+1, m-1]区间上的数，使得boxes[i]和boxes[m]直接相邻，
//那么我们获得的积分就是dp[i+1][m-1]，那么我们剩余了什么，boxes[i]和boxes[m, j]区间的数，
//此时我们无法处理子数组[m, j]，因为我们有些信息没有包括在我们的dp数组中，
//此类的题目归纳为不自己包含的子问题，其解法依赖于一些子问题以外的信息。
//这类问题通常没有定义好的重现关系，所以不太容易递归求解。
//为了解决这类问题，我们需要修改问题的定义，使得其包含一些外部信息，从而变成自包含子问题。

//那么对于这道题来说，无法处理boxes[m, j]区间是因为其缺少了关键信息，我们不知道boxes[m]左边相同数字的个数k，
//只有知道了这个信息，那么m的位置才有意义，所以我们的dp数组应该是一个三维数组dp[i][j][k]，
//表示区间[i, j]中能获得的最大积分，当boxes[i]左边有k个数字跟其相等，那么我们的目标就是要求dp[0][n-1][0]了，
//而且我们也能推出dp[i][i][k] = (1+k) * (1+k)这个等式。
//那么我们来推导重现关系，对于dp[i][j][k]，如果我们移除boxes[i]，那么我们得到(1+k)*(1+k) + dp[i+1][j][0]。
//对于上面提到的那种情况，当某个位置m，有boxes[i] == boxes[m]时，我们也应该考虑先移除[i+1,m-1]这部分，
//我们得到积分dp[i+1][m-1][0]，然后再处理剩下的部分，得到积分dp[m][j][k+1]，
//这里k加1点原因是，移除了中间的部分后，原本和boxes[m]不相邻的boxes[i]现在相邻了，又因为二者值相同，所以k应该加1，
//因为k的定义就是左边相等的数字的个数。讲到这里，那么DP方法最难的递推公式也就得到了，那么代码就不难写了，
//需要注意的是，这里的C++的写法不能用vector来表示三维数组，好像是内存限制超出，
//只能用C语言的写法，由于C语言数组的定义需要初始化大小，而题目中说了数组长度不会超100，
//所以我们就用100来初始化，参见代码如下：

class Solution {
public:
	int removeBoxes(vector<int>& boxes) {
		if (boxes.empty())
		{
			return 0;
		}
		int visited[100][100][100] = { 0 };
		return RemoveProcess(boxes, 0, boxes.size() - 1, 0, visited);
	}

	int RemoveProcess(const vector<int>& boxes, int i, int j, int k, int visited[100][100][100])
	{
		if (i > j)
		{
			return 0;
		}
		if (visited[i][j][k])
		{
			return visited[i][j][k];
		}
		int maxScore = (1 + k) * (1 + k) + RemoveProcess(boxes, i + 1, j, 0, visited);
		for (int m = i + 1; m <= j; ++m)
		{
			if (boxes[i] == boxes[m])
			{
				int score = RemoveProcess(boxes, i + 1, m - 1, 0, visited) + RemoveProcess(boxes, m, j, k + 1, visited);
				maxScore = std::max(maxScore, score);
			}
		}
		return visited[i][j][k] = maxScore;
	}
};


class Solution {
public:
	int removeBoxes(vector<int>& boxes) {
		int n = boxes.size();
		int dp[100][100][100] = { 0 };
		return helper(boxes, 0, n - 1, 0, dp);
	}
	int helper(vector<int>& boxes, int i, int j, int k, int dp[100][100][100]) {
		if (j < i) return 0;
		if (dp[i][j][k] > 0) return dp[i][j][k];
		//优化的地方 一次把我当前能走的和我相等的走完
        for (; i + 1 <= j && boxes[i + 1] == boxes[i]; i++, k++);
		int res = (1 + k) * (1 + k) + helper(boxes, i+1 , j, 0, dp);
        //cout<<res<<endl;
		for (int m = i + 1; m <= j; ++m) {
			if (boxes[m] == boxes[i]) {
				res = max(res, helper(boxes, i+1 , m-1 , 0, dp) + helper(boxes, m, j, k + 1, dp));
			}
		}
		return dp[i][j][k] = res;
	}
};



//题目: 移除盒子
//给出一些不同颜色的盒子，盒子的颜色由数字表示，即不同的数字表示不同的颜色。
//你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止。
//每一轮你可以移除具有相同颜色的连续 k 个盒子（k >= 1），这样一轮之后你将得到 k*k 个积分。
//当你将所有盒子都去掉之后，求你能获得的最大积分和。

//示例 1：
//输入:

//[1, 3, 2, 2, 2, 3, 4, 3, 1]
//输出:

//23
//解释:

//[1, 3, 2, 2, 2, 3, 4, 3, 1] 
//----> [1, 3, 3, 4, 3, 1] (3*3=9 分) 
//----> [1, 3, 3, 3, 1] (1*1=1 分) 
//----> [1, 1] (3*3=9 分) 
//----> [] (2*2=4 分)
 
//提示：盒子的总数 n 不会超过 100。