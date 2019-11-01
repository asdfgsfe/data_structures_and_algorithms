字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。


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