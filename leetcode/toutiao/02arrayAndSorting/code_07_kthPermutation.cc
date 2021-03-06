//第k个排列 60. 排列序列
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"
示例 2:

输入: n = 4, k = 9
输出: "2314"



首先考虑能不能确定第k个排列是以哪个数字开头的呢，以[1,2,3,4]的全排列为例，找第14个排列

以1开头的排列总共有3!个，原因是第一个位置是1，剩下3个位置可以随便排列，有6个
以2开头的排列总共有3!个，原因是第一个位置是2，剩下3个位置可以随便排列，有6个
此时已经有12个排列
所以剩下的两个排列即第14个排列一定在以3开头的排列中
用这种方式继续缩减数量，以3开头的排列中最小的为[3,1,2,4]，3已经固定，
那么就找[1,2,4]的全排列的第2个排列，就是整个排列的第14个排列

以1开头的排列共有2!个，原因是第二个位置是1，剩下2个位置可以随便排列，有2个
此时已经有两个排列，可以确定结果一定在以[3,1]开头的排列中，即[3,1,2,4]或[3,1,4,2]
继续缩减数量，以[3,1]开头的排列中最下的为[3,1,2,4]，[3,1]已经固定，
那么就找[2,4]的全排列的第2个排列，就是[1,2,4]的全排列的第2个排列，也就是整个排列的第14个排列

以2开头的排列共有1!个，原因是第三个位置是2，剩下一个位置给4，有1个
以4开头的排列共有1!个，原因是第三个位置是4，剩下一个位置给12，有1个
此时已经有两个排列，可以确定结果是以4开头的排列，即[4,2]，所以结果为[3,1,4,2]
所以，可以每次确定一个大范围，在大范围的基础上进一步缩小范围，直到最后只有一个数字为止。遍历n遍即可。

假设某次需要找到第k个排列（k从1开始），以第i个位置开头（i从1开始），上述过程可以表示为 
要找的排列的开头是所剩数字中的第k / (n-i)!个 （整除）或第k / (n-i)! + 1个（非整除）数字，（从1开始）

原因 
上述第一步，序列为[1,2,3,4]，k为14，i为1，(n-i)!为6，k / (n-i)!为2，此时因为要找第14个排列（从1开始），
以1,2开头的各占6个，所以在以3开头的排列中找，所以应该是k / (n-i)! + 1（非整除），即第3个数字，从1开始，
为3 上述第二步，序列为[1,2,3]，确定以3开头后，k为2，i为2，(n-i)!为2，k / (n-i)!为1，此时因为要找第2个排列，
以1开头的就有2个，所以在以1开头的排列中找，所以应该是k / (n-i)! （整除），即第1个数字，从1开始，为1

上面需要根据情况讨论的原因是位置索引都是从1开始的，如果索引从0开始，那么就不会有这么多问题，
此时k为14，即要找第13个排列（从0开始） 
上述第一步，序列为[1,2,3,4]，k为13，i为1，(n-i)!为6，k / (n-i)!为2，k / (n-i)!为2，即第2个数字（从0开始），为3 
上述第二步，序列为[1,2,3]，确定以3开头后，k为1，i为2，(n-i)!为2，k / (n-i)!为0，即第0个数字，为1

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n+1, 1);
        for(int i = 2; i <=n; ++i)
            factorial[i] = i * factorial[i - 1];

        vector<int> nums;
        for(int i = 1; i <= n; ++i)
            nums.emplace_back(i);

        string res("");
        for(int i = 1; i <= n; ++i)
        {
            /* 找开始点 */
            int index = k / factorial[n - i];
            /* 如果非整除，加一 */
            if(k % factorial[n - i] != 0)
                ++index;
            res += (nums[index - 1] + '0');
            //FIXME 可以采用让map里面数字连续的方法 解决vector删除元素慢的情况
            nums.erase(nums.begin() + index - 1);
	        //index-1表示除去我 k - (index-1)*f 表示减掉哪些我已经算过的数
            //index - 1表示我以前的 不能包含我 所以减1
            k = k - ((index - 1) * factorial[n - i]);
        }

        return res;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        if (n < 1 || k < 1)
        {
            return string();
        }
		vector<int> factorial(n + 1, 1);
		vector<int> nums(n);
		nums[0] = 1;
		for (int i = 2; i <= n; ++i)
		{
			factorial[i] = i * factorial[i - 1];
			nums[i - 1] = i;
		}
		
		string res;
	    for (int i = 1; i <= n; ++i)
		{
			int cur = k / factorial[n - i];
			int rest = k % factorial[n - i];
            cur = rest == 0 ? cur : cur + 1;
            res += nums[cur - 1] + '0';
            nums.erase(nums.begin() + cur - 1);
			k -= (cur - 1 )* factorial[n - i];
		}
        return res;
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n + 1, 1);
        vector<int> nums(n);
        nums[0] = 1;
        for (int i = 2; i < factorial.size(); ++i) {
            factorial[i] *= i * factorial[i - 1];
            nums[i - 1] = i;
        }
        string per;
        while (n > 0) {
            int cur = k / factorial[n - 1];
            int rest = k % factorial[n - 1];
            //如果能整出 说明我刚好在x*!(n-1)的这个线上
            //不能整除 说明我刚好在x*!(n-1)的上一个
            cur = rest == 0 ? cur : cur + 1;
            //nums中使用cur-1的原因是 nums[0]=1 nums[1]=2
            per.push_back(nums[cur - 1] + '0');
            //这个数字已经使用过删除
            nums.erase(nums.begin() + cur - 1);
            //如果我在x*(n-1)上一个，那么我跳过了cur和n-1，这里的cur已经+1了
            //如果我刚好在 那么我跳过cur-1和n-1
            k -= (cur - 1) * factorial[n - 1];
            --n;
        }
        return per;
    }
};
