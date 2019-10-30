Ѱ�����������������λ��
����������СΪ m �� n ���������� nums1 �� nums2��

�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(log(m + n))��

����Լ��� nums1 �� nums2 ����ͬʱΪ�ա�

ʾ�� 1:

nums1 = [1, 3]
nums2 = [2]

����λ���� 2.0
ʾ�� 2:

nums1 = [1, 2]
nums2 = [3, 4]

����λ���� (2 + 3)/2 = 2.5

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() && nums2.empty())
		{
			return 0;
		}
		if (nums1.empty() && !nums2.empty())
		{
			int size = nums2.size();
			return (size & 0x1) == 1 ? nums2[size / 2] : (nums2[size / 2] + nums2[size / 2 - 1]) / 2.0;
		}
		if (!nums1.empty() && nums2.empty())
		{
			int size = nums1.size();
			return (size & 0x1) == 1 ? nums1[size / 2] : (nums1[size / 2] + nums1[size / 2 - 1]) / 2.0;
		}
		while (nums1.back() > nums2.front())
		{
			std::swap(nums1.back(), nums2.front());
			for (int i = nums1.size() - 1; i > 0 && nums1[i - 1] > nums1[i]; --i)
			{
				std::swap(nums1[i], nums1[i - 1]);
			}
			for (int i = 0; i < nums2.size() - 1 && nums2[i + 1] < nums2[i]; ++i)
			{
				std::swap(nums2[i], nums2[i + 1]);
			}
		}
		int len = nums1.size() + nums2.size();
		int m =  len / 2;
		if (nums1.size() == nums2.size())
		{
			return (nums1.back() + nums2.front()) / 2.0;
		}
		if (nums1.size() > nums2.size())
		{
			return (len & 0x01) == 1 ? nums1[m] : (nums1[m - 1] + nums1[m]) / 2.0;
		}
		int rm = m - nums1.size();
		return(len & 0x01) == 1 ? nums2[rm] : (nums2[rm - 1] + nums2[rm]) / 2.0;
	}
};