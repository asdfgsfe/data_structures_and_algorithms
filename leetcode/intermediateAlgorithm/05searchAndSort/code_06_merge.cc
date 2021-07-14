class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].size() != 2) {
            return {};
        }
        std::sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& l, const vector<int>& r) {
                return l[0] != r[0] ? l[0] < r[0] : l[1] < r[1];
            });
        vector<vector<int>> merged;
        int s = intervals[0][0];
        int e = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (e < intervals[i][0]) {
                merged.emplace_back(vector<int>{s, e});
                s = intervals[i][0];
            }
            if (intervals[i][1] > e) {
                e = intervals[i][1];
            }
        }
        merged.emplace_back(vector<int>{s, e});
        return merged;
    }
};

合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

 

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 

提示：

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
相关标签
数组
排序

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-medium/xv11yj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
