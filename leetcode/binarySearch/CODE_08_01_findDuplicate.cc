//��Ŀ��Ѱ���ظ���

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) {
            return 1;
        }
        int i = 0;
        while (i < nums.size()) {
            if (i == nums[i] - 1) {
                ++i;
            } else if (nums[i] == nums[nums[i] - 1]) {
                return nums[i];
            } else {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return nums.size();
    }
};


//��������intersection point�� �ཻ��һ���ǻ��ϵĵ㣬����һ������ڡ�
//���������ͷ���������ǰһ����һ��a���㣬����һ��b���㣬��ôÿһ�����õľ��붼���һ��
//�ཻ��һ������ڵ����(b-a)���ĵ㡣 Ȼ������ǰ��a��������ڣ��ཻ��ǰ��a������Ҳ�ص���ڡ�

//�������ԭ���ҿ���ͼ���ǿ������������������ǰ��������ֵ֮���໥ת�����������ظ����ֵĴ��ڣ�
//��ôһ�����γɻ����ÿ���ָ������ҵ�����ȷ��������ʼλ��

// �������⣬�������ױ�Ȼ����һ�������ѵ�������ҵ�������� ��ͼ�ܿ���������ôת���ɿ�ʵ�ʱ��������������ѵ㡣 ���˺ù����������ת����׷�����⣬һ���Ӿͺý���ˡ� �ڻ����ڣ�һ���죬һ������ͬʱ���������Ȼ�����׷�����ģ���׷�ϵ��ǿ̣����Ǿ��ҵ��˽����������Կ�ס�
https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode/


//��������е����ֻ��������� ���ַ����ǿ��Ե� �������ĳ�����ֲ������ �Ͳ���ͨ��
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.size() < 2)
		{
			return 0x7fffffff;
		}
		int n = nums.size();
		int maxVal = 0x80000000;
		long long sum = 0;
		for (int num : nums)
		{
			maxVal = std::max(maxVal, num);
			sum += num;
		}
		std::cout << "maxVal=" << maxVal << " sum=" << sum << " n=" << n << std::endl;
		long long allSum = n * (1 + n) / 2;
		long long diff = (n - maxVal) * (maxVal + 1 +  n) / 2;
		std::cout << "allSum=" << allSum << " diff=" << diff << std::endl;
		sum = allSum - sum;
		int repeat = (diff - sum) / (n - maxVal);
		return repeat;
	}
};
