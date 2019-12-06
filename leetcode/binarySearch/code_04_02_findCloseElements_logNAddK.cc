class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		if (arr.empty() || k < 1 || k > arr.size())
		{
			return {};
		}
		if (arr[0] >= x)
		{
			return vector<int>(arr.begin(), arr.begin() + k);
		}
		if (arr.back() <= x)
		{
			return vector<int>(arr.end() - k, arr.end());
		}
		int right = RightFirstMaxId(arr, x);
		int s = std::max(0, right - k - 1);
		int e = std::min((int)arr.size() - 1, right + k - 1);
		while (e - s + 1 > k)
		{
			//int lD = std::abs(x - arr[s]);
			//int rD = std::abs(x - arr[e]);
			if (s < 0 || std::abs(x - arr[s]) <= std::abs(x - arr[e]))
			{
				--e;
			}
			else if (e == arr.size() || std::abs(x - arr[s]) > std::abs(x - arr[e]))
			{
				++s;
			}
		} 
		return vector<int>(arr.begin() + s, arr.begin() + e + 1);
	}

	int RightFirstMaxId(const vector<int>& nums, int target)
	{
		if (nums.empty())
		{
			return -1;
		}
		int l = 0;
		int r = nums.size() - 1;
		int right = -1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (nums[m] > target)
			{
				right = m;
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
		return right;
	}
};

//算法
//原本的数组是有序的，所以我们可以像如下步骤利用这一特点。

//如果目标 x 小于等于有序数组的第一个元素，那么前 k 个元素就是答案。
//类似的，如果目标 x 大于等于有序数组的最后一个元素，那么最后 k 个元素就是答案。
//其他情况，我们可以使用二分查找来找到恰好大于 x 一点点的元素的索引 index 。
//然后让 low 等于 index 左边 k-1 个位置的索引，high 等于 index 右边 k-1 个位置的索引。
//我们需要的 kk 个数字肯定在范围 [index-k-1, index+k-1] 里面。所以我们可以根据以下规则缩小范围以得到答案。
//如果 low 小于 0 或者 low 对应的元素比 high 对应的元素更接近 x ，那么减小 high 索引。
//如果 high 大于最后一个元素的索引 arr.size()-1 或者它比起 low 对应的元素更接近 x ，那么增加 low 索引。
//当且仅当 [low, high] 之间恰好有 k 个元素，循环终止，此时范围内的数就是答案。

//方法 1： 使用 Collection.sort()
//算法
//直观地，我们可以将数组中的元素按照与目标 x 的差的绝对值排序，排好序后前 k 个元素就是我们需要的答案。
public List<Integer> findClosestElements(List<Integer> arr, int k, int x) {
     Collections.sort(arr, (a,b) -> a == b ? a - b : Math.abs(a-x) - Math.abs(b-x));
     arr = arr.subList(0, k);
     Collections.sort(arr);
     return arr;
}