��֤���Ĵ�
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:

����: "A man, a plan, a canal: Panama"
���: true
ʾ�� 2:

����: "race a car"
���: false

//toupper ������ c ΪСд��ĸ�򽫸ö�Ӧ�Ĵ�д��ĸ����
//isalnum ����������ַ��Ƿ�����ĸ������

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r)
        {
            while(!isalnum(s[l]) && l < r) { ++l; }
            while(!isalnum(s[r]) && l < r) { --r; }
            if(toupper(s[l]) != toupper(s[r])) 
            {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};