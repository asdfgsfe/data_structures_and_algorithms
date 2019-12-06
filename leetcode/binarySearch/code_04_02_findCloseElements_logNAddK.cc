class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		if (arr.empty() || k < 1 || k > arr.size())
		{
			return {};
		}
		if (arr[0] >= x)
		{
			return vector<int>(arr.begin(), arr.begin() + k);
		}
		if (arr.back() <= x)
		{
			return vector<int>(arr.end() - k, arr.end());
		}
		int right = RightFirstMaxId(arr, x);
		int s = std::max(0, right - k - 1);
		int e = std::min((int)arr.size() - 1, right + k - 1);
		while (e - s + 1 > k)
		{
			//int lD = std::abs(x - arr[s]);
			//int rD = std::abs(x - arr[e]);
			if (s < 0 || std::abs(x - arr[s]) <= std::abs(x - arr[e]))
			{
				--e;
			}
			else if (e == arr.size() || std::abs(x - arr[s]) > std::abs(x - arr[e]))
			{
				++s;
			}
		} 
		return vector<int>(arr.begin() + s, arr.begin() + e + 1);
	}

	int RightFirstMaxId(const vector<int>& nums, int target)
	{
		if (nums.empty())
		{
			return -1;
		}
		int l = 0;
		int r = nums.size() - 1;
		int right = -1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] > target)
			{
				right = m;
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
		return right;
	}
};

//�㷨
//ԭ��������������ģ��������ǿ��������²���������һ�ص㡣

//���Ŀ�� x С�ڵ�����������ĵ�һ��Ԫ�أ���ôǰ k ��Ԫ�ؾ��Ǵ𰸡�
//���Ƶģ����Ŀ�� x ���ڵ���������������һ��Ԫ�أ���ô��� k ��Ԫ�ؾ��Ǵ𰸡�
//������������ǿ���ʹ�ö��ֲ������ҵ�ǡ�ô��� x һ����Ԫ�ص����� index ��
//Ȼ���� low ���� index ��� k-1 ��λ�õ�������high ���� index �ұ� k-1 ��λ�õ�������
//������Ҫ�� kk �����ֿ϶��ڷ�Χ [index-k-1, index+k-1] ���档�������ǿ��Ը������¹�����С��Χ�Եõ��𰸡�
//��� low С�� 0 ���� low ��Ӧ��Ԫ�ر� high ��Ӧ��Ԫ�ظ��ӽ� x ����ô��С high ������
//��� high �������һ��Ԫ�ص����� arr.size()-1 ���������� low ��Ӧ��Ԫ�ظ��ӽ� x ����ô���� low ������
//���ҽ��� [low, high] ֮��ǡ���� k ��Ԫ�أ�ѭ����ֹ����ʱ��Χ�ڵ������Ǵ𰸡�

//���� 1�� ʹ�� Collection.sort()
//�㷨
//ֱ�۵أ����ǿ��Խ������е�Ԫ�ذ�����Ŀ�� x �Ĳ�ľ���ֵ�����ź����ǰ k ��Ԫ�ؾ���������Ҫ�Ĵ𰸡�
public List<Integer> findClosestElements(List<Integer> arr, int k, int x) {
     Collections.sort(arr, (a,b) -> a == b ? a - b : Math.abs(a-x) - Math.abs(b-x));
     arr = arr.subList(0, k);
     Collections.sort(arr);
     return arr;
}