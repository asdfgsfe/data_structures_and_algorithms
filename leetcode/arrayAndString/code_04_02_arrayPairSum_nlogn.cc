class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		if (nums.size() < 2)
		{
			return 0;
		}
		std::sort(nums.begin(), nums.end());
		int sum = 0;
		for (int i = 0; i < nums.size(); i += 2)
		{
			sum += nums[i];
		}
		return sum;
	}
};

//����Ҫ��max(min(a1, b1) + min(a2, b2) + .. min(an, bn)) �����ۼӺ�
//��������� ѡȡ�����ֵ �����ж����ֵ���������Ǵ�