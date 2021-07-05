class KthLargest {
public:
	KthLargest(int k, vector<int>& nums)
		: k_(k)
	{
		int len = nums.size() >= k ? k : nums.size();
		int i = 0;
		while (i < len)
		{
			data_.emplace_back(nums[i++]);
			HeapInsert(data_, data_.size() - 1);
		}
		while (i < nums.size())
		{
			if (data_[0] < nums[i])
			{
				std::swap(data_[0], nums[i]);
				PercDown(data_, 0, k);
			}
			++i;
		}
	}

	int add(int val) {
		if (data_.size() < k_)
		{
			data_.emplace_back(val);
			HeapInsert(data_, data_.size() - 1);
			return data_[0];
		}
		if (data_[0] < val)
		{
			data_[0] = val;
			PercDown(data_, 0, k_);
		}
		return data_[0];
	}
private:
	void PercDown(vector<int>& data, int i, int n)
	{
		int left = 2 * i + 1;
		while (left < n)
		{
			if (left + 1 != n && data[left] > data[left + 1])
			{
				++left;
			}
			if (data[left] > data[i])
			{
				break;
			}
			std::swap(data[left], data[i]);
			i = left;
			left = 2 * i + 1;
		}
	}

	//上滤操作 因为数字在最后一个位置 所以一直向上走 找到合适的位置
	void HeapInsert(vector<int>& data, int i)
	{
		while (i > 0)
		{
	        int p = (i - 1) / 2;
			//小跟堆
            if (data_[p] < data_[i])
			{
				break;
			}
			std::swap(data_[p], data_[i]);
			i = p;
		}
	}
private:
	int k_;
	vector<int> data_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

//Kth Largest Element in a Stream
//设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。

//你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。
//每次调用 KthLargest.add，返回当前数据流中第K大的元素。

//示例:

//int k = 3;
//int[] arr = [4,5,8,2];
//KthLargest kthLargest = new KthLargest(3, arr);
//kthLargest.add(3);   // returns 4
//kthLargest.add(5);   // returns 5
//kthLargest.add(10);  // returns 5
//kthLargest.add(9);   // returns 8
//kthLargest.add(4);   // returns 8
//说明: 
//你可以假设 nums 的长度≥ k-1 且k ≥ 1。
