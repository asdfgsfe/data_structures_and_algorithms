�ϲ�������������
�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣

˵��:

��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
ʾ��:

����:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

���: [1,2,2,3,5,6]


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums1.empty() || nums2.empty())
        {
            return;
        }
        int p = m + n;
        --m;
        --n;
        while (m >= 0 && n >= 0)
        {
            if (nums1[m] > nums2[n])
            {
                nums1[--p] = nums1[m--];
            }
            else
            {
                nums1[--p] = nums2[n--];
            }
        }
        while (m >= 0)
        {
            nums1[--p] = nums1[m--];
        }
        while (n >= 0)
        {
            nums1[--p] = nums2[n--];
        }
    }
};