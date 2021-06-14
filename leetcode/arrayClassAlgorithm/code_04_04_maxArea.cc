//11. 盛最多水的容器

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }
        int area = 0;
        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            area = std::max(area, std::min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return area;
    }
};
