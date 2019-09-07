//单调栈递减 应该是可以 但是没有测试
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
        {
            return 0;
        }
        unordered_map<int, pair<int, int>> lrBig;
        stack<int> desc;
        for (int i = 0; i < height.size(); ++i)
        {
            while (!desc.empty() && height[desc.top()] <= height[i])
            {
                int m = desc.top();
                desc.pop();
                int l = desc.empty() ? 0 : desc.top();
                lrBig[m] = make_pair<int, int>(l, i);
            }
            desc.push(i);
        }
        while (!desc.empty())
        {
            int m = desc.top();
            desc.pop();
            int l = desc.empty() ? 0 : desc.top();
            lrBig[m] = make_pair<int, int>(l, height.size());
        }
        int howMuch = 0;
        for (const auto& lr : lrBig)
        {
            const auto& val = lr.second;
            howMuck += (val.second -  val.first) * (std::min(height[val.first], height[val.second]) - height[lr.first]);
        }
        return howMuch;
    }
};
