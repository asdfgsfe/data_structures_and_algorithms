2����
����һ����������дһ���������ж����Ƿ��� 2 ���ݴη���

ʾ�� 1:

����: 1
���: true
����: 20 = 1
ʾ�� 2:

����: 16
���: true
����: 24 = 16
ʾ�� 3:

����: 218
���: false

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1)
        {
            return true;
        }
        if (n < 1 || (n & 0x01) == 1)
        {
            return false;
        }
        while (n > 1)
        {
            if (n % 2 != 0)
            {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};