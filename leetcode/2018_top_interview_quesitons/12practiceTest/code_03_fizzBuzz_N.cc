fizzBuzzclass Solution {
public:
    vector<string> fizzBuzz(int n) {
        if (n < 1)
        {
            return {};
        }
        vector<string> ans;
        for (int i = 1; i <= n; ++i)
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                ans.emplace_back("FizzBuzz");
            }
            else if (i % 3 == 0)
            {
                ans.emplace_back("Fizz");
            }
            else if (i % 5 == 0)
            {
                ans.emplace_back("Buzz");
            }
            else
            {
                ans.emplace_back(std::to_string(i));
            }
        }
        return ans;
    }
};

Fizz Buzz
写一个程序，输出从 1 到 n 数字的字符串表示。

1. 如果 n 是3的倍数，输出“Fizz”；

2. 如果 n 是5的倍数，输出“Buzz”；

3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。

示例：

n = 15,

返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xm6kpg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
