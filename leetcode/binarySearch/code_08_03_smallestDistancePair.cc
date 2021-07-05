719. �ҳ��� k С�ľ����
����һ���������飬������������֮��ĵ� k ����С���롣һ�� (A, B) �ľ��뱻����Ϊ A �� B ֮��ľ��Բ�ֵ��

ʾ�� 1:

���룺
nums = [1,3,1]
k = 1
�����0 
���ͣ�
�����������£�
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
��˵� 1 ����С����������� (1,1)������֮��ľ���Ϊ 0��
��ʾ:

2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.

class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);

        int lo = 0;
        int hi = nums[nums.length - 1] - nums[0];
        while (lo < hi)
		{
            int mi = (lo + hi) / 2;
            int count = 0, left = 0;
            for (int right = 0; right < nums.length; ++right)
			{
                while (nums[right] - nums[left] > mi)
				{
					left++;
				}
                count += right - left; //ͳ�ƺʹ���mi���ж��ٸ����ж� �ǻ��ֵĴ��˻���С��
            }
            //count = number of pairs with distance <= mi
            if (count >= k) hi = mi;
            else lo = mi + 1; //cout < k ˵��m���ֵ�С��
        }
        return lo;
    }
}

���ߣ�LeetCode
���ӣ�https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/solution/hei-ming-dan-zhong-de-sui-ji-shu-by-leetcode/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
