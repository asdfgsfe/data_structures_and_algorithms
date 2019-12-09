//数学解法
//数学解法是在评论区看到的，也就是有个理论：任何一个数，都可以由小于等于4个的完全平方数相加得到。

//然后根据这个理论，有个推论（我也不知道这个推论怎么来的）：

//当\(n \)满足如下公式时，才只能由4个完全平方数得到, \(a \)和\(b \)为某个整数：

//n = 4^a * (8b + 7)
//n=4 
//a
// (8b+7)

//否则，就是只能由1-3个完全平方数得到。

//由一个完全平方数得到就非常好验证了。。。这个大家都懂，直接开方。。。

//由两个完全平方数相加，其实也很好懂，直接从小到大循环，直接看他是不是等于两个完全平方数相加就行了。

//也就是：

// 验证1
//int m = static_cast<int>(sqrt(n));
// 验证2
//if (m * m == n) return 1; 
//for (int i = 1; i * i <= n; i++) {
//    int j = static_cast<int>(pow(n - i * i, 0.5));
//    if (j * j + i * i == n) return 2;
//}
//那由三个完全平方数相加怎么验证呢？ 排除上述三种不就是了？？？？

//所以就很容易写出代码了：

class Solution {
public:
    int numSquares(int n) {
        // 验证1
        int m = static_cast<int>(sqrt(n));
        // 验证2
        if (m * m == n) return 1; 
        for (int i = 1; i * i <= n; i++) {
            int j = static_cast<int>(pow(n - i * i, 0.5));
            if (j * j + i * i == n) return 2;
        }
        // 验证4
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        return 3;
    }
};