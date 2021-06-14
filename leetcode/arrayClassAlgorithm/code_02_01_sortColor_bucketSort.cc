颜色分类
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x9wv2h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty())
        {
            return;
        }
        int times[3] = {0, 0, 0};
        for (int num : nums)
        {
            ++times[num];
        }
        int p = 0;
        for (int i = 0; i < 3; ++i)
        {
            while (times[i]--)
            {
                nums[p++] = i;
            }
        }
    }
};
