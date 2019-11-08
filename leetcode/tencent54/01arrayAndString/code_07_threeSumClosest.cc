��ӽ�������֮��
����һ������ n ������������ nums �� һ��Ŀ��ֵ target��
�ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ����������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�

���磬�������� nums = [-1��2��1��-4], �� target = 1.

�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3)
		{
			return target;
		}
		std::sort(nums.begin(), nums.end());
		int closest = 0x7fffffff;
		for (int i = 0; i < nums.size(); ++i)
		{
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r)
			{
				int sum = nums[i] + nums[l] + nums[r];
                int curDiff = std::abs(target - sum);
                int preDiff = closest == 0x7fffffff ? closest : std::abs(target - closest);
                if (curDiff < preDiff)
				{
					closest = sum;
				}
				if (target > sum)
				{
					++l;
				}
				else if (target < sum)
				{
					--r;
				}
				else
				{
					return target;
				}
			}
		}
		return closest;
	}
};