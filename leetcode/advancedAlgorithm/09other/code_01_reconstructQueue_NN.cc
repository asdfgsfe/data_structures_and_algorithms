class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.empty() || people[0].size() != 2)
        {
            return {};
        }
        std::sort(people.begin(), people.end(), 
                 [](const auto& lhs, const auto& rhs)
                 {
                     return lhs[1] != rhs[1] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
                 });
        int p = 0;
        while (p < people.size() && people[p][1] == 0)
        {
            ++p;
        }
        if (p == people.size())
        {
            return people;
        }
        while (p < people.size())
        {
			//多了一次for
            int cnt = 0;
            for (int i = p - 1; i >= 0; --i)
            {
                cnt = people[i][0] >= people[p][0] ? cnt + 1 : cnt;
            }
            int skip = people[p][1];
            for (int i = p - 1; i >= 0 && cnt > skip; --i)
            {
                if (people[i][0] >= people[i + 1][0])
                {
                    --cnt;
                }
                std::swap(people[i], people[i + 1]);
            }
            ++p;
        }
        return people;
    }
};

//空间复杂度o(1) 时间o(NN) 和参考算法比多了一个常数项