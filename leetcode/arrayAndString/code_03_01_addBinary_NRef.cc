class Solution {
public:
    string addBinary(string a, string b) {
        int al = a.size();
        int bl = b.size();
        while(al < bl) //�������ַ����ȳ��������ȳ����ڶ̵��ַ���ǰ���㣬����֮��Ĳ����ᳬ������
        {
            a = '0' + a;
            ++ al;
        }
        while(al > bl)
        {
            b = '0' + b;
            ++ bl;
        }
        for(int j = a.size() - 1; j > 0; -- j) //�Ӻ�ǰ�������е�λ����ͬλ���
        {
            a[j] = a[j] - '0' + b[j];
            if(a[j] >=  '2') //�����ڵ����ַ���2������Ҫ��һ
            {
                a[j] = (a[j] - '0') % 2 + '0';
                a[j-1] = a[j-1] + 1;
            }
        }
        a[0] = a[0] - '0' + b[0]; //��ab�ĵ�0λ���
        if(a[0] >= '2') //�����ڵ���2����Ҫ��һ
        {
            a[0] = (a[0] - '0') % 2 + '0';
            a = '1' + a;
        }
        return a;
    }
};