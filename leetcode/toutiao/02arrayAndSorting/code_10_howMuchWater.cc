class Solution {
public:
    int trap(vector<int>& container) {
        if (container.size() < 3)
        {
            return 0;
        }
        int leftMax = container[0];
        int rightMax = container[container.size() - 1];
        int l = 1;
        int r = container.size() - 2;
        int cnt = 0;
        while (l <= r)
        {
            if (leftMax < rightMax)
            {
                cnt += std::max(0, leftMax - container[l]);
                leftMax = std::max(leftMax, container[l++]);
            }
            else
            {
                cnt += std::max(0, rightMax - container[r]);
                rightMax = std::max(rightMax, container[r--]);
            }
        }
        return cnt;
    }
};
