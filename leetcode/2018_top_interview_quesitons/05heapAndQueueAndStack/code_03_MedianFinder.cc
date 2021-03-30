 class MedianFinder {
 public:
	 /** initialize your data structure here. */
	 MedianFinder() {

	 }

	 void addNum(int num) {
		 int size = min_.size() + max_.size();
		 if (size % 2 == 0)
		 {
			 if (!max_.empty() && num < max_.front())
			 {
				 max_.push_back(num);
				 std::push_heap(max_.begin(), max_.end(), std::less<int>());
				 num = max_.front();
				 std::pop_heap(max_.begin(), max_.end(), std::less<int>());
				 max_.pop_back();
			 }
			 min_.push_back(num);
			 std::push_heap(min_.begin(), min_.end(), std::greater<int>());
		 }
		 else
		 {
			 if (!min_.empty() && num > min_.front())
			 {
				 min_.push_back(num);
				 std::push_heap(min_.begin(), min_.end(), std::greater<int>());
				 num = min_.front();
				 std::pop_heap(min_.begin(), min_.end(), std::greater<int>());
				 min_.pop_back();
			 }
			 max_.push_back(num);
			 std::push_heap(max_.begin(), max_.end(), std::less<int>());
		 }
	 }

	 double findMedian() {
		 int size = min_.size() + max_.size();
		 if (size == 0)
		 {
			 return 0;
		 }
		 if (size % 2 == 1)
		 {
			 return min_.front();
		 }
		 return ((double)min_.front() + (double)max_.front()) / 2;
	 }
 private:
	 vector<int> min_;
	 vector<int> max_;
 };

 /**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 数据流的中位数
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
进阶:

如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xalff2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
