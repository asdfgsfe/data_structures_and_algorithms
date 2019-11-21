�ַ������
�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��

ʾ�� 1:

����: num1 = "2", num2 = "3"
���: "6"
ʾ�� 2:

����: num1 = "123", num2 = "456"
���: "56088"
˵����

num1 �� num2 �ĳ���С��110��
num1 �� num2 ֻ�������� 0-9��
num1 �� num2 �������㿪ͷ������������ 0 ����
����ʹ���κα�׼��Ĵ������ͣ����� BigInteger����ֱ�ӽ�����ת��Ϊ����������


class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int an[n1+n2]{0};
        for(int i = 0 ; i < n1 ; i++)
        {
            for(int j = 0 ; j < n2 ; j++)
            {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int c = (a*b);
                an[n1+n2-i-j-2] += c; 
            }
        }
        string ans;
        int ii = n1+n2-1 ;
        
        for(int jj = 0 ; jj < n1+n2 ;jj++)
        {
            if(9 < an[jj])
            {
                an[jj+1] += (an[jj]/10);
                an[jj] %= 10;
            }
        }
        
        while(-1 < ii && an[ii] == 0)
        {
            ii--;
        }

        
        for( ; -1 < ii ;ii--)
        {
            ans.push_back(an[ii]+'0');
        }
        if(ans == "")
        {
            ans.push_back('0');            
        }
        return ans;
    }
};