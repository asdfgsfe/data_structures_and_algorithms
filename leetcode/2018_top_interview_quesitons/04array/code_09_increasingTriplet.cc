class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return false;
        }
        int first = 0x7fffffff;
        int second = 0x7fffffff;
        for (int num : nums)
        {
			//�����С�ڵ�һ�� ��ô�ѵ�һ��������
            if (num <= first) //С�ڵ��ںܹؼ�
            {
                first = num;
            }
			//������˵���Ҵ��ڵ�һ�� �����С�ڵڶ��� �ѵڶ���������
            else if (num <= second)
            {
                second = num;
            }
            else //�Ҵ��ڵ�һ�� ���ڵڶ��� ���Ǵ�
            {
                return true;
            }
        }
        return false;
    }
};

//��������xԪ�����С�ͨ�ýⷨ��ά������������
//ά��һ������������win�������鳤���Ϊ3����ʼ��winΪ[nums[0]]�����������顣
//���������������һλ���Ԫ�أ�����Խ��������������
//�������������һλҪС������Ҫ���¸������У�ʹ�������С�����С��������������Ϊ[1,4]ʱ��
//��ʱ����Ԫ��2����ô��Ҫ�������и���Ϊ[1,2]����Ϊ�������С�����С��������²Ÿ�������������Ԫ�أ�
//��һ��������[4, 5], ����Ԫ��1,��ʱ��Ҫ����Ϊ[1,5]�����Է�����ʱ�������в����ϸ��Ӧ���յĵ��������У�
//������ֻ��Ҫ���ȵ�����¿��Բ��ÿ��������е�Ԫ�������

//ͨ�ýⷨ
class Solution {
public:
    bool increasingTriplet(vector<int>& nums, int k) {
        if (nums.size() < 3)
        {
            return false;
        }
		vector<int> less(k, 0x7fffffff);
        for (int num : nums)
        {
			for (int j = 0; j < k; ++j)
			{
				if (num <= less[j])
				{
					less[j] = num;
					break;
				}
			}
			if (j == k)
			{
				return true;
			}
        }
        return false;
    }
};