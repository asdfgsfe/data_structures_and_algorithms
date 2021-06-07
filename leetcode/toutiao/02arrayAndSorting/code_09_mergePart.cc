/*
56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

 

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 

提示：

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].empty())
        {
            return vector<vector<int>>();
        }
        std::sort(intervals.begin(), intervals.end(),
                 [](const auto& lhs, const auto& rhs) ->bool
                  {
                      return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
                  });
        vector<vector<int>> spaces;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] > end)
            {
                spaces.emplace_back(vector<int>({start, end}));
                start = intervals[i][0];
            }
            if (intervals[i][1] > end)
            {
                end = intervals[i][1];
            }
        }
        //这一步容易丢
        spaces.emplace_back(vector<int>({start, end}));
        return spaces;
    }
};
