ֻ����һ�ε�����
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

˵����

����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

ʾ�� 1:

����: [2,2,1]
���: 1
ʾ�� 2:

����: [4,1,2,1,2]
���: 4

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int oneTimes = 0;
        for (int num : nums)
        {
            oneTimes ^= num;
        }
        return oneTimes;
    }
};