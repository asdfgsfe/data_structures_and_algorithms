//��� nums1 �Ĵ�С�� nums2 С�ܶ࣬���ַ������ţ�
//��� nums2 ��Ԫ�ش洢�ڴ����ϣ������ڴ������޵ģ������㲻��һ�μ������е�Ԫ�ص��ڴ��У������ô�죿
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() || nums2.empty())
		{
			return {};
		}
		vector<int>& less = nums1.size() < nums2.size() ? nums1 : nums2;
		vector<int>& more = nums1.size() > nums2.size() ? nums1 : nums2;
		std::sort(less.begin(), less.end());
		unordered_set<int> visited;
		vector<int> intersection;
		for (int num : more)
		{
			int id = BinSearch(less, num);
			if (id != -1 && !visited.count(id))
			{
				intersection.emplace_back(num);
				visited.emplace(id);
			}
		}
		return intersection;
	}

	int BinSearch(const vector<int>& nums, int num)
	{
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (nums[m] == num)
			{
				return m;
			}
			else if (nums[m] > num)
			{
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
		return -1;
	}
};