合并两个有序数组
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。



作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/all-about-array/x9lhe7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n;
        int i = m - 1;
        int j = n - 1;
		//注意从后面写 不然会出现覆盖的情况
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[--p] = nums1[i--];
            } else {
                nums1[--p] = nums2[j--];
            }
        }
        while (i >= 0) {
            nums1[--p] = nums1[i--];
        }
        while (j >= 0) {
            nums1[--p] = nums2[j--];
        }
    }
};
