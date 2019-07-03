//��ʵ�ܼ� �ݹ�����˼����� ÿ��������������һ��
//for ��һ���������0~i����� ʣ�²�����ʣ�µĻ������


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

//��ԭʼ��dp˼�� 
public static int solution1(int[] arr, int num) {
	if (arr == null || arr.length == 0 || num < 1) {
		throw new RuntimeException("err");
	}
	int[] sumArr = new int[arr.length];
	int[] map = new int[arr.length]; //map = dp ֻ����dp�ĳ�ʼ���е�� ���˾���ѹ�� ��ά�ı����1ά
	sumArr[0] = arr[0];
	map[0] = arr[0];
	//Ŀ����Ϊ�˿������i~j���ۼӺ� sum[0~j] - sum[0~i] = sum[i~j]
	for (int i = 1; i < sumArr.length; i++) {
		sumArr[i] = sumArr[i - 1] + arr[i];
		map[i] = sumArr[i];
	}
	for (int i = 1; i < num; i++) {
		for (int j = map.length - 1; j > i - 1; j--) { //����������д��άdp�Ĳ���
			int min = Integer.MAX_VALUE;
			for (int k = i - 1; k < j; k++) {
				//�����Ǹ��Ż� �Ż������ۼӺ� sumArr[j] - sumArr[k]=sumArr[k~j]�ۼӺ�
				//���Ǹ��Ż� �Ҳ������ı���Ŀǰ�Ѿ� �õ���С������� ��ֻ�����Ķ� ��С�������С
				//ӦΪ�����ǲ���ִ�е� ��������Ҫȡ�����ֵʱ�� ���ֵʱ���Ǹ�ƿ��
				int cur = Math.max(map[k], sumArr[j] - sumArr[k]); 
				min = Math.min(min, cur);
			}
			map[j] = min;
		}
	}
	return map[arr.length - 1];
}