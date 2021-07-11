class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        int size = minHeap_.size() + maxHeap_.size();
        if (size % 2 == 0) {
            if (!maxHeap_.empty() && num < maxHeap_.front()) {
                maxHeap_.push_back(num);
                std::push_heap(maxHeap_.begin(), maxHeap_.end(), std::less<int>());
                std::pop_heap(maxHeap_.begin(), maxHeap_.end(), std::less<int>());
                num = maxHeap_.back();
                maxHeap_.pop_back();
            }
            minHeap_.push_back(num);
            std::push_heap(minHeap_.begin(), minHeap_.end(), std::greater<int>());
        } else {
            if (!minHeap_.empty() && num > minHeap_.front()) {
                minHeap_.push_back(num);
                std::push_heap(minHeap_.begin(), minHeap_.end(), std::greater<int>());
                std::pop_heap(minHeap_.begin(), minHeap_.end(), std::greater<int>());
                num = minHeap_.back();
                minHeap_.pop_back();
            }
            maxHeap_.push_back(num);
            std::push_heap(maxHeap_.begin(), maxHeap_.end(), std::less<int>());
        }
    }
    
    double findMedian() {
        assert (!minHeap_.empty());
        int size = minHeap_.size() + maxHeap_.size();
        if (size % 2 != 0) {
            return minHeap_.front();
        }
        assert (!maxHeap_.empty());
        return (maxHeap_.front() + minHeap_.front()) / 2.0;
    }

private:
    vector<int> minHeap_;
    vector<int> maxHeap_;
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
相关标签
设计
双指针
数据流
排序
堆（优先队列）

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xd3xme/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
