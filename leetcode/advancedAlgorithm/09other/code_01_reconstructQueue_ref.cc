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
                      return lhs[0] != rhs[0] ? lhs[0] > rhs[0] : lhs[1] < rhs[1];
                  });
        list<vector<int>> output;
        for (const vector<int>& p : people)
        {
            auto pos = output.begin();
            for (int i = 0; i < p[1]; ++i)
            {
                ++pos;
            }
            output.insert(pos, p);
        }
        return vector<vector<int>>(output.begin(), output.end());
    }
};

//h从大到小排 h相等 k从小到大排
//然后遍历 排序后的people 把k的值p[1]当做索引 在已经插入完的链表中前面插入 就是答案
//将最高的人按照 k 值升序排序，然后将它们放置到输出队列中与 k 值相等的索引位置上。

//参考理解
//按降序取下一个高度，同样按 k 值对该身高的人升序排序，然后逐个插入到输出队列中与 k 值相等的索引位置上。
//直到完成为止。
//链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/gen-ju-shen-gao-zhong-jian-dui-lie-by-leetcode/