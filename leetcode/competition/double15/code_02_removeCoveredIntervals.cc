class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals[0].size() != 2)
        {
            return 0;
        }
        std::sort(intervals.begin(), intervals.end(),
                 [](const auto& lhs, const auto& rhs)
                  {
                      return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
                  });
        int cnt = 1;
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (intervals[i][1] > intervals[p][1])
            {
                ++cnt;
                p = i;
            }
        }
        return cnt;
    }
};