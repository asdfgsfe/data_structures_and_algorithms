报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
6.     312211
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211



//题意：
//下一个数是对上一个数的描述，比方说 1211 里有 “ 1 个 1 ， 1 个 2 ， 2 个 1 ” ，
//那么 111221 就是它的下一个数。通常我们把这个数列叫做“外观数列”。
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
        {
            return string("1");
        }
        string pre = countAndSay(n - 1);
        int p = 0;
        string cur;
        while (p < pre.size())
        {
            int n = 1;
            for (int i = p; i < pre.size() - 1; ++i)
            {
                if (pre[i] != pre[i + 1])
                {
                    break;
                }
                ++n;
            }
            cur += std::to_string(n);
            cur += pre[p];
            p += n;
        }
        return cur;
    }
};
