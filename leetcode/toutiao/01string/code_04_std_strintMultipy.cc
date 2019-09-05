#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    void DebugVector(const vector<int>& v)
    {
        for (int val : v)
        {
            std::cout <<  val << " ";
        }
        std::cout << std::endl;
    }

    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        //int an[n1 + n2]{0};
        vector<int> an(n1 + n2, 0);
        //仅仅只是将相应的位置乘起来 从左向右和从右向左乘是一样的 因为都是那些数字
        //唯一要理解的就是这个初始的位置 怎么算
        for(int i = 0 ; i < n1 ; i++)
        {
            for(int j = 0 ; j < n2 ; j++)
            {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int c = (a * b);
                an[n1 + n2 - i - j - 2] += c;
                std::cout << "idx=" << (n1 + n2 - i - j -2) << std::endl;
            }
        }
        DebugVector(an);
        string ans;
        int i = n1 + n2 - 1 ;
        //向前进位 保证每个位置都为单个数字 其实就是把和累加起来的过程
        //因为上面的计算没有考虑进位
        for (int j = 0 ; j < n1 + n2 ; ++j)
        {
            if (9 < an[j])
            {
                an[j + 1] += (an[j] / 10);
                an[j] %= 10;
            }
        }
        
        while (-1 < i && an[i] == 0) 
        {
            --i;
        }
        //到这an存的都是单个数字了
        while (i >= 0)
        {
            ans.push_back(an[i--]+'0');
        }
        return ans.empty() ? string("0") : ans;
    }
};

int main(void)
{
    string lhs;
    string rhs;
    std::cin >> lhs >> rhs;
    Solution s;
    std::cout << s.multiply(lhs, rhs) << std::endl;

}
