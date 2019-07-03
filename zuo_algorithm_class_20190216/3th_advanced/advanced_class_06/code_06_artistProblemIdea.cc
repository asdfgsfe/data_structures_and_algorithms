//其实很简单 递归大体的思想就是 每个画家完成数组的一段
//for 第一个画家完成0~i这个段 剩下部分有剩下的画家完成


int MinTime(const vector<int>& pictures, int artistNum)
{
	if (pictures.empty() || artistNum < 1)
	{
		return 0;
	}
	return MinProcess(pictures, o, artist);
}

int MinProcess(const vector<int>& pictures, int i, int artistNum)
{
	if (artistNum == 0)
	{
		return i == pictures.size() ? 0 : pictures[i];
	}
	if (i == pictures.size())
	{
		return 0;
	}
	int curMin = 0x7fffffff;
	for (int s = i; s < pictures.size(); ++s)
	{
		int nextTime = MinProcess(pictures, s + 1, artistNum);
		int curTime = 0;
		for (int j = i; j <= s; ++j)
		{
			curTime += pictures[j];
		}
		int cur = std::max(curTime, nextTime);
		curMin = std::min(curMin, cur);
	}
	return curMin;
}

//最原始的dp思想 
public static int solution1(int[] arr, int num) {
	if (arr == null || arr.length == 0 || num < 1) {
		throw new RuntimeException("err");
	}
	int[] sumArr = new int[arr.length];
	int[] map = new int[arr.length]; //map = dp 只不过dp的初始化有点叼 做了矩阵压缩 二维的变成了1维
	sumArr[0] = arr[0];
	map[0] = arr[0];
	//目的是为了快速求出i~j的累加和 sum[0~j] - sum[0~i] = sum[i~j]
	for (int i = 1; i < sumArr.length; i++) {
		sumArr[i] = sumArr[i - 1] + arr[i];
		map[i] = sumArr[i];
	}
	for (int i = 1; i < num; i++) {
		for (int j = map.length - 1; j > i - 1; j--) { //本质上是填写二维dp的操作
			int min = Integer.MAX_VALUE;
			for (int k = i - 1; k < j; k++) {
				//这里是个优化 优化了求累加和 sumArr[j] - sumArr[k]=sumArr[k~j]累加和
				//就是个优化 我不能做的比我目前已经 拿的最小结果还少 我只有做的多 最小结果才能小
				//应为画家是并发执行的 所以这里要取个最大值时间 最大值时间是个瓶颈
				int cur = Math.max(map[k], sumArr[j] - sumArr[k]); 
				min = Math.min(min, cur);
			}
			map[j] = min;
		}
	}
	return map[arr.length - 1];
}