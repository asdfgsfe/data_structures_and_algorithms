//354 俄罗斯套娃信封问题
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。
当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty())
        {
            return 0;
        }  
        std::sort(envelopes.begin(), envelopes.end(), 
                  [](const auto& lhs, const auto& rhs) ->bool
                  {
                      if (lhs.front() != rhs.front())
                      {
                          return lhs.front() < rhs.front();
                      }
                      return lhs.back() > rhs.back();
                  });
        int maxEnv = 1;
        vector<int> dp(envelopes.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < envelopes.size(); ++i)
        {
            dp[i] = 1;
            for(int j = i - 1; j >= 0; --j)
            {
                if (envelopes[i][1] > envelopes[j][1]) //这个地方要注意 由于w已经从小到大排序 只需要选择h递增的就行
                {
                    dp[i]  = std::max(dp[i], dp[j] + 1); 
                }
            }
            maxEnv = std::max(maxEnv, dp[i]);
        }
        return maxEnv;
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty())
        {
            return 0;
        }  
        std::sort(envelopes.begin(), envelopes.end(), 
                  [](const auto& lhs, const auto& rhs) ->bool
                  {
                      if (lhs.front() != rhs.front())
                      {
                          return lhs.front() < rhs.front();
                      }
                      return lhs.back() > rhs.back();
                  });
        vector<int> ends(envelopes.size(), 0);
        ends[0] = envelopes[0][1]; //ends[i]表示 最长递增子序列为i + 1时对应原数组的最小值
        int right = 0;
        for (int i = 1; i < envelopes.size(); ++i)
        {
            int l = 0;
            int r = right;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (envelopes[i][1] > ends[m]) //找到最后一个小于等于envelopes[i][1]的数据
                {
                    //这个地方使用m+1不出问题的地方在于 就是要找目标值的下一个位置 从下一个位置插入
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            right = std::max(right, l);
            ends[l] = envelopes[i][1];
        }
        return right + 1; //ends[right]表示长度为right + 1时的最长递增子序列所以 返回right + 1
    }
};
