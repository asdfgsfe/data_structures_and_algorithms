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
        spaces.emplace_back(vector<int>({start, end}));
        return spaces;
    }
};
