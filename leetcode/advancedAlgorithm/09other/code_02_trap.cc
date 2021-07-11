class Solution {
    public int trap(int[] height) {
        if (height == null || height.length < 3) {
            return 0;
        }
        int leftMax = height[0];
        int rightMax = height[height.length - 1];
        int l = 1;
        int r = height.length - 2;
        int water = 0;
        while (l <= r) {
            if (leftMax < rightMax) {
                int cur = Math.max(0, leftMax - height[l]);
                water += cur;
                leftMax = Math.max(leftMax, height[l++]);
            } else {
                int cur = Math.max(0, rightMax - height[r]);
                water += cur;
                rightMax = Math.max(rightMax, height[r--]);
            }
        }
        return water;
    }
}

接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。


