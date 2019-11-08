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
