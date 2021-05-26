������
�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������

ʾ�� 1:

����: 121
���: true
ʾ�� 2:

����: -121
���: false
����: �������Ҷ�, Ϊ -121 �� ���������, Ϊ 121- �����������һ����������
ʾ�� 3:

����: 10
���: false
����: ���������, Ϊ 01 �����������һ����������
����:

���ܲ�������תΪ�ַ�����������������

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }

        string str;
        while(x) {
            int t = x % 10 + '0';
            x = x / 10;
            str.push_back(t);
        }

        for(int i = 0, j = str.length() - 1; i <= j;i++,j--) {
            if(str[i] != str[j]) {
                return false;
            }
        }

        return true;
        
    }
};

//meth2
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
		int bits = MaxBit(x);
        for (int i = 0; i < (bits / 10) && x > 0; i += 2)
        {
			int l = x % 10;
			int r = x / bits;
			if (l != r)
			{
				return false;
			}
			x /= bits;
			x /= 10;
			bits /= 100;
        }
        return i == (bits / 10);
    }

	int MaxBit(int x)
	{
		int bits = 1;
		while (x >= 10)
		{
			bits *= 10;
			x /= 10;
		}
		return bits;
	}
};

//�ٷ��ⷨ
class Solution {
public:
    bool isPalindrome(int x) {
        // ���������
        // ������������ x < 0 ʱ��x ���ǻ�������
        // ͬ���أ�������ֵ����һλ�� 0��Ϊ��ʹ������Ϊ���ģ�
        // �����һλ����ҲӦ���� 0
        // ֻ�� 0 ������һ����
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // �����ֳ���Ϊ����ʱ�����ǿ���ͨ�� revertedNumber/10 ȥ��������λ�����֡�
        // ���磬������Ϊ 12321 ʱ���� while ѭ����ĩβ���ǿ��Եõ� x = 12��revertedNumber = 123��
        // ���ڴ�����λ�����ֲ�Ӱ����ģ����������Լ���ȣ����������ǿ��Լ򵥵ؽ���ȥ����
        return x == revertedNumber || x == revertedNumber / 10;
    }
};

���ߣ�LeetCode-Solution
���ӣ�https://leetcode-cn.com/problems/palindrome-number/solution/hui-wen-shu-by-leetcode-solution/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
