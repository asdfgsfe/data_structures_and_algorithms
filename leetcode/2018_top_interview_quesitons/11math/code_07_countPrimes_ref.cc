class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
        {
            return 0;
        }
		//nlog(n)
        vector<bool> isPrimes(n, true);
        for (int i = 2; i * i < n; ++i)
        {
            if (isPrimes[i])
            {
				//���һ���������� ��ô���ı�����Ȼ��Ϊ����
				//i* i֮ǰ������ һ���ᱻǰ���� ���Դ�i*i��ʼ
                for (int j = i * i; j < n; j += i)
                {
                    isPrimes[j] = false;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < isPrimes.size(); ++i)
        {
            if (isPrimes[i])
            {
                ++cnt;
            }
        }
        return cnt;
    }
};

//������������  һ��������1���������ⲻ�ܱ����������� ��������
//���һ���������� ��ô���ı�����Ȼ��Ϊ����
//�ο���
//���ӣ�https://leetcode-cn.com/problems/count-primes/solution/ru-he-gao-xiao-pan-ding-shai-xuan-su-shu-by-labula/