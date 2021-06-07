//215�����еĵ�K�����Ԫ��
��δ������������ҵ��� k ������Ԫ�ء�
��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�

ʾ�� 1:

����: [3,2,1,5,6,4] �� k = 2
���: 5
ʾ�� 2:

����: [3,2,3,1,2,4,5,5,6] �� k = 4
���: 4
˵��:

����Լ��� k ������Ч�ģ��� 1 �� k �� ����ĳ��ȡ�


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 1 || k > nums.size())
        {
            return 0x7fffffff;
        }
        std::make_heap(nums.begin(), nums.begin() + k, std::greater<int>());
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[i] >= nums[0])
            {
                std::pop_heap(nums.begin(), nums.begin() + k, std::greater<int>());
                nums[k - 1] = nums[i]; //ֱ���滻���һ��ֵ Ҳ������push_heap ����һ����Ҫ��Push_back
                std::push_heap(nums.begin(), nums.begin() + k, std::greater<int>());
            }
        }
        return nums[0];
    }
};

//����һ�ֲ��Ծ��� heapInsert/heapify
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || k < 1 || k > nums.size())
        {
            return 0x7fffffff;
        }
        for (int i = k / 2; i >=0; --i)
        {
            PercDown(nums, i, k);
        }
        for (int i = k; i < nums.size(); ++i)
        {
            if (nums[i] > nums[0])
            {
                nums[0] = nums[i];
                PercDown(nums, 0, k);
            }
        }
        return nums[0];
    }
    
    void PercDown(vector<int>& nums, int i, int n)
    {
        int child = 2 * i + 1;
        while (child < n)
        {
            if (child + 1 != n && nums[child + 1] < nums[child])
            {
                ++child;
            }
            if (nums[i] <= nums[child])
            {
                break;
            }
            std::swap(nums[i], nums[child]);
            i = child;
            child = 2 * i + 1;
        }
    }
};
