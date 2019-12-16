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